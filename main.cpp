#include <iostream>
#include "compito.h"

using namespace std;

int main() {
    // PRIMA PARTE
    Cinema c(3, 7, "Moderno");
    c.b_prenota('A', 4);
    c.b_prenota('C', 1);
    c.b_prenota('C', 2);
    c.b_prenota('C', 3);
    c.b_prenota('C', 4);
    c.b_prenota('C', 5);
    c.b_prenota('C', 6);
    c.b_prenota('C', 7);
    c.b_prenota('B', 4);
    c.v_stampa();
    c.b_cancella('B', 4);
    c.v_stampa();

    // SECONDA PARTE
    cout << "Il numero di posti liberi in c e': " << c.i_quantiLiberi() << endl;
    c.b_prenotaAdiacenti(4);
    c.v_stampa();

    return 0;
}
