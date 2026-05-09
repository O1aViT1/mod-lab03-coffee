// Copyright 2022 GHA Test Team
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
    int balance;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
    int choiceIdx;

 public:
    Automata();
    void on();
    void off();
    void coin(int sum);
    std::vector<std::string> getMenu();
    STATES getState();
    void choice(int id);
    bool check();
    void cancel();
    void cook();
    void finish();
};

#endif
