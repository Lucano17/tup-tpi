#include <iostream>
#include "funciones.h"


using namespace std;

/// CONSTANTES
const int CANT_DADOS = 5;
const int MAX_LANZAMIENTOS = 3;



<<<<<<< HEAD

/// PuntuaciÃ³n mÃ¡xima

/// PuntuaciÂ¢n MÂ xima

=======
/// PuntuaciÂ¢n MÂ xima
>>>>>>> origin/fede-branch
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
<<<<<<< HEAD
        cout << "Aún no hay puntuaciones registradas." << endl;
=======
        cout << "AÃºn no hay puntuaciones registradas." << endl;
>>>>>>> origin/fede-branch
    }
    dibujarBordeXGrueso();
}

<<<<<<< HEAD
///

/// FUNCION TIRADA MANUAL
void lanzarDadosManual(int dadosLanzados[], int CANT_DADOS) {
    cout << "Modo Tirada Manual: ingrese el valor de cada dado (1-6)" << endl;
    for (int i = 0; i < CANT_DADOS; i++) {
        int valor;
        do {
            cout << "Dado " << (i + 1) << ": ";
            cin >> valor;
        } while (valor < 1 || valor > 6); // Validar que el valor esté entre 1 y 6
        dadosLanzados[i] = valor;
    }
}




/// FUNCION PARA LANZAR DADOS
void lanzarDados(int dadosLanzados[], int CANT_DADOS) {
    for (int i = 0; i < CANT_DADOS; i++) {
        dadosLanzados[i] = rand() % 6 + 1;
    }
}

///

=======
/// FUNCION PARA LANZAR DADOS
void lanzarDados(int dadosLanzados[], int CANT_DADOS) {
    for (int i = 0; i < CANT_DADOS; i++) {
        dadosLanzados[i] = rand() % 6 + 1;
    }
}

///

>>>>>>> origin/fede-branch
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
<<<<<<< HEAD
    cout << "Â¨Cuantos dados quieres volver a tirar? (0-5): ";
    cin >> cantidadReelanzar;

    for (int i = 0; i < cantidadReelanzar; i++) {
        int indice;
        cout << "Ingrese el numero del dado a relanzar (1-5): ";
=======
    cout << "Â¿CuÃ¡ntos dados querÃ©s volver a tirar? (0-5): ";
    cin >> cantidadReelanzar;

    if (cantidadReelanzar == 0) return;

    cout << "Ingrese los nÃºmeros de los dados a relanzar (1-5, separados por espacio): ";
    int indice;
    for (int i = 0; i < cantidadReelanzar; i++) {
>>>>>>> origin/fede-branch
        cin >> indice;
        if (indice >= 1 && indice <= 5) {
            dadosLanzados[indice - 1] = rand() % 6 + 1; // Re-lanza el dado elegido
        }
    }
}

/// FUNCION QUE CONTROLA EL TURNO DE UN JUGADOR
<<<<<<< HEAD
int turnoJugador(string nombre) {
    int dadosLanzados[CANT_DADOS];
=======
int turnoJugador(string nombre) {int dadosLanzados[CANT_DADOS];
>>>>>>> origin/fede-branch
    int lanzamientos = 1;
    char opcion;
    int puntosActuales = 0;

<<<<<<< HEAD
    // --- NUEVO: Preguntar si quiere tirada manual o automática ---
    char modo;
    cout << "Desea modo de tirada manual o automática? (m/a): ";
    cin >> modo;

    // Primer lanzamiento según el modo elegido
    if (modo == 'm' || modo == 'M') {
        lanzarDadosManual(dadosLanzados, CANT_DADOS); // Tirada manual
    } else {
        lanzarDados(dadosLanzados, CANT_DADOS); // Tirada automática (como antes)
    }
=======
    // PRIMER LANZAMIENTO: llenar el arreglo de dados y mostrarlo
    lanzarDados(dadosLanzados, CANT_DADOS);
>>>>>>> origin/fede-branch

    cout << "Turno de " << nombre << " Lanzamiento 1" << endl;
    mostrarDados(dadosLanzados, CANT_DADOS);
    puntosActuales = calcularPuntos(dadosLanzados);

<<<<<<< HEAD
    if (esGenerala(dadosLanzados)) {
        cout << "\n======================================" << endl;
        cout << "       GENERALA SERVIDA!" << endl;
        cout << " Felicitaciones " << nombre << ", ganaste el juego!" << endl;
        cout << "======================================\n" << endl;
        return 999;
    }

    while (lanzamientos < MAX_LANZAMIENTOS) {
        cout << "¿Deseas volver a lanzar algun dado? (s/n): ";
        cin >> opcion;

        if (opcion == 's' || opcion == 'S') {
            // Aquí también se podría aplicar tirada manual si querés, pero se deja automática como antes
=======
    //  Verificar si es generala servida
    if (esGenerala(dadosLanzados)) {
    cout << "\n======================================" << endl;
    cout << "       GENERALA SERVIDA!" << endl;
    cout << " Felicitaciones " << nombre << ", ganaste el juego!" << endl;
    cout << "======================================\n" << endl;
    return 999; // Valor especial para indicar que se terminÃ³ el juego
}


    // HASTA 3 LANZAMIENTOS POR TURNO
    while (lanzamientos < MAX_LANZAMIENTOS) {
        cout << "Â¨Deseas volver a lanzar algun dado? (s/n): ";
        cin >> opcion;

        if (opcion == 's' || opcion == 'S') {
>>>>>>> origin/fede-branch
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
