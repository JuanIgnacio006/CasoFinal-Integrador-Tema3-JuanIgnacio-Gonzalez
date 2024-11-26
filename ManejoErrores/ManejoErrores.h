#ifndef MANEJOERRORES_H
#define MANEJOERRORES_H

#include <iostream>
#include <string>

using namespace std;

// Estructura para manejar los colores de la consola
struct ColorConsole {
    static constexpr auto fg_blue = "\033[34m";  // Color de texto azul
    static constexpr auto bg_white = "\033[47m";  // Fondo blanco
};

// Estructura que simula una caja de consola donde se muestra el texto
struct ConsoleBox {
    void new_text() { /* Aquí podemos implementar la lógica para mostrar el texto si es necesario */ }
    void set_text(const string &text) { cout << text << endl; }  // Mostrar el texto en consola
};

void load_script(const char* filename, bool show_script = false);
void load_script();
void load_script_interactive(); // Declaración de la nueva función

#endif // MANEJOERRORES_H

