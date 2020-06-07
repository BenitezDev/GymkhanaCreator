#include <MainWindow.hpp>
#include <CreateGymkhawnaDialog.hpp>
#include <GymkhanaManager.hpp>
#include <model/Gymkhana.hpp>
#include <StageWidget.hpp>
#include <RouteWidget.hpp>
#include <AddStageComponentDialog.hpp>
#include <ARComponentWidget.hpp>
#include <iostream>
#include <model/StateComponentAR.hpp>
#include <AddRouteDialog.hpp>
#include <DialogueWidget.hpp>
#include <MonologueWidget.hpp>
#include <model/Route.hpp>
#include <model/Monologue.hpp>
#include <SentenceWidget.hpp>
#include "model/StageComponentDialogue.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	ui.AddRoute->hide();

	// Connect the Actio of Create gymkhana
    connect(ui.actionCreateNewGymkhana, &QAction::triggered, this, &MainWindow::create_new_gymkhana);
	// Connect the (hiden) button of create route
	connect(ui.AddRoute, &QAbstractButton::clicked, this, &MainWindow::add_route);
	// Connect the action of save gymkhana
	connect(ui.actionSaveGymkhana, &QAction::triggered, this, &MainWindow::save);

	// Clean all the widget
	ui.RoutesTabWidget->clear();
	
	routes.clear();
}


