#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
using namespace std;

void unJugador() {
    srand(time(0));

    string nombre;
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombre;

    int puntajeTotal = 0;

    //  Bucle de 5 rondas
    for (int ronda = 1; ronda <= 5; ronda++) {
        cout << "\n======================================" << endl;
        cout << "           RONDA " << ronda << " DE 5" << endl;
        cout << "======================================\n" << endl;

        int puntosRonda = turnoJugador(nombre);

        // Si saca generala servida, cortar el juego
        if (puntosRonda == 999) {
            cout << "\nEl juego terminó por generala servida!" << endl;
            break;
        }

        puntajeTotal += puntosRonda;
        cout << "Puntaje total acumulado: " << puntajeTotal << endl;
    }

    cout << "\n======================================" << endl;
    cout << "     FIN DEL JUEGO - PUNTAJE FINAL: " << puntajeTotal << endl;
    cout << "======================================\n" << endl;
}
