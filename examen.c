#include <stdio.h>
#include "examen.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void procesarFrases(char Mat[][TAM], size_t ce, char * obtenerFrase(char *), int cmp(int, int)){
    char frase[TAM];
    int tamMayor, tamSiguiente, i = 0, j, regInsert; // tamMayor: siempre guardará la cantidad de caracteres que contiene la cadena considerada de mayor longitud;   tamSiguiente: irá registrando la cant. de caracts. que contiene la siguiente cadena obtenida.   i: regulará cant. de elementos asignados a la matriz;
    while(obtenerFrase(frase)) {
        tamSiguiente = strlen(frase);
        j = 0;
        regInsert = 1; // ' regInsert ' ayudará a dectectar cuándo se realizón una inserción (sea limpia o sucia), así terminar el ciclo y no generar redundancia/otros errores
        while((j < i) && regInsert) {
            tamMayor = strlen(Mat[j]);
            if(cmp(tamMayor, tamSiguiente) < 0) {
                if(insertarOrdenado1(Mat, j, i, ce, frase)) { i++; } // ' insertarOrdenado ' devolverá 1 si es inserción limpia (ende corresponde sumar un elemento), caso contrario 0;
                regInsert = 0; // sea cualquiera el tipo de inserción que se haya hecho, debemos terminar el ciclo para ambos casos, así evitar lo mencionado en la línea 13
            }
            j++; }
        if((i < ce) && regInsert) { strcpy(Mat[i], frase); i++; } // No lo incluímos en el while ya que no verificaríamos todos los casos posibles
    }

}

int compararLongitud(int cantprimera, int cantsegunda) { // si:  a < b => retorna nro. < 0 ; a == b => retorna 0 ; a > b => retorna nro. > 0
    return cantprimera - cantsegunda;
}

void imprimirFrases(char Mat[][TAM], size_t ce) {
    int i = 0;
    while(i < ce) {
        printf("%s\n", Mat[i]);
        i++;
    }
}

int insertarOrdenado1(char Mat[][TAM], size_t pos, size_t ce, size_t max, void *nuevo) { // Obs: 1) ' ce ' es la cantidad actual registrada de elementos en la Mat, mientras que ' max ' es la capacidad máxima de la Mat ; 2) No hace falta regular la posición enviada ya que ese índice ' pos ', enviado desde el ciclo donde se llama esta fn., se corresponde a la posición correcta del elemento en la Mat (distinto es si solicitamos al usuario que nos indique una posición, lo lógico es que envíe por ejemplo ' 1 ' -quiere ponerlo en primer lugar-, entonces el índice debería ser 1 - 1 [este último 1 ya que la pos. del 1er elemento es 0]) ; 3) el puntero ' nuevo ' se trata como genérico ya que el enunciado menciona "se valora positivamente el manejo genérico"
    int i = 0, ant = ce-1, act = ce, cantCamb = ce - pos, r = 1;
    if(act == max) {  // si llegamos a la capacidad máxima de elementos, entonces comenzaremos a realizar inserciones ' sucias ', por lo cual debemos ajustar índices ya que no tenemos ese siguiente espacio disponible (al cual accedíamos fácilmente con solo asignar ' ce ', ya que la cantidad de elementos que se registra siempre lleva una unidad de diferencia con respecto a las posiciones de los elementos) "por defecto"
        r = 0;
        cantCamb = (ce - 1) - pos;
        act = ce - 1;
        ant = ce - 2;
    }
    while(i < cantCamb) {
        strcpy(Mat[act], Mat[ant]);
        act--;
        ant--;
        i++;
    }
    strcpy(Mat[pos], (char*)nuevo);
    return r;
}
