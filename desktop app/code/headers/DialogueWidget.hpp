#pragma once

#include <QWidget>
#include "ui_DialogueWidget.h"

class DialogueWidget : public QWidget
{
	Q_OBJECT

public:
	DialogueWidget(QWidget *parent = Q_NULLPTR);
	~DialogueWidget();

public:
	Ui::DialogueWidget ui;

public slots:

	void add_monologue();
	
};