void MainWindow::create_new_gymkhana()
{
	// Display the dialogue
	CreateGymkhawnaDialogue dialogue;
	
	auto text = dialogue.ui.NameInput->toPlainText().toStdString();

	auto status = dialogue.exec();

	while(status != QDialog::Rejected)
	{
		
		if (status == QDialog::Accepted)
		{
			text = dialogue.ui.NameInput->toPlainText().toStdString();

			// Validate input
			if (text.empty())
			{
				dialogue.ui.errorLabel->setText("Introduce a valid input."); 
				status = dialogue.exec();
			}
			else
			{
				std::string gymkhana_name = "Gymkhana: ";
				gymkhana_name += text;
				ui.gymkhanaName->setText(gymkhana_name.c_str());
				
				ui.RoutesTabWidget->clear(); // Reset the widget

				// Create the internal gymkhana
				backend::GymkhanaManager::instance().create_gymkhana(text);

				// show the add route button
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
	// Create the widget
	const auto new_stage = new StageWidget();

	// Add the widget to the route widget
	dynamic_cast<RouteWidget*>(ui.RoutesTabWidget->currentWidget())->ui.StageLayout->addWidget(new_stage);

	// Configure the add component button
	connect(new_stage->ui.AddComponent, &QAbstractButton::clicked, this, [=]() { show_all_stage_components(new_stage); });
}

void MainWindow::add_route()
{
	// Create the widget
	AddRouteDialog route_dialog;
	
	auto status = route_dialog.exec();
	std::string route_name = "";
	
	while (status != QDialog::Rejected)
	{

		if (status == QDialog::Accepted)
		{
			route_name = route_dialog.ui.RouteName->toPlainText().toStdString();

			// Validate input
			if (route_name.empty())
			{
				status = route_dialog.exec();
			}
			else
			{
				// Create the route
				const auto new_route = new RouteWidget();
				routes.push_back(new_route);

				// Add it to the tab
				ui.RoutesTabWidget->addTab(new_route, route_name.c_str());

				// Configure the button
				connect(new_route->ui.AddStage, &QAbstractButton::clicked, this, &MainWindow::add_stage_to_route);
				
				route_dialog.hide();
				return;
			}
		}
	}
}

void MainWindow::show_all_stage_components(StageWidget* stage)
{
	// Create the dialog
	AddStageComponentDialog* componentPanel = new AddStageComponentDialog();
	
	componentPanel->setWindowTitle({ "Select a component to add" });
	
	// Connect all components
	connect(componentPanel->ui.ARComponent       , &QAbstractButton::clicked, this, [=]() { add_ar_component_to_stage       (stage, componentPanel); });
	connect(componentPanel->ui.MonologueComponent, &QAbstractButton::clicked, this, [=]() { add_monologue_component_to_stage(stage, componentPanel); });

	// Show the dialog
	componentPanel->exec();
}

void MainWindow::add_ar_component_to_stage(StageWidget* stage, AddStageComponentDialog* all_components_dialog)
{
	// add the widget
	stage->ui.ComponentLayout->addWidget(new ARComponentWidget);

	all_components_dialog->hide();
}

void MainWindow::add_monologue_component_to_stage(StageWidget* stage, AddStageComponentDialog* all_components_dialog)
{
	DialogueWidget* dialogue_widget = new DialogueWidget;

	// Add a monologue (1 monologue at least in the component)
	dialogue_widget->add_monologue(); 

	// Add the widget
	stage->ui.ComponentLayout->addWidget(dialogue_widget);

	all_components_dialog->hide();
}

void MainWindow::save()
{

	std::cout << "Rutas count: " << routes.size() << std::endl << std::endl;

	// for all routes
	for(int i = 0; i < routes.size() ; ++i)
	{
		// set the current tab
		ui.RoutesTabWidget->setCurrentIndex(i);
		
		std::cout << "Rutas_" << i << std::endl;

		// Create the route
		backend::Route route(ui.RoutesTabWidget->tabText(i).toStdString());

		// Get the stage count
		int stages_count = dynamic_cast<RouteWidget*>(ui.RoutesTabWidget->currentWidget())->ui.StageLayout->count();
		std::cout << "    Etapas:" << stages_count << std::endl;

		// For all stages
		for(int j = 0; j < stages_count; ++j)
		{
			auto widget = dynamic_cast<RouteWidget*>(ui.RoutesTabWidget->currentWidget())->ui.StageLayout->itemAt(j)->widget();

			if(widget)
			{
				// check only for StageWidget
				if(auto stage_widget = dynamic_cast<StageWidget*>(widget))
				{
					// Get the count of components in the stage
					int components_count   = stage_widget->ui.ComponentLayout->count();
					std::string stage_name = stage_widget->ui.StageName->toPlainText().toStdString();
					
					std::cout << "        "  << stage_name << "-" <<"componentes:" << components_count << std::endl;

					// Create the stage
					backend::Stage stage(stage_name);

					// For all the components
					for(int k = 0; k < stage_widget->ui.ComponentLayout->count(); ++k)
					{
						// Check the type of component

						// AR component found
						if(auto ar_component = dynamic_cast<ARComponentWidget*>(stage_widget->ui.ComponentLayout->itemAt(k)->widget()))
						{
							std::cout << "            AR:" << std::endl;
							std::cout << "                img :" << ar_component->ui.ImageText->toPlainText().toStdString() << std::endl;
							std::cout << "                game:" << ar_component->ui.GameText->toPlainText().toStdString() << std::endl;

							// Create the component
							std::shared_ptr<backend::StageComponentAR> component_ar
							{
								new backend::StageComponentAR
								{
									ar_component->ui.ImageText->toPlainText().toStdString(),
									ar_component->ui.GameText->toPlainText().toStdString()
								}
							};

							// Add it to the stage components
							stage.add_component(component_ar);
						}
						// Dialogue component found
						else if(auto dialog_comp = dynamic_cast<DialogueWidget*>(stage_widget->ui.ComponentLayout->itemAt(k)->widget()))
						{
							// Get the MonologueWidget
							auto monologue = dialog_comp->ui.MonologueScrollArea->findChild<MonologueWidget*>("MonologueWidget");
							
							// Getting the sentences
							std::vector<std::string> sentences;

							// For all sentences
							for (int l = 0; l < monologue->ui.SentencesLayout->count(); ++l)
							{
								// check the widget
								auto w = monologue->ui.SentencesLayout->itemAt(l)->widget();
								if(auto sentence = dynamic_cast<SentenceWidget*>(w))
								{
									// get the user input and add it to our vector
									sentences.push_back(sentence->ui.plainTextEdit->toPlainText().toStdString());
								}
							}

							// Create the monologue
							backend::Monologue monologues 
							{
								monologue->ui.CharacterText->toPlainText().toStdString(),
								sentences,
								monologue->ui.SideText->toPlainText().toStdString()	
							};


							std::cout << "            Dialog:" << std::endl;
							std::cout << "                Character:" << monologue->ui.CharacterText->toPlainText().toStdString() << std::endl;
							std::cout << "                Side:" << monologue->ui.SideText->toPlainText().toStdString() << std::endl;
							for(int z = 0; z < sentences.size(); z++)
							{
								std::cout << "                    Sentence_" << z<< ":" <<sentences[z] << std::endl;	
							}

							// Add it to the stage component
							std::shared_ptr<backend::StageComponentDialogue> component_dialogue{ new backend::StageComponentDialogue({monologues}) };
							
							stage.add_component(component_dialogue);
						}
					}

					// Add the stage (with all the components) to the route
					route.add_stage(stage);
				}
			}
		}
		
		// Add the route (with all the stages) to the gymkhana
		backend::GymkhanaManager::instance().add_route(route);
	}

	// All the data is loaded. Create the xml with the data
	backend::GymkhanaManager::instance().create_xml();

}
