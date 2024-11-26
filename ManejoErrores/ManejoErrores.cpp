#include "ManejoErrores.h"
#include <iostream>
#include <cstdio>
#include <stdexcept>  // Para std::runtime_error

using namespace std;

ConsoleBox *consoleBox = new ConsoleBox; // supondremos que ya está inicializado

// Función para cargar el script desde un archivo y mostrarlo
void load_script(const char* filename, bool show_script) {
    string script;
    FILE* f = nullptr;

    try {
        // Intentamos abrir el archivo en modo binario
        f = fopen(filename, "rb");
        if (!f) {
            throw runtime_error("Error: No se pudo abrir el archivo " + string(filename));
        }

        // Leemos el archivo en fragmentos y lo almacenamos en el string
        char buf[4001];
        size_t bytes_read;
        while ((bytes_read = fread(buf, 1, 4000, f)) > 0) {
            buf[bytes_read] = '\0';  // Aseguramos que el contenido esté correctamente terminado en null
            script.append(buf);
        }

        // Verificamos si hubo error durante la lectura
        if (ferror(f)) {
            throw runtime_error("Error al leer el archivo.");
        }

        // Cerramos el archivo
        fclose(f);
        f = nullptr;

        // Si se debe mostrar el script en la consola
        if (show_script) {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }

        // Usamos el script en el ConsoleBox (como se mencionaba en el ejercicio original)
        consoleBox->new_text();
        consoleBox->set_text(script);

    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        if (f) fclose(f);  // Cerramos el archivo si se abrió correctamente
    } catch (...) {
        cerr << "Error inesperado durante la lectura del archivo." << endl;
        if (f) fclose(f);  // Cerramos el archivo si se abrió correctamente
    }
}

// Función para solicitar el nombre del archivo de forma interactiva
void load_script() {
    char filename[500];
    cout << "Archivo: ";
    cin.getline(filename, sizeof(filename));  // Usamos getline para capturar la entrada completa

    load_script(filename, true);  // Llamamos a la función que carga el archivo y lo muestra
}

// Definición de la función load_script_interactive()
// Solicita al usuario el nombre del archivo y luego llama a la función load_script para cargarlo.
void load_script_interactive() {
    char filename[500];
    cout << "Por favor ingrese el nombre del archivo: ";
    cin.getline(filename, sizeof(filename));  // Usamos getline para capturar la entrada completa

    load_script(filename, true);  // Llamamos a la función que carga el archivo y lo muestra
}