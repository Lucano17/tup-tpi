#include <iostream>
#include "puntaje.h"
#include "utils.h"

using namespace std;

/// Verificacion especial de ESCALERA y FULL
int verificarEscalera(int puntosCalculados, int contador[6]) {
    int escaleraPuntaje = 25;

    // Escalera 1-5
    if (contador[0] == 1 && contador[1] == 1 &&
        contador[2] == 1 && contador[3] == 1 &&
        contador[4] == 1) {
        return escaleraPuntaje;
    }

    // Escalera 2-6
    if (contador[1] == 1 && contador[2] == 1 &&
        contador[3] == 1 && contador[4] == 1 &&
        contador[5] == 1) {
        return escaleraPuntaje;
    }

    return 0;
}

int verificarFull(int i, int puntosCalculados, int contador[6]) {
    bool hayTres = false;
    bool hayDos = false;

    for (int i = 0; i < 6; i++) {
        if (contador[i] == 3) hayTres = true;
        if (contador[i] == 2) hayDos = true;
    }

    return (hayTres && hayDos) ? 30 : 0;
}

/// CALCULAR PUNTOS SEGUN CATEGORIA
int calcularPuntajePorCategoria(int categoria, int dados[]) {
    int contador[6] = {0};

    // Contar valores
    for (int i = 0; i < 5; i++) {
        contador[dados[i] - 1]++;
    }

    switch (categoria) {

        case 1: return contador[0] * 1;
        case 2: return contador[1] * 2;
        case 3: return contador[2] * 3;
        case 4: return contador[3] * 4;
        case 5: return contador[4] * 5;
        case 6: return contador[5] * 6;

        case 7: return verificarEscalera(0, contador);
        case 8: return verificarFull(0, 0, contador);

        case 9:     // Poker
            for (int i = 0; i < 6; i++)
                if (contador[i] == 4) return 40;
            return 0;

        case 10:    // Generala
            for (int i = 0; i < 6; i++)
                if (contador[i] == 5) return 50;
            return 0;

        default:
            return 0;
    }
}


/// MOSTRAR CATEGORIAS DISPONIBLES
void mostrarCategoriasDisponibles(bool jugadasUsadas[]) {
    cout << "=== Elegi una categoria disponible ===" << endl;

    if (!jugadasUsadas[0]) cout << "1) Jugada 1" << endl;
    if (!jugadasUsadas[1]) cout << "2) Jugada 2" << endl;
    if (!jugadasUsadas[2]) cout << "3) Jugada 3" << endl;
    if (!jugadasUsadas[3]) cout << "4) Jugada 4" << endl;
    if (!jugadasUsadas[4]) cout << "5) Jugada 5" << endl;
    if (!jugadasUsadas[5]) cout << "6) Jugada 6" << endl;
    if (!jugadasUsadas[6]) cout << "7) Escalera" << endl;
    if (!jugadasUsadas[7]) cout << "8) Full" << endl;
    if (!jugadasUsadas[8]) cout << "9) Poker" << endl;
    if (!jugadasUsadas[9]) cout << "10) Generala" << endl;
}


/// PEDIR CATEGORIA A USAR AL JUGADOR
int pedirCategoria(bool jugadasUsadas[]) {
    int opcion;

    while (true) {
        cout << "Ingrese el numero de jugada: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 10 && !jugadasUsadas[opcion - 1]) {
            jugadasUsadas[opcion - 1] = true;
            return opcion;
        }

        cout << "Jugada invalida o ya usada. Intente nuevamente.";
    }
}

void guardarMejorPuntaje(string jugador, int puntaje, string &mejorJugador, int &mejorPuntaje){
    if(puntaje > mejorPuntaje){
        mejorPuntaje = puntaje;
        mejorJugador = jugador;
    }
}

void verPuntacionMax(string mejorJugador, int mejorPuntaje){
    cout << "==== PUNTUACION MAS ALTA ====" << endl;
    if(mejorPuntaje > 0){
        cout << "Jugador: " << mejorJugador << endl;
        cout << "Puntaje: " << mejorPuntaje << endl;
    } else {
        cout << "Aun no hay puntuaciones registradas." << endl;
    }
    dibujarBordeXGrueso();

    cout << "Presione ENTER para continuar..." << endl;
    cin.ignore();
    cin.get();
    system("cls");
}


bool verificarGenerala(int dadosLanzados[], int CANT_DADOS) {
    for (int i = 1; i < CANT_DADOS; i++) {
        if (dadosLanzados[i] != dadosLanzados[0]) return false;
    }
    return true;
}
