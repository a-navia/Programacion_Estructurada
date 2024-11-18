#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"

// Crear un estudiante estático
Estudiante est1(const char* nombre, int edad, float promedio) {
    Estudiante estudiante1;
    strcpy(estudiante1.nombre, nombre);
    estudiante1.edad = edad;
    estudiante1.promedio = promedio;
    return estudiante1;
}

// Crear un estudiante dinámico
Estudiante* est2(const char* nombre, int edad, float promedio) {
    Estudiante* estudiante2 = (Estudiante*)malloc(sizeof(Estudiante));
    if (estudiante2 == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    strcpy(estudiante2->nombre, nombre);
    estudiante2->edad = edad;
    estudiante2->promedio = promedio;
    return estudiante2;
}

// Mostrar un estudiante desde un puntero
void verEstudiante(Estudiante* ptr) {
    printf("Estudiante (desde puntero): %s, Edad: %d, Promedio: %.2f\n",
           ptr->nombre, ptr->edad, ptr->promedio);
}

// Crear un nodo para la lista
Nodo* crearNodo(const char* nombre, int edad, float promedio) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nuevoNodo->estudiante.nombre, nombre);
    nuevoNodo->estudiante.edad = edad;
    nuevoNodo->estudiante.promedio = promedio;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Añadir un estudiante a la lista
void añadirEstudiante(Nodo** cabeza, const char* nombre, int edad, float promedio) {
    Nodo* nuevoNodo = crearNodo(nombre, edad, promedio);
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

// Ver todos los estudiantes en la lista
void verEstudiantes(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("Nombre: %s, Edad: %d, Promedio: %.2f\n",
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
    printf("Estudiante eliminado.\n");
}

// Liberar memoria de la lista
void liberarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}
