#include "bingo.h"
#include "ui_bingo.h"

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

