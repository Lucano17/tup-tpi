#include <iostream>
#include "funciones.h"

using namespace std;

/// CONSTANTES
const int CANT_DADOS = 5;
const int MAX_LANZAMIENTOS = 3;



/// Puntuacion Maxima
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
}

/// FUNCION PARA LANZAR DADOS (ALEATORIA)
void lanzarDados(int dadosLanzados[], int CANT_DADOS) {
    for (int i = 0; i < CANT_DADOS; i++) {
        dadosLanzados[i] = rand() % 6 + 1;
    }
}

/// FUNCION PARA LANZAR DADOS MANUAL
void lanzarDadosManual(int dadosLanzados[], int CANT_DADOS) {
    cout << "Modo Tirada Manual: ingrese el valor de cada dado (1-6)" << endl;
    for (int i = 0; i < CANT_DADOS; i++) {
        int valor;
        do {
            cout << "Dado " << (i + 1) << ": ";
            cin >> valor;
        } while (valor < 1 || valor > 6); // Validar que el valor este entre 1 y 6
        dadosLanzados[i] = valor;
    }
}

/// FUNCION PARA MOSTRAR LOS DADOS EN PANTALLA
void mostrarDados(int dadosLanzados[], int CANT_DADOS) {
    cout << "Dados: ";
    for (int i = 0; i < CANT_DADOS; i++) {
        cout << "[" << dadosLanzados[i] << "] ";
    }
    cout << endl;
}

/// FUNCION: verificar si es Generala servida
bool esGenerala(int dados[]) {
    for (int i = 1; i < CANT_DADOS; i++) {
        if (dados[i] != dados[0]) return false;
    }
    return true;
}

/// FUNCION PARA RELANZAR DADOS
void relanzarDados(int dadosLanzados[]) {
    int cantidadReelanzar;

    cout << "Cuantos dados queres volver a tirar? (0-5): ";
    cin >> cantidadReelanzar;
    if (cantidadReelanzar == 0) return;

    cout << "Ingrese los numeros de los dados a relanzar (1-5, separados por espacio): ";
    int indice; // declarar una sola vez
    for (int i = 0; i < cantidadReelanzar; i++) {
        cin >> indice;
        if (indice >= 1 && indice <= 5) {
            dadosLanzados[indice - 1] = rand() % 6 + 1;
        }
    }
}

/// FUNCION QUE CONTROLA EL TURNO DE UN JUGADOR
int turnoJugador(string nombre) {int dadosLanzados[CANT_DADOS];
    int lanzamientos = 1;
    char opcion;
    int puntosActuales = 0;

    // --- Preguntar si quiere tirada manual o autom�tica ---
    char modo;
    cout << "Desea modo de tirada manual o automatica? (m/a): ";
    cin >> modo;

    if (modo == 'm' || modo == 'M') {
        lanzarDadosManual(dadosLanzados, CANT_DADOS);
    } else {
        lanzarDados(dadosLanzados, CANT_DADOS);
    }

    cout << "Turno de " << nombre << " Lanzamiento 1" << endl;
    mostrarDados(dadosLanzados, CANT_DADOS);
    puntosActuales = calcularPuntos(dadosLanzados);

    if (esGenerala(dadosLanzados)) {
        cout << "\n======================================" << endl;
        cout << "       GENERALA SERVIDA!" << endl;
        cout << " Felicitaciones " << nombre << ", ganaste el juego!" << endl;
        cout << "======================================\n" << endl;
        return 999;
    }

    // Hasta 3 lanzamientos
    while (lanzamientos < MAX_LANZAMIENTOS) {
        cout << "Deseas volver a lanzar algun dado? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            relanzarDados(dadosLanzados);
            lanzamientos++;
            cout << "Lanzamiento " << lanzamientos << " de " << nombre << endl;
            mostrarDados(dadosLanzados, CANT_DADOS);
            puntosActuales = calcularPuntos(dadosLanzados);

            if (esGenerala(dadosLanzados)) {
                cout << "\n======================================" << endl;
                cout << "       GENERALA SERVIDA!" << endl;
                cout << " Felicitaciones " << nombre << ", ganaste el juego!" << endl;
                cout << "======================================\n" << endl;
                return 999;
            }
        } else {
            break;
        }
    }

    return puntosActuales;
}

int turnoPC(){
    int dadosLanzados[CANT_DADOS];
    int puntosActuales = 0;

    // PRIMER LANZAMIENTO: llenar el arreglo de dados y mostrarlo
    lanzarDados(dadosLanzados, CANT_DADOS);

    cout << "Turno de la PC Lanzamiento 1" << endl;
    mostrarDados(dadosLanzados, CANT_DADOS);
    puntosActuales = calcularPuntos(dadosLanzados);

    //  Verificar si es generala servida (solo en el primer lanzamiento)
    if (esGenerala(dadosLanzados)) {
        cout << "\n======================================" << endl;
        cout << "       GENERALA SERVIDA!" << endl;
        cout << " La PC gano el juego!" << endl;
        cout << "======================================\n" << endl;
        return 999; // Valor especial para indicar que se termin� el juego
        }

    return puntosActuales;
}
