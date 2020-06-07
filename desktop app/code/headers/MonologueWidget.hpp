#pragma once

#include <QWidget>
#include "ui_MonologueWidget.h"

class MonologueWidget : public QWidget
{
	Q_OBJECT

public:
	MonologueWidget(QWidget *parent = Q_NULLPTR);
	~MonologueWidget();

public:
	Ui::MonologueWidget ui;
};
