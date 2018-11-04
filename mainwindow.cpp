#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QDebug>
#include <sstream>
#include <string>
#include "randomvectorset.h"
#include "sort.h"
#include <thread>



MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(ui->button_beginSort, SIGNAL(clicked()), this, SLOT(test()));

	//	sortUIinfo[heapSort].checkBox = ui->checkBox_heapSort;
	//	sortUIinfo[heapSort].progression = ui->label_progression_heapSort;
	//	sortUIinfo[heapSort].timeToComplete = ui->label_timeToComplete_heapSort;

	//	sortUIinfo[stdSort].checkBox = ui->checkBox_stdSort;
	//	sortUIinfo[stdSort].progression = ui->label_progression_stdSort;
	//	sortUIinfo[stdSort].timeToComplete = ui->label_timeToComplete_stdSort;


}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::test()
{

	int vectorSize = ui->spinBox_vectorSizeInput->value();
	int vectorAmount = ui->spinBox_vectorAmountInput->value();

	//	for (int i = 0; i < end; i++) {
	//		runSort(vectorSize, vectorAmount, sortUIinfo[i]);
	//	}

	if(ui->checkBox_heapSort->isChecked()) {
		ui->label_progression_heapSort->setText("Sorting...");
		ui->label_progression_heapSort->repaint();
		qDebug() << "heapSort checked";
		ui->label_timeToComplete_heapSort->setText(QString::number(Sort::testTime<int>(vectorSize, vectorAmount, heapSort)));
		ui->label_progression_heapSort->setText("Finished.");
	}
	else {
		ui->label_progression_heapSort->setText("");
		ui->label_timeToComplete_heapSort->setText("");
	}

	if(ui->checkBox_stdSort->isChecked()) {
		ui->label_progression_stdSort->setText("Sorting...");
		qApp->processEvents();
		qDebug() << "stdSort checked";
		ui->label_timeToComplete_stdSort->setText(QString::number(Sort::testTime<int>(vectorSize, vectorAmount, stdSort)));
		ui->label_progression_stdSort->setText("Finished.");
	}
	else {
		ui->label_progression_stdSort->setText("");
		ui->label_timeToComplete_stdSort->setText("");
	}
}

void MainWindow::runSort(int vectorSize, int vectorAmount, sortUI sortFuntion) {

	if(sortFuntion.checkBox->isChecked()) {
		sortFuntion.progression->setText("Sorting...");
		qApp->processEvents();
		auto secondsToComplete = QString::number(Sort::testTime<int>(vectorSize, vectorAmount, stdSort));
		sortFuntion.timeToComplete->setText(secondsToComplete);
		sortFuntion.progression->setText("Finished.");
	}
}
