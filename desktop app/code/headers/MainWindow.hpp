#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::MainWindowClass ui;

public slots:
	
	void create_new_gymkhana();

	void add_stage_to_route();
	
};
