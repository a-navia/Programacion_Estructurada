#include <stdio.h>
#include <stdlib.h>
#include "Estructura/Persona.h"
#include "Union/Variable.h"

int main() {
    // NODO PARA LA LISTA DE ESTUDIANTES
    Nodo *listaEstudiantes = NULL;
    // ESTUDIANTES INDIVIDUALES
    printf("Estructura estudiantes->\n");
    Estudiante estudiante1 = est1("Juan", 20, 9.5);
    Estudiante* estudiante2 = est2("Ana", 22, 9.8);
    // MOSTRAR ESTUDIANTES DESDE PUNTERO
    printf("Puntero->\n");
    verEstudiante(&estudiante1);
    verEstudiante(estudiante2);
    // CREAR NODO "nuevoNodo" Y AÑADIR ESTUDIANTE
    añadirEstudiante(&listaEstudiantes, "Juan", 20, 9.5);
    añadirEstudiante(&listaEstudiantes, "Ana", 22, 9.8);
    // extras para la lista
    añadirEstudiante(&listaEstudiantes, "Rodrigo", 19, 9.8);
    añadirEstudiante(&listaEstudiantes, "Louise", 22, 2.1);
    // MOSTRAR LISTA DE ESTUDIANTES
    printf("LISTA->\n");
    printf("\tLista de estudiantes:\n");
    verEstudiantes(listaEstudiantes);
    // ELIMINAR ESTUDIANTE
    printf("ELIMINADO->\n");
    printf("\tEliminando a Juan\n");
    eliminarEstudiante(&listaEstudiantes, "Juan");
    // MOSTRAR LISTA DE ESTUDIANTES ACTUALIZADA
    printf("\t\nLista de estudiantes actualizada:\n");
    verEstudiantes(listaEstudiantes);
    // LIBERAR MEMORIA
    liberarLista(listaEstudiantes);
    free(estudiante2);
    // Uso de la union
    printf("UNION ->\n");
    usaUnion();
    return 0;
}