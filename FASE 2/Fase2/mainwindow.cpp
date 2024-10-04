#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./admin.h"
#include "./userint.h"
#include "./crearuser.h"
#include "./listaEnlazadaArbol.h"
#include "./nodoPublicacion.h"
#include <string>
#include <QMessageBox>
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("SocialStructure");
    listaArbol = new listaEnlazadaArb();
    listaPub = new listaPublicaciones();

/*
    listaArbol->agregarUsuario("esdras","eliab","ee","123","23/08/2000");
    listaArbol->agregarUsuario("gabriel","garcia","aa","456","15/06/1995");
    listaArbol->agregarUsuario("juan","perez","bb","789","22/11/1988");
    listaArbol->agregarUsuario("maria","gomez","cc","123","15/06/1995");
*/




}

MainWindow::~MainWindow()
{
    delete ui;
    delete listaArbol;
    delete listaPub;
}

void MainWindow::on_btnIngresar_clicked()
{

    QString qCorreo = ui->txtCorreo->text();  // Obtener texto como QString
    QString qContra = ui->txtContra->text();  // Obtener texto como QString

    string correo = qCorreo.toStdString();    // Convertir a std::string
    string contra = qContra.toStdString();    // Convertir a std::string

    int resultado = listaArbol->iniciodeSesionArb(contra,correo);

    if(qCorreo.isEmpty() || qContra.isEmpty()){
        QMessageBox::warning(this, "Error de Inicio de Sesion", "Llena los campos para iniciar sesion!");
    }else{

        if(resultado == 1){
            Admin *ventAdmin = new Admin(this,listaArbol,listaPub);
            this->hide();
            ventAdmin->show();
            ui->txtContra->clear();
            ui->txtCorreo->clear();
        }else if(resultado == 2){
            UserInt *user = new UserInt(this,listaArbol,correo,listaPub);
            user->setNombreUsuario(listaArbol->buscarNombreArb(correo));
            this->hide();
            user->show();
            ui->txtContra->clear();
            ui->txtCorreo->clear();
        }else{
            QMessageBox::warning(this, "Error de Inicio de Sesion", "Correo o contraseña incorrectos.");
            ui->txtContra->clear();
            ui->txtCorreo->clear();
        }
    }

}


void MainWindow::on_btnCrear_clicked()
{
    CrearUser *crear = new CrearUser(this,listaArbol);
    this->hide();
    crear->show();
    ui->txtContra->clear();
    ui->txtCorreo->clear();
}


void MainWindow::on_btnVerU_clicked()
{
    //listaArbol->postOrden();
    listaArbol->graph();
    listaPub->graficarListaP();
}


void MainWindow::on_btnInfo_clicked()
{
    QMessageBox::information(this, "Informacion", "Esdras Eliab Bautista Guerra - 202100301");
}

