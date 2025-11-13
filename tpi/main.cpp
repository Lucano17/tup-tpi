#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "funciones.h"

using namespace std;


int main() {
    srand(time(0));

    string mejorJugador = "";
    int mejorPuntaje = 0;
<<<<<<< HEAD


    char bordeX = '�';

=======
>>>>>>> origin/fede-branch
    int opcion;

   do {
        dibujarBordeXGrueso();
        cout << "      MENU JUEGO DE DADOS        " << endl;
        dibujarBordeXGrueso();
        cout << "1. Juego nuevo para un jugador " << endl;
        cout << "2. Juego nuevo para dos jugadores " << endl;
<<<<<<< HEAD
        cout << "3. Ver la puntuaci¢n mas alta" << endl;
        cout << "4. Ver cr‚ditos" << endl;
        cout << "5. Ver las reglas" << endl;
        cout << "0. Salir" << endl;
        dibujarBordeXGrueso();
        cout << "Seleccione una opci¢n: ";
=======
        cout << "3. Ver la puntuacion mas alta" << endl;
        cout << "4. Ver creditos" << endl;
        cout << "5. Ver las reglas" << endl;
        cout << "0. Salir" << endl;
        dibujarBordeXGrueso();
        cout << "Seleccione una opcion: ";
>>>>>>> origin/fede-branch
        cin >> opcion;
        cout << endl;
        system("cls");

        switch (opcion) {
            case 1:
                unJugador();
                break;

           case 2:
                dosJugadores(mejorJugador, mejorPuntaje);
                break;


            case 3:
                verPuntacionMax(mejorJugador, mejorPuntaje);
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
<<<<<<< HEAD
                cout << "Opci¢n inv lida. Intente nuevamente." << endl << endl;
=======
                cout << "Opcion invalida. Intente nuevamente." << endl << endl;
>>>>>>> origin/fede-branch
        }

    } while (opcion != 0);

    return 0;
}
