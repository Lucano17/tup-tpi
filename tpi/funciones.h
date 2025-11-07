#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;

void pruebas();
void dibujarBordeX();
void unJugador();
int dosJugadores();
void verPuntacionMax();
void creditos();
void reglas();
int lanzarUnDado();
void tiradaDeDados();
int calcularPuntos(int dadosLanzados[]);
int verificarEscalera(int puntosCalculados, int contadorDadosPorValor[]);
int verificarFull(int i, int puntosCalculados, int contadorDadosPorValor[]);
void calcularTirada(int cantidadDados, int dadosLanzados[]);
void relanzarDados(int dados[]);
int turnoJugador(string nombre);

#endif
