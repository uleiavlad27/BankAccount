#include "service.h"
#include <ctime>
Service::Service(Repo repo) {
    this->repo = repo;
}

Service::~Service(){
    this->repo.destroy();
}

void Service::addElem(Tranzactie tranzactie) {
    repo.addElem(tranzactie);
}

void Service::adauga(int suma, char* tip, char* descriere) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int ziua = ltm->tm_mday;
    Tranzactie tranzactie = Tranzactie(suma, ziua, tip, descriere);
    std::pair<function, std::vector<Tranzactie>> inapoi;
    inapoi.first = &Service::del;
    inapoi.second.push_back(tranzactie);
    undo.push(inapoi);
    this->repo.addElem(tranzactie);
}

void Service::inserare(int suma,int ziua, char* tip, char* descriere) {
    Tranzactie tranzactie = Tranzactie(suma, ziua, tip, descriere);
    std::pair<function, std::vector<Tranzactie>> inapoi;
    inapoi.first = &Service::del;
    inapoi.second.push_back(tranzactie);
    undo.push(inapoi);
    this->repo.addElem(tranzactie);
}

void Service::del(Tranzactie tranzactie) {
    repo.del(tranzactie);
}

void Service::delElem(int j) {
    std::pair<function, std::vector<Tranzactie>> inapoi;
    inapoi.first = &Service::addElem;
    inapoi.second.push_back(repo.getElem(j));
    undo.push(inapoi);
    repo.delElem(j);
}

void Service::delZiua(int ziua) {
    std::pair<function, std::vector<Tranzactie>> inapoi;
    inapoi.first = &Service::addElem;
    for(int i = 0;i < repo.getSize();i++)
        if(repo.getElem(i).getZiua() == ziua)
        {
            inapoi.second.push_back(repo.getElem(i));
            repo.delElem(i);
            i--;
        }
    undo.push(inapoi);
}

void Service::delZiua(int ziua1, int ziua2) {
    std::pair<function, std::vector<Tranzactie>> inapoi;
    inapoi.first = &Service::addElem;
    for(int i = 0;i < repo.getSize();i++)
        if(repo.getElem(i).getZiua() >= ziua1 and repo.getElem(i).getZiua() <= ziua2)
        {
            inapoi.second.push_back(repo.getElem(i));
            repo.delElem(i);
            i--;
        }
    undo.push(inapoi);
}

void Service::delTip(char* tip) {
    std::pair<function, std::vector<Tranzactie>> inapoi;
    inapoi.first = &Service::addElem;
    for(int i = 0;i < repo.getSize();i++)
        if(strcmp(repo.getElem(i).geTip(),tip) == 0)
        {
            inapoi.second.push_back(repo.getElem(i));
            repo.delElem(i);
            i--;
        }
    undo.push(inapoi);
}

void Service::modify(Tranzactie tranzactie) {
    repo.modify(tranzactie);
}

void Service::modify(int suma, int ziua, char* tip, char* descriere) {
    std::pair<function, std::vector<Tranzactie>> inapoi;
    inapoi.first = &Service::modify;
    Tranzactie tranzactie = Tranzactie(suma, ziua, tip, descriere);
    for(int i = 0;i <repo.getSize();i++)
        if(this->repo.getElem(i).getZiua() == ziua and strcmp(this->repo.getElem(i).geTip(),tip) == 0)
        {
            inapoi.second.push_back(repo.getElem(i));
            this->repo.modify(tranzactie);
        }
    undo.push(inapoi);
}

Tranzactie* Service::getAll() {
    return this->repo.getAll();
}

std::vector<Tranzactie> Service::getByTip(char* tip) {
    std::vector<Tranzactie> tranzactii;
    int nr = 0;
    for(int i = 0;i < this->repo.getSize();i++)
        if(strcmp(this->repo.getElem(i).geTip(), tip) == 0)
            tranzactii.push_back(repo.getElem(i));
    return tranzactii;
}

