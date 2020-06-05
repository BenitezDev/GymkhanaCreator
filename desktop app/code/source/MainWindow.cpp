

#include <MainWindow.hpp>
#include <CreateGymkhawnaDialogue.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    connect(ui.actionCreateNewGymkhana, &QAction::triggered, this, &MainWindow::create_new_gymkhana);
    
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
			ui.debugText->setText(text.c_str());
			dialogue.hide();
		}
	}
	if (dialogue.exec() == QDialog::Rejected)
	{
		ui.debugText->setText("se ha cerrado el dialoguo");
		dialogue.hide();
	}
}
