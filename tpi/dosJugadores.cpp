#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "dosjugadores.h"
#include "utils.h"
#include "partida.h"
#include "puntaje.h"

using namespace std;

/// MODALIDAD DOS JUGADORES
void dosJugadores(int CANT_DADOS, int CANT_RONDAS, string &mejorJugador, int &mejorPuntaje, int dadosLanzados[]) {


    bool jugadasUsadas1[10] = {false, false, false, false, false,
                                false, false, false, false, false};

    bool jugadasUsadas2[10] = {false, false, false, false, false,
                                false, false, false, false, false};

    bool esGeneralaServida1 = false;
    bool esGeneralaServida2 = false;

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
        dibujarBordeXFino();

        /// TURNO JUGADOR 1
        int resultado = turnoJugador(jugador1, CANT_DADOS, jugadasUsadas1, esGeneralaServida1);
        puntaje1 += resultado;

        /// MOSTRAR RESULTADOS ENTRE TURNOS
        cout << "==== FIN DEL TURNO DE " << jugador1 << " ====";
        cout << "Puntaje total: " << jugador1 << " = " << puntaje1
             << " - " << jugador2 << " = " << puntaje2 << endl;
        dibujarBordeXFino();
        cin.ignore();
        cin.get();

        /// TURNO JUGADOR 2
        dibujarBordeXGrueso();
        resultado = turnoJugador(jugador2, CANT_DADOS, jugadasUsadas2, esGeneralaServida2);
        puntaje2 += resultado;


        /// CORTA SI HAY GENERALA SERVIDA
        if (esGeneralaServida1 == true && esGeneralaServida2 == true){
            guardarMejorPuntaje(jugador1, puntaje1, mejorJugador, mejorPuntaje);
            guardarMejorPuntaje(jugador2, puntaje2, mejorJugador, mejorPuntaje);

            cout << "Es empate!!" << endl;
            /// LOTERIA SI HAY EMPATE
            int ganadorSorteado = rand() % 2;

            if (ganadorSorteado == 0) {
                cout << "Ganador por sorteo: " << jugador1 << endl;
            } else {
                cout << "Ganador por sorteo: " << jugador2 << endl;
            }
            return;
        }
        else if (esGeneralaServida1 == true && esGeneralaServida2 == false){
            cout << "El ganador es: " << jugador1 << endl;
            guardarMejorPuntaje(jugador1, puntaje1, mejorJugador, mejorPuntaje);
            cout << "Pulsa ENTER para continuar..." <<endl;
            cin.ignore();
            cin.get();
            system("cls");
            return;
        }

        else if (esGeneralaServida1 == false && esGeneralaServida2 == true){
            cout << "El ganador es: " << jugador2 << endl;
            guardarMejorPuntaje(jugador2, puntaje2, mejorJugador, mejorPuntaje);
            cout << "Pulsa ENTER para continuar..." <<endl;
            cin.ignore();
            cin.get();
            system("cls");
            return;
        }

        cin.ignore();
        cin.get();

        ///  FIN DE RONDA
        cout << "===== FIN DE LA RONDA " << ronda << " =====" << endl;
        cout << "Puntajes totales hasta ahora:" << endl;
        cout << jugador1 << ": " << puntaje1 << " puntos" << endl;
        cout << jugador2 << ": " << puntaje2 << " puntos" << endl;
        cout << "Presione Enter para continuar...";
        cin.ignore();
        cin.get();
    }

    ///  FIN DEL JUEGO
    cout << "======================================" << endl;
    cout << "          FIN DEL JUEGO" << endl;
    cout << "======================================" << endl;
    cout << jugador1 << ": " << puntaje1 << " puntos" << endl;
    cout << jugador2 << ": " << puntaje2 << " puntos" << endl;

    ///  MOSTRAR GANADOR O EMPATE
    if (puntaje1 > puntaje2) {
        cout << "El ganador es: " << jugador1 << endl;
    }
    else if (puntaje2 > puntaje1) {
        cout << "El ganador es: " << jugador2 << endl;
    }
    else {
        cout << "=== EMPATE DE PUNTAJE ===" << endl;
        cout << "Se decide ganador por LOTERIA..." << endl;

        /// LOTERIA SI HAY EMPATE
        int ganadorSorteado = rand() % 2;

        if (ganadorSorteado == 0) {
            cout << "Ganador por sorteo: " << jugador1 << endl;
        } else {
            cout << "Ganador por sorteo: " << jugador2 << endl;
        }
    }

    /// GUARDA EL MEJOR PUNTAJE
    guardarMejorPuntaje(jugador1, puntaje1, mejorJugador, mejorPuntaje);
    guardarMejorPuntaje(jugador2, puntaje2, mejorJugador, mejorPuntaje);

    cout << "Pulsa ENTER para continuar..." <<endl;
    cin.ignore();
    cin.get();
    system("cls");

    return;
}
