#pragma once
#include "Ficha.h"


class Nodo 
{
private:

	//Atributos
	Nodo *ptrSig;
	Ficha *ptrFicha;
	Nodo *ptrAnt;

public:

	//Metodos Contructores y Destructor
	Nodo (Ficha*);
	Nodo ();
	~Nodo ();

	//Metodos Set y Get
	void setPtrSig (Nodo*);
	void setPtrAnt (Nodo*);
	void setPtrFicha (Ficha*);
	Nodo* getPtrAnt ();
	Nodo* getPtrSig ();
	Ficha* getPtrFicha ();
};