#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


/// CONSTANTES
const int CANT_DADOS = 5;
const int CANT_RONDAS = 10;
const int MAX_LANZAMIENTOS = 3;


/// FUNCION PARA LANZAR DADOS
void lanzarDados(int dados[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        dados[i] = rand() % 6 + 1;
    }
}


/// FUNCION PARA MOSTRAR LOS DADOS EN PANTALLA
void mostrarDados(int dados[]) {
    cout << "Dados: ";
    for (int i = 0; i < CANT_DADOS; i++) {
        cout << "[" << dados[i] << "] ";
    }
    cout << endl;
}


/// FUNCION PARA SUMAR LOS VALORES DE LOS DADOS
int sumarPuntos(int dados[]) {
    int total = 0;
    for (int i = 0; i < CANT_DADOS; i++) {
        total += dados[i];
    }
    return total;
}


/// FUNCION PARA RE-LANZAR LOS DADOS SELECCIONADOS
void relanzarDados(int dados[]) {
    int cantidadReelanzar;
    cout << "¿Cuantos dados quieres volver a tirar? (0-5): ";
    cin >> cantidadReelanzar;

    for (int i = 0; i < cantidadReelanzar; i++) {
        int indice;
        cout << "Ingrese el numero del dado a relanzar (1-5): ";
        cin >> indice;
        if (indice >= 1 && indice <= 5) {
            dados[indice - 1] = rand() % 6 + 1; // Re-lanza el dado elegido
        }
    }
}


/// FUNCION QUE CONTROLA EL TURNO DE UN JUGADOR
int turnoJugador(string nombre) {
    int dados[CANT_DADOS];
    int lanzamientos = 1;
    char opcion;

    // PRIMER LANZAMIENTO
    lanzarDados(dados, CANT_DADOS);
    cout << "Turno de " << nombre << " Lanzamiento 1" << endl;
    mostrarDados(dados);
    cout << "Puntos actuales: " << sumarPuntos(dados) << endl;

    // HASTA 3 LANZAMIENTOS POR TURNO
    while (lanzamientos < MAX_LANZAMIENTOS) {
        cout << "¿Deseas volver a lanzar algun dado? (s/n): ";
        cin >> opcion;

        if (opcion == 's' || opcion == 'S') {
            relanzarDados(dados);
            lanzamientos++;

            cout << "Lanzamiento " << lanzamientos << " de " << nombre << endl;
            mostrarDados(dados);
            cout << "Puntos actuales: " << sumarPuntos(dados) << endl;
        } else {
            break;
        }
    }

    // EL PUNTAJE FINAL DE LA RONDA ES EL ÚLTIMO RESULTADO
    int puntosTotales = sumarPuntos(dados);
    cout << "Puntos obtenidos por " << nombre << " en este turno: " << puntosTotales << endl;
    return puntosTotales;
}

/// FUNCION PRINCIPAL DEL PROGRAMA (main)
int main() {
    srand(time(0));

    /// INGRESO DE NOMBRES DE LOS JUGADORES
    string jugador1, jugador2;
    cout << "Ingrese el nombre del Jugador 1: ";
    cin >> jugador1;
    cout << "Ingrese el nombre del Jugador 2: ";
    cin >> jugador2;

    /// VARIABLES DE PUNTAJE TOTAL
    int puntaje1 = 0, puntaje2 = 0;

    /// BUCLE PRINCIPAL DE LAS RONDAS
    for (int ronda = 1; ronda <= CANT_RONDAS; ronda++) {

        ///  MOSTRAR DATOS DE RONDA
        cout << "======================================" << endl;
        cout << "           RONDA " << ronda << " DE " << CANT_RONDAS << endl;
        cout << "======================================" << endl;
        cout << "Puntaje total hasta ahora:" << endl;
        cout << jugador1 << ": " << puntaje1 << " puntos" << endl;
        cout << jugador2 << ": " << puntaje2 << " puntos" << endl;
        cout << "--------------------------------------" << endl;

        /// TURNO JUGADOR 1
        cout << "Turno de " << jugador1 << endl;
        puntaje1 += turnoJugador(jugador1);

        /// MOSTRAR RESULTADOS ENTRE TURNOS
        cout << "==== FIN DEL TURNO DE " << jugador1 << " ====\n";
        cout << "Puntaje total: " << jugador1 << " = " << puntaje1
             << " - " << jugador2 << " = " << puntaje2 << endl;
        cout << "--------------------------------------" << endl;

        /// TURNO JUGADOR 2
        cout << "Turno de " << jugador2 << endl;
        puntaje2 += turnoJugador(jugador2);

        ///  FIN DE RONDA -
        cout << "===== FIN DE LA RONDA " << ronda << " =====" << endl;
        cout << "Puntajes totales hasta ahora:" << endl;
        cout << jugador1 << ": " << puntaje1 << " puntos" << endl;
        cout << jugador2 << ": " << puntaje2 << " puntos" << endl;
        cout << "Presione Enter para continuar...";
        cin.ignore();
        cin.get();
    }

    ///  FIN DEL JUEGO
    cout << "\n======================================" << endl;
    cout << "          FIN DEL JUEGO" << endl;
    cout << "======================================" << endl;
    cout << jugador1 << ": " << puntaje1 << " puntos" << endl;
    cout << jugador2 << ": " << puntaje2 << " puntos" << endl;

    ///  MOSTRAR GANADOR O EMPATE
    if (puntaje1 > puntaje2) {
        cout << " El ganador es: " << jugador1 << endl;
    } else if (puntaje2 > puntaje1) {
        cout << "El ganador es: " << jugador2 << endl;
    } else {
        cout << "Empate" << endl;
    }

    return 0;
}
