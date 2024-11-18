//
// Created by navia on 18-Nov-24.
//
#include <stdio.h>
#include "Persona.h"
#include <stdlib.h>
int main (){
    //NODO PARA LA LISTA DE ESTUDIANTES
    Nodo *listaEstudiantes = NULL;
//ESTUDIANTES INDIVIDUALES
    Estudiante estudiante1 = est1("Juan", 20, 9.5);
    Estudiante* estudiante2 = est2("Ana", 22, 9.8);
//MOSTRAR ESTUDIANTES
    printf("Estudiante 1: %s, Edad: %d, Promedio: %.2f\n", estudiante1.nombre, estudiante1.edad, estudiante1.promedio);
    printf("Estudiante 2: %s, Edad: %d, Promedio: %.2f\n", estudiante2->nombre, estudiante2->edad, estudiante2->promedio);
//MOSTRAR ESTUDIANTES DESDE PUNTERO
    verEstudiante(&estudiante1);
    verEstudiante(estudiante2);
//CREAR NODO "nuevoNodo" Y AÑADIR ESTUDIANTE
    añadirEstudiante(&listaEstudiantes, "Juan", 20, 9.5);
    añadirEstudiante(&listaEstudiantes, "Ana", 22, 9.8);
// extras para la lista
    añadirEstudiante(&listaEstudiantes, "Rodrigo", 19, 9.8);
    añadirEstudiante(&listaEstudiantes, "Louise", 22, 2.1);
//MOSTRAR LISTA DE ESTUDIANTES
    printf("Lista de estudiantes:\n");
    verEstudiantes(listaEstudiantes);
//ELIMINAR ESTUDIANTE
    printf("\nEliminando a Juan...\n");
    eliminarEstudiante(&listaEstudiantes, "Juan");
//MOSTRAR LISTA DE ESTUDIANTES ACTUALIZADA
    printf("\nLista de estudiantes actualizada:\n");
    verEstudiantes(listaEstudiantes);
//LIBERAR MEMORIA
    free(estudiante2);
    return 0;
}
