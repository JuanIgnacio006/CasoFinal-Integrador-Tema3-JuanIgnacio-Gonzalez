#include <iostream>
#include <limits> // Para std::numeric_limits
#include "ManejoErrores/ManejoErrores.h"

void load_script_interactive(); // Declaración de la función (agregada aquí)

int main() {
    std::cout << "Bienvenido al cargador de scripts!!!.\n";

    int opcion;

    do {
        std::cout << "Seleccione una opcion:\n";
        std::cout << "1. Cargar un archivo especificando su nombre (mostrar contenido).\n";
        std::cout << "2. Salir.\n";

        // Validación de entrada
        while (!(std::cin >> opcion)) {
            std::cin.clear(); // Limpia el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora entrada inválida
            std::cout << "Entrada inválida. Por favor ingrese un número.\n";
        }

        switch (opcion) {
        case 1:
            load_script_interactive(); // Aquí la llamamos
            break;
        case 2:
            std::cout << "Saliendo del programa.\n";
            break;
        default:
            std::cout << "Opción inválida. Por favor intente nuevamente.\n";
        }
    } while (opcion != 2); // Repetir hasta que el usuario seleccione salir

    return 0;
}