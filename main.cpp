#include "sculptor.h"
#include <iostream>

int main() {
    Sculptor cena(60, 60, 60);

    cena.setColor(0.0, 0.6, 0.0, 1.0);
    cena.putBox(0, 39, 0, 39, 0, 0);
    cena.setColor(0.95, 0.95, 0.95, 1.0);
    
    cena.putBox(6, 33, 2, 2, 0, 0);
    cena.putBox(6, 33, 37, 37, 0, 0);
    
    cena.putBox(6, 6, 2, 37, 0, 0);
    cena.putBox(33, 33, 2, 37, 0, 0); 
    
    cena.putBox(6, 33, 19, 19, 0, 0);

    cena.setColor(0.95, 0.95, 0.95, 1.0);
    cena.putBox(15, 15, 2, 2, 1, 7);
    cena.putBox(24, 24, 2, 2, 1, 7);
    cena.putBox(15, 24, 2, 2, 7, 7);

    cena.setColor(0.95, 0.95, 0.95, 1.0);
    cena.putBox(15, 15, 37, 37, 1, 7);
    cena.putBox(24, 24, 37, 37, 1, 7);
    cena.putBox(15, 24, 37, 37, 7, 7);

    cena.setColor(0.95, 0.95, 0.95, 1.0);
    cena.putSphere(19, 19, 1, 1);

    cena.writeOFF("campo_futebol.off");

    return 0;
}
