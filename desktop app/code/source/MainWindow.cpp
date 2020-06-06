

#include <MainWindow.hpp>
#include <CreateGymkhawnaDialog.hpp>

#include <GymkhanaManager.hpp>

#include <model/Gymkhana.hpp>
#include <StageWidget.hpp>
#include <RouteWidget.hpp>

#include <AddStageComponentDialog.hpp>
#include <ARComponentDialog.hpp>
#include <ARComponentWidget.hpp>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    connect(ui.actionCreateNewGymkhana, &QAction::triggered, this, &MainWindow::create_new_gymkhana);

	

	ui.RoutesTabWidget->clear();
	
	
	
}


void MainWindow::create_new_gymkhana()
{
	CreateGymkhawnaDialogue* dialogue = new CreateGymkhawnaDialogue();

	if (dialogue->exec() == QDialog::Accepted)
	{

		auto text = dialogue->ui.NameInput->toPlainText().toStdString();
		//auto version = dialogue.ui.VersionInput->toPlainText().toStdString();

		if (text.empty() /*|| version.empty()*/)
		{
			dialogue->ui.errorLabel->setText("Introduce a valid input.");
		}
		else
		{
			std::string gymkhana_name = "Gymkhana: ";
			gymkhana_name += text;
			backend::GymkhanaManager::instance().get_gymkhana().change_name(text);
			ui.gymkhanaName->setText(gymkhana_name.c_str());
			
			ui.RoutesTabWidget->addTab(new RouteWidget, { "route" });
			connect(dynamic_cast<RouteWidget*>(ui.RoutesTabWidget->currentWidget())->ui.AddStage, &QAbstractButton::clicked, this, &MainWindow::add_stage_to_route);
			
			dialogue->hide();

			
		}
	}
	else if (dialogue->exec() == QDialog::Rejected)
	{
		dialogue->hide();
		delete dialogue;
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
	
	AddStageComponentDialog* componentPanel = new AddStageComponentDialog();
	connect(componentPanel->ui.ARComponent, &QAbstractButton::clicked, this, [=]() { add_ar_component_to_stage(stage, componentPanel); });
	componentPanel->setWindowTitle({ "Select a component to add" });
	componentPanel->exec();
	//componentPanel.ui.ARComponent

	// Connect all components
	
	
}

void MainWindow::add_ar_component_to_stage(StageWidget* stage, AddStageComponentDialog* all_components_dialog)
{

	stage->ui.ComponentLayout->addWidget(new ARComponentWidget);


	ui.gymkhanaName->setText("AR compp");

	all_components_dialog->hide();
	delete all_components_dialog;
}
