#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "funciones.h"

using namespace std;

/// CONSTANTES
const int CANT_RONDAS = 10;


/// MODALIDAD DOS JUGADORES
int dosJugadores() {

    /// INGRESO DE NOMBRES DE LOS JUGADORES
    string jugador1, jugador2;
    cout << "Ingrese el nombre del Jugador 1: ";
    cin >> jugador1;
    cout << "Ingrese el nombre del Jugador 2: ";
    cin >> jugador2;

    /// VARIABLES DE PUNTAJE TOTAL
    int puntaje1 = 0, puntaje2 = 0;

    /// BUCLE PRINCIPAL DE LAS RONDAS
    for (int ronda = 1; ronda <= CANT_RONDAS; ronda++) {

        ///  MOSTRAR DATOS DE RONDA
        cout << "======================================" << endl;
        cout << "           RONDA " << ronda << " DE " << CANT_RONDAS << endl;
        cout << "======================================" << endl;
        cout << "Puntaje total hasta ahora:" << endl;
        cout << jugador1 << ": " << puntaje1 << " puntos" << endl;
        cout << jugador2 << ": " << puntaje2 << " puntos" << endl;
        cout << "--------------------------------------" << endl;

        /// TURNO JUGADOR 1
        cout << "Turno de " << jugador1 << endl;
        puntaje1 += turnoJugador(jugador1);

        /// MOSTRAR RESULTADOS ENTRE TURNOS
        cout << "==== FIN DEL TURNO DE " << jugador1 << " ====\n";
        cout << "Puntaje total: " << jugador1 << " = " << puntaje1
             << " - " << jugador2 << " = " << puntaje2 << endl;
        cout << "--------------------------------------" << endl;

        /// TURNO JUGADOR 2
        cout << "Turno de " << jugador2 << endl;
        puntaje2 += turnoJugador(jugador2);

        ///  FIN DE RONDA -
        cout << "===== FIN DE LA RONDA " << ronda << " =====" << endl;
        cout << "Puntajes totales hasta ahora:" << endl;
        cout << jugador1 << ": " << puntaje1 << " puntos" << endl;
        cout << jugador2 << ": " << puntaje2 << " puntos" << endl;
        cout << "Presione Enter para continuar...";
        cin.ignore();
        cin.get();
    }

    ///  FIN DEL JUEGO
    cout << "\n======================================" << endl;
    cout << "          FIN DEL JUEGO" << endl;
    cout << "======================================" << endl;
    cout << jugador1 << ": " << puntaje1 << " puntos" << endl;
    cout << jugador2 << ": " << puntaje2 << " puntos" << endl;

    ///  MOSTRAR GANADOR O EMPATE
    if (puntaje1 > puntaje2) {
        cout << " El ganador es: " << jugador1 << endl;
    } else if (puntaje2 > puntaje1) {
        cout << "El ganador es: " << jugador2 << endl;
    } else {
        cout << "Empate" << endl;
    }

    return 0;
}
