#include <stdio.h>
#include "examen.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void procesarFrases(char Mat[][TAM], size_t ce, char * obtenerFrase(char *), int cmp(int, int)){
    char frase[TAM];
    int tamMayor, tamSiguiente, i = 0, j, regInsert; // tamMayor: siempre guardar� la cantidad de caracteres que contiene la cadena considerada de mayor longitud;   tamSiguiente: ir� registrando la cant. de caracts. que contiene la siguiente cadena obtenida.   i: regular� cant. de elementos asignados a la matriz;
    while(obtenerFrase(frase)) {
        tamSiguiente = strlen(frase);
        j = 0;
        regInsert = 1; // ' regInsert ' ayudar� a dectectar cu�ndo se realiz�n una inserci�n (sea limpia o sucia), as� terminar el ciclo y no generar redundancia/otros errores
        while((j < i) && regInsert) {
            tamMayor = strlen(Mat[j]);
            if(cmp(tamMayor, tamSiguiente) < 0) {
                if(insertarOrdenado1(Mat, j, i, ce, frase)) { i++; } // ' insertarOrdenado ' devolver� 1 si es inserci�n limpia (ende corresponde sumar un elemento), caso contrario 0;
                regInsert = 0; // sea cualquiera el tipo de inserci�n que se haya hecho, debemos terminar el ciclo para ambos casos, as� evitar lo mencionado en la l�nea 13
            }
            j++; }
        if((i < ce) && regInsert) { strcpy(Mat[i], frase); i++; } // No lo inclu�mos en el while ya que no verificar�amos todos los casos posibles
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

int insertarOrdenado1(char Mat[][TAM], size_t pos, size_t ce, size_t max, void *nuevo) { // Obs: 1) ' ce ' es la cantidad actual registrada de elementos en la Mat, mientras que ' max ' es la capacidad m�xima de la Mat ; 2) No hace falta regular la posici�n enviada ya que ese �ndice ' pos ', enviado desde el ciclo donde se llama esta fn., se corresponde a la posici�n correcta del elemento en la Mat (distinto es si solicitamos al usuario que nos indique una posici�n, lo l�gico es que env�e por ejemplo ' 1 ' -quiere ponerlo en primer lugar-, entonces el �ndice deber�a ser 1 - 1 [este �ltimo 1 ya que la pos. del 1er elemento es 0]) ; 3) el puntero ' nuevo ' se trata como gen�rico ya que el enunciado menciona "se valora positivamente el manejo gen�rico"
    int i = 0, ant = ce-1, act = ce, cantCamb = ce - pos, r = 1;
    if(act == max) {  // si llegamos a la capacidad m�xima de elementos, entonces comenzaremos a realizar inserciones ' sucias ', por lo cual debemos ajustar �ndices ya que no tenemos ese siguiente espacio disponible (al cual acced�amos f�cilmente con solo asignar ' ce ', ya que la cantidad de elementos que se registra siempre lleva una unidad de diferencia con respecto a las posiciones de los elementos) "por defecto"
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
