

#include <MainWindow.hpp>
#include <CreateGymkhawnaDialog.hpp>

#include <GymkhanaManager.hpp>

#include <model/Gymkhana.hpp>
#include <StageWidget.hpp>
#include <RouteWidget.hpp>


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
}


void MainWindow::add_stage_to_route()
{
	dynamic_cast<RouteWidget*>(ui.RoutesTabWidget->currentWidget())->ui.StageLayout->addWidget(new StageWidget);
	
}
