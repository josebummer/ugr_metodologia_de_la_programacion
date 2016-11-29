#include <iostream>
#include <string>
#include "byte.h"

using namespace std;

typedef unsigned char byte;

//enciende el led pos del bloqueLedb.
void on(byte &b, int pos){

	unsigned char mask = 1 << pos;
	b = b | mask;

}

void off(byte &b, int pos){
	unsigned char mask = 1 << pos;
	mask=~mask;

	b = b & mask;
}

bool getbit(byte b, int pos){

	bool encendido = false;
	unsigned char mask = 1 << pos;

	if((b&mask)!=0)
		encendido=true;

	return encendido;
}

string byteToString(byte b){

	string byte;

	for(int i=0;i<8;i++)
		if(getbit(b,i))
			byte+="1";
		else
			byte+="0";

	return byte;
}

void encender(byte &b){
	b=0;
	b=~b;
}

void apagar(byte &b){
	b=0;
}

void asignar(byte &b, const bool v[]){

	for(int i=0;i<8;i++)
		if(v[i])
			on(b,i);
		else
			off(b,i);
}

void volcar(byte b, bool v[]){

	for(int i=0;i<8;i++)
		v[i]=getbit(b,i);
}

void encendidos(byte b, int posic[], int &cuantos){

	cuantos=0;
	for(int i=0;i<8;i++)
		if(getbit(b,i)){
			posic[cuantos]=i;
			cuantos++;
		}
}

void MostrarAnimacion1(){
	unsigned char b;

	encender(b);
    	cout << byteToString(b)<< endl;
    	for(int i=0;i<8;i++){
		off(b,i);
		cout << byteToString(b)<< endl;
		on(b,i);
    	}
}

void MostrarAnimacion2(){
	unsigned char b;
	encender(b);

	cout << byteToString(b)<< endl;
    	for(int i=0,j=7;i<8;i++,j--){
		if(i<j){
			off(b,i);
			off(b,j);
			cout << byteToString(b)<< endl;
		}
		else{
			on(b,i);
			on(b,j);
			cout << byteToString(b)<< endl;
		}
    	}
}
