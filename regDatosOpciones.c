#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "metodos.c"

int main(int argc, char *argv[])
{
    int opt;
    int cantidadPersonas = 0;
    Profesor *profesores;
    Estudiante *estudiantes;
    while ((opt = getopt(argc, argv, ":a:p:e:")) != -1)
    {
        cantidadPersonas = atoi(optarg);
        while (cantidadPersonas < 2)
        {
            printf("Ingrese una cantidad personas igual o mayor a 2: ");
            scanf("%i", &cantidadPersonas);
        }
        switch (opt)
        {
        case 'a':
            profesores = (Profesor *)malloc(sizeof(Profesor));
            crearProfesor(profesores);
            estudiantes = (Estudiante *)malloc((cantidadPersonas - 1) * sizeof(Estudiante));
            for(int i = 0; i<cantidadPersonas-1; i++){
                crearEstudiante(&estudiantes[i]);
            }
            mostrarProfesores(profesores, 1);
            mostrarEstudiantes(estudiantes, (cantidadPersonas-1));
            eliminarMateriaProfesores(profesores, 1);
            eliminarMateriaEstudiante(estudiantes, (cantidadPersonas-1));
            cambiarNivel(estudiantes, (cantidadPersonas-1));
            free(estudiantes);
            free(profesores);
            break;
        case 'p':
            profesores = (Profesor *)malloc((cantidadPersonas)*sizeof(Profesor));
            for(int i = 0; i<cantidadPersonas; i++){
                crearProfesor(&profesores[i]);
            }
            mostrarProfesores(profesores, cantidadPersonas);
            eliminarMateriaProfesores(profesores, cantidadPersonas);
            free(profesores);
            break;
        case 'e':
            estudiantes = (Estudiante *)malloc((cantidadPersonas) * sizeof(Estudiante));
            for(int i = 0; i<cantidadPersonas; i++){
                crearEstudiante(&estudiantes[i]);
            }
            mostrarEstudiantes(estudiantes, cantidadPersonas);
            eliminarMateriaEstudiante(estudiantes, cantidadPersonas);
            cambiarNivel(estudiantes, cantidadPersonas);
            free(estudiantes);
            break;
        case ':':
            printf("Opcion %s recibida, pero sin argumentos", optopt);
            break;
        case '?':
            printf("Opción no reconocida: %c\n", optopt);
            break;
        }
    }
}