#include "Ficha.h"

//Metodos Contructores y Destructor
Ficha::Ficha(int aLado, int bLado, int i)
{
	this ->indice=i;
	this -> ladoA = aLado;
	this -> ladoB = bLado;
}

Ficha::Ficha()
{
	this ->indice=28;
	this -> ladoA = 0;
	this -> ladoB = 0;
}

Ficha::~Ficha()
{
}


//Metodos Set y Get
void Ficha::setLadoA(int aLado)
{
	this -> ladoA = aLado;
}

void Ficha::setLadoB(int bLado)
{
	this -> ladoB = bLado;
}

void Ficha::setIndice(int i)
{
	this -> indice = i;
}

int Ficha::getLadoA()
{
	return ladoA;
}

int Ficha::getLadoB()
{
	return ladoB;
}

int Ficha::getIndice()
{
	return indice;
}


//Metodos para imprimir fichas
void Ficha::mostrarFicha()
{
	cout<<"["<<ladoA<<" | "<<ladoB<<" ] ( "<<indice<<" )"<<endl;
}

void Ficha::mostrarFichaEnMesa()
{
	cout<<"["<<ladoA<<" | "<<ladoB<<" ] ";
}

