#include <iostream>
#include "funciones.h"


using namespace std;


int calcularPuntos(int dadosLanzados[]){
    //
    int escalera = 0;
    int full = 0;
    int pokerPuntaje = 40;
    int generalaPuntaje = 50;
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
    int dadoMaxActual = 0;
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
        // Full
        full = verificarFull(i, puntosCalculados, contadorDadosPorValor);
        if (full != 0) {
                puntosCalculados = full;
        }

        // Escalera
        escalera = verificarEscalera(puntosCalculados, contadorDadosPorValor);
        if (escalera != 0) {
                puntosCalculados = escalera;
        }
    }
    // Si no es una jugada especial, imprime la mejor combinaci¢n obtenida
    if(puntosCalculados < 25){
        cout << "Mejor combinaci¢n: Dado " << dadoMaxActual
        << " con " << valorCantMax << " igualdad/es"<< endl;
    }
    if(puntosCalculados == 50){
        cout << "Mejor combinaci¢n: Generala " << endl;
    }
    if(puntosCalculados == 40){
        cout << "Mejor combinaci¢n: Poker " << endl;
    }
    if(puntosCalculados == 30){
        cout << "Mejor combinaci¢n: Full " << endl;
    }
    if(puntosCalculados == 25){
        cout << "Mejor combinaci¢n: Escalera " << endl;
    }
    //

    cout << "Puntos obtenidos: " << puntosCalculados << endl;
    return puntosCalculados;
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
