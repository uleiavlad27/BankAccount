//
// Created by Spaca on 4/12/2023.
//

#ifndef LAB7OOP_ENTITATE_H
#define LAB7OOP_ENTITATE_H
#include <iostream>
#include <map>
#include <string.h>


class Tranzactie {
private:
    unsigned int suma, ziua;
    char* descriere;
    bool tip;
public:
    /**
 * constructorul unei tranzactii
 * @return o instanta a structurii de tip tranzactie
 */
    Tranzactie();
    /**
* constructorul unei tranzactii
* @param id - int pozitiv
* @param nume - un pointer catre un sir de caractere alocat dinamic
* @param cantitate - int pozitiv
* @param concentratie - int pozitiv
* @return o instanta a structurii de tip tranzactie
*/
    Tranzactie(int suma, int ziua, char *tip, char *descriere);

/**
* constructorul unei tranzactii
* @param tranzactie - clasa tranzactie
*/
    Tranzactie(const Tranzactie& entitate);
    /**
* desconstructorul unei tranzactii
* @param tranzactie - clasa tranzactie
*/
    ~Tranzactie();
    /**
* creare operatorului unei tranzactii
* @param tranzactie - clasa tranzactie
*/
    Tranzactie& operator=(const Tranzactie& entitate);
    /**
* creare operatorului  == unei tranzactii
* @param tranzactie - clasa tranzactie
*/
    bool operator==(const Tranzactie &entitate);
    /**
* seteaza suma tranzactiei
* @param suma- int
*/
    void setSuma(int s);
    /**
* constructorul unei tranzactii
* @return o instanta a structurii de tip suma
*/
    unsigned int getSuma();
    /**
* seteaza descrierea tranzactiei
* @param descriere - char
*/
    void setDescriere(char *descriere);

    /**
* seteaza tipul tranzactiei
* @param tip - char
*/

    void setTip(char *tip);

    /**
* seteaza tipul tranzactiei
* @param ziua - int
*/
    void setZiua(int zi);
    /**
* constructorul unei tranzactii
* @return o instanta a structurii de tip descriere
*/
    char *getDescriere();
    /**
* constructorul unei tranzactii
* @return o instanta a structurii de tip tip
*/
    char* geTip();

    /**
* constructorul unei tranzactii
* @return o instanta a structurii de tip ziua
*/
    unsigned int getZiua();
};


#endif //LAB7OOP_ENTITATE_H
