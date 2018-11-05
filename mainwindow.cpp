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

	RandomVectorSet<int> vector(20, 1);

	vector.printAll();

	Sort::mergeSort<int>(vector.m_vectorSet[0]);

	vector.printAll();

	qDebug() << "test";


	// MERGE SORT
	if(ui->checkBox_mergeSort->isChecked()) {
		ui->label_progression_mergeSort->setText("Sorting...");
		ui->label_progression_mergeSort->repaint();
		qDebug() << "heapSort checked";
		ui->label_secondsToComplete_mergeSort->setText(QString::number(Sort::testTime<int>(vectorSize, vectorAmount, MERGE_SORT)));
		ui->label_progression_mergeSort->setText("Finished.");
	}
	else {
		ui->label_progression_mergeSort->setText("");
		ui->label_secondsToComplete_mergeSort->setText("");
	}


	// INSERTION SORT
	if(ui->checkBox_insertionSort->isChecked()) {
		ui->label_progression_insertionSort->setText("Sorting...");
		ui->label_progression_insertionSort->repaint();
		qDebug() << "heapSort checked";
		ui->label_secondsToComplete_insertionSort->setText(QString::number(Sort::testTime<int>(vectorSize, vectorAmount, INSERTION_SORT)));
		ui->label_progression_insertionSort->setText("Finished.");
	}
	else {
		ui->label_progression_insertionSort->setText("");
		ui->label_secondsToComplete_insertionSort->setText("");
	}


	// SELECTION SORT
	if(ui->checkBox_selectionSort->isChecked()) {
		ui->label_progression_selectionSort->setText("Sorting...");
		ui->label_progression_selectionSort->repaint();
		qDebug() << "heapSort checked";
		ui->label_secondsToComplete_selectionSort->setText(QString::number(Sort::testTime<int>(vectorSize, vectorAmount, SELECTION_SORT)));
		ui->label_progression_selectionSort->setText("Finished.");
	}
	else {
		ui->label_progression_selectionSort->setText("");
		ui->label_secondsToComplete_selectionSort->setText("");
	}


	// BINARY SEARCH TREE
	if(ui->checkBox_binarySearchTreeSort->isChecked()) {
		ui->label_progression_binarySearchTreeSort->setText("Sorting...");
		ui->label_progression_binarySearchTreeSort->repaint();
		qDebug() << "heapSort checked";
		ui->label_secondsToComplete_binarySearchTreeSort->setText(QString::number(Sort::testTime<int>(vectorSize, vectorAmount, BINARY_SEARCH_TREE_SORT)));
		ui->label_progression_binarySearchTreeSort->setText("Finished.");
	}
	else {
		ui->label_progression_binarySearchTreeSort->setText("");
		ui->label_secondsToComplete_binarySearchTreeSort->setText("");
	}


	// HEAP SORT
	if(ui->checkBox_heapSort->isChecked()) {
		ui->label_progression_heapSort->setText("Sorting...");
		ui->label_progression_heapSort->repaint();
		qDebug() << "heapSort checked";
		ui->label_timeToComplete_heapSort->setText(QString::number(Sort::testTime<int>(vectorSize, vectorAmount, HEAP_SORT)));
		ui->label_progression_heapSort->setText("Finished.");
	}
	else {
		ui->label_progression_heapSort->setText("");
		ui->label_timeToComplete_heapSort->setText("");
	}


	// STD SORT
	if(ui->checkBox_stdSort->isChecked()) {
		ui->label_progression_stdSort->setText("Sorting...");
		qApp->processEvents();
		qDebug() << "stdSort checked";
		ui->label_timeToComplete_stdSort->setText(QString::number(Sort::testTime<int>(vectorSize, vectorAmount, STD_SORT)));
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
		auto secondsToComplete = QString::number(Sort::testTime<int>(vectorSize, vectorAmount, STD_SORT));
		sortFuntion.timeToComplete->setText(secondsToComplete);
		sortFuntion.progression->setText("Finished.");
	}
}
