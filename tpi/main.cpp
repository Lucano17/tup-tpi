#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "unJugador.h"
#include "dosJugadores.h"
#include "puntaje.h"
#include "creditos.h"
#include "reglas.h"
#include "utils.h"

using namespace std;


int main() {
    int CANT_DADOS = 5;
    int CANT_RONDAS = 10;
    int dadosLanzados[5];

    srand(time(0));

    string mejorJugador1P = "";
    int mejorPuntaje1P = 0;

    string mejorJugador2P = "";
    int mejorPuntaje2P = 0;


    int opcion;

   do {
        dibujarBordeXGrueso();
        cout << "      MENU JUEGO DE DADOS        " << endl;
        dibujarBordeXGrueso();
        cout << "1. Juego nuevo para un jugador " << endl;
        cout << "2. Juego nuevo para dos jugadores " << endl;
        cout << "3. Ver la puntuacion mas alta" << endl;
        cout << "4. Ver creditos" << endl;
        cout << "5. Ver las reglas" << endl;
        cout << "0. Salir" << endl;
        dibujarBordeXGrueso();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;
        system("cls");

        switch (opcion) {
            case 1:
            unJugador(CANT_DADOS, CANT_RONDAS, dadosLanzados,
                    mejorJugador1P, mejorPuntaje1P);
                break;

            case 2:
                dosJugadores(CANT_DADOS, CANT_RONDAS,
                            mejorJugador2P, mejorPuntaje2P,
                            dadosLanzados);
                break;

            case 3:
                verPuntacionMax(mejorJugador1P, mejorPuntaje1P,
                                mejorJugador2P, mejorPuntaje2P);
                break;

            case 4:
                creditos();
                break;

            case 5:
                reglas();
                break;

            case 0:
                cout << "Saliendo del juego..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
            }
    } while (opcion != 0);

    return 0;
}
