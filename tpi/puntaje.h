
#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <iostream>
using namespace std;

// Puntaje
int calcularPuntos(int dadosLanzados[], bool jugadasUsadas[], int CANT_DADOS);
int calcularPuntajePorCategoria(int categoria, int dados[]);
int verificarEscalera(int puntosCalculados, int contadorDadosPorValor[]);
int verificarFull(int i, int puntosCalculados, int contadorDadosPorValor[]);
bool verificarGenerala(int dadosLanzados[], int CANT_DADOS);
void calcularTirada(int cantidadDados, int dadosLanzados[]);
void guardarMejorPuntaje(string jugador, int puntaje, string &mejorJugador, int &mejorPuntaje);
void verPuntacionMax(string mj1, int mp1, string mj2, int mp2);


#endif
