#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;

// Utils
void dibujarBordeXGrueso();
void dibujarBordeXFino();
// Un jugador
void unJugador(int CANT_DADOS, int CANT_RONDAS, int dadosLanzados[]);
// Dos jugadores
void dosJugadores(int CANT_DADOS, int CANT_RONDAS, string &mejorJugador, int &mejorPuntaje, int dadosLanzados[]);
// Creditos
void creditos();
// Reglas
void reglas();
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
// Puntaje
int calcularPuntos(int dadosLanzados[], bool jugadasUsadas[], int CANT_DADOS);
int calcularPuntajePorCategoria(int categoria, int dados[]);
int verificarEscalera(int puntosCalculados, int contadorDadosPorValor[]);
int verificarFull(int i, int puntosCalculados, int contadorDadosPorValor[]);
bool verificarGenerala(int dadosLanzados[], int CANT_DADOS);
void calcularTirada(int cantidadDados, int dadosLanzados[]);
// Puntuacion maxima
void guardarMejorPuntaje(string jugador, int puntaje, string &mejorJugador, int &mejorPuntaje);
void verPuntacionMax(string mejorJugador, int mejorPuntaje);







#endif
