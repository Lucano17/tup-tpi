#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;

void pruebas();
void dibujarBordeXGrueso();
void dibujarBordeXFino();
void unJugador(int CANT_DADOS, int CANT_RONDAS);
int dosJugadores(int CANT_DADOS, int CANT_RONDAS, string &mejorJugador, int &mejorPuntaje);
void creditos();
void reglas();
int lanzarUnDado();
void tiradaDeDados();
int calcularPuntos(int dadosLanzados[]);
int verificarEscalera(int puntosCalculados, int contadorDadosPorValor[]);
int verificarFull(int i, int puntosCalculados, int contadorDadosPorValor[]);
void calcularTirada(int cantidadDados, int dadosLanzados[]);
void relanzarDados(int dados[]);
int turnoJugador(string nombre, int CANT_DADOS);
int turnoJugadorSolitario(int CANT_DADOS, string nombre);
int turnoPC(int CANT_DADOS);
void guardarMejorPuntaje(string jugador, int puntaje, string &mejorJugador, int &mejorPuntaje);
void verPuntacionMax(string mejorJugador, int mejorPuntaje);
void lanzarDados(int dadosLanzados[], int CANT_DADOS);
void lanzarDadosManual(int dadosLanzados[], int CANT_DADOS);
bool esGenerala(int dados[], int CANT_DADOS);
int tresLanzamientos(int CANT_DADOS, string nombre, int puntosActuales);









#endif
