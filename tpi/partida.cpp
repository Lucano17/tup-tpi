#include <iostream>
#include "funciones.h"


using namespace std;

/// CONSTANTES
const int CANT_DADOS = 5;
const int MAX_LANZAMIENTOS = 3;



/// Puntuaci¢n M xima
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
        cout << "A£n no hay puntuaciones registradas." << endl;
    }
    dibujarBordeXGrueso();
}

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

/// NUEVA FUNCION: verificar si es Generala servida
bool esGenerala(int dados[]) {
    for (int i = 1; i < CANT_DADOS; i++) {
        if (dados[i] != dados[0]) return false;
    }
    return true;
}


void relanzarDados(int dadosLanzados[]) {
    int cantidadReelanzar;
    int valorCantMax = 0;
    int dadoMaxActual = 0;

    cout << "¨Cuantos dados quieres volver a tirar? (0-5): ";
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

    //  Verificar si es generala servida (solo en el primer lanzamiento)
    if (esGenerala(dadosLanzados)) {
        cout << "\n======================================" << endl;
        cout << "       GENERALA SERVIDA!" << endl;
        cout << " Felicitaciones " << nombre << ", ganaste el juego!" << endl;
        cout << "======================================\n" << endl;
        return 999; // Valor especial para indicar que se termin¢ el juego
        }

    // HASTA 3 LANZAMIENTOS POR TURNO
    while (lanzamientos < MAX_LANZAMIENTOS) {
        cout << "¨Deseas volver a lanzar algun dado? (s/n): ";
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
        cout << " La PC gan¢ el juego!" << endl;
        cout << "======================================\n" << endl;
        return 999; // Valor especial para indicar que se termin¢ el juego
        }

    return puntosActuales;
}
