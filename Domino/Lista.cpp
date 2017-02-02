#include "Lista.h"

//Metodos Constructor y Destructor
Lista::Lista() 
{
	this ->pInicio = NULL;
	//this ->pActual = NULL;
	this ->pUltimo = NULL;
}

Lista::~Lista() 
{

	Nodo *aux = NULL;
	do 
	{
		aux = pInicio;
		pInicio = aux->getPtrSig();
		delete aux;
	}
	while(pInicio != NULL);
}


//Metodos Set y Get
Nodo* Lista::getPtrInicio()
{
	return pInicio;
}

//Nodo* Lista::getPtrActual()
/*{
	return pActual;
}*/

Nodo* Lista::getPtrUltimo()
{
	return pUltimo;
}

void Lista::setPtrInicio(Nodo *fich)
{
	this->pInicio = fich;
}

//void Lista::setPtrActual(Nodo *fich)
/*{
	this->pActual = fich;
}*/

void Lista::setPtrUltimo(Nodo *fich)
{
	this->pUltimo = fich;
}


//Metodos de manipulacion de las listas
void Lista::insertarInicio(Ficha *pficha)
{
	Nodo *nodoFichaNueva = new Nodo(pficha);

	if (vacio() == true) {
        pInicio = nodoFichaNueva;
        pUltimo = nodoFichaNueva;
    } else {
        pInicio->setPtrAnt(nodoFichaNueva);
        nodoFichaNueva->setPtrSig(pInicio);
        pInicio = nodoFichaNueva;
    }

}

void Lista::insertarFinal(Ficha *fich)
{      
	Nodo *aux = pInicio;
    Nodo *pNuevo=new Nodo(fich); 
	if(pInicio==NULL)
    {
		 pInicio = pNuevo;
		 pUltimo = pNuevo;
    } 
	else   
	{      
		while (aux->getPtrSig()!=NULL)
		{
			aux=aux->getPtrSig(); //While sera eliminado porr ultimo  
        }
		aux->setPtrSig(pNuevo);
		pNuevo->setPtrAnt(aux);
	}
	pUltimo = pNuevo;
}


//este metodo se encarga de crear las 28 fichas del domino con los numeros correctos sin repetirse, una vez creadas, son depositadas las 28 en el pozo
void Lista::llenar(){
	int x=0;
	for(int i=0;i<=6;i++){
		for(int j=i;j<=6;j++){
			Ficha *aux=new Ficha(i,j,x);
			x++;
			insertarInicio(aux);
		}
	}
}
//este metodo verifica si una lista cualquiera esta vacia o no
bool Lista::vacio()
{
	if (pInicio == NULL)
	{
		return true;
    }
	return false;
}


//Metodos para imprimir listas
void Lista::imprimirLista() {
    if (!vacio()) {
        Nodo *aux = pInicio;
		cout<<endl;
        do {
			
            cout<< "            " <<endl;
            aux->getPtrFicha()->mostrarFicha();     
			cout<< "            " <<endl;
			
            aux = aux->getPtrSig();
			
        } while (aux != NULL);
		cout<<endl;
    }
}

void Lista::imprimirMesa() {   
    if (!vacio()) {
        Nodo *aux = pInicio;
		cout<<endl;
        do {
			
            cout<< "" ;
            aux->getPtrFicha()->mostrarFichaEnMesa();
			cout<< "" ;
			
            aux = aux->getPtrSig();
        } while (aux != NULL);
		cout<<endl;
    }
}


