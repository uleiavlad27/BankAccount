#ifndef LAB7OOP_SERVICE_H
#define LAB7OOP_SERVICE_H
#include "../entitate/entitate.h"
#include "../repository/repo.h"
#include <iostream>
#include <stack>
#include <vector>
class Service {
private:
    Repo repo;
    typedef void (Service::*function)(Tranzactie);
    std::stack<std::pair<function, std::vector<Tranzactie>>> undo;
    int numarOperatii = 0;
public:
    /**
* constructorul service ului
* @param repo - Repo
* @return o instanta a structurii de tip tranzactie
*/
    Service(Repo repo);
/**
* destructorul service ului
 */
    ~Service();

    /**
* adauga o tranzactie in lista
* @param entitate- Tranzactie
*/
    void adauga(int suma, char* tip, char *descriere);

    /**
* insereaza o tranzactie in lista
* @param suma - int
* @param ziua - int
* @param tip - char
* @param descriere - char
*/
    void inserare(int suma, int ziua, char *tip, char *descriere);

    /**
* sterge o tranzactie in lista dupa ziua
* @param ziua- int
*/
void delZiua(int ziua);
    /**
* sterge o tranzactie in lista dupa ziua
* @param ziua1- int
* @param ziua2- int
*/
void delZiua(int ziua1, int ziua2);

    /**
* sterge o tranzactie in lista dupa tip
* @param tip - char
*/
void delTip(char *tip);
    /**
* modifica o tranzactie in lista
* @param suma - int
* @param ziua - int
* @param tip - char
* @param descriere - char
*/
void modify(int suma, int ziua, char *tip, char *descriere);

Tranzactie *getAll();

/**
* afiseaza o tranzactie in lista dupa suma
* @param suma - int
* @return lista - std::vector<Tranzactie>
*/
std::vector<Tranzactie> getBySuma(int suma);

/**
* afiseaza o tranzactie in lista dupa elemntele mai mare decat suma citita
* @param suma - int
* @return lista - std::vector<Tranzactie>
*/
std::vector<Tranzactie> getGreaterSuma(int suma);
/**
* afiseaza o tranzactie in lista dupa elemntele mai mica decat suma citita
* @param suma - int
* @return lista - std::vector<Tranzactie>
*/
std::vector<Tranzactie> getBellowSuma(int suma);

/**
* afiseaza soldul din acea zi
* @param ziua - int
* @return sold - int
*/
int getSold(int ziua);

/**
* afiseaza marimea listei
* @return size - int
*/
int getSize();

/**
* afiseaza o tranzactie in lista dupa suma
* @param suma - int
* @return lista - std::vector<Tranzactie>
*/
std::vector<Tranzactie> getByTip(char *tip);

/**
* afiseaza o tranzactie in lista dupa suma
* @param suma - int
* @return lista - std::vector<Tranzactie>
*/
int getSumaByTip(char *tip);

/**
* afiseaza maximul unei tranzactii dupa suma si tip
* @param suma - int
* @param tip - char
* @return lista - std::vector<Tranzactie>
*/
int maxim(char *tip, int ziua);

/**
* afiseaza minimul unei tranzactii dupa suma si tip
* @param suma - int
* @param tip - char
* @return lista - std::vector<Tranzactie>
*/
int minim(char *tip, int ziua);
/**
* afiseaza o tranzactie in lista dupa suma
* @param suma - int
* @return lista - std::vector<Tranzactie>
*/
void filtrareTip(char *tip);

/**
* afiseaza o tranzactie in lista dupa suma
* @param suma - int
* @return lista - std::vector<Tranzactie>
*/
void filtrareTipSuma(char *tip, int suma);


/**
* functie undo ce revine la valorile precedente
*/
void Getundo();




























void delElem(int j);

void del(Tranzactie tranzactie);

void addElem(Tranzactie tranzactie);

void modify(Tranzactie tranzactie);

std::vector<Tranzactie> getByTipandSum(char *tip, int suma);
};


#endif //LAB7OOP_SERVICE_H
