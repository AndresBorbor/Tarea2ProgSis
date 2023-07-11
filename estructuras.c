typedef struct materia_t{
    char nombre[20];
    int creditos;
    int paralelo;
} Materia;

typedef struct profesor_t{
    char nombre[20];
    char carrera[20];
    int numeroMaterias;
    Materia *materias;
} Profesor;

typedef struct estudiante_t{
    char nombre[20];
    int nivel;
    char carrera[20];
    int numeroMaterias;
    Materia *materias;
} Estudiante;