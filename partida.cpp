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
    string nombre1 = "Lucas";
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

Partida
int lanzarUnDado(){
    int num = (rand() % 6) + 1;
    return num;
}
void tiradaDeDados(){
    const int cantidadDados = 5;
    int dadosLanzados[cantidadDados];

    // Primera tirada
    for(int i = 0; i < cantidadDados; i++){
        dadosLanzados[i] = lanzarUnDado();
    }

    for(int ronda = 1; ronda <= 3; ronda++){
        cout << "\nRonda " << ronda << endl;
        for(int i = 0; i < cantidadDados; i++){
            cout << dadosLanzados[i] << " ";
        }
        cout << endl;

        if(ronda == 3) break;

        cout << "Ingresa 1 si queres volver a tirar ese dado, 0 para mantenerlo (separados por espacios): ";
        int eleccion;
        for(int i = 0; i < cantidadDados; i++){
            cin >> eleccion;
            if(eleccion == 1){
                dadosLanzados[i] = lanzarUnDado();
            }
        }
    }

    cout << "\nResultado final: ";
    for(int i = 0; i < cantidadDados; i++){
        cout << dadosLanzados[i] << " ";
    }
    cout << endl;

    calcularPuntos(dadosLanzados);
}


/// Puntaje
void calcularPuntos(int dadosLanzados[]){
    //
    int escalera = 0;
    int full = 0;
    int pokerPuntaje = 40;
    int generalaPuntaje = 50;
    bool tresIgualdades = false;
    bool dosIgualdades = false;
    //
    int cantidadDados = 5;
    int cantidadValores = 6;
    int dados[6] = {1, 2, 3, 4, 5, 6};
    //
    int cantidadUno = 0;
    int cantidadDos = 0;
    int cantidadTres = 0;
    int cantidadCuatro = 0;
    int cantidadCinco = 0;
    int cantidadSeis = 0;
    int contadorDadosPorValor[6];
    //
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
    // Condicionales para calcular escalera, full, poker y generala
    for(int i = 0; i < cantidadDados; i++){
        if(contadorDadosPorValor[i] == 5){
            puntosCalculados = generalaPuntaje;
        }
        if(contadorDadosPorValor[i] == 4){
            puntosCalculados = pokerPuntaje;
        }
        if(contadorDadosPorValor[i] == 3){
            tresIgualdades = true;
        }
        // Full
        full = verificarFull(i, puntosCalculados, contadorDadosPorValor);
        if (full != 0) puntosCalculados = full;

        // Escalera
        escalera = verificarEscalera(puntosCalculados, contadorDadosPorValor);
        if (escalera != 0) puntosCalculados = escalera;
        //
    }
    //

    cout << "Mejor combinaci¢n: Dado " << dadoMaxActual
    << " con " << valorCantMax << " igualdad/es"<< endl;

    cout << "Puntos obtenidos: " << puntosCalculados << endl;
}

    void pruebas(){
        int cantidadDados = 5;
        int puntosCalculados = 0;
        int contadorDadosPorValor[6] = {3, 2, 0, 0, 0, 0};
        int escalera = 0;
        int full = 0;
        int pokerPuntaje = 40;
        int generalaPuntaje = 50;
        int generalaServidaPuntaje = 250;

        for(int i = 0; i < cantidadDados; i++){
            // Generala
            if(contadorDadosPorValor[i] == 5){
                puntosCalculados = generalaPuntaje;
            }
            // Poker
            if(contadorDadosPorValor[i] == 4){
                puntosCalculados = pokerPuntaje;
            }
            // Full
            full = verificarFull(i, puntosCalculados, contadorDadosPorValor);
            if (full != 0) puntosCalculados = full;
        }
        // Escalera
        escalera = verificarEscalera(puntosCalculados, contadorDadosPorValor);
        if (escalera != 0) puntosCalculados = escalera;
        //

    cout << "Puntaje: " << puntosCalculados << endl;
}

int verificarEscalera(int puntosCalculados, int contadorDadosPorValor[6]){
    int escaleraPuntaje = 25;
    if(contadorDadosPorValor[0] == 1 && contadorDadosPorValor[1] == 1&&
        contadorDadosPorValor[2] == 1 && contadorDadosPorValor[3] == 1 &&
        contadorDadosPorValor[4] == 1){
        puntosCalculados = escaleraPuntaje;
    }

    if(contadorDadosPorValor[5] == 1 && contadorDadosPorValor[1] == 1&&
        contadorDadosPorValor[2] == 1 && contadorDadosPorValor[3] == 1 &&
        contadorDadosPorValor[4] == 1){
        puntosCalculados = escaleraPuntaje;
    }
    return puntosCalculados;
}

int verificarFull(int i, int puntosCalculados,int contadorDadosPorValor[6]){
    int fullPuntaje = 30;
    bool tresIgualdades = false;
    bool dosIgualdades = false;

    for(int i = 0; i < 6; i++){
        if(contadorDadosPorValor[i] == 3){
            tresIgualdades = true;
        }
        if(contadorDadosPorValor[i] == 2){
            dosIgualdades = true;
        }

        if(dosIgualdades == true && tresIgualdades == true){
            puntosCalculados = fullPuntaje;
        }
    }
    return puntosCalculados;
}

