#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"

using namespace std;

/// Cr‚ditos
void creditos(){

    cout << "=========== CREDITOS ===========" << endl;
                cout << "Programaci¢n 1" << endl;
                cout << "Equipo 50" << endl;
                cout << "Acosta, Ian. Legajo: 32869" << endl;
                cout << "de la Fuente, Lucas. Legajo: 34179" << endl;
                cout << "Wolf, Federico. Legajo: 31650" << endl;
                cout << "Zunini, Francisco. Legajo: 32915" << endl;
                dibujarBordeXGrueso();
    cout << "Presione ENTER para continuar..." << endl;
    cin.ignore();
    cin.get();
    system("cls");
}
