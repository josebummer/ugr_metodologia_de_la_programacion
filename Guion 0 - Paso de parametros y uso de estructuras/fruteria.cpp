#include <iostream>
#include <string>

using namespace std;

struct Producto{
	string nombre;
	int peso; //en gramos
	float precio_kg;	
};

struct Compra{
	static const int MAX=10;
	Producto lista[MAX];
};

//funcion para devolver los datos de un prodcuto como un string.
string productoToString(const Producto &a){

	string rta;

	rta=a.nombre+"\t\t"+to_string(a.peso)+"\t"+to_string(a.precio_kg);
	
	return rta;

}

//crea una variable de tipo Producto y la devuelve
Producto creaProducto(const string &nombre, int peso, float precio){
	Producto a;

	a.nombre=nombre;
	a.peso=peso;
	a.precio_kg=precio;
	
	//p = {nombre, peso, precio};
	
	return a;
}

//incrementa el precio de cada producto en un k %
void incrementarPrecios(Compra &c, int k){
	for(int i=0;i<c.MAX;i++)
		c.lista[i].precio_kg+=c.lista[i].precio_kg*k/100.0;
}

//muestra el listado de productos comprados
void listarCompra(const Compra &c){
	for(int i=0;i<c.MAX;i++){
		cout << productoToString(c.lista[i]) << endl;
	}
}

//funcion que devuelve el importe total de la compra (sinIVA) y su peso
void obtenerImporteYPeso(const Compra &c, float &precio, int &peso){
	precio=0.0;
	peso=0;

	for(int i=0;i<c.MAX;i++){
		peso+=c.lista[i].peso;
		precio+=(c.lista[i].peso*c.lista[i].precio_kg)/1000.0;
	}
	peso/=1000;	
}

//funcion que muestra el "ticket" de compra segun el formato sugerido
void mostrarTicketCompra(const Compra &c){
	float subtotal,IVA;
	int aux;

	obtenerImporteYPeso(c,subtotal,aux);
	listarCompra(c);
	
	cout << "Subtotal: \t\t" << subtotal << endl;
	
	IVA=subtotal*0.21;
	cout << "IVA (21%): \t\t" << IVA << endl;

	cout << "Total de la compra: \t" << subtotal+IVA << endl;
}

int main(){
	const int TAM = 10;
	Producto actual;
	Compra mi_compra;
	float precio;
	int peso;
	string nombre;

	for(int i = 0; i < TAM; i++)
	{
		cin >> nombre >> peso >> precio;
		mi_compra.lista[i] = creaProducto(nombre, peso, precio);
	}
	// se muestra la lista de productos.
	cout << "\n ******** Prueba de funcion listarCompra ******** \n";
	listarCompra(mi_compra);
	// se muestra el importe total de la compra y el peso
	cout << "\n ******** Prueba de funcion obtenerImporteYPeso ******** \n";
	obtenerImporteYPeso(mi_compra, precio, peso);
	cout << "\nEl importe de la compra es: " << precio << ", su compra pesa:" << peso << " Kg. " << endl;
	// se muestra el ticket de la compra.
	cout << "\n ******** Prueba de la funcion mostrarTicketCompra ******** \n";
	mostrarTicketCompra(mi_compra);
	cout << "\n ******** Prueba de la funcion incrementarPrecio ********";
	incrementarPrecios(mi_compra, 10);
	cout << "\n ******** y listarCompra de nuevo\t\t********\n\n";
	listarCompra(mi_compra);
	return(0);
}
