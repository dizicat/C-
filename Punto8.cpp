#include<iostream>
#include<stdlib.h>
using namespace std;
//definicion de estructuras
typedef struct tnodo *pnodo;
typedef struct tnodo{
					int dato;
					pnodo ant;
					pnodo sig;
			};
typedef struct tlista{
					pnodo inicio;
					pnodo fin;
				};			
//prototipos de funciones y procedimientos
void menu(int &op);
void iniciar(tlista &lis);
void crear_nodo(pnodo &nuevo);
void agregar_final(tlista &lis, pnodo nuevo);
pnodo quitar_nodo(tlista &lis, int valor);
void mostrar(tlista lis);
void mayor_dato(tlista lis);
void liberar(tlista &lis);
main()
{//variables
	tlista lista;
	pnodo aux,nuevo;
	int numero, op;
	iniciar(lista);
	do
	{
		system("cls");
		menu(op);
		switch(op){
			case 1:	cout<<"agregar elemento"<<endl;
					
					crear_nodo(nuevo);
					agregar_final(lista,nuevo);						
					break;
			case 2:	
					cout<<"El mayor dato de la lista:"<<endl;
					mayor_dato(lista);
											
					break;
			case 3:	cout<<"elementos de la lista"<<endl;
					//if(lista_vacia(lista)==false)
						mostrar(lista);
			
					break;
			case 4:	cout<<"Fin del programa"<<endl;
					//liberar(lista);
			default:	cout<<"opcion incorrecta"<<endl;															
		}
		system("pause"); 
	}while(op!=4);
	system("pause");
}
//procedimientos y funciones
 void menu(int &op)
 {
 	cout<<"*********MENU***********"<<endl;
 	cout<<"1-agregar un elemento"<<endl;
 	cout<<"2-quitar un elemento"<<endl;
 	cout<<"3-mostrar elementos de la lista"<<endl;
 	cout<<"4-salir del programa"<<endl;
 	cout<<"elegir opcion"<<endl;
 	cin>>op;
 }


void iniciar(tlista &lis)
{
	lis.inicio=NULL;
	lis.fin=NULL;
}
void crear_nodo(pnodo &nuevo)
{
//	pnodo variable;
//	pnodo corroboracion;
	//pnodo c;
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"ingrese valor";
		cin>>nuevo->dato;
		
	
		if(nuevo->ant<nuevo->sig)
			{	
				cout<<"prueba1"<<endl;
			}
			else
			{
				//cout<<"error"<<endl;
				delete(nuevo->sig);				
			}
				
			
			
		nuevo->sig=NULL;
		nuevo->ant=NULL;
	}
}
void agregar_final(tlista &lis, pnodo nuevo)
{
	if(lis.inicio==NULL)
	{
		lis.inicio=nuevo;
		lis.fin=nuevo;
		
	}
	else 								//orden descendente
	{	
				
				nuevo->ant=lis.fin;
				lis.fin->sig=nuevo;
				lis.fin=nuevo;
	}	
	lis.inicio->ant=lis.fin;
	lis.fin->sig=lis.inicio;
}
pnodo quitar_nodo(tlista &lis, int valor)
{
	pnodo p, aux;
	if(lis.inicio==NULL)
		aux=NULL;
	else
		if(lis.inicio==lis.fin)	//unico elemento
			{if(lis.inicio->dato==valor)	//si es el elemento?
			{
				aux=lis.inicio;
				lis.inicio=NULL;
				lis.fin=NULL;
			}
			else
				aux=NULL;
			}
		else		//varios elementos
		{
			if(lis.inicio->dato==valor)
			{
				aux=lis.inicio;
				lis.inicio=aux->sig;
				lis.inicio->ant=lis.fin;
				lis.fin->sig=lis.inicio;
				aux->sig=NULL;
				aux->ant=NULL;
			}
			else
				if(lis.fin->dato==valor)
				{
					aux=lis.fin;
					lis.fin=aux->ant;
					lis.inicio->ant=lis.fin;
					lis.fin->sig=lis.inicio;
					aux->sig=NULL;
					aux->ant=NULL;
					
				}	
				else	
				{
					for(p=lis.inicio->sig;p!=lis.fin && p->dato!=valor;p=p->sig);
					if(p==lis.fin)
						aux=NULL;
					else
						{aux=p;
							(p->ant)->sig=p->sig=aux->sig;
							(p->sig)->ant=aux->ant;
							aux->sig=NULL;
							aux->ant=NULL;
						}
						
						
				}
		}
		return aux;
}
void mostrar(tlista lis)
{
	pnodo p;
	if(lis.inicio==NULL)
		cout<<"lista vacia"<<endl;
	else
		{for(p=lis.inicio;p!=lis.fin;p=p->sig)
			cout<<p->dato<<endl;
		cout<<p->dato<<endl;}		
}

void mayor_dato(tlista lis)
{
	pnodo mayor, p;
	if(lis.inicio != NULL)
		{
			mayor=lis.inicio;
			for(p=lis.inicio->sig;p!=lis.fin;p=p->sig)
				if(p->dato>mayor->dato)
					mayor=p;
			mostrar(mayor->dato);						//here
				
		}
		else
			cout<<"no hay registros"<<endl;
}

void liberar(tlista &lis);

