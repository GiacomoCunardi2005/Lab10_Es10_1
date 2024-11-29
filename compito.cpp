#include "compito.h"
#include <iostream>

Cinema::Cinema(int i_numFile, int i_numPosti, string s_nomeCinema) {
    this->i_numFile = i_numFile;
    this->i_numPosti = i_numPosti;
    this->s_nomeCinema = s_nomeCinema;

    // Allocazione dinamica della matrice per i posti
    b_postiSala = new bool*[i_numFile];
    for (int i = 0; i < i_numFile; ++i) {
        b_postiSala[i] = new bool[i_numPosti]();
    }
}

Cinema::~Cinema() {
    // Deallocazione della matrice
    for (int i = 0; i < i_numFile; ++i) {
        delete[] b_postiSala[i];
    }
    delete[] b_postiSala;
}

bool Cinema::b_prenota(char c_fila, int i_posto) {
    int i_fila = c_fila - 'A';  // Converto la lettera in indice
    if (i_fila < 0 || i_fila >= i_numFile || i_posto < 1 || i_posto > i_numPosti) {
        return false;  // Indice fila o posto non valido
    }
    if (b_postiSala[i_fila][i_posto - 1]) {
        return false;  // Il posto è già occupato
    }
    b_postiSala[i_fila][i_posto - 1] = true;
    return true;
}

bool Cinema::b_cancella(char c_fila, int i_posto) {
    int i_fila = c_fila - 'A';  // Converto la lettera in indice
    if (i_fila < 0 || i_fila >= i_numFile || i_posto < 1 || i_posto > i_numPosti) {
        return false;  // Indice fila o posto non valido
    }
    if (!b_postiSala[i_fila][i_posto - 1]) {
        return false;  // Il posto è già libero
    }
    b_postiSala[i_fila][i_posto - 1] = false;
    return true;
}

void Cinema::v_stampa() const {
    cout << "Nome del cinema: " << s_nomeCinema << endl;
    for (int i = 0; i < i_numFile; ++i) {
        cout << (char)('A' + i) << " ";  // Stampa la lettera della fila
        for (int j = 0; j < i_numPosti; ++j) {
            if (b_postiSala[i][j]) {
                cout << "*";  // Posto occupato
            } else {
                cout << " ";  // Posto libero
            }
        }
        cout << endl;
    }
}

int Cinema::i_quantiLiberi() const {
    int i_postiLiberi = 0;
    for (int i = 0; i < i_numFile; ++i) {
        for (int j = 0; j < i_numPosti; ++j) {
            if (!b_postiSala[i][j]) {
                i_postiLiberi++;
            }
        }
    }
    return i_postiLiberi;
}

bool Cinema::b_prenotaAdiacenti(int i_numPosti) {
    for (int i = 0; i < i_numFile; ++i) {
        int i_conteggioPostiLiberi = 0;
        for (int j = 0; j < i_numPosti; ++j) {
            if (!b_postiSala[i][j]) {
                i_conteggioPostiLiberi++;
                if (i_conteggioPostiLiberi == i_numPosti) {
                    // Prenotiamo i posti adiacenti
                    for (int k = j - i_numPosti + 1; k <= j; ++k) {
                        b_postiSala[i][k] = true;
                    }
                    return true;
                }
            } else {
                i_conteggioPostiLiberi = 0;  // Reset contatore
            }
        }
    }
    return false;  // Non sono stati trovati k posti adiacenti
}
