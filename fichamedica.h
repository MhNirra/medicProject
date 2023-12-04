#ifndef FICHAMEDICA_H
#define FICHAMEDICA_H

// Estructura para la información demográfica del paciente
typedef struct {

    char rut[10];
    char nombre[50];
    char direccion[100];
    char email[50];
    char fono[15];
    struct VisitaMedica* visitas;
} Paciente;

// Estructura para la visita médica
typedef struct VisitaMedica {

    int id_visita;
    char fecha[10];
    char doctor[50];
    char especialidad[50];
    char diagnostico[100];
    char resumen[500];
    char medicamento[50];
    char posologia[100];
    struct VisitaMedica* next;  // apuntador al siguiente nodo en la lista enlazada

} VisitaMedica;

// Estructura para el nodo de la tabla hash
typedef struct {

    Paciente paciente;
    VisitaMedica* visitas;  // apuntador al primer nodo de la lista enlazada de visitas
    
} NodoHash;

// Definición de la tabla hash
#define SIZE 100  // tamaño de la tabla hash

// Declaraciones de las funciones
void insertarPaciente(Paciente paciente);
void insertarVisitaMedica(char* rut, VisitaMedica visita);
Paciente* buscarPaciente(char* rut);
void actualizarPaciente(Paciente paciente);
void eliminarPaciente(char* rut);

#endif