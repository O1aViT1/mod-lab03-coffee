#include <iostream>
#include "Automata.h"

int main() {
    Automata machine;

    machine.on();
    machine.coin(100);
    
    machine.choice(2);
    
    if (machine.check()) {
        machine.cook();
        machine.finish();
    } else {
        machine.cancel();
    }
    
    machine.off();
    
    return 0;
}
