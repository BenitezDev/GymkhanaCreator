

#include <MainWindow.hpp>
#include <CreateGymkhawnaDialog.hpp>

#include <GymkhanaManager.hpp>

#include <model/Gymkhana.hpp>
#include <StageWidget.hpp>
#include <RouteWidget.hpp>

#include <AddStageComponentDialog.hpp>
#include <ARComponentDialog.hpp>
#include <ARComponentWidget.hpp>
#include <iostream>
#include <model/StateComponentAR.hpp>
#include <AddRouteDialog.hpp>

#include <model/Route.hpp>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	ui.AddRoute->hide();
	
    connect(ui.actionCreateNewGymkhana, &QAction::triggered, this, &MainWindow::create_new_gymkhana);
	connect(ui.AddRoute, &QAbstractButton::clicked, this, &MainWindow::add_route);

	connect(ui.actionSaveGymkhana, &QAction::triggered, this, &MainWindow::save);
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
				backend::GymkhanaManager::instance().create_gymkhana(text);
				ui.gymkhanaName->setText(gymkhana_name.c_str());
				std::cout << gymkhana_name << std::endl;
				ui.AddRoute->show();
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
	
	AddRouteDialog route_dialog;
	
	auto status = route_dialog.exec();
	std::string route_name = "";
	
	while (status != QDialog::Rejected)
	{

		if (status == QDialog::Accepted)
		{
			route_name = route_dialog.ui.RouteName->toPlainText().toStdString();

		
			if (route_name.empty())
			{

				status = route_dialog.exec();
			}
			else
			{
				auto new_route = new RouteWidget();
				routes.push_back(new_route);
				ui.RoutesTabWidget->addTab(new_route, route_name.c_str());

				connect(new_route->ui.AddStage, &QAbstractButton::clicked, this, &MainWindow::add_stage_to_route);
				
				route_dialog.hide();
				return;
			}
		}
	}
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

void MainWindow::save()
{
	backend::GymkhanaManager::instance().get_gymkhana();
	std::cout << "Rutas count: " << routes.size() << std::endl << std::endl;
	
	for(int i = 0; i < routes.size() ; ++i)
	{

		ui.RoutesTabWidget->setCurrentIndex(i);
		std::cout << "Rutas_" << i << std::endl;

		
		backend::Route route(ui.RoutesTabWidget->tabText(i).toStdString());
		
		
		int stages_count = dynamic_cast<RouteWidget*>(ui.RoutesTabWidget->currentWidget())->ui.StageLayout->count();
		std::cout << "    etapas:" << stages_count << std::endl;
		
		for(int j = 0; j < stages_count; ++j)
		{
			auto widget = dynamic_cast<RouteWidget*>(ui.RoutesTabWidget->currentWidget())->ui.StageLayout->itemAt(j)->widget();

			if(widget)
			{
				if(auto stage_widget = dynamic_cast<StageWidget*>(widget))
				{

					int components_count = stage_widget->ui.ComponentLayout->count();
					std::string stage_name = stage_widget->ui.StageName->toPlainText().toStdString();
					std::cout << "        "  << stage_name << "-" <<"componentes:" << components_count << std::endl;

					backend::Stage stage(stage_name);
					
					for(int k = 0; k < stage_widget->ui.ComponentLayout->count(); ++k)
					{
						auto ar_component = dynamic_cast<ARComponentWidget*>(stage_widget->ui.ComponentLayout->itemAt(k)->widget());
						
						if(ar_component)
						{
							std::cout << "            AR:" << std::endl;
							std::cout << "                img :" << ar_component->ui.ImageText->toPlainText().toStdString() << std::endl;
							std::cout << "                game:" << ar_component->ui.GameText->toPlainText().toStdString() << std::endl;

							
							std::shared_ptr<backend::StageComponentAR> component_ar
							{
								new backend::StageComponentAR
								{
									ar_component->ui.ImageText->toPlainText().toStdString(),
									ar_component->ui.GameText->toPlainText().toStdString()
								}
							};

							stage.add_component(component_ar);
						}
					}
					
					route.add_stage(stage);
				}
			}
		}

		backend::GymkhanaManager::instance().add_route(route);
		
	}
	
	backend::GymkhanaManager::instance().create_xml();

}
