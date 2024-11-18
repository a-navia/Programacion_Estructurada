#ifndef PERSONA_H
#define PERSONA_H

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

typedef struct Nodo {
    Estudiante estudiante;
    struct Nodo* siguiente;
} Nodo;

// Prototipos de funciones
Estudiante est1(const char* nombre, int edad, float promedio);
Estudiante* est2(const char* nombre, int edad, float promedio);
void verEstudiante(Estudiante* ptr);
Nodo* crearNodo(const char* nombre, int edad, float promedio);
void añadirEstudiante(Nodo** cabeza, const char* nombre, int edad, float promedio);
void verEstudiantes(Nodo* cabeza);
void eliminarEstudiante(Nodo** cabeza, const char* nombre);
void liberarLista(Nodo* cabeza);

#endif // PERSONA_H
