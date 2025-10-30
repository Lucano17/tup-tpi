#include <iostream>
#include "funciones.h"

using namespace std;

/// Reglas
void reglas(){
    //
    int escaleraPuntaje = 25;
    int fullPuntaje = 30;
    int pokerPuntaje = 40;
    int generalaPuntaje = 50;
    //
    dibujarBordeX();
    cout << "Estas son las reglas:" << endl;
    cout << "" << endl;
    // Juego 1
    cout << "Combinaci¢n: 1 o m s dados con valor 1" << endl;
    cout << "Nombre de jugada: Juego de 1" << endl;
    cout << "Puntaje otorgado: Suma de la cantidad de dados con el valor 1" << endl;
    cout << "" << endl;
    // Juego 2
    cout << "Combinaci¢n: 1 o m s dados con valor 2" << endl;
    cout << "Nombre de jugada: Juego de 2" << endl;
    cout << "Puntaje otorgado: 2*(La suma de la cantidad de dados con el valor 2)" << endl;
    cout << "" << endl;
    // Juego 3
    cout << "Combinaci¢n: 1 o m s dados con valor 3" << endl;
    cout << "Nombre de jugada: Juego de 3" << endl;
    cout << "Puntaje otorgado: 3*(La suma de la cantidad de dados con el valor 3)" << endl;
    cout << "" << endl;
    // Juego 4
    cout << "Combinaci¢n: 1 o m s dados con valor 4" << endl;
    cout << "Nombre de jugada: Juego de 4" << endl;
    cout << "Puntaje otorgado: 4*(La suma de la cantidad de dados con el valor 4)" << endl;
    cout << "" << endl;
    // Juego 5
    cout << "Combinaci¢n: 1 o m s dados con valor 5" << endl;
    cout << "Nombre de jugada: Juego de 5" << endl;
    cout << "Puntaje otorgado: 5*(La suma de la cantidad de dados con el valor 5)" << endl;
    cout << "" << endl;
    // Juego 6
    cout << "Combinaci¢n: 1 o m s dados con valor 6" << endl;
    cout << "Nombre de jugada: Juego de 6" << endl;
    cout << "Puntaje otorgado: 6*(La suma de la cantidad de dados con el valor 6)" << endl;
    cout << "" << endl;
    // Escalera
    cout << "Combinaci¢n: 5 dados en orden creciente (1,2,3,4,5), (2,3,4,5,6)" << endl;
    cout << "Nombre de jugada: Escalera" << endl;
    cout << "Puntaje otorgado: "<< escaleraPuntaje << endl;
    cout << "" << endl;
    // Full
    cout << "Combinaci¢n: 3 dados iguales m s otros 2 iguales (3,3,3,2,2)" << endl;
    cout << "Nombre de jugada: Full" << endl;
    cout << "Puntaje otorgado: "<< fullPuntaje << endl;
    cout << "" << endl;
    // P¢ker
    cout << "Combinaci¢n: 4 dados iguales (1,4,4,4,4)" << endl;
    cout << "Nombre de jugada: P¢ker" << endl;
    cout << "Puntaje otorgado: "<< pokerPuntaje << endl;
    cout << "" << endl;
    // Generala
    cout << "Combinaci¢n: 5 dados con el mismo valor (2,2,2,2,2)" << endl;
    cout << "Nombre de jugada: Generala" << endl;
    cout << "Puntaje otorgado: 50 o si es en la primera tirada del turno, gana el partido" << endl;
    cout << "" << endl;
    dibujarBordeX();
}
///
