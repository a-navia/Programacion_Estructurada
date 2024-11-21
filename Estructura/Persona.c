#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"

// Crear un estudiante estático

Estudiante est1(const char* nombre, int edad, double promedio) {
    Estudiante estudiante1;
    strcpy(estudiante1.nombre, nombre);
    estudiante1.edad = edad;
    estudiante1.promedio = (float)promedio;
    printf("\tEstudiante 1: %s, Edad: %d, Promedio: %.2f\n", estudiante1.nombre, estudiante1.edad, estudiante1.promedio);
    return estudiante1;
}

// Crear un estudiante dinámico
Estudiante* est2(const char* nombre, int edad, double promedio) {
    Estudiante* estudiante2 = (Estudiante*)malloc(sizeof(Estudiante));
    if (estudiante2 == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    strcpy(estudiante2->nombre, nombre);
    estudiante2->edad = edad;
    estudiante2->promedio = (float)promedio;
    printf("\tEstudiante 2: %s, Edad: %d, Promedio: %.2f\n", estudiante2->nombre, estudiante2->edad, estudiante2->promedio);
    return estudiante2;
}

// Mostrar un estudiante desde un puntero
void verEstudiante(Estudiante* ptr) {
    printf("\tEstudiante (desde puntero): %s, Edad: %d, Promedio: %.2f\n",
           ptr->nombre, ptr->edad, ptr->promedio);
}

// Crear un nodo para la lista
Nodo* crearNodo(const char* nombre, int edad, double promedio) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nuevoNodo->estudiante.nombre, nombre);
    nuevoNodo->estudiante.edad = edad;
    nuevoNodo->estudiante.promedio = (float)promedio;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Añadir un estudiante a la lista
void añadirEstudiante(Nodo** cabeza, const char* nombre, int edad, double promedio) {
    Nodo* nuevoNodo = crearNodo(nombre, edad, (float)promedio);
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

// Ver todos los estudiantes en la lista
void verEstLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("\t""Nombre: %s, Edad: %d, Promedio: %.2f\n",
               actual->estudiante.nombre, actual->estudiante.edad,
               actual->estudiante.promedio);
        actual = actual->siguiente;
    }
}

// Eliminar un estudiante de la lista
void eliminarEstudiante(Nodo** cabeza, const char* nombre) {
    Nodo* actual = *cabeza;
    Nodo* anterior = NULL;
    while (actual != NULL && strcmp(actual->estudiante.nombre, nombre) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL) {
        printf("Estudiante no encontrado.\n");
        return;
    }
    if (anterior == NULL) {
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    free(actual);
    printf("\t""Estudiante eliminado.\n");
}

// Liberar memoria de la lista
void liberarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    printf("\t""Memoria liberada.\n");
}
Estudiante copiarEstudiante(Estudiante original) {
    Estudiante copia;
    strcpy(copia.nombre, original.nombre);
    copia.edad = original.edad;
    copia.promedio = original.promedio;
    return copia;
}
void modificarEstudiante(Estudiante* estudiante, const char* nombre, int edad, double promedio) {
    strcpy(estudiante->nombre, nombre);
    estudiante->edad = edad;
    estudiante->promedio = (float)promedio;
}
void medianteDireccion(Estudiante* estudiante, const char* nombre, int edad, double promedio) {
    strcpy(estudiante->nombre, nombre);
    estudiante->edad = edad;
    estudiante->promedio = (float)promedio;
    printf("\tEstudiante modificado por direccion: %s, Edad: %d, Promedio: %.2f\n",
           estudiante->nombre, estudiante->edad, estudiante->promedio);
}
