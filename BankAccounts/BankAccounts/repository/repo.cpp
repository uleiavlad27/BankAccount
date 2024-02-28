#include "repo.h"
#include <iostream>
using namespace std;

Repo::Repo() {
    this->nrElem = 0;
    this->entitati = new Tranzactie[0];
}

Repo::~Repo() {

}


void Repo::destroy() {
    delete[] this->entitati;
}

Repo& Repo::operator=(const Repo repo) {
    for(int i = 0;i< repo.nrElem;i++)
        this->entitati[i] = repo.entitati[i];
    return *this;
}

void Repo::addElem(Tranzactie entitate) {

    Tranzactie* copie = new Tranzactie[this->nrElem];
    for(int i = 0;i< this->nrElem;i++)
        copie[i] = this->entitati[i];
    this->entitati = new Tranzactie[++this->nrElem];
    for(int i = 0;i< this->nrElem-1;i++)
        this->entitati[i] = copie[i];
    this->entitati[this->nrElem-1] = entitate;
}

int Repo::getIndex(Tranzactie entitate) {
    for(int i = 0;i<this->nrElem;i++)
        if(this->entitati[i] == entitate)
            return i;
    return -1;
}

void Repo::delElem(int j) {
    Tranzactie* copie = new Tranzactie[this->nrElem];
    for(int i = j;i< this->nrElem-1;i++)
        this->entitati[i] = this->entitati[i+1];
    for(int i = 0;i< this->nrElem-1;i++)
        copie[i] = this->entitati[i];
    this->entitati = new Tranzactie[--this->nrElem];
    for(int i = 0;i< this->nrElem;i++)
        this->entitati[i] = copie[i];
}

void Repo::del(Tranzactie entitate) {
    for(int i = 0;i < this->nrElem;i++)
        if(this->entitati[i] == entitate) {
            delElem(i);
            i = this->nrElem;
        }
}
void Repo::modify(Tranzactie nou) {
    for(int i = 0;i < this->nrElem; i++)
        if(this->entitati[i].getZiua() == nou.getZiua() and strcmp(this->entitati[i].geTip(),nou.geTip()) == 0)
            this->entitati[i] = nou;
}

Tranzactie* Repo::getAll() {
    return this->entitati;
}

int Repo::getSize() {
    return this->nrElem;
}

Tranzactie Repo::getElem(int i) {
    return this->entitati[i];
}

