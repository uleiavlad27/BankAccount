//
// Created by Spaca on 4/12/2023.
//

#ifndef LAB7OOP_REPO_H
#define LAB7OOP_REPO_H
#include "../entitate/entitate.h"
#include <stack>
class Repo {
private:
    Tranzactie* entitati;
    int nrElem = 0;
public:
    /**
* constructorul unei liste de tranzactii
* @return o instanta a structurii de tip tranzactie
*/
    Repo();
    /**
* desconstructorul unei liste de tranzactii
* @return o instanta a structurii de tip tranzactie
*/
    ~Repo();
    /**
* creare operatorului  = unei liste de tranzactii
* @param repo - clasa repo
*/
    Repo& operator=(const Repo repo);
    /**
* adauga o tranzactie in lista
* @param entitate- Tranzactie
*/
    void addElem(Tranzactie entitate);


    int getIndex(Tranzactie entitate);

    /**
* modifica o tranzactie in lista
* @param nou- Tranzactie
*/
    void modify(Tranzactie nou);
    /**
* sterge o tranzactie in lista
* @param j- int
*/
    void delElem(int j);

    /**
* desconstructorul unei liste de tranzactii
* @return o instanta a structurii de tip tranzactie
*/
    void destroy();

    /**
* sterge o tranzactie in lista
* @param nou- Tranzactie
*/
    void del(Tranzactie entitate);

    Tranzactie *getAll();

    int getSize();

    Tranzactie getElem(int i);
};

#endif //LAB7OOP_REPO_H
