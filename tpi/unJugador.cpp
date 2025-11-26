#include <iostream>
#include <cstdlib>
#include <ctime>
#include "unJugador.h"
#include "puntaje.h"
#include "partida.h"
#include "utils.h"
using namespace std;

void unJugador(int CANT_DADOS, int CANT_RONDAS, int dadosLanzados[],
               string &mejorJugador1P, int &mejorPuntaje1P)
{
    //
    string nombre;
    int puntosRondaJugador = 0;
    int puntajeTotalJugador = 0;
    int esGeneralaServida = false;
    bool jugadasUsadas[10] = {false, false, false, false, false,
                                false, false, false, false, false};
    //

    cout << "Ingrese el nombre del jugador: ";
    cin >> nombre;

    for (int ronda = 1; ronda <= CANT_RONDAS; ronda++){
        /// Jugador
        dibujarBordeXGrueso();
        cout << "           RONDA " << ronda << " DE " << CANT_RONDAS << endl;
        dibujarBordeXGrueso();
        cout << "Puntaje total de " << nombre << ": " <<puntajeTotalJugador << endl;
        dibujarBordeXFino();

        puntosRondaJugador = turnoJugadorSolitario(CANT_DADOS, nombre, jugadasUsadas, dadosLanzados);

        puntajeTotalJugador += puntosRondaJugador;

        esGeneralaServida = verificarGenerala(dadosLanzados, CANT_DADOS);

        if (esGeneralaServida){
            if (puntajeTotalJugador > mejorPuntaje1P) {
                mejorPuntaje1P = puntajeTotalJugador;
                mejorJugador1P = nombre;
            }
            cout << "Puntaje total: " << puntajeTotalJugador << " puntos!" <<endl;
            cout << "Presione ENTER para continuar..." <<endl;
            cin.ignore();
            cin.get();
            system("cls");
            return;
        }

        cout << "==== FIN DEL TURNO DE " << nombre << " ====";
        cout << "Puntaje total: " << puntajeTotalJugador << endl;
        dibujarBordeXFino();

        cout << "Presione ENTER para continuar...";
        cin.ignore();
        cin.get();
    }

    dibujarBordeXGrueso();
    cout << "          FIN DEL JUEGO" << endl;
    dibujarBordeXGrueso();
    cout << nombre << ": " << puntajeTotalJugador << " puntos" << endl;
    cout << "Gracias por jugar!" << endl;
    cout << "Pulsa ENTER para continuar..." <<endl;
    cin.ignore();
    cin.get();
    system("cls");

    if (puntajeTotalJugador > mejorPuntaje1P) {
        mejorPuntaje1P = puntajeTotalJugador;
        mejorJugador1P = nombre;
    }
}

