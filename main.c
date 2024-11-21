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
    verEstLista(listaEstudiantes);
    // ELIMINAR ESTUDIANTE
    printf("ELIMINADO->\n");
    printf("\tEliminando a Juan\n");
    eliminarEstudiante(&listaEstudiantes, "Juan");
    // MOSTRAR LISTA DE ESTUDIANTES ACTUALIZADA
    printf("\t\nLista de estudiantes actualizada:\n");
    verEstLista(listaEstudiantes);
    // LIBERAR MEMORIA
    liberarLista(listaEstudiantes);
    free(estudiante2);
    // Uso de la union
    printf("UNION ->\n");
    usaUnion();
    // Uso de Copia
    printf("COPIA ->\n");
    Estudiante estudianteCopia = copiarEstudiante(estudiante1);
    // Imprimir los datos para verificar la copia
    printf("\tOriginal: Edad = %d, Nombre = %s, Promedio = %.2f\n",
           estudiante1.edad, estudiante1.nombre, estudiante1.promedio);
    printf("\tCopia: Edad = %d, Nombre = %s, Promedio = %.2f\n",
           estudianteCopia.edad, estudianteCopia.nombre, estudianteCopia.promedio);
    // Modificar estudiante
    printf("MODIFICAR ->\n");
    modificarEstudiante(&estudianteCopia, "Patrick", 21, 8.5);
    printf("\tOriginal: Edad = %d, Nombre = %s, Promedio = %.2f\n",
           estudiante1.edad, estudiante1.nombre, estudiante1.promedio);
    printf("\tModificado: Edad = %d, Nombre = %s, Promedio = %.2f\n",
           estudianteCopia.edad, estudianteCopia.nombre, estudianteCopia.promedio);
//uso de direccion
    printf("Direccion ->\n");
    medianteDireccion(&estudianteCopia, "Luis", 20, 9.0);
    return 0;
}