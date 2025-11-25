#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
using namespace std;

// Partida
int lanzarUnDado();
void tiradaDeDados();
void mostrarDados(int dadosLanzados[], int CANT_DADOS);
void relanzarDados(int dados[]);
int turnoJugador(string nombre, int CANT_DADOS, bool jugadasUsadas[], bool &esGeneralaServida);
int turnoJugadorSolitario(int CANT_DADOS, string nombre, bool jugadasUsadas[], int dadosLanzados[]);
void lanzarDados(int dadosLanzados[], int CANT_DADOS);
void lanzarDadosManual(int dadosLanzados[], int CANT_DADOS);
int tresLanzamientos(string nombre, int puntosActuales, int dadosLanzados[], int CANT_DADOS, bool jugadasUsadas[]);
int pedirCategoria(bool jugadasUsadas[]);
void mostrarCategoriasDisponibles(bool jugadasUsadas[]);
#endif
