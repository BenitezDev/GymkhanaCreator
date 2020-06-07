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
	/**
	 * Vector with all the route widgets
	 */
	std::vector<RouteWidget*> routes;
	
public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::MainWindowClass ui;

public slots:

	/**
	 * Display the a dialog to create a gymkhana
	 */
	void create_new_gymkhana();

	/**
	 * Add a empty stage to the current route
	 */
	void add_stage_to_route();

	/**
	 * Add a route to the tab widget
	 */
	void add_route();

	/**
	 * Show a dialog with all the stage components
	 */
	void show_all_stage_components(StageWidget* stage);

	/**
	 * Add a AR component to the selected stage
	 */
	void add_ar_component_to_stage(StageWidget* stage, AddStageComponentDialog* all_components_dialog);

	/**
	 * Add a Dialog component to the selected stage
	 */
	void add_monologue_component_to_stage(StageWidget* stage, AddStageComponentDialog* all_components_dialog);

	/**
	 * Save the data into a xml
	 */
	void save();
};


