#include<iostream>
using namespace std;

struct nodo{
	int dato;
	nodo* siguiente;
	nodo* atras;
	
}*primero=NULL, *ultimo=NULL;

void insertNodoF();
void insertNodoP();
void desplegarListaPU();
void desplegarListaUP();
void insertarPosicion(int posicion, int numero);
void mayor();
void sumatorio();
void ordenada();

int main(){
	
	int op=1;
	
	
	while(op!=0){
		cout<<"\nElija la opcion que desea hacer: ";
		cin>>op;
		switch (op){
		case 1: desplegarListaPU();
		break;
		case 2: insertNodoF();
		break;
		case 3: insertNodoP();
		break;
		case 4: cout<<"Introduce la posicion en la que deseas meter el numero";
			 	
	 			int posicion;
			 	cin>>posicion;
			 	cout<<"Introduce el numero";
			 	int numero;
			 	cin>>numero;
			 	insertarPosicion(posicion,numero);
			 	break;
			 	
		case 5: mayor();
		break;
		case 6: sumatorio();
		break;
		case 7: ordenada();
		break;
	}
		
	}
		
			
	
	
}

void insertNodoF(){
	nodo *nuevo= new nodo();
	cout<<"\nIngrese el numero: ";
	cin>>nuevo->dato;
	
	//declarar la cabeza de la lista
	if(primero==NULL){
		primero=nuevo;
		primero->siguiente=NULL;
		primero->atras=NULL;
		
		ultimo=primero;
	}else{
		ultimo->siguiente=nuevo;
		nuevo->siguiente=NULL;
		nuevo->atras=ultimo;//para apuntar atras
		
		ultimo=nuevo;
	}
	
	cout<<"\n -----------------------Nodo ingresado---------------------------\n";
	
	
}

void insertNodoP(){
	nodo *nuevo= new nodo();
	cout<<"\nIngrese el numero: ";
	cin>>nuevo->dato;
	
	//declarar la cabeza de la lista
	if(primero==NULL){
		primero=nuevo;
		primero->siguiente=NULL;
		primero->atras=NULL;
		
		ultimo=primero;
	}else{
		primero->atras=nuevo;
		nuevo->siguiente=primero;
		nuevo->atras=NULL;
		
		primero=nuevo;
	}
	
	cout<<"\n -----------------------Nodo ingresado---------------------------\n";
	
	
}

void desplegarListaPU(){
	nodo *actual= new nodo();
	actual=primero;
	
	if(primero==NULL){
		cout<<"/n la lista esta vacia/n";
	}else{
		
		while(actual!=NULL){
			cout<<"\n"<<actual->dato;
			actual=actual->siguiente;
			
		}
	}
	
}

void desplegarListaUP(){
	nodo *actual= new nodo();
	
	actual=ultimo;
	
	if(actual==NULL){
		cout<<"/n la lista esta vacia/n";
	}else{
		while(actual!=NULL){
			cout<<"\n"<<actual->dato;
			actual=actual->atras;
		}
	}
}

void mayor(){
	int mayor=0;
	int cont=0;
	
	nodo *actual= new nodo();
	
	actual=primero;

	
	if(primero==NULL){
		cout<<" La lista esta vacia";
	}else{
		
		while(actual!=NULL){
			if(actual->dato>=mayor){
				mayor=actual->dato;
				
			}
			actual=actual->siguiente;
			
		}
		actual=primero;
		
		while(actual!=NULL){
			if(actual->dato==mayor){
				cont++;
				
			}
			actual=actual->atras;
			
		}
		
 		cout<<"El numero mayor es: "<<mayor<<" y se repite: "<<cont<<" veces";

	}
		

	
}
	
void sumatorio(){
	nodo *actual= new nodo();
	actual=primero;
	int sumatorio=0;
	
	if(primero==NULL){
		cout<<"/n la lista esta vacia/n";
	}else{
		
		while(actual!=NULL){
			sumatorio=sumatorio+actual->dato;
			actual=actual->siguiente;
			
		}
		cout<<" La suma de todos los digitos es: "<<sumatorio;
	}
}	

void ordenada(){
	//TODO: buenos dias
	
	nodo *actual= new nodo();//el actual
	nodo *reves= new nodo();//el siguente
	actual=primero;
	reves=ultimo;
	bool estaOrdenado=false;
		
	
	while(actual!=NULL){
		int v1=actual->dato;
		int v2=reves->dato;
		bool estaOrdenada=true;
		
		if(v1=v2){
			cout<<"-------";
			cout<<"No esta ordenada";
			estaOrdenado=false;
			break;
		}
	}
	
	if(estaOrdenado==true){
		cout<<"Esta ordenada";
	}
	
	
	
	
}

void insertarPosicion(int posicion, int numero){
	nodo *actual= new nodo();
	nodo *nuevo= new nodo();
	nodo *actuals= new nodo();
	int cent=0;
	int cont=2;
	actual=primero;
	if(primero==NULL){
		cout<<"/n la lista esta vacia/n";
	}else{
		
		while((actual!=NULL)){
			
			if(cont==posicion){
				nuevo->dato=numero;
				actuals=actual->siguiente;
				actual->siguiente=nuevo;
				nuevo->atras=actual;
				nuevo->siguiente=actuals;
				actuals->atras=nuevo;
				
				break;
			}
			actual=actual->siguiente;
		 	cont++;
			
		}
	}
	
}
