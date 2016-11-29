#include<iostream>
#include<string>

using namespace std;

struct Producto
{
    string nombre;
    int peso; // en gramos
    float precio_kg;
};

struct Compra
{
    static const int MAX = 10;
    Producto lista[MAX];
};

// función para devolver los datos de un producto como un string
string productoToString(Producto a)
{
    string rta;
    rta = a.nombre + "\t\t" + to_string(a.peso) + "\t" + to_string(a.precio_kg);
    return rta;
}

// PARA COMPLETAR
// crea una variable de tipo Producto y la devuelve
Producto creaProducto(string nombre, int peso, float precio)
{
    Producto p;
    p = {nombre, peso, precio};
    return p;
}


// PARA COMPLETAR
// incrementa el precio de cada producto en un k %
void incrementarPrecios(Compra & c, int k)
{
    int i;
    float np;
    for(i = 0; i < c.MAX; i++)
    {
        np = c.lista[i].precio_kg;
        np = np + (np * k / 100.0);
        c.lista[i].precio_kg = np;
    }
}

// PARA COMPLETAR
// muestra el listado de productos comprados
void listarCompra(const Compra & c)
{
    for(int i = 0; i < c.MAX; i++)
        cout << productoToString(c.lista[i]) << endl;
}


// PARA COMPLETAR
// función que devuelve el importe total de la compra (sinIVA) y su peso (en kgs)
void obtenerImporteYPeso(const Compra & c, float & precio, int & peso)
{
    precio = 0;
    peso = 0;
    Producto actual;
    for(int i = 0; i < c.MAX; i++)
    {
        actual = c.lista[i];
        peso = peso + actual.peso;
        precio = precio + (actual.peso * actual.precio_kg) / 1000.0;
    }
    peso = peso / 1000.0;
}

// PARA COMPLETAR
// función que muestra el "ticket" de compra según el formato sugerido
void mostrarTicketCompra(const Compra & c)
{
    float total, iva;
    int aux;

    obtenerImporteYPeso(c, total, aux);
    listarCompra(c);

    cout << "Subtotal: \t\t" << total << endl;
    iva = total * 0.21;
    cout << "IVA (21%): \t\t" << iva << endl;
    cout << "Total de la compra: \t" << total + iva << endl;
}


int main()
{
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
    cout << "\nEl importe de la compra es: " << precio << ", su compra pesa:" 
		 << peso << " Kg. " << endl;

    // se muestra el ticket de la compra.
    cout << "\n ******** Prueba de la funcion mostrarTicketCompra ******** \n";
    mostrarTicketCompra(mi_compra);

    cout << "\n ******** Prueba de la funcion incrementarPrecio ********";
    incrementarPrecios(mi_compra, 10);
    cout << "\n ******** y listarCompra de nuevo   \t\t********\n\n";
    listarCompra(mi_compra);

    return(0);
}

 
