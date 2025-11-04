#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;

void pruebas();
void dibujarBordeX();
void unJugador();
void dosJugadores();
void verPuntacionMax();
void creditos();
void reglas();
int lanzarUnDado();
void tiradaDeDados();
void calcularPuntos(int dadosLanzados[]);
int verificarEscalera(int puntosCalculados, int contadorDadosPorValor[]);
int verificarFull(int i, int puntosCalculados, int contadorDadosPorValor[]);
#endif
