#ifndef COMPITO_H
#define COMPITO_H

#include <string>
using namespace std;

class Cinema {
private:
    string s_nomeCinema;  // Nome del cinema
    int i_numFile;        // Numero di file
    int i_numPosti;       // Numero di posti per fila
    bool **b_postiSala;   // Matr. di bool per tenere traccia dei posti (true se occupato, false se libero)

public:
    // Costruttore
    Cinema(int i_numFile, int i_numPosti, string s_nomeCinema);

    // Distruttore
    ~Cinema();

    // Funzioni per prenotare, cancellare prenotazioni e stampare
    bool b_prenota(char c_fila, int i_posto);
    bool b_cancella(char c_fila, int i_posto);
    void v_stampa() const;

    // Funzione per contare posti liberi
    int i_quantiLiberi() const;

    // Funzione per prenotare posti adiacenti
    bool b_prenotaAdiacenti(int i_numPosti);
};

#endif
