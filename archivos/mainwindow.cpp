#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
using namespace std;
int z = 1;
int v = 1;
float t = 0.5;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,0,0);
    ui->graphicsView->setScene(scene);

    //sol = new estrellas(0,0,0,0,400000);
    //scene->addItem(sol);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::zoom);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::velocidad);
    //float G = 6.67384*pow(10,-11);
    int cont=0;
    ifstream sis;
    string datos="", dato="";
    char* pEnd;
    double px, py, vx, vy, m, px2, py2, r;
    sis.open("../sistema.txt");
    if(!sis.is_open()){
        cout<<"no se pudo abrir el archivo"<<endl;
        //exit(1);
    }
    while(!sis.eof()){
        getline(sis,dato);
        datos=datos+dato+" ";
        dato="";
    }
    sis.close();
    while(cont<=9){
        if(cont==0){
            px=strtod(datos.c_str(),&pEnd);
            py=strtod(pEnd,&pEnd);
            vx=strtod(pEnd,&pEnd);
            vy=strtod(pEnd,&pEnd);
            m=strtod(pEnd,&pEnd);
            sol = new estrellas(px,py,vx,vy,m);
            scene->addItem(sol);
        }
        else{
            px=strtod(pEnd,&pEnd);
            py=strtod(pEnd,&pEnd);
            vx=strtod(pEnd,&pEnd);
            vy=strtod(pEnd,&pEnd);
            m=strtod(pEnd,&pEnd);
            px2=strtod(pEnd,&pEnd);
            py2=strtod(pEnd,&pEnd);
            r=strtod(pEnd,&pEnd);
            sistema.push_back(new planetas(px,py,vx,vy,m,px2,py2,r));
            scene->addItem(sistema.back());
        }
        cont=cont+1;
    }
    /*for(int i=0;i<=8;i++){
        if(i==8){
            sistema.push_back(new planetas(0,-100-i*40,sqrt((G*sol->getmsol())/(100+i*40)),0,sol->getmsol(),0,0,20));
        }
        else{
            if(i==4){
                sistema.push_back(new planetas(0,-100-i*40,sqrt((G*sol->getmsol())/(100+i*40)),0,sol->getmsol(),0,0,50));
            }
            else{
                sistema.push_back(new planetas(0,-100-i*40,sqrt((G*sol->getmsol())/(100+i*40)),0,sol->getmsol(),0,0,-(i*i)/2+5*i+30));
            }

        }
        scene->addItem(sistema.back());
    }*/

    tiempo = new QTimer();
    tiempo->start(15);
    ui->graphicsView->scale(0.36,0.36);

    connect(tiempo, &QTimer::timeout, this, &MainWindow::onUpdate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onUpdate(){
    scene->advance();
    ui->graphicsView->ensureVisible(sol);
    ui->graphicsView->centerOn(sol);
}

void MainWindow::zoom(){
if(z==0){ui->graphicsView->scale(2.2222222222,2.2222222222);z++;}
else if(z==1){ui->graphicsView->scale(0.45,0.45);z=0;}
}

void MainWindow::velocidad(){
if(v==0){tiempo->stop();t=15;v++; tiempo->start(t);}
else if(v==1){tiempo->stop();t=30;v++; tiempo->start(t);}
else{tiempo->stop();t=5;v=0; tiempo->start(t);}

}
