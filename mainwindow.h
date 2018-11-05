#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "sort.h"

struct sortUI {
	QCheckBox* checkBox;
	QLabel* progression;
	QLabel* timeToComplete;
};

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

public slots:
	void test();
	void runSort(int vectorSize, int vectorAmount, sortUI sortFunction, sortFunctions name);

signals:

private:
	Ui::MainWindow* ui;
	sortUI sortUIinfo[7];
};

#endif // MAINWINDOW_H
