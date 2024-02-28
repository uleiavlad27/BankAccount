cmake_minimum_required(VERSION 3.24)
project(BankAccounts)

set(CMAKE_CXX_STANDARD 17)

add_executable(BankAccounts main.cpp entitate/entitate.cpp entitate/entitate.h repository/repo.cpp repository/repo.h tests/tests.cpp tests/tests.h service/service.cpp service/service.h UI/UI.cpp UI/UI.h)
