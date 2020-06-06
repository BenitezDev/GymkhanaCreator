#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"



class StageWidget;

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
	
	void show_all_components_of_stage(StageWidget* stage);

	void add_ar_component_to_stage(StageWidget* stage);
	
};
