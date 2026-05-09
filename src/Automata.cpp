#include "Automata.h"

Automata::Automata() {
    balance = 0;
    state = OFF;
    choiceIdx = -1;
    menu = {"Water", "Black Tea", "Espresso", "Hot Chocolate"};
    prices = {15, 30, 50, 45};
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
    }
}

void Automata::coin(int sum) {
    if (state == WAIT || state == ACCEPT) {
        balance += sum;
        state = ACCEPT;
    }
}

std::vector<std::string> Automata::getMenu() {
    return menu;
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int id) {
    if (state == ACCEPT && id >= 0 && id < static_cast<int>(menu.size())) {
        choiceIdx = id;
        state = CHECK;
    }
}

bool Automata::check() {
    if (state == CHECK) {
        return (balance >= prices[choiceIdx]);
    }
    return false;
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        balance = 0;
        choiceIdx = -1;
        state = WAIT;
    }
}

void Automata::cook() {
    if (state == CHECK && check()) {
        state = COOK;
    }
}

void Automata::finish() {
    if (state == COOK) {
        balance -= prices[choiceIdx];
        choiceIdx = -1;
        state = WAIT;
        balance = 0;
    }
}