std::vector<Tranzactie> Service::getByTipandSum(char* tip, int suma) {
    std::vector<Tranzactie> tranzactii;
    int nr = 0;
    for(int i = 0;i < this->repo.getSize();i++)
        if(strcmp(this->repo.getElem(i).geTip(), tip) == 0 and this->repo.getElem(i).getSuma() < suma)
            tranzactii.push_back(repo.getElem(i));
    return tranzactii;
}

std::vector<Tranzactie> Service::getBySuma(int suma) {
    std::vector<Tranzactie> tranzactii;
    for(int i = 0;i < this->repo.getSize();i++)
        if(this->repo.getElem(i).getSuma() == suma)
            tranzactii.push_back(repo.getElem(i));
    return tranzactii;
}

std::vector<Tranzactie> Service::getGreaterSuma(int suma) {
    std::vector<Tranzactie> tranzactii;
    for(int i = 0;i < this->repo.getSize();i++)
        if(this->repo.getElem(i).getSuma() > suma)
            tranzactii.push_back(repo.getElem(i));
    return tranzactii;
}

std::vector<Tranzactie> Service::getBellowSuma(int suma) {
    std::vector<Tranzactie> tranzactii;
    for(int i = 0;i < this->repo.getSize();i++)
        if(this->repo.getElem(i).getSuma() < suma)
            tranzactii.push_back(repo.getElem(i));
    return tranzactii;
}

int Service::getSold(int ziua) {
    int in=0, out = 0;
    for(int i = 0;i < this->repo.getSize();i++)
        if(this->repo.getElem(i).getZiua() == ziua)
            if(strcmp(this->repo.getElem(i).geTip(), "out") == 0)
                out+=this->repo.getElem(i).getSuma();
            else
                in+=this->repo.getElem(i).getSuma();
    return in-out;
}

int Service::getSumaByTip(char* tip) {
    int out = 0;
    for(int i = 0;i < this->repo.getSize();i++)
        if(strcmp(this->repo.getElem(i).geTip(), tip) == 0)
                out+=this->repo.getElem(i).getSuma();
    return out;
}

int Service::maxim(char* tip, int ziua) {
    int max = 0;
    for(int i = 0;i < this->repo.getSize();i++)
        if(strcmp(this->repo.getElem(i).geTip(), tip) == 0 && this->repo.getElem(i).getZiua() == ziua
            && this->repo.getElem(i).getSuma() > max)
            max = this->repo.getElem(i).getSuma();
    return max;
}

int Service::minim(char* tip, int ziua) {
    int min = this->repo.getElem(0).getSuma();
    for(int i = 1;i < this->repo.getSize();i++)
        if(strcmp(this->repo.getElem(i).geTip(), tip) == 0 && this->repo.getElem(i).getZiua() == ziua
           && this->repo.getElem(i).getSuma() < min)
            min = this->repo.getElem(i).getSuma();
    return min;
}

void Service::filtrareTip(char* tip) {
    std::pair<function, std::vector<Tranzactie>> inapoi;
    inapoi.first = &Service::addElem;
    for(int i = 0;i < this->repo.getSize();i++)
        if(strcmp(this->repo.getElem(i).geTip(), tip) != 0)
        {
            inapoi.second.push_back(repo.getElem(i));
            repo.delElem(i);
            i--;
        }
    undo.push(inapoi);
}

void Service::filtrareTipSuma(char* tip, int suma) {
    std::pair<function, std::vector<Tranzactie>> inapoi;
    inapoi.first = &Service::addElem;
    for(int i = 0;i < this->repo.getSize();i++)
        if(strcmp(this->repo.getElem(i).geTip(), tip) != 0 && this->repo.getElem(i).getSuma() >= suma)
        {
            inapoi.second.push_back(repo.getElem(i));
            repo.delElem(i);
            i--;
        }
    undo.push(inapoi);
}

int Service::getSize() {
    return this->repo.getSize();
}

void Service::Getundo() {
    for(auto tranzactie:undo.top().second)
        (this->*undo.top().first)(tranzactie);
    undo.pop();
}