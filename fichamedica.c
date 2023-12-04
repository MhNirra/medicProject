#include "fichamedica.h"
#include <stdlib.h>
#include <string.h>

// Inicialización de la tabla hash
NodoHash* tablaHash[SIZE] = {NULL};

// Función de hashing
int hash(char* rut) {
    unsigned long hash = 5381;
    int c;

    while ((c = *rut++))
        hash = ((hash << 5) + hash) + c;

    return hash % SIZE;
}

// Función para insertar un nuevo paciente
void insertarPaciente(Paciente paciente) {
    int index = hash(paciente.rut);

    // Buscar un espacio libre en caso de colisión
    while (tablaHash[index] != NULL) {
        index = (index + 1) % SIZE;
    }

    // Crear un nuevo nodo
    NodoHash* nuevoNodo = (NodoHash*) malloc(sizeof(NodoHash));
    nuevoNodo->paciente = paciente;
    nuevoNodo->visitas = NULL;

    // Insertar el nodo en la tabla hash
    tablaHash[index] = nuevoNodo;
}

// Función para buscar un paciente
Paciente* buscarPaciente(char* rut) {
    int index = hash(rut);

    // Buscar el paciente en la tabla hash
    while (tablaHash[index] != NULL) {
        if (strcmp(tablaHash[index]->paciente.rut, rut) == 0) {
            return &tablaHash[index]->paciente;
        }
        index = (index + 1) % SIZE;
    }

    // Si no se encuentra el paciente, devolver NULL
    return NULL;
}

// Función para actualizar la información de un paciente
void actualizarPaciente(Paciente paciente) {
    // Buscar el paciente en la tabla hash
    Paciente* pacienteExistente = buscarPaciente(paciente.rut);
    if (pacienteExistente != NULL) {
        // Actualizar la información demográfica del paciente
        strcpy(pacienteExistente->nombre, paciente.nombre);
        strcpy(pacienteExistente->direccion, paciente.direccion);
        strcpy(pacienteExistente->email, paciente.email);
        strcpy(pacienteExistente->fono, paciente.fono);
    }
}
// Función para eliminar un paciente
void eliminarPaciente(char* rut) {
    int index = hash(rut);

    // Buscar el paciente en la tabla hash
    while (tablaHash[index] != NULL) {
        if (strcmp(tablaHash[index]->paciente.rut, rut) == 0) {
            // Liberar la memoria de las visitas médicas
            VisitaMedica* visitaActual = tablaHash[index]->visitas;

            while (visitaActual != NULL) {
                
                VisitaMedica* visitaSiguiente = visitaActual->next;
                free(visitaActual);
                visitaActual = visitaSiguiente;
            }

            // Liberar la memoria del nodo y marcarlo como NULL
            free(tablaHash[index]);
            tablaHash[index] = NULL;

            return;
        }
        index = (index + 1) % SIZE;
    }
}

// Función para insertar una nueva visita médica
void insertarVisitaMedica(char* rut, VisitaMedica visita) {
    // Buscar el paciente en la tabla hash
    Paciente* paciente = buscarPaciente(rut);

    if (paciente != NULL) {
        // Crear una nueva visita
        VisitaMedica* nuevaVisita = (VisitaMedica*) malloc(sizeof(VisitaMedica));
        *nuevaVisita = visita;
        nuevaVisita->next = NULL;

        // Insertar la visita al principio de la lista enlazada
        if (paciente->visitas == NULL) {
            paciente->visitas = nuevaVisita;
        } else {

            nuevaVisita->next = paciente->visitas;
            paciente->visitas = nuevaVisita;
        }
    }
}