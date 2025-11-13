#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
using namespace std;

void unJugador() {
    srand(time(0));

    string nombre1;
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombre1;
    int puntosRondaJugador = 0;
    int puntajeTotalJugador = 0;
    int puntosRondaPC = 0;
    int puntajeTotalPC = 0;

    // Bucle de rondas
    for (int ronda = 1; ronda <= 10; ronda++){
        dibujarBordeXGrueso();
        cout << "           RONDA " << ronda << " DE 10" << endl;
        dibujarBordeXGrueso();
        cout << "Puntaje total de" << nombre1 << ": " <<puntajeTotalJugador << endl;
        dibujarBordeXFino();

        cout << "Turno de " << nombre1 << endl;

        puntosRondaJugador = turnoJugador(nombre1);
        puntajeTotalJugador += puntosRondaJugador;

        cout << "\n==== FIN DEL TURNO DE " << nombre1 << " ====\n";
        cout << "Puntaje total: " << puntajeTotalJugador << endl;
        dibujarBordeXFino();

        cout << "Presione Enter para continuar...";

        cin.ignore();
        cin.get();

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

        cout << "Presione Enter para continuar...";
        cin.ignore();
        cin.get();
    }

    dibujarBordeXGrueso();
    cout << "          FIN DEL JUEGO" << endl;
    dibujarBordeXGrueso();
    cout << nombre1 << ": " << puntajeTotalJugador << " puntos" << endl;
    cout << "PC: " << puntajeTotalPC << " puntos" << endl;
    cout << "Gracias por jugar!" << endl;
}
