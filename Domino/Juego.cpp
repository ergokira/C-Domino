#include "Juego.h"


//Metodos Constructores y Destructor
Juego::Juego(Lista *p,Lista *j,Lista *c,Lista *m, Ficha *fich, Ficha *fichMag)
{
	this->pozo=p;
	this->jugadorB=c;
	this->jugadorA=j;
	this->mesa=m;
	this->fichaParaJugar=fich;
	this->fichaMagica=fichMag;

}

Juego::Juego()
{
	this->pozo=new Lista();
	this->jugadorB=new Lista();
	this->jugadorA=new Lista();
	this->mesa=new Lista();
	pozo->llenar();
	this->fichaParaJugar = new Ficha();
	this->fichaMagica=new Ficha();
}

Juego::~Juego()
{

}


//Metodos Set y Get
string Juego::getNombreJugador()
{
	return nombreJugador;
}

Lista* Juego::getPozo()
{
	return pozo;
}

Lista* Juego::getJugadorA()
{
	return jugadorA;
}

Lista* Juego::getJugadorB()
{
	return jugadorB;
}

Lista* Juego::getMesa()
{
	return mesa;
}

Ficha* Juego::getFichaParaJugar()
{
	return fichaParaJugar;
}

Ficha* Juego::getFichaMagica()
{
	return fichaMagica;
}

void Juego::setNombreJugador(string name)
{
	this->nombreJugador = name;
}

void Juego::setPozo(Lista* p)
{
	this -> pozo = p;
}

void Juego::setJugadorA(Lista* jA)
{
	this -> jugadorA = jA;
}

void Juego::setJugadorB(Lista* jB)
{
	this -> jugadorB = jB;
}

void Juego::setMesa(Lista* m)
{
	this -> mesa = m;
}

void Juego::setFichaParaJugar(Ficha* fich)
{
	this -> fichaParaJugar = fich;
}

void Juego::setFichaMagica(Ficha *fich)
{
	this -> fichaMagica = fich;
}


//Metodo que reparte las manos de los jugadores aleatoriamente
void Juego::repartir()
{
	//Repartir Jugador
	srand((unsigned) time(0));
	for(int i=0;i<=6;i++)
	{
		
		int j=rand() % 28; 
		Ficha* aux=pozo->sacarFicha(j);  //Toma las fichas del pozo y las introduce en la lista JugadorA
		if(aux==NULL)
		{
			i--;
		}
		else
		{
			jugadorA->insertarInicio(aux);
		}
		
	}
	//Repartir Computadora
	for(int i=0;i<=6;i++)
	{
		
		int j=rand() % 28; 
		Ficha* aux=pozo->sacarFicha(j); //Toma las fichas del pozo y las introduce en la lista JugadorB
		if(aux==NULL)
		{
			i--;
		}
		else
		{
			jugadorB->insertarInicio(aux);
		}
		
	}
}


//Metodos de reglas del domino
void Juego::sacarDelPozo(Lista* player){

	srand((unsigned) time(0));
	bool laFichaEstaAqui=false;
	int j;
		do
		{

				j=rand() % 28; 
				if(pozo->comprobarSiEsta(j))
				{			
				Ficha* aux=pozo->sacarFicha(j);
				player->insertarInicio(aux);
				laFichaEstaAqui=true;
				}
			
		}
		while(!laFichaEstaAqui);

		}

int Juego::terminarJuego(Lista* player) {

	/*esta variable se inicializa en 0, porque la manera en que se inicia el juego, este tendra oportunidad de ser jugado
	al menos la primera vez, entonces la primera vez no debe ser validada
	*/
int elJuegoTermino = 0;
if (player -> vacio()==true)  // esta es la opcion de un jugador haya ganado por quedarse sin fichas
	{
		elJuegoTermino = 1;
		return elJuegoTermino;
	}

	else
		{
			if((buscarMinimoChance(player) == false)&&(pozo->vacio()==true))  // esta la opcion de que el juego termine a razon de que no se pueda jugar mas
				{
					elJuegoTermino = 2;
					return elJuegoTermino;
				}
		}

return elJuegoTermino;

}







/*aqui empieza el metodo buscar minimo chance*/
// Este metodo recibe una lista como parametro, esta lista sera el jugador A o el jugador B
// el metodo toma esta lista y compara en ella ficha por ficha en sus ambos lados buscando un lado
// que sea igual a algun lado de las puntas validas de la mesa

bool Juego::buscarMinimoChance(Lista *player) { 

	Ficha *fichaMagica= new Ficha();  
	fichaMagica = mesa->tomarPuntas();
	Nodo *aux= NULL;
	aux = player->getPtrInicio();

	bool chance = false;
	do {
		if (aux ->getPtrFicha()->getLadoA() == fichaMagica->getLadoA() || 
			aux ->getPtrFicha()->getLadoB() == fichaMagica->getLadoA() ||
			aux ->getPtrFicha()->getLadoA() == fichaMagica->getLadoB() ||
			aux ->getPtrFicha()->getLadoB() == fichaMagica->getLadoB() )
		{
			chance = true;
			return chance;
		}
		else
		{ 
			aux= aux->getPtrSig();
		}





	}

	while (aux!=NULL);

	return chance;
	
}

//este metodo se encarga de cambiar cada turno el parametro que indica cual turno es
int Juego::siguienteJugada (int quienJuega)
{

if(quienJuega == 1)
	{
		return 0;
	}

	else
		{
			return 1;
		}
}

