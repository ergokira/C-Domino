#pragma once
#include "Nodo.h"

class Lista 
{

private:

	//Atributos
	Nodo *pInicio;
	//Nodo *pActual;        
	Nodo *pUltimo;

public:

	//Metodos Constructor y Destructor
	Lista (); 
	~Lista ();

	//Metodos Set y Get
	Nodo* getPtrInicio();
	//Nodo* getPtrActual();
	Nodo* getPtrUltimo();
	void setPtrInicio(Nodo *fich);
	//void setPtrActual(Nodo *fich);
	void setPtrUltimo(Nodo *fich);

	//Metodos de manipulacion de las listas
	void insertarInicio(Ficha *pficha);
	void insertarFinal(Ficha *pficha);
	bool vacio(); 
	void llenar();

	//Metodos para imprimir las listas
	void imprimirLista();
	void imprimirMesa();
	
	//Metodosde extraccion y eliminacion de fichas
	void borrarFicha(int pos);
	Ficha* sacarFicha(int); 
	Ficha* copiarFicha(int); 
	//Actualizacion de los extremos validos de mesa
	Ficha* tomarPuntas();
	
	//Metodos de reglas del domino
	bool comprobarSiEsta(int);
	Ficha* extraerGrandeza();
	int sumarLista();

	friend class Nodo;

};

