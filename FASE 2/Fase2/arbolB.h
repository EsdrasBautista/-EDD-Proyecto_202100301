#ifndef ARBOLB_H
#define ARBOLB_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Llave;
class Nodo;


class Nodo{
private:
    bool hoja;
    Llave *primero;
    int numeroLlaves;

    std::tm convertirFecha(string fecha) {
        std::tm tm = {};
        std::istringstream ss(fecha);
        ss >> std::get_time(&tm, "%d/%m/%Y"); // Formato d/m/y
        if (ss.fail()) {
            throw std::runtime_error("Error al convertir la fecha");
        }
        return tm;
    }

    std::tm convertirHora(const std::string& hora) {
        std::tm tm = {};
        std::istringstream ss(hora);
        ss >> std::get_time(&tm, "%H:%M"); // Formato H:M
        if (ss.fail()) {
            throw std::runtime_error("Error al convertir la hora");
        }
        return tm;
    }

public:
    Nodo();
    ~Nodo();

    void insertarLlave(Llave *llave);

    Llave* getPrimero();
    int getNumeroLlaves();
    bool esHoja();

    void setPrimero(Llave *llave);
    void setNumeroLlaves(int numeroLlaves);
    void setHoja(bool hoja);

    int compararFechas(const std::string& f1, const std::string& f2) {
        std::tm tm1 = convertirFecha(f1);
        std::tm tm2 = convertirFecha(f2);

        // Convertir las fechas a tiempo en segundos
        time_t time1 = std::mktime(&tm1);
        time_t time2 = std::mktime(&tm2);

        // Comparar fechas
        double diff = std::difftime(time1, time2);
        if (diff < 0) {
            return 1;  // f1 es menor que f2
        } else if (diff > 0) {
            return -1;   // f1 es mayor que f2
        } else {
            return 0;   // f1 es igual a f2
        }
    }

    int compararHoras(const std::string& h1, const std::string& h2) {
        std::tm tm1 = convertirHora(h1);
        std::tm tm2 = convertirHora(h2);

        // Comparar las horas directamente
        if (tm1.tm_hour < tm2.tm_hour) {
            return 1;  // h1 es menor que h2
        } else if (tm1.tm_hour > tm2.tm_hour) {
            return -1; // h1 es mayor que h2
        }

        // Si las horas son iguales, comparar los minutos
        if (tm1.tm_min < tm2.tm_min) {
            return 1;  // h1 es menor que h2
        } else if (tm1.tm_min > tm2.tm_min) {
            return -1; // h1 es mayor que h2
        }

        // Si las horas y los minutos son iguales
        return 0;  // h1 es igual a h2
    }



};



class Llave{
private:
    string fecha;
    string hora;
    string correo;
    string contenido;

    Llave *prev;
    Llave *sig;
    Nodo *izq;
    Nodo *drcha;

public:
    Llave(string fecha,string hora,string correo,string contenido);
    ~Llave();

    bool tieneHijos();

    string getFecha();
    string getHora();
    string getCorreo();
    string getContenido();

    Llave* getPrev();
    Llave* getSig();
    Nodo* getIzq();
    Nodo* getDrcha();

    void setFecha(string fecha);
    void setHora(string hora);
    void setContenido(string contenido);
    void setCorreo(string correo);
    void setPrev(Llave*);
    void setSig(Llave*);
    void setIzq(Nodo*);
    void setDrcha(Nodo*);


};


class ArbolB {
private:
    Nodo *raiz;
    int orden;

    Llave* insertarEnHoja(string fecha,string hora,string correo,string contenido,Nodo *raiz);
    Llave* dividir(Nodo *nodo);
    void eliminarComentarios(string fecha,string correo,Nodo *raiz);


    std::tm convertirFecha(string fecha) {
        std::tm tm = {};
        std::istringstream ss(fecha);
        ss >> std::get_time(&tm, "%d/%m/%Y"); // Formato d/m/y
        if (ss.fail()) {
            throw std::runtime_error("Error al convertir la fecha");
        }
        return tm;
    }

    std::tm convertirHora(const std::string& hora) {
        std::tm tm = {};
        std::istringstream ss(hora);
        ss >> std::get_time(&tm, "%H:%M"); // Formato H:M:S
        if (ss.fail()) {
            throw std::runtime_error("Error al convertir la hora");
        }
        return tm;
    }

    void recorrer(Nodo* nodo,QPlainTextEdit *textEdit);
    void verArbol(Nodo* raiz, std::ofstream &archivoDot);

public:
    ArbolB();
    ~ArbolB();

    void insert(string fecha,string hora,string correo,string contenido);
    void eliminarComentarios(string fecha,string correo);

    int compararFechas(const std::string& f1, const std::string& f2) {
        std::tm tm1 = convertirFecha(f1);
        std::tm tm2 = convertirFecha(f2);

        // Convertir las fechas a tiempo en segundos
        time_t time1 = std::mktime(&tm1);
        time_t time2 = std::mktime(&tm2);

        // Comparar fechas
        double diff = std::difftime(time1, time2);
        if (diff < 0) {
            return 1;  // f1 es menor que f2
        } else if (diff > 0) {
            return -1;   // f1 es mayor que f2
        } else {
            return 0;   // f1 es igual a f2
        }
    }

    int compararHoras(const std::string& h1, const std::string& h2) {
        std::tm tm1 = convertirHora(h1);
        std::tm tm2 = convertirHora(h2);

        // Comparar las horas directamente
        if (tm1.tm_hour < tm2.tm_hour) {
            return 1;  // h1 es menor que h2
        } else if (tm1.tm_hour > tm2.tm_hour) {
            return -1; // h1 es mayor que h2
        }

        // Si las horas son iguales, comparar los minutos
        if (tm1.tm_min < tm2.tm_min) {
            return 1;  // h1 es menor que h2
        } else if (tm1.tm_min > tm2.tm_min) {
            return -1; // h1 es mayor que h2
        }

        // Si las horas y los minutos son iguales
        return 0;  // h1 es igual a h2
    }


    void recorrer(QPlainTextEdit* txtarea);
    string verArbol();
};




#endif // ARBOLB_H
