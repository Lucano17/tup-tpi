#include <iostream>
#include "funciones.h"


using namespace std;

/// CONSTANTES
const int CANT_DADOS = 5;
const int MAX_LANZAMIENTOS = 3;



/// Puntuaci√≥n m√°xima
void verPuntacionMax(){
    string mejorJugador;
    int mejorPuntaje = 0;
    cout << "==== PUNTUACION MAS ALTA ====" << endl;
    if (mejorPuntaje > 0) {
        cout << "Jugador: " << mejorJugador << endl;
        cout << "Puntaje: " << mejorPuntaje << endl;
    } else {
        cout << "A√∫n no hay puntuaciones registradas." << endl;
    }
    dibujarBordeX();
}
///

/// Partida

/// FUNCION PARA LANZAR DADOS
void lanzarDados(int dadosLanzados[], int CANT_DADOS) {
    for (int i = 0; i < CANT_DADOS; i++) {
        dadosLanzados[i] = rand() % 6 + 1;
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

void relanzarDados(int dadosLanzados[]) {
    int cantidadReelanzar;
    cout << "®Cuantos dados quieres volver a tirar? (0-5): ";
    cin >> cantidadReelanzar;

    for (int i = 0; i < cantidadReelanzar; i++) {
        int indice;
        cout << "Ingrese el numero del dado a relanzar (1-5): ";
        cin >> indice;
        if (indice >= 1 && indice <= 5) {
            dadosLanzados[indice - 1] = rand() % 6 + 1; // Re-lanza el dado elegido
        }
    }
}



/// FUNCION QUE CONTROLA EL TURNO DE UN JUGADOR
int turnoJugador(string nombre) {
    int dadosLanzados[CANT_DADOS];
    int lanzamientos = 1;
    char opcion;
    int puntosActuales = 0;

    // PRIMER LANZAMIENTO: llenar el arreglo de dados y mostrarlo
    lanzarDados(dadosLanzados, CANT_DADOS);

    cout << "Turno de " << nombre << " Lanzamiento 1" << endl;
    mostrarDados(dadosLanzados, CANT_DADOS);
    puntosActuales = calcularPuntos(dadosLanzados);

    // HASTA 3 LANZAMIENTOS POR TURNO
    while (lanzamientos < MAX_LANZAMIENTOS) {
        cout << "®Deseas volver a lanzar algun dado? (s/n): ";
        cin >> opcion;

        if (opcion == 's' || opcion == 'S') {
            relanzarDados(dadosLanzados);
            lanzamientos++;

            cout << "Lanzamiento " << lanzamientos << " de " << nombre << endl;
            mostrarDados(dadosLanzados, CANT_DADOS);
            puntosActuales = calcularPuntos(dadosLanzados);
        } else {
            break;
        }
    }

    return puntosActuales;
}
