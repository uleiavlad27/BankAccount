//
// Created by Spaca on 4/12/2023.
//

#include "tests.h"
#include <assert.h>
#include <iostream>

Tests::Tests() {

}

Tests::~Tests() {

}

void Tests::testEntitate() {
    char descriere[7] = "abcd", tip[4] = "in";
    this->tranzactie.setDescriere(descriere);
    this->tranzactie.setSuma(12);
    this->tranzactie.setTip(tip);
    this->tranzactie.setZiua(10);
    assert(strcmp(this->tranzactie.getDescriere(), "abcd") == 0);
    assert(this->tranzactie.getZiua() == 10);
    assert(this->tranzactie.getSuma() == 12);
    assert(strcmp(this->tranzactie.geTip(), "in") == 0);
}

void Tests::testRepo() {
    char descriere[7] = "abcd", in[] = "in", out[] = "out";
    Tranzactie tranzactie1(12, 8,in,descriere);
    Tranzactie tranzactie2(10,7,out, descriere);
    repo.addElem(tranzactie1);
    repo.addElem(tranzactie2);
    assert(repo.getSize() == 2);
    assert(repo.getElem(1).getZiua() == 7);
    assert(repo.getIndex(tranzactie1) == 0);
    Tranzactie tranzactie3(11,20,in, descriere);
    repo.delElem(1);
    assert(repo.getSize() == 1);
}

void Tests::testService() {
    char descriere[7] = "abcd", in[] = "in", out[] = "out";
    Tranzactie tranzactie1(12, 8,in,descriere);
    Tranzactie tranzactie2(10,7,out, descriere);
    service.adauga(12,in,descriere);
    service.inserare(10,7,out, descriere);
    service.Getundo();
    assert(service.getBySuma(10).size() == 0);
    assert(service.getBySuma(12).size() == 1);
    service.inserare(10,7,out, descriere);
    assert(service.getGreaterSuma(13).size() == 0);
    assert(service.getBellowSuma(13).size() == 2);
    assert(service.getSold(7) == -10);
    service.Getundo();
    assert(service.getBySuma(10).size() == 0);
    service.delZiua(7);
    assert(service.getBySuma(11).size() == 0);
    service.Getundo();
    assert(service.getBySuma(10).size() == 0);

}

void Tests::tests() {
    testRepo();
    testService();
    testEntitate();
    std::cout<<"Teste == OK";
}
