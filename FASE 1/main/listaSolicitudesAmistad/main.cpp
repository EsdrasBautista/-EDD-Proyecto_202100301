
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <limits>
#include "GestionarSoli.h"
#include "GestionarAdmin.h"
#include "listaEnlazada.h"
#include "nodoPublicacion.h"
#include "nodoMatriz.h"
#include "json/json.h"

/*
admin@gmail.com  EDD2S2024
C:\Users\bauti\Desktop\solicitudes.json
C:\Users\bauti\Desktop\usuarios.json
C:\Users\bauti\Desktop\publicaciones.json
*/


using namespace std;


ListaEnlazada usuarios;
listaPublicaciones listaPub;
matriz matrizG;

void iniciarSesion();
void registrarse();
void informacion();
void salir();
void verListaUsuarios();
void menuUsuario(string correo);
void Perfil(string correo, bool &salirDelMenuUsuario);
void ReportesUsuario(string correo);
void Solicitudes(string correo);
void Publicaciones(string correo);
void salirUsuario();
void menuAdmin();
void cargaUsrs();
void cargaRelac();
void cargaPubl();
void gestionarUsrs();
void ReportesAdmin();
void top();


int main(){
    int opcion;

    do{
        // Mostrar el menu Principal
        cout << "Menu Principal:" << endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Registrarse" << endl;
        cout << "3. Informacion" << endl;
        cout << "4. Salir" << endl;
        cout << "Selecciona una opcion (1-5): ";

        
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, selecciona un numero entre 1 y 4." << endl;
            continue;
        }
        
        cin.ignore();

        // Ejecutar Opciones
        switch(opcion) {
            case 1:
                iniciarSesion();
                break;
            case 2:
                registrarse();
                break;
            case 3:
                informacion();
                break;
            case 4:
                salir();
                break;
            default:
                cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 4." << endl;
                break;
        }

        cout << endl; 

    } while(opcion != 4); 


    return 0;
}

void iniciarSesion() {
    //admin@gmail.com  EDD2S2024

    cout << endl;
    cout << "Has seleccionado Iniciar sesion." << endl;
    string correo,contra,nombre;

    cout << "Ingresa tu correo: ";
    getline(cin,correo);
    cout << "Ingresa tu contrasena: ";
    getline(cin,contra);


    //verificamos si es valida la contraseña
    int verificar = 0;
    
    verificar = usuarios.iniciodeSesion(contra,correo);
    if(verificar == 2){

        cout  << endl;
        menuUsuario(correo);

    }else if(verificar == 1){

        cout  << endl;
        menuAdmin();

    }
    else{
        cout << "Usuario no encontrado, Intenta de nuevo!" << endl;
    }

}

void registrarse() {
    cout << endl;
    cout << "Has seleccionado Registrarse." << endl;
    string nombres, apellidos, correo, contrasena, fechaNacimiento;

    // Solicitar y leer datos del usuario
    cout << "Ingrese sus nombres: ";
    getline(cin, nombres);

    cout << "Ingrese sus apellidos: ";
    getline(cin, apellidos);

    cout << "Ingrese su correo electronico: ";
    getline(cin, correo);

    cout << "Ingrese su contrasena: ";
    getline(cin, contrasena);

    cout << "Ingrese su fecha de nacimiento (dd/mm/yyyy): ";
    getline(cin, fechaNacimiento);

    //aqui ira mi lista enlazada y verificacion de correo

    bool verificacion;
    verificacion = usuarios.verificarCorreo(correo);
    if(verificacion == true){
        usuarios.agregarUsuario(nombres,apellidos,correo,contrasena,fechaNacimiento);
        cout << "Usuario Registrado con exito!." << endl;
    }else{
        cout << "Correo ya existente, por favor ingresa nuevamente tu informacion" << endl;
    }

}

void informacion() {
    cout << endl;
    cout << "Has seleccionado Informacion." << endl;
    cout << "Nombre: Esdras Eliab Bautista Guerra" <<endl;
    cout << "Carnet: 202100301" << endl;
}

void salir() {
    cout << endl;
    cout << "Saliendo del programa Social Structure." << endl;
}


