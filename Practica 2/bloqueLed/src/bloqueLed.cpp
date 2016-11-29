#include <iostream>
#include <string>
#include "bloqueLed.h"

using namespace std;

typedef unsigned char bloqueLed;

//enciende el led pos del bloqueLedb.
void on(bloqueLed &b, int pos){

	unsigned char mask = 1 << pos;
	b = b | mask;

}

void off(bloqueLed &b, int pos){
	unsigned char mask = 1 << pos;
	mask=~mask;

	b = b & mask;
}

bool get(bloqueLed b, int pos){
	
	bool encendido = false;
	unsigned char mask = 1 << pos;
	
	if((b&mask)!=0)
		encendido=true;

	return encendido;
}

string bloqueLedToString(bloqueLed b){
	
	string bloqueLed;

	for(int i=0;i<8;i++)
		if(get(b,i))
			bloqueLed+="1";
		else
			bloqueLed+="0";

	return bloqueLed;
}

void encender(bloqueLed &b){
	b=0;
	b=~b;
}

void apagar(bloqueLed &b){
	b=0;
}

void asignar(bloqueLed &b, const bool v[]){
	
	for(int i=0;i<8;i++)
		if(v[i])
			on(b,i);
		else
			off(b,i);
}

void volcar(bloqueLed b, bool v[]){
	
	for(int i=0;i<8;i++)
		v[i]=get(b,i);
}

void encendidos(bloqueLed b, int posic[], int &cuantos){
	
	cuantos=0;
	for(int i=0;i<8;i++)
		if(get(b,i)){
			posic[cuantos]=i;
			cuantos++;
		}
}

void MostrarAnimacion1(){
	unsigned char b;
	
	encender(b);
    	cout << bloqueLedToString(b)<< endl;
    	for(int i=0;i<8;i++){
		off(b,i);
		cout << bloqueLedToString(b)<< endl;
		on(b,i);
    	}
}

void MostrarAnimacion2(){
	unsigned char b;
	encender(b);

	cout << bloqueLedToString(b)<< endl;
    	for(int i=0,j=7;i<8;i++,j--){
		if(i<j){
			off(b,i);
			off(b,j);
			cout << bloqueLedToString(b)<< endl;
		}
		else{
			on(b,i);
			on(b,j);
			cout << bloqueLedToString(b)<< endl;
		}
    	}
}
