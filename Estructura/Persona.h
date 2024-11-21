#ifndef PERSONA_H
#define PERSONA_H

typedef struct {
    char nombre[50];
    int edad;
    float promedio; //float a double en las declaraciones para evitar clang-tidy warning
} Estudiante;

typedef struct Nodo {
    Estudiante estudiante;
    struct Nodo* siguiente;
} Nodo;

//prototipos
Estudiante est1(const char* nombre, int edad, double promedio);
Estudiante* est2(const char* nombre, int edad, double promedio);
Estudiante copiarEstudiante(Estudiante original);
Nodo* crearNodo(const char* nombre, int edad, double promedio);
//voids
void verEstudiante(Estudiante* ptr);
void añadirEstudiante(Nodo** cabeza, const char* nombre, int edad, double promedio);
void verEstLista(Nodo* cabeza);
void eliminarEstudiante(Nodo** cabeza, const char* nombre);
void liberarLista(Nodo* cabeza);
void modificarEstudiante(Estudiante* estudiante, const char* nombre, int edad, double promedio);
void medianteDireccion(Estudiante* estudiante, const char* nombre, int edad, double promedio);

#endif // PERSONA_H
