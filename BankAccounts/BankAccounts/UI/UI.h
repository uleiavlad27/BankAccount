//
// Created by spac on 4/23/23.
//

#ifndef LAB7OOP_UI_H
#define LAB7OOP_UI_H
#include "../service/service.h"
#include "../entitate/entitate.h"
#include "iostream"
#include <cstring>
using namespace std;
class UI {
private:
    Repo repo;
    Service service = Service(repo);
    void adauga(char v[6][100]);
    void insereaza(char v[6][100]);
    void delZiua(char v[6][100]);
    void delTip(char v[6][100]);
    void delZiua2(char v[6][100]);
    void modify(char v[6][100]);
    int inInt(char v[100]);
    void afisare(Tranzactie* a, int nr);
    void getSold(char v[6][100]);
    void getBellowSuma(char v[6][100]);
    void getGreaterSuma(char v[6][100]);
    void GetByTip(char v[6][100]);
    void getSumaByTip(char v[6][100]);
    void getMin(char v[6][100]);
    void getMax(char v[6][100]);
    void filtrareTipSuma(char v[6][100]);
    void filtrareTip(char v[6][100]);
public:
    UI();
    ~UI();

    void menu();

    void GetByTipandSum(char[100][100]);
    void getBySuma(char v[6][100]);
};
#endif //LAB7OOP_UI_H
