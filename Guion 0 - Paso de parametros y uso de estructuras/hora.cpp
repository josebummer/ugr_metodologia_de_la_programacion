/*
Defina una estructura para representar un instante de tiempo. Debe
almacenar horas (entre 0 y 23), minutos (entre 0 y 59) y segundos (entre
0 y 59). Posteriormente defina las siguientes funciones:
- esPosterior.
- convertir ASegundos.
- obtenerNuevoTiempo.
*/

#include <iostream>
#include <string>

using namespace std;

struct Tiempo{

	int horas;
	int minutos;
	int segundos;
};

void LeerEntero(int &valor){

	do{
	cout << "Indique ahora un numero de segundos para sumarselos al primer instante: ";
	cin >> valor;
	}while(valor<1);

}

void LeerHoras(int &hora){
	
	do{
		cout << "Introduce el numero de horas: ";
		cin >> hora;
	}while(hora<0 || hora>23);

}

void LeerMinutosYSegundos(int &valor, const string &PREGUNTA){

	do{
		cout << "Introduce el numero de " << PREGUNTA << ": ";
		cin >> valor;
	}while(valor<0 || valor>59);

}

void esPosterior(const Tiempo &a, const Tiempo &b, bool &posterior){
/*
Dados dos instantes de tiempo devuelve true si el se-
gundo instante es posterior al primero y false en caso contrario.
*/
	posterior=false;
	
	if(b.horas>a.horas){
		posterior=true;
	}
	else if(b.horas==a.horas){
		if(b.minutos>a.minutos){
			posterior=true;
		}
		else if(b.minutos==a.minutos){
			if(b.segundos>a.segundos){
				posterior=true;
			}
		}
	}

	/*if(convertirASegundos(a,ensegundos)<convertirASegundos(b,ensegundos))
	posterior=true;
	*/
}

void convertirASegundos(const Tiempo &a, int &ensegundos){
/*
transforma el instante de tiempo dado, a un
valor en segundos. Por ejemplo, si tenemos 1 hora, 1 minuto y 3
segundos, deber ́ıa devolver 3663 segundos.
*/
	
	ensegundos=(a.horas*3600)+(a.minutos*60)+a.segundos;
	
}

void obtenerNuevoTiempo(const Tiempo &t, int s, Tiempo &t2){
/*
Dados un instante de tiempo T y un valor
entero S (que representa una cantidad de segundos), devuelva un
nuevo instante de tiempo T 2 que represente la suma de S segundos
a T . Los valores de T 2 deben estar en los intervalos correctos.
*/

	t2=t;

	t2.segundos+=s;
	
	if(t2.segundos>60){
		t2.minutos+=t2.segundos/60;		
		t2.segundos=t2.segundos%60;		
		
		if(t2.minutos>60){
			t2.horas+=t2.minutos/60;		
			t2.minutos=t2.minutos%60;
		}
	}

}

void MostrarTiempo(const Tiempo &t){

	cout << "HORAS: " << t.horas << ", MINUTOS: " << t.minutos << ", SEGUNDOS: " << t.segundos << "." << endl;

}

int main(){

	Tiempo t, t2, t3;
	string M="minutos", S="segundos";
	bool posterior;
	int ensegundos;

	LeerHoras(t.horas);
	LeerMinutosYSegundos(t.minutos,M);
	LeerMinutosYSegundos(t.segundos,S);

	cout << endl << "Introduce otro instante para comparlos:" << endl;

	LeerHoras(t2.horas);
	LeerMinutosYSegundos(t2.minutos,M);
	LeerMinutosYSegundos(t2.segundos,S);

	esPosterior(t,t2,posterior);
	
	if(posterior)
		cout << "El segundo instante es posterior al primero." << endl;
	else
		cout << "El segundo instante NO es posterior al primero." << endl;
	
	convertirASegundos(t,ensegundos);
	cout << "El valor del primer instante en segundos es: " << ensegundos << endl;
	
	convertirASegundos(t2,ensegundos);
	cout << "El valor del segundo instante en segundos es: " << ensegundos << endl;
	
	LeerEntero(ensegundos);
	obtenerNuevoTiempo(t,ensegundos,t3);

	cout << "Al sumarle al instante uno " << ensegundos << " segundos, se nos ha quedado este instante: " << endl;
	MostrarTiempo(t3); 
	


}