void verListaUsuarios(){
    //gestionaradmin::gradicaListaUsuarios(usuarios);
    //gestionaradmin::graficaPublicacionesTodas(listaPub);
    gestionaradmin::top5conMasPublicaciones(listaPub);
    
}

void menuAdmin(){
    int opcion;

    do{
        
        cout << "Menu Administrador:" << endl;
        cout << "1. Cargar Usuarios" << endl;
        cout << "2. Cargar Relaciones" << endl;
        cout << "3. Cargar Publicaciones" << endl;
        cout << "4. Gestionar Usuarios" << endl;
        cout << "5. Reportes " << endl;
        cout << "6. Cerrar Sesion" << endl;
        cout << "Selecciona una opcion (1-6): ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, selecciona un numero entre 1 y 5." << endl;
            continue;
        }
        cin.ignore();
        switch (opcion)
        {
        case 1:
            cargaUsrs();
            break;
        case 2:
            cargaRelac();
            break;
        case 3:
            cargaPubl();
            break;
        case 4: 
            gestionarUsrs();
            break;
        case 5:
            ReportesAdmin();
            break;
        case 6:
            salirUsuario();
            break;

        default:
            cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 6." << endl;
                break;
        }

        cout << endl; 

    } while(opcion != 6); 



}

void menuUsuario(string correo){
    int opcion;
    bool salirDelMenuUsuario = false;

    do{

        cout << "Menu Usuario:" << endl;
        cout << "1. Perfil" << endl;
        cout << "2. Solicitudes" << endl;
        cout << "3. Publicaciones" << endl;
        cout << "4. Reportes" << endl;
        cout << "5. Cerrar Sesion" << endl;
        cout << "Selecciona una opcion (1-5): ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, selecciona un numero entre 1 y 5." << endl;
            continue;
        }
        cin.ignore();

        switch (opcion){
        case 1:
            cout << endl;
            Perfil(correo, salirDelMenuUsuario);
            if(salirDelMenuUsuario){
                opcion = 5;
            }
            break;
        case 2:
            cout << endl;
            Solicitudes(correo);
            break;
        case 3:
            cout << endl;
            Publicaciones(correo);
            break;
        case 4: 
            cout << endl;
            ReportesUsuario(correo);
            break;
        case 5:
            cout << endl;
            salirUsuario();
            break;
        
        default:
            cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 5." << endl;
                break;
        }

        cout << endl; 

    } while(opcion != 5); 
    

}

void salirUsuario(){
    cout << endl;
    cout << "Cerrando Sesion..." << endl;
}

void Perfil(string correo, bool &salirDelMenuUsuario){
    int opcion;
    string respuestaF;
    Nodo* info = usuarios.buscarNodoPorCorreo(correo);

    do{
        
        cout << "Perfil:" << endl;
        cout << "1. Ver Perfil" << endl;
        cout << "2. Eliminar Cuenta" << endl;
        cout << "3. Regresar" << endl;
        cout << "Selecciona una opcion (1-3): ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, selecciona un numero entre 1 y 3." << endl;
            continue;
        }
        cin.ignore();
        switch (opcion){
        
            case 1:
                cout << endl;
                cout << "Mi informacion:" << endl;
                cout<< "Nombre: " << info->getNombres() << endl;
                cout << "Apellido: " << info->getApellidos() << endl;
                cout << "Correo Usuario: " << info->getCorreo() << endl;
                cout << "Fecha Nacimiento: "<< info->getFechaNacimiento() << endl;
                 
                cout << "Mis publicaciones" << endl;
                gestionarSoli::vermisPublicaciones(usuarios,correo);
                
                
            break;

            case 2:
                cout << "Esta seguro de eliminar tu cuenta? (s/n): ";
                getline(cin,respuestaF);
                if(respuestaF == "S" || respuestaF == "s"){
                    cout << "Intentando eliminar cuenta: " << correo << endl;
                    gestionarSoli::EliminarCuenta(usuarios,correo); 
                    cout << "Cuenta eliminada con Exito!" << endl;

                    salirDelMenuUsuario = true;
                    opcion = 3;
                    
                }
                break;

            case 3:
            cout << "Regresando a menu Usuario..." << endl;
            break;

            default:
            cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 3." << endl;
            break;

        }

        cout << endl; 

    } while(opcion != 3); 

}

