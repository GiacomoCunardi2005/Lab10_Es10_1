#ifndef COMPITO_H
#define COMPITO_H

#include <string>
using namespace std;

class Cinema {
private:
    string s_nomeCinema;  // Nome del cinema (es. "Moderno")
    int i_numFile;        // Numero di file nella sala (es. 3 file)
    int i_numPosti;       // Numero di posti per fila (es. 7 posti per fila)
    bool **b_postiSala;   // Matr. di bool per tenere traccia dei posti (true se occupato, false se libero)

public:
    // Costruttore
    Cinema(int i_numFile, int i_numPosti, string s_nomeCinema);

    // Distruttore per deallocare la memoria dinamica
    ~Cinema();

    // Funzione per prenotare un posto (restituisce true se il posto è stato prenotato, false altrimenti)
    bool b_prenota(char c_fila, int i_posto);

    // Funzione per cancellare una prenotazione (restituisce true se il posto è stato liberato, false altrimenti)
    bool b_cancella(char c_fila, int i_posto);

    // Funzione per stampare lo stato della sala (mostra se i posti sono liberi o occupati)
    void v_stampa() const;

    // Funzione per contare e restituire il numero di posti liberi nella sala
    int i_quantiLiberi() const;

    // Funzione per prenotare una sequenza di k posti adiacenti (restituisce true se la prenotazione è riuscita)
    bool b_prenotaAdiacenti(int i_numPosti);
};

#endif
