#include <iostream>

#include "tests/tests.h"
#include "UI/UI.h"

int main() {
    Tests tests;
    tests.tests();
    UI ui;
    ui.menu();
    return 0;
}