void Solicitudes(string correo){
    
    int opcion;
    string correoReceptor,correoPeek,respuesta;
    string correoEmisor = correo;
    bool estado = true;
    Nodo* miPila = usuarios.buscarNodoPorCorreo(correoEmisor);
    PilaSolicitudesRecibidas* pilaReceptor = miPila->getPilaSolicitudesRecibidas();
    
    
    do{
        
        cout << "Solicitudes:" << endl;
        cout << "1. Aceptar/Rechazar" << endl;
        cout << "2. Enviar" << endl;
        cout << "3. Regresar" << endl;
        cout << "Selecciona una opcion (1-3): ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, selecciona un numero entre 1 y 3." << endl;
            continue;
        }
        cin.ignore();
        
        switch (opcion){
        case 1:
            
            
            if(!pilaReceptor->estaVacia()){
                correoPeek = pilaReceptor->peek();
                cout << "Tienes una solicitud de: " << correoPeek << endl;
                cout << "Deseas aceptar la solicitud? (s/n): ";
                getline(cin, respuesta);

                if(respuesta == "s" || respuesta == "S"){
                    gestionarSoli::aceptarSolicitud(usuarios,correoPeek,correoEmisor,matrizG);
                }else{
                    gestionarSoli::rechazarSolicitud(usuarios,correoPeek,correoEmisor);
                }
            }else{
                cout << "No tienes solicitudes de amistad :( " << endl;
            }
            break;
        case 2:
            cout << "Escribe el correo de quien quieres enviarle solicitud de amistad: ";
            getline(cin, correoReceptor);
            estado = usuarios.verificarExistenciaUsuario(correoReceptor);
            if(estado){
                gestionarSoli::enviarSolicitud(usuarios,correoEmisor,correoReceptor);

            }else{
                cout << "Usuario no encontrado, prueba de nuevo!" << endl;
            }
            

            break;
        case 3:
            cout << "Saliendo de la opcion de Solicitudes..." << endl;
            break;
        default:
            cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 3." << endl;
            break;
        }

        cout << endl; 

    } while(opcion != 3); 


}

void Publicaciones(string correo){
    int opcion;
    string contenido, fecha, hora;

    do{
        
        cout << "Has seleccionado Publicaciones:" << endl;
        cout << "1. Ver todas" << endl;
        cout << "2. Crear" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Regresar" << endl;
        cout << "Selecciona una opcion (1-4): ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, selecciona un numero entre 1 y 4." << endl;
            continue;
        }
        cin.ignore();
        switch (opcion){
        case 1:
            cout << endl;
            cout << "Mi feed" << endl;
            gestionarSoli::verPublicacionesAmigos(usuarios,correo);
            break;
        case 2:
            cout << endl;
            cout << "Ingrese el contenido de la publicacion: " << endl;
            getline(cin,contenido);
            cout << "Ingrese la fecha: " << endl;
            getline(cin,fecha);
            cout << "Ingrese la Hora: "<<endl;
            getline(cin,hora);

            gestionarSoli::crearPublicacion(usuarios,correo,contenido,fecha,hora,listaPub);

            
            break;

        case 3:
            cout << endl;
            gestionarSoli::eliminarMiPublicacion(usuarios,correo,listaPub);
            break;
        
        case 4:
            cout << "Saliendo de la opcion de Publicaciones..." << endl;
            break;

        default:
            cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 3." << endl;
            break;
        }

        cout << endl; 

    } while(opcion != 4); 



}
void ReportesUsuario(string correo){
    int opcion;
    do{

        cout << "Reporte Usuario:" << endl;
        cout << "1. Solicitudes Enviadas y Recibidas" << endl;
        cout << "2. Relaciones de Amistad" << endl;
        cout << "3. Publicaciones" << endl;
        cout << "4. Mis Amigos" << endl;
        cout << "5. Regresar" << endl;
        cout << "Selecciona una opcion (1-5): ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, selecciona un numero entre 1 y 5." << endl;
            continue;
        }
        cin.ignore();

        switch (opcion){
        case 1:
            cout << endl;
            gestionarSoli::graficasSoliEnviadasyRecibidas(usuarios,correo);
            break;
        case 2:
            cout << endl;
            // graph de matriz dispersa
            gestionarSoli::graficarMatrizAmigos(usuarios,correo);
            break;
        case 3:
            cout << endl;
            // grap de publicaciones mias y de mis amigos
            gestionarSoli::graficarListaCircularPublicaciones(usuarios,correo);
            break;
        case 4: 
            cout << endl;
            gestionarSoli::graficaListaAmigos(usuarios,correo);
            break;
        case 5:
            cout << endl;
            cout << "Saliendo de Reportes..." << endl;
            break;
        
        default:
            cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 5." << endl;
            break;
        }

        cout << endl; 

    } while(opcion != 5); 
    


}

