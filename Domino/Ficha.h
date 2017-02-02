#pragma once
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;


class Ficha 
{

private:

	//Atributos
	int ladoA;
	int ladoB;
	int indice;


public: 
	
	//Metodos Contructores y Destructor
	Ficha (int, int,int);  
	Ficha (); 
	~Ficha ();

	//Metodos Set y Get 
	void setIndice (int);
	void setLadoA (int);
	void setLadoB (int);
	int getIndice ();
	int getLadoA ();
	int getLadoB ();

	//Metodos para imprimir fichas
	void mostrarFicha(); 
	void mostrarFichaEnMesa();


};
