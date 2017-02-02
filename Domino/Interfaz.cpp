#include "Interfaz.h"

Interfaz::Interfaz(){

}

Interfaz::~Interfaz(){

}



void Interfaz::ySeHizoElDomino()
{


	cout<<"BIENVENIDO"<<endl;
	cout<<"JUEGA AL DOMINO!"<<endl;
	cout<<"que fue GENIALMENTE creado por Jorge Arias y Josue Granados!!"<<endl;
	cout<<endl;
	system("pause");
	system("cls");

	cout<<"el juego iniciara!"<<endl;
	system("pause");
	system("cls");


	Juego *juegoNuevo = new Juego();
	juegoNuevo->repartir();

	string nombreHumano;
	cout<<"ingrese su nombre: "<<endl;
	cin>>nombreHumano;

	string nombreCPU="el gran cerebro del CPU!";

	juegoNuevo->setNombreJugador(nombreHumano);

	cout<<"La ficha para iniciar el juego sera buscada!"<<endl;
	int quienInicia;
	quienInicia = juegoNuevo ->buscarPares();
	if(quienInicia==2){quienInicia=juegoNuevo->grandezaDosListasInicial();}

	string nombreActual;
	nombreActual = nombreCPU;
	if(quienInicia == 1){nombreActual=nombreHumano;}

	Ficha *fichaComenzar = new Ficha();
	fichaComenzar=juegoNuevo->getFichaParaJugar();
	system("pause");
	system("cls");

	cout<<"La ficha ya fue encontrada!"<<endl;
	system("pause");
	system("cls");

	cout<<"la ficha indicada para iniciar el juego es: ";
	fichaComenzar->mostrarFichaEnMesa();
	cout<<" !"<<endl;
	cout<<endl;
	system("pause");
	cout<<"                 "<<endl;
	cout<<"                 "<<endl;
	cout<<"                 "<<endl;
	cout<<"y el jugador que la posee es: ";
	cout<<nombreActual<<endl;
	system("pause");
	system("cls");

	cout<<"la ficha ";
	fichaComenzar->mostrarFichaEnMesa();
	cout<<endl;
	cout<<"ha sido ya jugada y colocada en la mesa!"<<endl;



	juegoNuevo->getMesa()->setPtrUltimo(juegoNuevo->getMesa()->getPtrInicio());

	Ficha *fichaMagica = NULL;
	fichaMagica = juegoNuevo->getMesa()->tomarPuntas();
	
	
	quienInicia=juegoNuevo->siguienteJugada(quienInicia);


	system("pause");

	//aqui empieza el juego con sus jugadas regulares
	
	int juegoTermino;
	//*****************************************  INICIO JUGADAS REGULARES ***********************************************************
	do
	{
		system("cls");
		if(quienInicia==1)
		{
		
		
		
			bool puedeJugarSusFichas=false; //este booleano se encarga de verificar si el jugador debe tomar del pozo
			juegoTermino=juegoNuevo->terminarJuego(juegoNuevo->getJugadorA());
			if(juegoTermino==0)
			{
				do
				{
					juegoTermino=juegoNuevo->terminarJuego(juegoNuevo->getJugadorA());
					if(juegoTermino==0)
					{
							puedeJugarSusFichas=juegoNuevo->buscarMinimoChance(juegoNuevo->getJugadorA());

							if(puedeJugarSusFichas==true) //en caso que tenga fichas para jugar entonces dara oportunidad al usuario de realizar una movida
							{
								bool yaHizoJugada=false; //este booleano se encarga de verificar que la jugada que el usuario realizo sea correcta
								do
								{		
										int f;
										char pos;
										do{
										cout<<"es el turno del jugador: "<<nombreHumano<<endl;
										cout<<"las fichas jugadas en la mesa son: ";
										cout<<endl;cout<<endl;
										juegoNuevo->getMesa()->imprimirMesa();
										cout<<endl;
										cout<<endl;cout<<endl;cout<<endl;
										cout<<"las fichas que ud posee son: "<<endl;
										juegoNuevo->getJugadorA()->imprimirLista();
										cout<<"digite el indice de la ficha que desea jugar: "<<endl;
									

										cin>>f;
										
										cout<<"digite 'i' si desea insertar la ficha seleccionada al inicio"<<endl;
										cout<<"digite 'f' si desea insertar la ficha seleccionada al final"<<endl;
									
										cin>>pos;
										system("pause");
										system("cls");
										}
										while(!juegoNuevo->getJugadorA()->comprobarSiEsta(f));
										yaHizoJugada = juegoNuevo ->checkPosibleColocacion(f, pos, juegoNuevo->getJugadorA());				
						
								}while(yaHizoJugada==false); 

								cout<<"la ficha ha sido colocada!"<<endl;
								juegoTermino=juegoNuevo->terminarJuego(juegoNuevo->getJugadorA());
								if(juegoTermino==1){juegoTermino=3;}
								cout<<"ahora es el turno del gran CPU"<<endl;

								system("pause");
								system("cls");
								quienInicia=juegoNuevo->siguienteJugada(quienInicia);	
							
				
							}
							/****************************************************************************************************************/
							else //aqui se procede a tomar del pozo una ficha aleatoria
							{
								cout<<"entre sus actuales fichas, no hay ficha con opcion alguna para realizar una jugada..."<<endl;
								cout<<"se procedera a tomar una ficha aleatoriamente del pozo de fichas..."<<endl;
								system("pause");
								system("cls");
								juegoNuevo->sacarDelPozo(juegoNuevo->getJugadorA());
								cout<<"se tomo una ficha del pozo!"<<endl;
								system("pause");

							
							}
					}
				}while(!puedeJugarSusFichas);
		
			}

			//este if es para verificar si se cerro el juego o termino y quien fue el ultimo en jugar
			if(juegoTermino==2){juegoTermino=4;}
			
		}

		//  FIN DE LA JUGADA HUMANA

		/**********************************************************************************************************************************************/

		//COMIENZO JUGADA I.A.

		else
		{
			if(quienInicia==0)
			{
				cout<<"las fichas en la mesa son..."<<endl;
				juegoNuevo->getMesa()->imprimirMesa();
										  

				juegoTermino = juegoNuevo->terminarJuego(juegoNuevo->getJugadorB());
				cout<<"es el turno de: "<<nombreCPU<<endl;
				system("pause");
				cout<<"el gran cerebro del CPU esta maquinando la jugada que realizara...."<<endl;
				system("pause");
				system("cls");
				if(juegoTermino == 0)
				{
					Ficha* aux=NULL;
					bool turnoValido=false;
					//aqui empieza el turno hasta que juegue
					bool decisionTomada = false;
					do
					{	
						if(juegoTermino==2){juegoTermino=6;}
						turnoValido = juegoNuevo->buscarMinimoChance(juegoNuevo->getJugadorB());
						if(turnoValido == true)
						{
							/*                        SECCION  ACTUALIZACION                           */ 
							/*         en esta seccion se actualizan los datos generales del juego en curso, tales como:
											las fichas que fueron colocadas en la ultima jugada, tambien se actualizan
											las variables locales que se utilizaran para los diferentes analisis de fichas 
												que se realizaran para escoger la ficha que sera colocada por el CPU			*/

							fichaMagica=juegoNuevo->getMesa()->tomarPuntas();
							Ficha *fichaRecorrido = NULL;			                                                                                                                    
							Nodo *aux = juegoNuevo->getJugadorB()->getPtrInicio();
							cout<<"el gran cerebro del CPU esta acercandose a una conclusion...."<<endl;
							system("pause");
							Lista *opcionDelTurno = new Lista();
							opcionDelTurno = juegoNuevo->getJugadorB();
							system("pause");
							Lista *lasQueFueronDescartadas = new Lista();
							Lista *posibilidadDoble = new Lista(); //iniciar en NULL

							/*                    ***+++ FIN DE LA SECCION ACTUALIZACION +++***                                   */


							/*                                SECCION ANALISIS "DE LAS DOBLES"                                     */
							/* SECCION PARA ANALISAR LAS FICHAS QUE PUEDEN SER COLOCADAS EN AMBOS EXTREMOS DEL JUEGO EN LA MESA ACTUAL
								UNA VEZ SELECCIONADAS ESTAS FICHAS, SERAN SEPARADAS PARA SER USADAS EN CASO QUE APARTE DE ESTAS MISMAS
									NO HAYA MAS OPCION PARA JUGAR EN EL TURNO ACTUAL, YA QUE, LAS FICHAS CON POSIBILIDAD DE SER JUGADAS
									EN AMBOS LADOS DEL JUEGO, TIENEN, POR ASI DECIRLO, UNA GARANTIA DE 2 TURNOS PARA SER JUGADAS
							*/
							do
							{
								if(
									((aux->getPtrFicha()->getLadoA()==fichaMagica->getLadoA()) ||
									(aux->getPtrFicha()->getLadoB()==fichaMagica->getLadoA()) ) &&
									((aux->getPtrFicha()->getLadoA()==fichaMagica->getLadoB()) ||
									(aux->getPtrFicha()->getLadoB()==fichaMagica->getLadoB()) )
								  )
								{
									fichaRecorrido=aux->getPtrFicha();
									fichaRecorrido=opcionDelTurno->copiarFicha(fichaRecorrido->getIndice());
									posibilidadDoble->insertarInicio(fichaRecorrido);
									aux = aux -> getPtrSig();
								}
								else 
								{
										aux = aux -> getPtrSig();
								}
					
	 
							}while(aux != NULL);

							/*                      ***+++    FIN DE LA SECCION ANALISIS "DE LAS DOBLES"   +++***                                */



							/*                                  SECCION PARA ELEGIR LA FICHA ADECUADA                                            */
							/*                                                   fase.A
															EN ESTA SECCION SE ANALISARAN LOS 2 "MEJORES" ESCENARIOS PARA
										                          ELEGIR LA FICHA ADECUADA PARA JUGAR EL TURNO ACTUAL

							DE ENTRE LAS FICHAS QUE QUEDARON RESTANTES, DESPUES DE HABER SEPARADO LAS OPCIONES "DOBLES",
							SE TOMARA LA FICHA CON EL LADO MAYOR Y SE INTENTARA JUGAR AL INICIO DE LA MESA, Y LUEGO INTENTARA JUGARLA AL FINAL
							EN CASO QUE NO CALZE EN NINGUNO DE LOS LADOS, SE DESCARTARA LA FICHA DE LAS OPCIONES PARA ANALISAR Y VOLVERA A TOMAR
							LA FICHA CON EL LADO MAYOR E INTENTARA COLOCARLA EN AMBOS HASTA QUE LOGRE COLOCAR UNA FICHA EN ALGUNO DE LOS LADOS

							*/
							fichaRecorrido=opcionDelTurno->extraerGrandeza();
							bool fichaValida =  false;
							char pos=' ';
							Ficha *fichaDescartada =NULL;
							do
							{
								pos='i';
								fichaValida=juegoNuevo->checkPosibleColocacion(fichaRecorrido->getIndice(), pos, juegoNuevo->getJugadorB());
								decisionTomada=fichaValida;
								if(fichaValida==false)
								{
									pos='f';
									fichaValida=juegoNuevo->checkPosibleColocacion(fichaRecorrido->getIndice(), pos, juegoNuevo->getJugadorB());
									decisionTomada=fichaValida;
								}

								if(fichaValida==false)
								{
									fichaDescartada = opcionDelTurno->sacarFicha(fichaRecorrido->getIndice());
									lasQueFueronDescartadas->insertarInicio(fichaDescartada);
								}

								if((fichaValida==false)&&(!opcionDelTurno->vacio()))
								{
									fichaRecorrido=opcionDelTurno->extraerGrandeza();
								}
					
							}while(!fichaValida);
							/*                                       FIN DE LA fase.A                                                      */
							/*                                           fase.B                                                             */
							/*                    si en la fase A, no se logro elegir una ficha de entre las que habian sido
									previamente separadas, entonces, se procedera a elegir nuevamente la ficha que tenga el lado mayor de
									la lista DE FICHAS DE POSIBILIDAD DOBLE que habian sido separadas al inicio, ... 
							     ...No se puede dar el caso que NO se de un resultado de eleccion en la primera fase Y que NO se de tampoco un
								 resultado en la faseB, de ser el caso que se presente un escenario para que esta sitacion se propicie, no
								 hubiera entrado al proceso de ejecutar movida pues la validacion del juego hubiera detenido el juego.
							*/

							if(decisionTomada==false)
							{
								fichaRecorrido=posibilidadDoble->extraerGrandeza();
								bool fichaValida =  false;
				
								Ficha *fichaDescartada =NULL;
								do
								{
									pos='i';
									fichaValida=juegoNuevo->checkPosibleColocacion(fichaRecorrido->getIndice(), pos, juegoNuevo->getJugadorB());
									decisionTomada=fichaValida;
									if(fichaValida==false)
									{
										pos='f';
										fichaValida=juegoNuevo->checkPosibleColocacion(fichaRecorrido->getIndice(), pos, juegoNuevo->getJugadorB());
										decisionTomada=fichaValida;
									}

									if(fichaValida==false)
									{
										fichaDescartada = posibilidadDoble->sacarFicha(fichaRecorrido->getIndice());
										juegoNuevo->getJugadorB()->insertarInicio(fichaDescartada);
									}

									if(fichaValida==false)
									{
										fichaRecorrido=opcionDelTurno->extraerGrandeza();
									}

								}while(!fichaValida);
							}	
								/*                                      +++++*** FIN fase.B ***+++++                                     */
							cout<<"el gran cerebro del CPU ya tomo la mejor decision de entre todas las opciones!"<<endl;
							system("pause");
							system("cls");
							juegoNuevo->getMesa()->imprimirMesa();
							/* en esta parte se nulifican las direcciones de las variables locales para ser usadas en los turnos proximos */
							posibilidadDoble=NULL;
							opcionDelTurno=NULL;
							lasQueFueronDescartadas=NULL;
		
						}

						else

						{

							juegoNuevo->sacarDelPozo(juegoNuevo->getJugadorB());
										cout<<"el cerebro del CPU tomo una ficha del pozo!"<<endl;
										system("pause");
										if(juegoNuevo->getPozo()->vacio())
										{
											juegoTermino = juegoNuevo->terminarJuego(juegoNuevo->getJugadorB());
											if(juegoTermino==2){juegoTermino=6;}
										}
						}


			
			
						juegoTermino = juegoNuevo->terminarJuego(juegoNuevo->getJugadorB());
						if(juegoTermino==1){juegoTermino=5;}
					
					}while(!decisionTomada);
				}
				quienInicia=juegoNuevo->siguienteJugada(quienInicia);
	

			}
		}

	


	}while(juegoTermino==0);   









	//**********************************************  FIN DEL JUEGO *************************************************************

	switch (juegoTermino)
	{
		case 3:
		{
			cout<<"Felicidades!"<<nombreHumano;
			cout<<"  ha ganado!"<<endl;
			break;
		}

		case 4:
		{
			int ptosJugA, ptosJugB;
			ptosJugA = juegoNuevo->getJugadorA()->sumarLista();
			ptosJugB = juegoNuevo->getJugadorB()->sumarLista();
			cout<<"los puntos obtenidos por ambos jugadores fueron: "<<endl;
			cout<<"el jugador: "<<nombreHumano<<"obtuvo"<<ptosJugA<<" puntos!"<<endl;
			cout<<"el jugador: "<<nombreCPU<<"obtuvo"<<ptosJugB<<" puntos!"<<endl;
			if(ptosJugA>ptosJugB)
			{
				cout<<"Felicidades!"<<nombreHumano;
				cout<<"  ha ganado!"<<endl;
			}
			else
			{
				if(ptosJugB>ptosJugA)
					{
						cout<<"el gran cerebro del CPU ha ganado!"<<endl;
					}

					else
					{
						cout<<"se ha llegado a un empate!"<<endl;
					}
			}
			break;
		}
	
		case 5:
			{
				cout<<"El"<<nombreCPU;
				cout<<"  ha ganado!"<<endl;
				break;
			}

		case 6:
		{
			int ptosJugA, ptosJugB;
			ptosJugA = juegoNuevo->getJugadorA()->sumarLista();
			ptosJugB = juegoNuevo->getJugadorB()->sumarLista();
			cout<<"los puntos obtenidos por ambos jugadores fueron: "<<endl;
			cout<<"el jugador: "<<nombreHumano<<"obtuvo"<<ptosJugA<<" puntos!"<<endl;
			cout<<"el jugador: "<<nombreCPU<<"obtuvo"<<ptosJugB<<" puntos!"<<endl;
			if(ptosJugA>ptosJugB)
			{
				cout<<"Felicidades!"<<nombreHumano;
				cout<<"  ha ganado!"<<endl;
			}
			else
			{
				if(ptosJugB>ptosJugA)
				{
					cout<<"el gran cerebro del CPU ha ganado!"<<endl;
				}

				else
				{
					cout<<"se ha llegado a un empate!"<<endl;
				}
			}
			break;
		}
		break;
	}


//EL FINAL DEL JUEGO

}







