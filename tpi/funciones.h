#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;

void pruebas();
void dibujarBordeXGrueso();
void dibujarBordeXFino();
void unJugador();
int dosJugadores(string &mejorJugador, int &mejorPuntaje);
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
void guardarMejorPuntaje(string jugador, int puntaje, string &mejorJugador, int &mejorPuntaje);
void verPuntacionMax(string mejorJugador, int mejorPuntaje);

void lanzarDadosManual(int dadosLanzados[], int CANT_DADOS);



bool esGenerala(int dados[]);




#endif
