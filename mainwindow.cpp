#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QDebug>
#include <sstream>
#include <string>
#include "randomvectorset.h"


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);




	connect(ui->button_beginSort, SIGNAL(clicked()), this, SLOT(test()));


}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::test()
{

	auto vectors = new RandomVectorSet<int>(ui->spinBox_vectorSizeInput->value(), ui->spinBox_vectorAmountInput->value());

//	RandomVectorSet<int> vectors(ui->spinBox_vectorSizeInput->value(), ui->spinBox_vectorAmountInput->value());

	if(ui->checkBox->isChecked())
		qDebug() << "checkbox checked";
	else
		qDebug() << "checkbox NOT checked";

	delete vectors;


}
