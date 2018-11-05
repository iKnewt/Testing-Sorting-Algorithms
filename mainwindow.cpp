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


	sortUIinfo[MERGE_SORT].checkBox = ui->checkBox_mergeSort;
	sortUIinfo[MERGE_SORT].progression = ui->label_progression_mergeSort;
	sortUIinfo[MERGE_SORT].timeToComplete = ui->label_secondsToComplete_mergeSort;

	sortUIinfo[INSERTION_SORT].checkBox = ui->checkBox_insertionSort;
	sortUIinfo[INSERTION_SORT].progression = ui->label_progression_insertionSort;
	sortUIinfo[INSERTION_SORT].timeToComplete = ui->label_secondsToComplete_insertionSort;

	sortUIinfo[SELECTION_SORT].checkBox = ui->checkBox_selectionSort;
	sortUIinfo[SELECTION_SORT].progression = ui->label_progression_selectionSort;
	sortUIinfo[SELECTION_SORT].timeToComplete = ui->label_secondsToComplete_selectionSort;

	sortUIinfo[QUICK_SORT].checkBox = ui->checkBox_quickSort;
	sortUIinfo[QUICK_SORT].progression = ui->label_progression_quickSort;
	sortUIinfo[QUICK_SORT].timeToComplete = ui->label_secondsToComplete_quickSort;

	sortUIinfo[BINARY_SEARCH_TREE_SORT].checkBox = ui->checkBox_binarySearchTreeSort;
	sortUIinfo[BINARY_SEARCH_TREE_SORT].progression = ui->label_progression_binarySearchTreeSort;
	sortUIinfo[BINARY_SEARCH_TREE_SORT].timeToComplete = ui->label_secondsToComplete_binarySearchTreeSort;

	sortUIinfo[HEAP_SORT].checkBox = ui->checkBox_heapSort;
	sortUIinfo[HEAP_SORT].progression = ui->label_progression_heapSort;
	sortUIinfo[HEAP_SORT].timeToComplete = ui->label_secondsToComplete_heapSort;

	sortUIinfo[STD_SORT].checkBox = ui->checkBox_stdSort;
	sortUIinfo[STD_SORT].progression = ui->label_progression_stdSort;
	sortUIinfo[STD_SORT].timeToComplete = ui->label_secondsToComplete_stdSort;
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::test()
{

	int vectorSize = ui->spinBox_vectorSizeInput->value();
	int vectorAmount = ui->spinBox_vectorAmountInput->value();

	for (int i = 0; i < END; i++) {
		runSort(vectorSize, vectorAmount, sortUIinfo[i], static_cast<sortFunctions>(i));
	}
}

void MainWindow::runSort(int vectorSize, int vectorAmount, sortUI sortFunction, sortFunctions name) {

	if(sortFunction.checkBox->isChecked()) {
		sortFunction.progression->setText("Sorting...");
		qApp->processEvents();
		QString secondsToComplete = QString::number(Sort::testTime<int>(vectorSize, vectorAmount, name));
		sortFunction.timeToComplete->setText(secondsToComplete);
		sortFunction.progression->setText("Finished.");
	}
	else {
		sortFunction.progression->setText("");
		sortFunction.timeToComplete->setText("");
	}
}
