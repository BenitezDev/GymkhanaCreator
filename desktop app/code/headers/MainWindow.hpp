#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"



class StageWidget;
class AddStageComponentDialog;
class RouteWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
	std::vector<RouteWidget*> routes;
	
public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::MainWindowClass ui;

public slots:
	
	void create_new_gymkhana();

	void add_stage_to_route();
	void add_route();
	
	void show_all_stage_components(StageWidget* stage);

	void add_ar_component_to_stage(StageWidget* stage, AddStageComponentDialog* all_components_dialog);

	void save();
};
