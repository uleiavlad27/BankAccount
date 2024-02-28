//
// Created by Spaca on 4/12/2023.
//

#ifndef LAB7OOP_TESTS_H
#define LAB7OOP_TESTS_H
#include "../entitate/entitate.h"
#include "../repository/repo.h"
#include "../service/service.h"

class Tests {
private:
    Repo repo;
    Tranzactie tranzactie;
    Service service = Service(repo);
public:
    /**
* constructorul Tests
*/
    Tests();
    /**
* destructorul Tests
*/
    ~Tests();
    /**
* testeaza clasa entitate
*/
    void testEntitate();
    /**
* testeaza clasa repo
*/
    void testRepo();
    /**
* testeaza
*/
    void tests();

    void testService();
};


#endif //LAB7OOP_TESTS_H