/*este metodo se encarga de buscar en las listas de ambos jugadores la ficha:
				-6/6
				-5/5
				-4/4
				-3/3
				-2/2
				-1/1
				-0/0
		en ese orden, si es encontrada cualquiera de ellas, se actualiza esta ficha encontrada y se retorna un valor que indica cual jugador la posee
*/
int Juego::buscarPares()
{

	Nodo * aux = new Nodo();  //este nodo auxiliar sera solo para recorrer la lista UNICAMENTE
	bool fichaEncontrada = false;
	int indiceTransform =0;	
	int indiceCod = 28;


	do{		
								indiceCod=indiceCod-indiceTransform;
										indiceTransform ++;
								
								aux = jugadorA -> getPtrInicio();
								do{
													if(aux ->getPtrFicha() -> getIndice() == indiceCod-indiceTransform)
														{
							
																			fichaEncontrada=true;
																			fichaParaJugar=aux->getPtrFicha();
																			fichaParaJugar = jugadorA->sacarFicha(indiceCod-indiceTransform);
																			mesa -> insertarInicio(fichaParaJugar);
							

																			return 1; 
														}
														else 
															{
																aux = aux -> getPtrSig();
															}
								 }
								while(aux != NULL);
				
								aux = jugadorB -> getPtrInicio();
								do{
												if(aux ->getPtrFicha() -> getIndice() == indiceCod-indiceTransform)
															{
																fichaEncontrada=true; 
																fichaParaJugar=aux->getPtrFicha();
																fichaParaJugar = jugadorB->sacarFicha(indiceCod-indiceTransform);
																mesa -> insertarInicio(fichaParaJugar);


																return 0; 
															}
															else 
																{
																	aux = aux -> getPtrSig();
																}
								 }

								while(aux != NULL);
	}
		while(!fichaEncontrada);


	{return 2;}
		

}


//este metodo se encarga de definir el desempate de dos listas en caso que no se encontrara ningun par en ninguna de ellas
//el desempate se logra utilizando en ambas listas el metodo extraerGrandeza
/*pregunta!: xq el metodo extraerGrandeza y no usar un metodo que tome la ficha con la suma mas alta?
respuesta!: xq existen pocas, pero varias posibilidades, en las que ambos jugadores tengan una ficha, DIFERENTE (obviamente) NO PAR (obviamente)
con el mismo resultado en su suma; dados estos posibles escenarios, el metodo extraerGrandeza, no solo toma en cuenta los valores mas altos, sino que establece
un 2do paso en el que para cualquier caso dado, siempre existira una diferencia, la cual, logre el verdadero desempate.

esta idea del metodo extraerGrandeza, su concepcion, planteamiento, implementacion y uso, fue 100% innovada por el grupo: COMARCA PIEDRA GRANDE II
*/
int Juego::grandezaDosListasInicial(){

Ficha *grandeza1 = NULL;
Ficha *grandeza2 = NULL;
Ficha *grandezaTotal = NULL;

grandeza1 = jugadorA->extraerGrandeza();
grandeza2 = jugadorB->extraerGrandeza();

Lista *aux = new Lista();

aux -> insertarInicio(grandeza1);
aux -> insertarInicio(grandeza2);

grandezaTotal = aux->extraerGrandeza();
fichaParaJugar=grandezaTotal;
if(grandezaTotal = grandeza1)
{
	grandeza1=jugadorA->sacarFicha(grandezaTotal->getIndice());
	mesa->insertarInicio(grandeza1);
	return 1;}

else
{
	grandeza2=jugadorB->sacarFicha(grandezaTotal->getIndice());
	mesa->insertarInicio(grandeza2);
	return 0;}

delete aux;

}

//Metodo que verifica una ficha con indice X en una posicion al inicio ó al final de una lista Y y en caso de darse la situacion apropiada ejecuta una movida
bool Juego::checkPosibleColocacion(int f, char pos, Lista* player) {	
	fichaParaJugar = player->sacarFicha(f);
	delete fichaMagica;
	fichaMagica = mesa->tomarPuntas();
	bool bandera = false;
	switch (pos)
	{
	case 'i':
		{
			if((fichaParaJugar->getLadoB())==(fichaMagica->getLadoA()))
			{
				mesa->insertarInicio(fichaParaJugar);
				bandera = true;
			} else
			if((fichaParaJugar->getLadoA())==(fichaMagica->getLadoA()))
			{
				int x,y;
				x=fichaParaJugar->getLadoA();
				y=fichaParaJugar->getLadoB();
				fichaParaJugar->setLadoA(y);
				fichaParaJugar->setLadoB(x);
				mesa->insertarInicio(fichaParaJugar);
				bandera = true;
			}
			break;
		}

	case 'f':
		{
			if((fichaParaJugar->getLadoA())==(fichaMagica->getLadoB()))
			{
				mesa->insertarFinal(fichaParaJugar);
				bandera = true;
			} else
			if((fichaParaJugar->getLadoB())==(fichaMagica->getLadoB()))
			{
				int x,y;
				x=fichaParaJugar->getLadoA();
				y=fichaParaJugar->getLadoB();
				fichaParaJugar->setLadoA(y);
				fichaParaJugar->setLadoB(x);
				
				mesa->insertarFinal(fichaParaJugar);
				bandera = true;				
			}
			break;
		}
	default:
		
		bandera = false;
		break;
	}
	
	if(bandera==false)
	{
		player->insertarInicio(fichaParaJugar);
	}
	return bandera;
}

