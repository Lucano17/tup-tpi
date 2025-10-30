#include "funciones.h"

using namespace std;
// Variables
/// Utils
char bordeX = 'Í';
/// Puntajes
int dadosIguales = 0;
int juego1Puntaje = 1 * dadosIguales;
int juego2Puntaje = 2 * dadosIguales;
int juego3Puntaje = 3 * dadosIguales;
int juego4Puntaje = 4 * dadosIguales;
int juego5Puntaje = 5 * dadosIguales;
int juego6Puntaje = 6 * dadosIguales;
int escaleraPuntaje = 25;
int fullPuntaje = 30;
int pokerPuntaje = 40;
int generalaPuntaje = 50;
int puntosCalculados = 0;
int puntosMaxCalculados = 0;
bool generalaServida = false;
int valorCantMax = 0;
int listaDadosMax[5];
int dadoMaxActual = 0;

/// Partida
int cantidadRondas = 5;
int cantidadTiradasXRonda = 3;
int cantidadDados = 5;
int cantidadValores = 6;
int dados[6] = {1, 2, 3, 4, 5, 6};
int contadorDadosPorValor[6];
int dadosLanzados[5];
//

/// Utils
void dibujarBordeX(char bordeX){
    for (int i = 0; i <= 31; i++){
        cout << bordeX;
    }
    cout << "" << endl;
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
    dibujarBordeX(bordeX);
}
///

/// Cr‚ditos
void creditos(){
    cout << "=========== CREDITOS ===========" << endl;
                cout << "Programaci¢n 1" << endl;
                cout << "Equipo 50" << endl;
                cout << "Acosta, Ian" << endl;
                cout << "de la Fuente, Lucas" << endl;
                cout << "Wolf, Federico" << endl;
                cout << "Zunini, Francisco" << endl;
                dibujarBordeX(bordeX);
}
///

/// Reglas
void reglas(){
    dibujarBordeX(bordeX);
    cout << "Estas son las reglas:" << endl;
    cout << "" << endl;
    // Juego 1
    cout << "Combinaci¢n: 1 o m s dados con valor 1" << endl;
    cout << "Nombre de jugada: Juego de 1" << endl;
    cout << "Puntaje otorgado: Suma de la cantidad de dados con el valor 1" << endl;
    cout << "" << endl;
    // Juego 2
    cout << "Combinaci¢n: 1 o m s dados con valor 2" << endl;
    cout << "Nombre de jugada: Juego de 2" << endl;
    cout << "Puntaje otorgado: 2*(La suma de la cantidad de dados con el valor 2)" << endl;
    cout << "" << endl;
    // Juego 3
    cout << "Combinaci¢n: 1 o m s dados con valor 3" << endl;
    cout << "Nombre de jugada: Juego de 3" << endl;
    cout << "Puntaje otorgado: 3*(La suma de la cantidad de dados con el valor 3)" << endl;
    cout << "" << endl;
    // Juego 4
    cout << "Combinaci¢n: 1 o m s dados con valor 4" << endl;
    cout << "Nombre de jugada: Juego de 4" << endl;
    cout << "Puntaje otorgado: 4*(La suma de la cantidad de dados con el valor 4)" << endl;
    cout << "" << endl;
    // Juego 5
    cout << "Combinaci¢n: 1 o m s dados con valor 5" << endl;
    cout << "Nombre de jugada: Juego de 5" << endl;
    cout << "Puntaje otorgado: 5*(La suma de la cantidad de dados con el valor 5)" << endl;
    cout << "" << endl;
    // Juego 6
    cout << "Combinaci¢n: 1 o m s dados con valor 6" << endl;
    cout << "Nombre de jugada: Juego de 6" << endl;
    cout << "Puntaje otorgado: 6*(La suma de la cantidad de dados con el valor 6)" << endl;
    cout << "" << endl;
    // Escalera
    cout << "Combinaci¢n: 5 dados en orden creciente (1,2,3,4,5), (2,3,4,5,6)" << endl;
    cout << "Nombre de jugada: Escalera" << endl;
    cout << "Puntaje otorgado: "<< escaleraPuntaje << endl;
    cout << "" << endl;
    // Full
    cout << "Combinaci¢n: 3 dados iguales m s otros 2 iguales (3,3,3,2,2)" << endl;
    cout << "Nombre de jugada: Full" << endl;
    cout << "Puntaje otorgado: "<< fullPuntaje << endl;
    cout << "" << endl;
    // P¢ker
    cout << "Combinaci¢n: 4 dados iguales (1,4,4,4,4)" << endl;
    cout << "Nombre de jugada: P¢ker" << endl;
    cout << "Puntaje otorgado: "<< pokerPuntaje << endl;
    cout << "" << endl;
    // Generala
    cout << "Combinaci¢n: 5 dados con el mismo valor (2,2,2,2,2)" << endl;
    cout << "Nombre de jugada: Generala" << endl;
    cout << "Puntaje otorgado: 50 o si es en la primera tirada del turno, gana el partido" << endl;
    cout << "" << endl;
    dibujarBordeX(bordeX);
}
///

/// Partida
int lanzarUnDado(){
    int num = (rand() % 6) + 1;
    //cout << num << " ";
    return num;
}
void tiradaDeDados(){
    int dadosLanzados[cantidadDados];
    //int num = 0;
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
    int cantidadUno = 0;
    int cantidadDos = 0;
    int cantidadTres = 0;
    int cantidadCuatro = 0;
    int cantidadCinco = 0;
    int cantidadSeis = 0;
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

        int valorCantMax = 0;
        int dadoMaxActual = 0;

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
