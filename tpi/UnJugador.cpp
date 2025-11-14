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
    int puntosRondaJugador = 0;
    int puntajeTotalJugador = 0;
    int puntosRondaPC = 0;
    int puntajeTotalPC = 0;

    // Bucle de rondas
    for (int ronda = 1; ronda <= 10; ronda++){
        /// Jugador
        dibujarBordeXGrueso();
        cout << "           RONDA " << ronda << " DE 10" << endl;
        dibujarBordeXGrueso();
        cout << "Puntaje total de " << nombre << ": " <<puntajeTotalJugador << endl;
        dibujarBordeXFino();

        puntosRondaJugador = turnoJugadorSolitario(nombre);
        puntajeTotalJugador += puntosRondaJugador;

        cout << "\n==== FIN DEL TURNO DE " << nombre << " ====\n";
        cout << "Puntaje total: " << puntajeTotalJugador << endl;
        dibujarBordeXFino();

        cout << "Presione Enter para continuar...";

        cin.ignore();
        cin.get();
        ///

        /// PC
        dibujarBordeXGrueso();
        cout << "           RONDA " << ronda << " DE 10" << endl;
        dibujarBordeXGrueso();
        cout << "Puntaje total de la PC: " <<puntajeTotalPC << endl;
        dibujarBordeXFino();

        cout << "Turno de la PC" << endl;

        puntosRondaPC = turnoPC();
        puntajeTotalPC += puntosRondaPC;

        cout << "\n==== FIN DEL TURNO DE LA PC ====\n" << endl;
        cout << "Puntaje total: " << puntajeTotalPC << endl;
        dibujarBordeXFino();
        ///
    }

    dibujarBordeXGrueso();
    cout << "          FIN DEL JUEGO" << endl;
    dibujarBordeXGrueso();
    cout << nombre << ": " << puntajeTotalJugador << " puntos" << endl;
    cout << "PC: " << puntajeTotalPC << " puntos" << endl;
    cout << "Gracias por jugar!" << endl;
}
