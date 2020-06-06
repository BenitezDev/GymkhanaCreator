

#include <MainWindow.hpp>
#include <CreateGymkhawnaDialog.hpp>

#include <GymkhanaManager.hpp>

#include <model/Gymkhana.hpp>
#include <StageWidget.hpp>
#include <RouteWidget.hpp>

#include <AddStageComponentDialog.hpp>
#include <ARComponentDialog.hpp>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    connect(ui.actionCreateNewGymkhana, &QAction::triggered, this, &MainWindow::create_new_gymkhana);

	

	ui.RoutesTabWidget->clear();
	
	
	
}


void MainWindow::create_new_gymkhana()
{
	CreateGymkhawnaDialogue dialogue;

	if (dialogue.exec() == QDialog::Accepted)
	{

		auto text = dialogue.ui.NameInput->toPlainText().toStdString();
		//auto version = dialogue.ui.VersionInput->toPlainText().toStdString();

		if (text.empty() /*|| version.empty()*/)
		{
			dialogue.ui.errorLabel->setText("Introduce a valid input.");
		}
		else
		{
			std::string gymkhana_name = "Gymkhana: ";
			gymkhana_name += text;
			backend::GymkhanaManager::instance().get_gymkhana().change_name(text);
			ui.gymkhanaName->setText(gymkhana_name.c_str());
			
			ui.RoutesTabWidget->addTab(new RouteWidget, { "route" });
			connect(dynamic_cast<RouteWidget*>(ui.RoutesTabWidget->currentWidget())->ui.AddStage, &QAbstractButton::clicked, this, &MainWindow::add_stage_to_route);
			
			dialogue.hide();

			
		}
	}
	else if (dialogue.exec() == QDialog::Rejected)
	{
		dialogue.hide();
	}
	else
	{
		dialogue.hide();
	}
}


void MainWindow::add_stage_to_route()
{
	auto new_stage = new StageWidget();
	dynamic_cast<RouteWidget*>(ui.RoutesTabWidget->currentWidget())->ui.StageLayout->addWidget(new_stage);

	connect(new_stage->ui.AddComponent, &QAbstractButton::clicked, this, [=]() { show_all_components_of_stage(new_stage); });
	
	
}

void MainWindow::show_all_components_of_stage(StageWidget* stage)
{
	
	AddStageComponentDialog componentPanel;
	connect(componentPanel.ui.ARComponent, &QAbstractButton::clicked, this, [=]() { add_ar_component_to_stage(stage); });
	componentPanel.setWindowTitle({ "Select a component to add" });
	componentPanel.exec();
	//componentPanel.ui.ARComponent

	// Connect all components
	
	
}

void MainWindow::add_ar_component_to_stage(StageWidget* stage)
{
	ARComponentDialog ar_component_dialog;
	if(ar_component_dialog.exec() == QDialog::Accepted)
	{
		ui.gymkhanaName->setText("AR compp");
	}
	
	
}