void cargaUsrs(){
    //C:\Users\bauti\Desktop\usuarios.json
    cout << "Carga Masiva de Usuarios" << endl;

    // Solicitar al usuario que ingrese la ruta del archivo JSON
    cout << "Ingrese la ruta del archivo JSON: ";
    string rutaArchivo;
    getline(std::cin, rutaArchivo);

    Json::Value root;
    ifstream ifs(rutaArchivo);

    // Verificar si el archivo se abrio correctamente
    if (!ifs.is_open()) {
        cerr << "Error al abrir el archivo: " << rutaArchivo << endl;
        return;
    }

    // Configurar el lector de JSON
    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    JSONCPP_STRING errs;

    // Leer y parsear el archivo JSON
    if (!parseFromStream(builder, ifs, &root, &errs)) {
        cerr << "Error al parsear JSON: " << errs << endl;
        return;
    }

    

    // Iterar sobre cada usuario en el json
    for (const auto& item : root) {
        
        string nombres = item["nombres"].asString();
        string apellidos = item["apellidos"].asString();
        string fechaNac = item["fecha_de_nacimiento"].asString();
        string correo = item["correo"].asString();
        string contra = item["contraseña"].asString();

        if(nombres.empty() || apellidos.empty() || fechaNac.empty() || correo.empty() || contra.empty()){
            cout << "No se pudo extraer la informacion del archivo" << endl;
        }else{

            usuarios.agregarUsuario(nombres,apellidos,correo,contra,fechaNac);
        }
    }

    //usuarios.verListadoUsuarios();


}

void cargaRelac(){

    cout << "Carga Masiva de Relaciones de Usuarios" <<endl;
    //C:\Users\bauti\Desktop\solicitudes.json
    cout << "Ingrese la ruta del archivo JSON: ";
    string rutaArchivo;
    getline(std::cin, rutaArchivo);

    // Crear un objeto para manejar el JSON
    Json::Value root;
    ifstream ifs(rutaArchivo);

    // Verificar si el archivo se abrió correctamente
    if (!ifs.is_open()) {
        cerr << "Error al abrir el archivo: " << rutaArchivo << endl;
        return;
    }


    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    JSONCPP_STRING errs;


    if (!parseFromStream(builder, ifs, &root, &errs)) {
        cerr << "Error al parsear JSON: " << errs << endl;
        return;
    }

    
    // Iterar sobre cada solicitud del json
    for (const auto& item : root) {
        
        string emisor = item["emisor"].asString();
        string receptor = item["receptor"].asString();
        string estado = item["estado"].asString();

        if(emisor.empty() || receptor.empty() || estado.empty()){
            cout << "No se pudo extraer la informacion del archivo" <<endl;
        }else{
            if(estado == "ACEPTADA"){
                gestionarSoli::aceptarSolicitudD(usuarios,receptor,emisor,matrizG);

            }else if(estado == "PENDIENTE"){
                gestionarSoli::enviarSolicitud(usuarios,emisor,receptor);
            }else if(estado == "RECHAZADA"){
                gestionarSoli::rechazarSolicitud(usuarios,receptor,emisor);
            }
        }

    }


}

