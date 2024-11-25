#include <stdio.h>
#include "Manejo_Errores/Manejo_errores.h"

int main() {
    printf("Bienvenido al cargador de scripts!!!.\n");
    printf("Seleccione una opcion:\n");
    printf("1. Cargar un archivo especificando su nombre (mostrar contenido).\n");
    printf("2. Salir.\n");

    int opcion;
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
        load_script_interactive();
        break;
    case 2:
        printf("Saliendo del programa.\n");
        break;
    default:
        printf("Opción inválida. Por favor intente nuevamente.\n");
    }

    return 0;
}

