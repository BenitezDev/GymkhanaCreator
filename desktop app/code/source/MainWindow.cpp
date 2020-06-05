

#include <MainWindow.hpp>
#include <CreateGymkhawnaDialogue.hpp>

#include <GymkhanaManager.hpp>

#include <model/Gymkhana.hpp>
#include <StageWidget.hpp>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    connect(ui.actionCreateNewGymkhana, &QAction::triggered, this, &MainWindow::create_new_gymkhana);

	connect(ui.pushButton, &QAbstractButton::clicked, this, &MainWindow::add_stage_to_route);

	ui.RoutesTabWidget->clear();
}


void MainWindow::create_new_gymkhana()
{
	CreateGymkhawnaDialogue dialogue;

	if (dialogue.exec() == QDialog::Accepted)
	{

		auto text = dialogue.ui.NameInput->toPlainText().toStdString();
		auto version = dialogue.ui.VersionInput->toPlainText().toStdString();

		if (text.empty() || version.empty())
		{
			dialogue.ui.errorLabel->setText("Introduce a valid input.");
		}
		else
		{
			backend::GymkhanaManager::instance().get_gymkhana().change_name(text);
			ui.debugText->setText(text.c_str());
			dialogue.hide();

			
		}
	}
	else if (dialogue.exec() == QDialog::Rejected)
	{
		ui.debugText->setText("se ha cerrado el dialoguo");
		dialogue.hide();
	}
}

void MainWindow::add_stage_to_route()
{
	ui.RoutesTabWidget->addTab(new StageWidget(), { "f" });
}
