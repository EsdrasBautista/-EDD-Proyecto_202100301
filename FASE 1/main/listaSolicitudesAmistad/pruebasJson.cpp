/*#include <fstream>
#include <iostream>
#include <string>
#include "json/json.h"
#include "listaEnlazada.h"

//C:\Users\bauti\Desktop\usuarios.json

int main()
{
    // Solicitar al usuario que ingrese la ruta del archivo JSON
    std::cout << "Ingrese la ruta del archivo JSON: ";
    std::string rutaArchivo;
    std::getline(std::cin, rutaArchivo);

    // Crear un objeto para manejar el JSON
    Json::Value root;
    std::ifstream ifs(rutaArchivo);

    // Verificar si el archivo se abrió correctamente
    if (!ifs.is_open()) {
        std::cerr << "Error al abrir el archivo: " << rutaArchivo << std::endl;
        return EXIT_FAILURE;
    }

    // Configurar el lector de JSON
    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    JSONCPP_STRING errs;

    // Leer y parsear el archivo JSON
    if (!parseFromStream(builder, ifs, &root, &errs)) {
        std::cerr << "Error al parsear JSON: " << errs << std::endl;
        return EXIT_FAILURE;
    }

    

    // Iterar sobre cada usuario en el array JSON
    for (const auto& item : root) {
        
        string correo = item["correo"].asString();
        string contenido = item["contenido"].asString();
        string fecha = item["fecha"].asString();
        string hora = item["hora"].asString();

        

    }



    return 0;
}
*/