//Metodos de extraccion y eliminacion de fichas
Ficha* Lista::sacarFicha(int i) {
	Ficha* sacar = NULL;
    if (!vacio()) {
        Nodo *aux = pInicio;
        do {
			if(aux->getPtrFicha()->getIndice()==i){
				sacar = aux->getPtrFicha();
				borrarFicha(sacar->getIndice());
				aux = NULL;
			} else
			{
				aux = aux->getPtrSig();
			}            
        } while (aux != NULL);
    }
	return sacar;
}
//este metodo elimina una ficha cualquiera de una lista cualquiera
void Lista::borrarFicha(int i) {
	if (!vacio()) {
		Nodo *aux = pInicio;
		do {
			if(aux->getPtrFicha()->getIndice()==i){	
				if (aux == pInicio){
					pInicio = aux->getPtrSig();
				}
				else
				{
					if(aux == pUltimo){											  
						aux->getPtrAnt()->setPtrSig(NULL);
						pUltimo = aux->getPtrAnt();
					}
					else{
						aux->getPtrAnt()->setPtrSig(aux->getPtrSig());
						aux->getPtrSig()->setPtrAnt(aux->getPtrAnt());
					}
				}
				aux->setPtrFicha(NULL);
				delete aux;
				aux = NULL;
			}
			else {
				aux = aux->getPtrSig();
			}
		} while (aux != NULL);
    }
	//this->imprimirLista();
}


//Actualizacion de los extremos validos de mesa
Ficha* Lista::tomarPuntas()
	//metodo para crear la ficha magica
{
	int x,y;
	x=pInicio->getPtrFicha()->getLadoA();
	y=pUltimo->getPtrFicha()->getLadoB();
	Ficha* fichaMagica = new Ficha();
	fichaMagica->setLadoA(x);
	fichaMagica->setLadoB(y);
	fichaMagica->setIndice(29);
	return fichaMagica;
}


//Metodos de reglas del domino
//este metodo retorna la ficha con el numero mayor junto con el mayor despues de ser establecido el primero
Ficha* Lista::extraerGrandeza()
{
	Nodo* aux = new Nodo();
	aux = pInicio;
	int ladoBactual;
	int bMayor = 0;
	Lista* virtualDeBmayor = new Lista();
	int aMayor = 0;
	int ladoAactual;
	Ficha* grandeza = NULL;
	do
	{
		ladoBactual = aux -> getPtrFicha() -> getLadoB();
		if (ladoBactual >= bMayor)
		{
			bMayor = ladoBactual;
		}

		aux = aux ->getPtrSig();
	} while(aux != NULL);

	aux = pInicio;

	do
	{
		if(aux -> getPtrFicha() -> getLadoB() == bMayor)
		{
			virtualDeBmayor -> insertarInicio(aux -> getPtrFicha());		}
		aux = aux -> getPtrSig();
	}while(aux != NULL);

	aux = virtualDeBmayor ->getPtrInicio();

	do 
	{
		ladoAactual = aux -> getPtrFicha() -> getLadoA();
		
		if(ladoAactual >= aMayor)
		{
			aMayor = ladoAactual;
			grandeza = aux ->getPtrFicha();
		}
		aux = aux -> getPtrSig();
	}while(aux != NULL);

	return grandeza;

	delete virtualDeBmayor;


}



//este metodo suma todos los lados de todas las fichas de una lista cualquiera
int Lista::sumarLista()
{ 
	int total = 0;
	Nodo * aux = new Nodo();
	aux = pInicio;
	if(!vacio())
	{
	do
		{
			total = total + (aux ->getPtrFicha() -> getLadoA()) + (aux ->getPtrFicha() -> getLadoB());
			aux = aux -> getPtrSig();
		}while(aux != NULL);
	}
	
	return total;
}


//este metodo verifica si una ficha de indice X se encuentra en una lista cualquiera
bool Lista::comprobarSiEsta(int i) {
	bool laFichaEstaAqui=false;
    if (!vacio()) {
        Nodo *aux = pInicio;
        do {
			if(aux->getPtrFicha()->getIndice()==i){
				laFichaEstaAqui=true;
				aux=NULL;
			} else
			{
				aux = aux->getPtrSig();
			}            
        } while (aux != NULL);
		delete aux;
    }
	return laFichaEstaAqui;
}

//este metodo busca una ficha de indice X en una lista cualquiera y la retorna sin modificar la que encontro.
Ficha* Lista::copiarFicha(int i) {
	Ficha* copiar = NULL;
    if (!vacio()) {
        Nodo *aux = pInicio;
        do {
			if(aux->getPtrFicha()->getIndice()==i){
				copiar = aux->getPtrFicha();
				
				aux = NULL;
			} else
			{
				aux = aux->getPtrSig();
			}            
        } while (aux != NULL);
    }
	return copiar;
}