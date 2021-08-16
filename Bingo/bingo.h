#ifndef BINGO_H
#define BINGO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Bingo; }
QT_END_NAMESPACE

class Bingo : public QMainWindow
{
    Q_OBJECT

public:
    Bingo(QWidget *parent = nullptr);
    ~Bingo();

private slots:

    void on_btnGenerarCarton1_clicked();

    void on_btnGenerarCarton2_clicked();

private:
    Ui::Bingo *ui;
};
#endif // BINGO_H
