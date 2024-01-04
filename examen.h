#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
#define TAM 1024

char* obtenerFrase(char* frase);
void procesarFrases(char Mat[][TAM], size_t, char * obtenerFrase(char *), int cmp(int, int));
int compararLongitud(int, int);
void imprimirFrases(char Mat[][TAM], size_t);
int insertarOrdenado1(char Mat[][TAM], size_t, size_t, size_t, void *);

#endif // EXAMEN_H_INCLUDED
