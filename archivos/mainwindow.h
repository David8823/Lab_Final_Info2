#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsItem>
#include <QMainWindow>
#include "estrellas.h"
#include "planetas.h"
#include <QList>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void zoom();
    void velocidad();
public slots:
    void onUpdate();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList<planetas *> sistema;
    planetas *tierra;
    estrellas *sol;
    QTimer *tiempo;

};
#endif // MAINWINDOW_H
