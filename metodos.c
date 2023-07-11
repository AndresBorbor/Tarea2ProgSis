#include "estructuras.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearProfesor(Profesor *profesor){
 
    printf("Ingrese el nombre del profesor: \n");
    scanf("%s", profesor->nombre);
    printf("Ingrese la carrera del profesor: \n");
    scanf("%s", profesor->carrera);
    int cantidadMaterias;
    printf("Cuantas materias dicta el profesor: ");
    scanf("%i", &cantidadMaterias);

    while (cantidadMaterias < 2 || cantidadMaterias > 3) {
        printf("Solo puede dictar de 2 a 3 materias, ingrese cuantas materias esta "
            "dictando el profesor: ");
        scanf("%i", &cantidadMaterias);
    }
    profesor->numeroMaterias = cantidadMaterias;
    profesor->materias = (Materia *)malloc(cantidadMaterias*sizeof(Materia));
    
    for(int i=0; i<cantidadMaterias; i++){
        Materia* materia = &profesor->materias[i];
        printf("Nombre de la materia %i: \n", i+1);
        scanf("%s", materia->nombre);
        printf("Paralelo de la materia %i: \n", i+1);
        scanf(" %d", &(materia->paralelo));
        scanf("%*[^\n]");
        getchar();
    }
    
    


}
void crearEstudiante(Estudiante *estudiante){
    printf("Ingrese el nombre del estudiante: \n");
    scanf("%s", estudiante->nombre);
    printf("Ingrese el nivel del estudiante: \n");
    scanf(" %i", &(estudiante->nivel));
    scanf("%*[^\n]");
    getchar();
    
    printf("Ingrese la carrera del estudiante: \n");
    scanf("%s", estudiante->carrera);
    int cantidadMaterias;
    printf("Cuantas materias ve el estudiante: ");
    scanf("%i", &cantidadMaterias);

    while (cantidadMaterias < 3 || cantidadMaterias > 7) {
        printf("Solo puede tomar de 3 a 7 materias, ingrese cuantas materias esta "
            "tomando el estudiante: ");
        scanf("%i", &cantidadMaterias);
    }
    estudiante->numeroMaterias = cantidadMaterias;
    estudiante->materias = (Materia *)calloc(cantidadMaterias,sizeof(Materia));
    for(int i=0; i<cantidadMaterias; i++){
        Materia* materia = &estudiante->materias[i];
        printf("Nombre de la materia %i: \n", i+1);
        scanf("%s", materia->nombre);
        printf("Creditos de la materia %i: \n", i+1);
        scanf(" %d", &(materia->creditos));
        scanf("%*[^\n]");
        getchar();

    }
}


void mostrarProfesores(Profesor *profesores, int cantidadPersonas) {
  printf("\nProfesores\n");
  for (int i = 0; i < cantidadPersonas; i++) {
    printf("Nombre: %s, Carrera: %s\n", profesores[i].nombre,
           profesores[i].carrera);
    for(int j = 0; j < profesores[i].numeroMaterias; j++){
        printf("Materia %i\n", j+1);
        printf("\tNombre:%s\n", profesores[i].materias[j].nombre);
        printf("\tCreditos:%i\n", profesores[i].materias[j].paralelo);
    }

  }
}

void mostrarEstudiantes(Estudiante *estudiantes, int cantPersonas) {
  printf("\nEstudiantes\n");
  for (int i = 0; i < cantPersonas; i++) {
    printf("Nombre: %s, Nivel: %i, Carrera: %s\n", estudiantes[i].nombre,
           estudiantes[i].nivel, estudiantes[i].carrera);

    for(int j = 0; j < estudiantes[i].numeroMaterias; j++){
        printf("Materia %i\n", j+1);
        printf("\tNombre:%s\n", estudiantes[i].materias[j].nombre);
        printf("\tCreditos:%i\n", estudiantes[i].materias[j].creditos);
    }
  }
}



void eliminarMateriaEstudiante(Estudiante *estudiantes, int cantidadEstudiantes){
    int opcion;
    printf("Desea eliminar una materia de un estudiante? [Si=1/No=0]:\n");
    scanf("%i", &opcion);
    if(opcion == 0){ return ;}
    printf("Ingrese el nombre del estudiante:\n");
    char nombreEstudiante[20];
    scanf("%s", nombreEstudiante);
    printf("Ingrese el numero de la materia que quiere eliminar:\n");
    int materia;
    scanf("%i", &materia);
    Estudiante *estudianteModificar;
    for(int i=0; i<cantidadEstudiantes; i++){
        if(strcmp(estudiantes[i].nombre, nombreEstudiante) == 0){
            estudianteModificar = &estudiantes[i];
            break;
        }
    }
    Materia materiaEliminada = estudianteModificar->materias[materia-1];

    for(int j =  (materia-1); j < (*estudianteModificar).numeroMaterias - 1; j++){
       estudianteModificar->materias[j] = estudianteModificar->materias[j+1];
    }
    

    estudianteModificar->numeroMaterias--;
    printf("La materia %s del estudiante %S ha sido eliminada con éxito", materiaEliminada, nombreEstudiante);
    mostrarEstudiantes(estudiantes,cantidadEstudiantes);
}

void eliminarMateriaProfesores(Profesor *profesores, int cantidadProfesores){
    int opcion;
    printf("Desea eliminar una materia de un profesor? [Si=1/No=0]:\n");
    scanf("%i", &opcion);
    if(opcion == 0){ return ;}
    printf("Ingrese el nombre del profesor:\n");
    char nombreProfesor[20];
    scanf("%s", nombreProfesor);
    printf("Ingrese el numero de la materia que quiere eliminar:\n");
    int materia;
    scanf("%i", &materia);
    Profesor *profesorModificar;
    for(int i=0; i<cantidadProfesores; i++){
        if(strcmp(profesores[i].nombre, nombreProfesor) == 0){
            profesorModificar = &profesores[i];
            break;
        }
    }
    Materia materiaEliminada = profesorModificar->materias[materia-1];
    for(int j = (materia-1); j < (*profesorModificar).numeroMaterias - 1; j++){
       profesorModificar->materias[j] = profesorModificar->materias[j+1];
    }
    profesorModificar->numeroMaterias--;
    printf("La materia %s del profesor %S ha sido eliminada con exito\n", materiaEliminada.nombre,nombreProfesor );
    mostrarProfesores(profesores,cantidadProfesores);
}



void cambiarNivel(Estudiante *estudiantes, int cantidadEstudiantes){
    int opcion;
    printf("Desea cambiar el nivel de un estudiante? [Si=1/No=0]:\n");
    scanf("%i", &opcion);
    if(opcion == 0){ return ;}
    printf("Ingrese el nombre del estudiante:\n ");
    char nombreEstudiante[20];
    scanf("%s", nombreEstudiante);
    printf("Ingrese el nuevo nivel del estudiante:\n");
    int nuevoNivel;
    scanf("%i",&nuevoNivel);
    Estudiante *estudianteModificar;
    for(int i=0; i<cantidadEstudiantes; i++){
        if(strcmp(estudiantes[i].nombre, nombreEstudiante) == 0){
            estudianteModificar = &estudiantes[i];
            break;
        }
    }
    estudianteModificar->nivel = nuevoNivel;
    mostrarEstudiantes(estudiantes, cantidadEstudiantes);

}
