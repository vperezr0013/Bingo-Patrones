#include "bingo.h"
#include "ui_bingo.h"
#include "cartoncontroller.h"
#include "List.h"
#include "Nodo.h"
#include "carton.h"
#include <string>

Bingo::Bingo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bingo)
{
    ui->setupUi(this);

}

Bingo::~Bingo()
{
    delete ui;
}



void Bingo::on_btnGenerarCarton1_clicked()
{

    CartonController *controller = new CartonController();
    List *carton1 = (List*) controller->getCarton1();
    ui->tblCarton1->setRowCount(5);
    ui->tblCarton1->setColumnCount(5);
    ui->tblCarton1->horizontalHeader()->hide();
    ui->tblCarton1->verticalHeader()->hide();
    ui->tblCarton1->horizontalHeader()->setStretchLastSection(true);
    ui->tblCarton1->verticalHeader()->setStretchLastSection(true);
    ui->tblCarton1->resizeColumnsToContents();
    ui->tblCarton1->resizeRowsToContents();
    Nodo *aux = carton1->getHead();

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            Carton *carton = (Carton*) aux->getInfo();
            ui->tblCarton1->setItem(i, j, new QTableWidgetItem(QString::fromStdString(std::to_string(carton->getNum()))));
            aux = aux->getSig();
        }
    }
    ui->btnGenerarCarton1->setEnabled(false);
}


void Bingo::on_btnGenerarCarton2_clicked()
{
    CartonController *controller = new CartonController();
    List *carton2 = (List*) controller->getCarton2();
    ui->tblCarton2->setRowCount(5);
    ui->tblCarton2->setColumnCount(5);
    ui->tblCarton2->horizontalHeader()->hide();
    ui->tblCarton2->verticalHeader()->hide();
    ui->tblCarton2->horizontalHeader()->setStretchLastSection(true);
    ui->tblCarton2->verticalHeader()->setStretchLastSection(true);
    ui->tblCarton2->resizeColumnsToContents();
    ui->tblCarton2->resizeRowsToContents();

    Nodo *aux = carton2->getHead();

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            Carton *carton = (Carton*) aux->getInfo();
            ui->tblCarton2->setItem(i, j, new QTableWidgetItem(QString::fromStdString(std::to_string(carton->getNum()))));
            aux = aux->getSig();
        }
    }
    ui->btnGenerarCarton2->setEnabled(false);
}

