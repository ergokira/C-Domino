#pragma once
#include <stdio.h> 
#include <stdlib.h> 
#include <ctime> 
#include <cstdlib>
#include "Lista.h"


class Juego
{

private:

	//Atributos
	Lista *pozo;
	Lista *jugadorA;
	Lista *jugadorB;
	Lista *mesa;
	Ficha *fichaParaJugar;
	Ficha *fichaMagica;
	string nombreJugador;

public:

	//Metodos Constructores y Destructor
	Juego();
	Juego(Lista*,Lista*,Lista*,Lista*,Ficha*, Ficha*);
	~Juego();	

	//Metodos Set y Get
	string getNombreJugador();
	Lista* getPozo();
	Lista* getJugadorA();
	Lista* getJugadorB();
	Lista* getMesa();
	Ficha* getFichaParaJugar();
	Ficha* getFichaMagica();
	void setNombreJugador(string);
	void setPozo(Lista*);
	void setJugadorA(Lista*);
	void setJugadorB(Lista*);
	void setMesa(Lista*);
	void setFichaParaJugar(Ficha*);
	void setFichaMagica(Ficha*);


	//Metodo que reparte las manos de los jugadores aleatoreamente
	void repartir();

	//Metodos de reglas del domino
	int terminarJuego(Lista*);
	bool buscarMinimoChance(Lista*);
	int siguienteJugada (int);
	int buscarPares();
	int grandezaDosListasInicial();

	//metodo que da fichas aleatorias a los jugadores (listas) que lo soliciten
	void sacarDelPozo(Lista*);

	//Metodo que verifica y en caso de darse la situacion apropiada ejecuta una movida
	bool checkPosibleColocacion(int, char, Lista* player);

	
};
