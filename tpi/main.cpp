#include <iostream>
#include "funciones.h"
#include "variables.h"

using namespace std;


int main() {
    srand(time(0));
    char bordeX = 'Í';
    int opcion;
   do {
        dibujarBordeX(bordeX);
        cout << "      MENU JUEGO DE DADOS        " << endl;
        dibujarBordeX(bordeX);
        cout << "1. Juego nuevo para un jugador " << endl;
        cout << "2. Juego nuevo para dos jugadores " << endl;
        cout << "3. Ver la puntuaci¢n mas alta" << endl;
        cout << "4. Ver cr‚ditos" << endl;
        cout << "5. Ver las reglas" << endl;
        cout << "0. Salir" << endl;
        dibujarBordeX(bordeX);
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;
        system("cls");

        switch (opcion) {
            case 1:
                unJugador();
                break;

            case 2:
                dosJugadores();
                break;

            case 3:
                verPuntacionMax();
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
                cout << "Opci¢n inv lida. Intente nuevamente." << endl << endl;
        }

    } while (opcion != 0);

    return 0;
}
