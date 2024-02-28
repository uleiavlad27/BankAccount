#include "entitate.h"

Tranzactie::Tranzactie() {
    this->setSuma(0);
    this->setZiua(8);
    this->setTip("out");
    this->descriere = nullptr;
}

Tranzactie::Tranzactie(int suma, int ziua, char* tip, char* descriere) {
    this->setSuma(suma);
    this->setZiua(ziua);
    this->setTip(tip);
    this->descriere = new char[strlen(descriere)+1];
    strcpy(this->descriere, descriere);
}

Tranzactie::Tranzactie(const Tranzactie &entitate) {
    this->setSuma(entitate.suma);
    this->setZiua(entitate.ziua);
    char in[] = "in", out[] = "out";
    if(entitate.tip)
        this->setTip(in);
    else
        this->setTip(out);
    if(entitate.descriere != nullptr) {
        this->descriere = new char[strlen(entitate.descriere)+1];
        strcpy(this->descriere, entitate.descriere);
    }
    else
        this->descriere = nullptr;
}

Tranzactie::~Tranzactie() {
    delete[] this->descriere;
    descriere = nullptr;
}

Tranzactie &Tranzactie::operator=(const Tranzactie &entitate) {
    this->setSuma(entitate.suma);
    this->setZiua(entitate.ziua);
    char in[] = "in", out[] = "out";
    if(entitate.tip)
        this->setTip(in);
    else
        this->setTip(out);
    if(entitate.descriere != nullptr) {
        this->descriere = new char[strlen(entitate.descriere)+1];
        strcpy(this->descriere, entitate.descriere);
    }
    else
        this->descriere = nullptr;
    return *this;
}

bool Tranzactie::operator==(const Tranzactie &entitate) {
    return (this->suma == entitate.suma) && (this->ziua == entitate.ziua) && (strcmp(this->descriere, entitate.descriere) == 0) && this->tip == entitate.tip;
}

void Tranzactie::setSuma(int s) {
    this->suma = s;
}

void Tranzactie::setDescriere(char* descriere) {
    if(this->descriere)
        delete[] this->descriere;
    this->descriere = new char[strlen(descriere)+1];
    strcpy(this->descriere, descriere);
}

void Tranzactie::setTip(char* tip) {
    if(strcmp(tip, "in") == 0)
        this->tip = 1;
    else
        this->tip = 0;
}

void Tranzactie::setZiua(int zi) {
    this->ziua = zi;
}

unsigned int Tranzactie::getSuma() {
    return this->suma;
}

unsigned int Tranzactie::getZiua() {
    return this->ziua;
}

char* Tranzactie::geTip() {
    if(this->tip)
        return "in";
    else
        return "out";
}

char* Tranzactie::getDescriere() {
    return this->descriere;
}
