#include "Nodo.h"

//Metodos Contructres y Destructor
Nodo::Nodo(Ficha *pficha) {
	this -> ptrSig = NULL;
	this -> ptrAnt= NULL;
	this -> ptrFicha = pficha;
}

Nodo::Nodo() {
	this -> ptrSig = NULL;
	this -> ptrAnt= NULL;
	this -> ptrFicha = new Ficha();
}

Nodo::~Nodo() {
	delete this->ptrFicha;
}


//Metodos Set y Get
void Nodo::setPtrAnt(Nodo *pant)
{
	this -> ptrAnt = pant;
}

void Nodo::setPtrSig(Nodo *psig)
{
	this -> ptrSig = psig;
}

void Nodo::setPtrFicha(Ficha *pficha) 
{
	this -> ptrFicha = pficha;
}

Nodo* Nodo::getPtrSig() 
{
	return ptrSig;
}

Nodo* Nodo::getPtrAnt()
{
	return ptrAnt;
}

Ficha* Nodo::getPtrFicha() 
{
	return ptrFicha;
}
