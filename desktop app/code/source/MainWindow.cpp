

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
	connect(ui.AddRoute, &QAbstractButton::clicked, this, &MainWindow::add_route);

	ui.RoutesTabWidget->clear();
	
	
	routes.clear();
}


void MainWindow::create_new_gymkhana()
{
	CreateGymkhawnaDialogue dialogue;
	
	auto text = dialogue.ui.NameInput->toPlainText().toStdString();

	auto status = dialogue.exec();

	while(status != QDialog::Rejected)
	{
		
		if (status == QDialog::Accepted)
		{
			text = dialogue.ui.NameInput->toPlainText().toStdString();

			//auto version = dialogue.ui.VersionInput->toPlainText().toStdString();

			if (text.empty() /*|| version.empty()*/)
			{

				dialogue.ui.errorLabel->setText("Introduce a valid input."); 
				status = dialogue.exec();
			}
			else
			{
				std::string gymkhana_name = "Gymkhana: ";
				gymkhana_name += text;
				ui.RoutesTabWidget->clear();
				backend::GymkhanaManager::instance().get_gymkhana().change_name(text);
				ui.gymkhanaName->setText(gymkhana_name.c_str());
				add_route();
				

				dialogue.hide();
				return;
			}
		}	
	}
	
}


void MainWindow::add_stage_to_route()
{
	auto new_stage = new StageWidget();
	dynamic_cast<RouteWidget*>(ui.RoutesTabWidget->currentWidget())->ui.StageLayout->addWidget(new_stage);


	connect(new_stage->ui.AddComponent, &QAbstractButton::clicked, this, [=]() { show_all_stage_components(new_stage); });
	
}

void MainWindow::add_route()
{
	auto new_route = new RouteWidget();
	routes.push_back(new_route);
	std::string route = "Route";
	std::string route_number = std::to_string(routes.size());
	std::string sum = route + route_number;
	ui.RoutesTabWidget->addTab(new_route, sum.c_str());
	
	connect(new_route->ui.AddStage, &QAbstractButton::clicked, this, &MainWindow::add_stage_to_route);
}

void MainWindow::show_all_stage_components(StageWidget* stage)
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

	all_components_dialog->hide();
	delete all_components_dialog;
}
