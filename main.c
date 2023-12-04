#include <stdio.h>
#include <string.h>
#include "fichamedica.h"

int idVisita = 1;  // ID de la visita, se incrementa con cada nueva visita

void limpiarBuffer() {

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
}

Paciente ingresarPaciente() {

    Paciente paciente;

    printf("Ingrese RUT: ");
    fgets(paciente.rut, sizeof(paciente.rut), stdin);
    paciente.rut[strcspn(paciente.rut, "\n")] = 0;
    limpiarBuffer();

    printf("Ingrese nombre: ");
    fgets(paciente.nombre, sizeof(paciente.nombre), stdin);
    paciente.nombre[strcspn(paciente.nombre, "\n")] = 0;

    printf("Ingrese direccion: ");
    fgets(paciente.direccion, sizeof(paciente.direccion), stdin);
    paciente.direccion[strcspn(paciente.direccion, "\n")] = 0;

    printf("Ingrese email: ");
    fgets(paciente.email, sizeof(paciente.email), stdin);
    paciente.email[strcspn(paciente.email, "\n")] = 0;

    printf("Ingrese telefono: ");
    fgets(paciente.fono, sizeof(paciente.fono), stdin);
    paciente.fono[strcspn(paciente.fono, "\n")] = 0;

    return paciente;
}

VisitaMedica ingresarVisita() {

    VisitaMedica visita;
    visita.id_visita = idVisita++;

    printf("Ingrese fecha: ");
    fgets(visita.fecha, sizeof(visita.fecha), stdin);
    visita.fecha[strcspn(visita.fecha, "\n")] = 0;
    limpiarBuffer();

    printf("Ingrese doctor: ");
    fgets(visita.doctor, sizeof(visita.doctor), stdin);
    visita.doctor[strcspn(visita.doctor, "\n")] = 0;

    printf("Ingrese especialidad: ");
    fgets(visita.especialidad, sizeof(visita.especialidad), stdin);
    visita.especialidad[strcspn(visita.especialidad, "\n")] = 0;

    printf("Ingrese diagnostico: ");
    fgets(visita.diagnostico, sizeof(visita.diagnostico), stdin);
    visita.diagnostico[strcspn(visita.diagnostico, "\n")] = 0;

    printf("Ingrese resumen: ");
    fgets(visita.resumen, sizeof(visita.resumen), stdin);
    visita.resumen[strcspn(visita.resumen, "\n")] = 0;

    printf("Ingrese medicamento: ");
    fgets(visita.medicamento, sizeof(visita.medicamento), stdin);
    visita.medicamento[strcspn(visita.medicamento, "\n")] = 0;

    printf("Ingrese dosis: ");
    fgets(visita.posologia, sizeof(visita.posologia), stdin);
    visita.posologia[strcspn(visita.posologia, "\n")] = 0;
    return visita;
}

int main() {

    int opcion;
    char rut[10];

    Paciente paciente;
    VisitaMedica visita;
    Paciente* p;  

    do {

        printf("\nSistema de Gestion de Fichas Medicas\n");
        printf("1. Insertar Paciente\n");
        printf("2. Buscar Paciente\n");
        printf("3. Actualizar Paciente\n");
        printf("4. Eliminar Paciente\n");
        printf("5. Insertar Visita Medica\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        getchar();  

        switch (opcion) {
            case 1:

                printf("\nIngrese los datos del paciente...\n");
                paciente = ingresarPaciente();
                insertarPaciente(paciente);
                printf("Ficha medica insertada.\n");
                break;

            case 2:

                printf("\nIngrese el RUT del paciente a buscar: ");
                fgets(rut, sizeof(rut), stdin);
                rut[strcspn(rut, "\n")] = 0;
                p = buscarPaciente(rut);
                if (p != NULL) {
                    printf("Paciente encontrado: %s\n", p->nombre);
                } else {
                    printf("Paciente no encontrado.\n");
                }
                break;

            case 3:

                printf("\nIngrese los datos del paciente a actualizar...\n");
                paciente = ingresarPaciente();
                actualizarPaciente(paciente);
                printf("Ficha medica actualizada.\n");
                break;

            case 4:

                printf("\nIngrese el RUT del paciente a eliminar: ");
                fgets(rut, sizeof(rut), stdin);
                rut[strcspn(rut, "\n")] = 0;
                eliminarPaciente(rut);
                printf("Ficha medica eliminada.\n");
                break;

            case 5:

                printf("\nIngrese los datos de la visita medica...\n");
                visita = ingresarVisita();
                printf("Ingrese el RUT del paciente: ");
                fgets(rut, sizeof(rut), stdin);
                rut[strcspn(rut, "\n")] = 0;
                insertarVisitaMedica(rut, visita);
                printf("Visita medica insertada.\n");
                break;

            case 6:

                printf("\nSaliendo del sistema...\n");
                break;

            default:
                printf("Opcion invalida. Por favor, intente de nuevo.\n");

        }
    } while (opcion != 6);

    return 0;
}