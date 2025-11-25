#include <iostream>
#include "partida.h"
#include "puntaje.h"
#include "utils.h"

using namespace std;



void lanzarDados(int dadosLanzados[], int CANT_DADOS) {
    for (int i = 0; i < CANT_DADOS; i++) {
        dadosLanzados[i] = rand() % 6 + 1;
    }
}

void lanzarDadosManual(int dadosLanzados[], int CANT_DADOS) {
    cout << "Modo Tirada Manual: Ingrese el valor de cada dado (1-6)" << endl;
    for (int i = 0; i < CANT_DADOS; i++) {
        int valor;
        do {
            cout << "Dado " << (i + 1) << ": ";
            cin >> valor;
        } while (valor < 1 || valor > 6);
        dadosLanzados[i] = valor;
    }
}

void mostrarDados(int dadosLanzados[], int CANT_DADOS) {
    cout << "Dados: ";
    for (int i = 0; i < CANT_DADOS; i++) {
        cout << "[" << dadosLanzados[i] << "] ";
    }
    cout << endl;
}


void relanzarDados(int dadosLanzados[]) {
    int cantidadReelanzar;

    cout << "Cuantos dados queres volver a tirar? (0-5): ";
    cin >> cantidadReelanzar;
    if (cantidadReelanzar == 0) return;

    cout << "Ingrese los numeros de los dados a relanzar (1-5, separados por espacio): ";
    int indice;
    for (int i = 0; i < cantidadReelanzar; i++) {
        cin >> indice;
        if (indice >= 1 && indice <= 5) {
            dadosLanzados[indice - 1] = rand() % 6 + 1;
        }
    }
}

int turnoJugador(string nombre, int CANT_DADOS, bool jugadasUsadas[], bool &esGeneralaServida) {
    int dadosLanzados[CANT_DADOS];
    int puntosActuales = 0;
    lanzarDados(dadosLanzados, CANT_DADOS);

    puntosActuales = tresLanzamientos(nombre, puntosActuales, dadosLanzados, CANT_DADOS, jugadasUsadas);

    esGeneralaServida = verificarGenerala(dadosLanzados, CANT_DADOS);

    return puntosActuales;
}

int turnoJugadorSolitario(int CANT_DADOS, string nombre, bool jugadasUsadas[], int dadosLanzados[]) {
    int puntosActuales = 0;
    bool esGeneralaServida = false;

    char modo;
    cout << "Desea modo de tirada manual o automatica? (m/a): ";
    cin >> modo;

    if (modo == 'm' || modo == 'M') {
        lanzarDadosManual(dadosLanzados, CANT_DADOS);
    } else {
        lanzarDados(dadosLanzados, CANT_DADOS);
    }

    puntosActuales = tresLanzamientos(nombre, puntosActuales, dadosLanzados, CANT_DADOS, jugadasUsadas);

    esGeneralaServida = verificarGenerala(dadosLanzados, CANT_DADOS);

    if (esGeneralaServida == true) return puntosActuales;

    return puntosActuales;
}

int tresLanzamientos(string nombre, int puntosActuales, int dadosLanzados[], int CANT_DADOS, bool jugadasUsadas[]){
    int MAX_LANZAMIENTOS = 3;
    int lanzamientos = 1;
    char opcion;

    cout << "Turno de " << nombre << " Lanzamiento 1" << endl;

    mostrarDados(dadosLanzados, CANT_DADOS);

    if (verificarGenerala(dadosLanzados, CANT_DADOS)) {
    cout << "GENERALA SERVIDA! +50 PUNTOS" << endl;
    cout << "­­­GANASTE EL JUEGO!!!" << endl;
    return 50;
    }

    while (lanzamientos < MAX_LANZAMIENTOS) {
        cout << "Deseas volver a lanzar algun dado? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            relanzarDados(dadosLanzados);
            lanzamientos++;
            cout << "Lanzamiento " << lanzamientos << " de " << nombre << endl;
            mostrarDados(dadosLanzados, CANT_DADOS);

            if (verificarGenerala(dadosLanzados, CANT_DADOS)) {
                cout << "======================================" << endl;
                cout << "       GENERALA!" << endl;
                cout << " Felicitaciones " << nombre << ", hiciste generala (no servida)." << endl;
                cout << "======================================" << endl;
                return puntosActuales;
            }
        } else {
            break;
        }
    }
    mostrarCategoriasDisponibles(jugadasUsadas);
    int categoria = pedirCategoria(jugadasUsadas);
    int puntos = calcularPuntajePorCategoria(categoria, dadosLanzados);

    cout << "Puntos obtenidos: " << puntos << endl;
    puntosActuales = puntos;
    return puntosActuales;
}
