#include <iostream>
#include <cstdlib>
#include <string>
#include "GestionarSoli.h"
#include "listaEnlazada.h"



using namespace std;

ListaEnlazada usuarios;

void iniciarSesion();
void registrarse();
void informacion();
void salir();
void verListaUsuarios();
void menuUsuario(string correo);
void Perfil(string correo, bool &salirDelMenuUsuario);
void ReportesUsuario();
void Solicitudes(string correo);
void Publicaciones(string correo);
void salirUsuario();
void menuAdmin();
void cargaUsrs();
void cargaRelac();
void cargaPubl();
void gestionarUsrs();
void ReportesAdmin();


int main(){
    int opcion;

    do{
        // Mostrar el menu Principal
        cout << "Menu Principal:" << endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Registrarse" << endl;
        cout << "3. Informacion" << endl;
        cout << "4. listado Usuarios" << endl;
        cout << "5. Salir" << endl;
        cout << "Selecciona una opcion (1-5): ";
        cin >> opcion;
        
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
                verListaUsuarios();
                break;
            case 5:
                salir();
                continue;
            default:
                cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 5." << endl;
                break;
        }

        cout << endl; 

    } while(opcion != 5); 

    


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
    usuarios.verListadoUsuarios();
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
        cin >> opcion;
        
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
        cout << "4. Reoortes" << endl;
        cout << "5. Cerrar Sesion" << endl;
        cout << "Selecciona una opcion (1-5): ";
        cin >> opcion;
        
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
            ReportesUsuario();
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

    do{
        
        cout << "Has seleccionado Perfil:" << endl;
        cout << "1. Ver Perfil" << endl;
        cout << "2. Eliminar Cuenta" << endl;
        cout << "3. Regresar" << endl;
        cout << "Selecciona una opcion (1-3): ";
        cin >> opcion;
        
        cin.ignore();
        switch (opcion){
        
            case 1:
            break;

            case 2:
                cout << "Esta seguro de eliminar tu cuenta? (s/n): ";
                getline(cin,respuestaF);
                if(respuestaF == "S" || respuestaF == "s"){
                    cout << "Intentando eliminar cuenta: " << correo << endl;
                    usuarios.eliminarCuenta(correo);   //REVISAR POR QUE AL ELIMINARLA SE SALE DEL PROGRAMA
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
        
        cout << "Has seleccionado Solicitudes:" << endl;
        cout << "1. Aceptar/Rechazar" << endl;
        cout << "2. Enviar" << endl;
        cout << "3. Regresar" << endl;
        cout << "Selecciona una opcion (1-3): ";
        cin >> opcion;
        
        cin.ignore();
        
        switch (opcion){
        case 1:
            
            
            if(!pilaReceptor->estaVacia()){
                correoPeek = pilaReceptor->peek();
                cout << "Tienes una solicitud de: " << correoPeek << endl;
                cout << "Deseas aceptar la solicitud? (s/n): ";
                getline(cin, respuesta);

                if(respuesta == "s" || respuesta == "S"){
                    gestionarSoli::aceptarSolicitud(usuarios,correoPeek,correoEmisor);
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
        cin >> opcion;
        
        cin.ignore();
        switch (opcion){
        case 1:
            break;
        case 2:
            cout << "Ingrese el contenido de la publicacion: " << endl;
            getline(cin,contenido);
            cout << "Ingrese la fecha: " << endl;
            getline(cin,fecha);
            cout << "Ingrese la Hora: "<<endl;
            getline(cin,hora);

            gestionarSoli::crearPublicacion(usuarios,correo,contenido,fecha,hora);
            
            break;

        case 3:
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
void ReportesUsuario(){

}

void cargaUsrs(){


}

void cargaRelac(){

}

void cargaPubl(){

}

void gestionarUsrs(){

}

void ReportesAdmin(){

}

