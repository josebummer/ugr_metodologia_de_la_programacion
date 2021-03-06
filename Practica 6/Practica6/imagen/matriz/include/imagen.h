/**
@file
@brief Clase imagen blanco y negro.
*/

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include "lista.h"

typedef unsigned char byte; ///< byte = 8bits almacenado en un unsigned char

/**
@brief Una imagen en blanco y negro. Cada píxel es un byte
*/
class Imagen{
private:
   byte **m;        ///< puntero a matriz
   int nfilas; 			///< número de filas de la imagen
   int ncolumnas;		///< número de columnsa de la imagen
public:
/// Construye una imagen vacía (0 filas, 0 columnas)
   Imagen();


/**
@brief Construye una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Construye una imagen de tamaño @a filas x @a columnas y pone todos
sus elementos a 0.
*/
   Imagen(int filas, int columnas);


/**
@brief Crea una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Dimensiona la imagen a tamaño @a filas x @a columnas y pone todos
sus elementos a 0.
*/
   void crear(int filas, int columnas);


/**
@brief Devuelve el número de filas de las imagen
@return el número de filas de la imagen
*/
   int filas() const;


/**
@brief Devuelve el número de columnas de las imagen
@return el número de columnas de la imagen
*/
   int columnas() const;


/**
@brief Asigna el valor @a v a la posición (@a x,@a y) de la imagen
@param y 	fila de la imagen
@param x 	columna de la imagen
@param v 	valor a asignar

Asigna el valor @a v a la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x
del vector.
*/
   void set(int y, int x, byte v);


/**
@brief Devuelve el valor de la posición (@a x,@a y) de la imagen
@param y	 fila de la imagen
@param x	 columna de la imagen
@return el valor de la posición (@a x,@a y) de la imagen

Devuelve el valor de la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x
del vector.
*/
   byte get(int y, int x) const;


/**
@brief Asigna el valor @a v a la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector
@param v 	valor a asignar

Asigna el valor @a v a la posición @a i de la imagen considerada como vector. La posición @a i
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la
fila y @c x representa la columna.
*/
   void setPos(int i, byte v);


/**
@brief Devuelve el valor de la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector

Devuelve el valor de la posición @a i de la imagen considerada como vector. La posición @a i
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la
fila y @c x representa la columna.
*/
   byte getPos(int i) const;


/**
@brief Carga una imagen desde un fichero
@param nombreFichero nombre del fichero que contiene la imagen
@retval true 	si ha tenido éxito en la lectura
@retval false 	si se ha producido algún error en la lectura

Lee desde disco los datos de la imagen llamada @a nombreFichero y la guarda en la memoria. La función debe asegurarse de que la imagen es de un tipo de imagen conocido y de que su tamaño es menor del tamaño máximo permitido (@c MAXDATOS).
*/
   bool leerImagen(const char nombreFichero[]);


/**
@brief Guarda una imagen desde un fichero
@param nombreFichero nombre del fichero que contiene la imagen
@param esBinario toma el valor @c true si el fichero se escribe en formato binario o @c false en caso contrario.
@retval true 	si ha tenido éxito en la escritura
@retval false 	si se ha producido algún error en la escritura
*/
   bool escribirImagen(const char nombreFichero[], bool esBinario) const;

   Imagen plano(int k);

/**
  @brief Nos va a permitir pasandole un vector con distintos elementos crearnos la imagen con esos simbolos.
  @param grises contiene los elementos a convertir en la imagen
  @param arteASCIInombre del fichero que contiene los elementos
  @param maxlon numero maximo del tamaño de la imagen.
  @retval true 	si ha tenido éxito en la escritura
  @retval false 	si se ha producido algún error en la escritura
*/
    bool aArteASCII(const char grises[], char arteASCII[], int maxlong);

/**
  @brief destruye la estructura de la imagen y libera toda la memoria
*/
    void destruir();

/**
  @brief Nos va a permitir pasandole una Lista con distintos valores transformarlo a ficheros
  @param celdas es una Lista con varias celdas de elementos
  @retval true 	si ha tenido éxito en la escritura
  @retval false 	si se ha producido algún error en la escritura
*/
    bool listaAArteASCII(const Lista celdas);

/**
  @brief Destructor de la clase
*/
    ~Imagen();

/**
  @brief Constructor de copia de Imagen.
  @param img Imagen de la que copiaremos el contenido
*/
    Imagen(const Imagen &img);

/**
  @brief Operador = de la imagen; nos igualara dos imagenes.
  @param otra_imagen es la imagen que contiene el contenido y que copiaremos a la otra imagen.
*/
    Imagen& operator=(const Imagen &otra_imagen);

/**
  @brief Operador + que nos permitira sumar dos imagenes en 1 sola
  @param otra_imagen es la imagen a sumar con la interna de la clase.
*/
    Imagen operator+(const Imagen &otra_imagen)const;
};

#endif
