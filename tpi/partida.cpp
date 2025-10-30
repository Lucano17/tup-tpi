#include <iostream>
#include "funciones.h"


using namespace std;

/// Jugar
void jugar(){
    int cantidadRondas = 5;
    int cantidadTiradasXRonda = 3;
}
///

/// Un jugador
void unJugador(){
    string nombre1;
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombre1;
    cout << "Iniciando juego para un jugador..." << endl;
    cout << "Buena suerte " << nombre1 << endl;
    // Partida
    cout << "Primer tirada" << endl;
    tiradaDeDados();
}
///

/// Dos jugadores
void dosJugadores(){
    string nombre1;
    string nombre2;
    cout << "Ingrese el nombre del jugador 1: ";
    cin >> nombre1;
    cout << "Ingrese el nombre del jugador 2: ";
    cin >> nombre2;
    cout << "Iniciando juego para dos jugadores..." << endl;
    cout << "Buena suerte " << nombre1 << " y " << nombre2 << endl;
    cout << endl;
}
///

/// Puntuaci¢n m xima
void verPuntacionMax(){
    string mejorJugador;
    int mejorPuntaje = 0;
    cout << "==== PUNTUACION MAS ALTA ====" << endl;
    if (mejorPuntaje > 0) {
        cout << "Jugador: " << mejorJugador << endl;
        cout << "Puntaje: " << mejorPuntaje << endl;
    } else {
        cout << "A£n no hay puntuaciones registradas." << endl;
    }
    dibujarBordeX();
}
///



/// Partida
int lanzarUnDado(){
    int num = (rand() % 6) + 1;
    return num;
}
void tiradaDeDados(){
    //
    int cantidadDados = 5;
    int cantidadValores = 6;
    int dados[6] = {1, 2, 3, 4, 5, 6};
    int dadosLanzados[cantidadDados];
    //
    for(int i = 0; i < cantidadDados; i++){
        dadosLanzados[i] = lanzarUnDado();
    }
    for(int i = 0; i < cantidadDados; i++){
        cout << dadosLanzados[i] << " ";
    }
    cout << endl;
    calcularPuntos(dadosLanzados);

}

/// Puntaje
void calcularPuntos(int dadosLanzados[]){
    //
    int cantidadDados = 5;
    int cantidadValores = 6;
    int dados[6] = {1, 2, 3, 4, 5, 6};
    int cantidadUno = 0;
    int cantidadDos = 0;
    int cantidadTres = 0;
    int cantidadCuatro = 0;
    int cantidadCinco = 0;
    int cantidadSeis = 0;
    int contadorDadosPorValor[6];
    int puntosCalculados = 0;
    int valorCantMax = 0;
    int listaDadosMax[5];
    int dadoMaxActual = 0;
    bool generalaServida = false;
    //
    for(int i = 0; i < cantidadDados; i++){
        if (dadosLanzados[i] == 1){
            cantidadUno++;
        }
        if (dadosLanzados[i] == 2){
            cantidadDos++;
        }
        if (dadosLanzados[i] == 3){
            cantidadTres++;
        }
        if (dadosLanzados[i] == 4){
            cantidadCuatro++;
        }
        if (dadosLanzados[i] == 5){
            cantidadCinco++;
        }
        if (dadosLanzados[i] == 6){
            cantidadSeis++;
        }
    }
        contadorDadosPorValor[0] = cantidadUno;
        contadorDadosPorValor[1] = cantidadDos;
        contadorDadosPorValor[2] = cantidadTres;
        contadorDadosPorValor[3] = cantidadCuatro;
        contadorDadosPorValor[4] = cantidadCinco;
        contadorDadosPorValor[5] = cantidadSeis;

        //int valorCantMax = 0;
        //int dadoMaxActual = 0;

        for(int i = 0; i <= cantidadDados; i++){
            cout << "Dados " << i + 1 << ": " << contadorDadosPorValor[i] << endl;
        }

        for(int i = 0; i < cantidadValores; i++){
            if (contadorDadosPorValor[i] >= valorCantMax && dados[i] > dadoMaxActual){
                valorCantMax = contadorDadosPorValor[i];
                dadoMaxActual = dados[i];
            }
        }

        switch(dadoMaxActual){
            case 1: puntosCalculados = valorCantMax * 1;
                    break;
            case 2: puntosCalculados = valorCantMax * 2;
                    break;
            case 3: puntosCalculados = valorCantMax * 3;
                    break;
            case 4: puntosCalculados = valorCantMax * 4;
                    break;
            case 5: puntosCalculados = valorCantMax * 5;
                    break;
            case 6: puntosCalculados = valorCantMax * 6;
                    break;
            default: cout << "Valor desconocido";
                    break;
        }
        for(int i = 0; i < cantidadValores; i++){
            if (dados[i] > puntosCalculados){
                puntosCalculados = dados[i];
                dadoMaxActual = dados[i];
                valorCantMax = 1;
            }
        }


        cout << "Mejor combinaci¢n: Dado " << dadoMaxActual
        << " con " << valorCantMax << " igualdad/es"<< endl;

        cout << "Puntos obtenidos: " << puntosCalculados << endl;
}
