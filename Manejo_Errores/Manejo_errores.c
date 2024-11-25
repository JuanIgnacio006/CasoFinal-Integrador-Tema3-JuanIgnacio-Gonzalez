#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Manejo_errores.h"

void load_script(const char* filename, int show_script) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        // Manejo del error si no se puede abrir el archivo
        fprintf(stderr, "Error: No se pudo abrir el archivo '%s'.\n", filename);
        return;
    }

    // Leer el contenido del archivo
    char buffer[4096];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer) - 1, file)) > 0) {
        buffer[bytesRead] = '\0'; // Agregar un terminador nulo al final del contenido leído
        if (show_script) {
            printf("%s", buffer); // Mostrar el contenido en pantalla si show_script es verdadero
        }
    }

    if (ferror(file)) {
        // Manejo del error si ocurre un problema durante la lectura
        fprintf(stderr, "Error: Ocurrió un problema al leer el archivo '%s'.\n", filename);
    }

    fclose(file); // Cerrar el archivo
}

void load_script_interactive() {
    char filename[256];
    printf("Introduce el nombre del archivo a cargar: ");
    if (scanf("%255s", filename) != 1) {
        fprintf(stderr, "Error: Entrada inválida.\n");
        return;
    }

    load_script(filename, 1); // Llama a load_script mostrando el contenido del archivo
}