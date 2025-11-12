#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"  // o el que tenga la declaración de turnoJugador()
using namespace std;

void unJugador() {
    srand(time(0));

    string nombre1;
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombre1;

    int puntajeTotal = 0;

    // Bucle de rondas
    for (int ronda = 1; ronda <= 5; ronda++) {
        cout << "======================================" << endl;
        cout << "           RONDA " << ronda << " DE 5" << endl;
        cout << "======================================" << endl;
        cout << "Puntaje total hasta ahora: " << puntajeTotal << endl;
        cout << "--------------------------------------" << endl;

        cout << "Turno de " << nombre1 << endl;

        int puntosRonda = turnoJugador(nombre1);  // <-- CAMBIO CLAVE
        puntajeTotal += puntosRonda;

        cout << "\n==== FIN DEL TURNO DE " << nombre1 << " ====\n";
        cout << "Puntaje total: " << puntajeTotal << endl;
        cout << "--------------------------------------" << endl;

        cout << "Presione Enter para continuar...";
        cin.ignore();
        cin.get();
    }

    cout << "\n======================================" << endl;
    cout << "          FIN DEL JUEGO" << endl;
    cout << "======================================" << endl;
    cout << nombre1 << ": " << puntajeTotal << " puntos" << endl;
    cout << "Gracias por jugar!" << endl;
}