void cargaPubl(){
    cout << "Carga Masiva de Publicaciones de Usuarios" << endl;

    std::cout << "Ingrese la ruta del archivo JSON: ";
    std::string rutaArchivo;
    std::getline(std::cin, rutaArchivo);

    // Crear un objeto para manejar el JSON
    Json::Value root;
    std::ifstream ifs(rutaArchivo);

    // Verificar si el archivo se abrió correctamente
    if (!ifs.is_open()) {
        std::cerr << "Error al abrir el archivo: " << rutaArchivo << std::endl;
        return;
    }

    // Configurar el lector de JSON
    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    JSONCPP_STRING errs;

    // Leer y parsear el archivo JSON
    if (!parseFromStream(builder, ifs, &root, &errs)) {
        std::cerr << "Error al parsear JSON: " << errs << std::endl;
        return;
    }

    

    // Iterar sobre cada usuario en el array JSON
    for (const auto& item : root) {
        
        string correo = item["correo"].asString();
        string contenido = item["contenido"].asString();
        string fecha = item["fecha"].asString();
        string hora = item["hora"].asString();

        if(correo.empty() || contenido.empty() || fecha.empty() || hora.empty()){
            cout << "No se pudo extraer la informacion del archivo" << endl;
        }else{

            gestionarSoli::crearPublicacion(usuarios,correo,contenido,fecha,hora,listaPub);

        }
    }


}

void gestionarUsrs(){
    int opcion;
    string usuarioE;
    string  respuestaF;
    do{

        cout << "Gestionar Usuario:" << endl;
        cout << "1. Eliminar Usuario" << endl;
        cout << "2. Regresar" << endl;
        cout << "Selecciona una opcion (1-2): ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, selecciona un numero entre 1 y 2." << endl;
            continue;
        }
        cin.ignore();

        switch (opcion){
        case 1:
            cout << endl;
            cout << "Ingresa el correo del Usuario a elminar: ";
            getline(cin,usuarioE);
            cout << "Esta seguro de eliminar tu cuenta? (s/n): ";
            getline(cin,respuestaF);
            if(respuestaF == "S" || respuestaF == "s"){
                cout << "Intentando eliminar cuenta: " << usuarioE << endl;
                gestionaradmin::eliminarUsuario(usuarios,usuarioE,listaPub,matrizG); 
                cout << "Cuenta eliminada con Exito!" << endl;
            }else{
                cout << "Gestion cancelada!" << endl;
            }
            
            break;
        case 2:
            cout << endl;
            cout << "Regresando a menu Admini..." << endl;
            break;
        default:
            cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 2." << endl;
                break;
        }

        cout << endl; 

    } while(opcion != 2); 
    
}

void ReportesAdmin(){
    int opcion;
    do{

        cout << "Reportes:" << endl;
        cout << "1. Grafico Usuarios" << endl;
        cout << "2. Relaciones de Amistad" << endl;
        cout << "3. Publicaciones" << endl;
        cout << "4. Top" << endl;
        cout << "5. Regresar" << endl;
        cout << "Selecciona una opcion (1-5): ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, selecciona un numero entre 1 y 5." << endl;
            continue;
        }
        cin.ignore();

        switch (opcion){
        case 1:
            cout << endl;
            cout << "Generando grafico..." << endl;
            gestionaradmin::gradicaListaUsuarios(usuarios);
            break;
        case 2:
            cout << endl;
            cout << "Generando grafico..." << endl;
            gestionaradmin::graficaMatrizDispersaTodos(matrizG);
            break;
        case 3:
            cout << endl;
            cout << "Generando grafico..." << endl;
            gestionaradmin::graficaPublicacionesTodas(listaPub);
            break;
        case 4:
            cout << endl;
            top();
            break;
        case 5: 
            cout << "Regresando..." << endl;
            break;

        default:
            cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 5." << endl;
                break;
        }

        cout << endl; 

    } while(opcion != 5);


}

void top(){
    
    int opcion;
    do{
        cout << "Top 5:" << endl;
        cout << "1. Usuarios con más publicaciones" << endl;
        cout << "2. Usuarios con menos amigos." << endl;
        cout << "3. Regresar" << endl;
        cout << "Selecciona una opcion (1-2): ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, selecciona un numero entre 1 y 2." << endl;
            continue;
        }
        cin.ignore();

        switch (opcion){
        case 1:
            cout << endl;
            cout << "Generando grafico..." << endl;
            gestionaradmin::top5conMasPublicaciones(listaPub);
            break;
        case 2:
            cout << endl;
            cout << "Generando grafico..." << endl;
            //gestionaradmin::top5conMenosAmigos();
            break;
        
        case 3:
            cout << " Regresando..." << endl;
        default:
            cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 2." << endl;
                break;
        }

        cout << endl; 

    } while(opcion != 3); 
    
}


