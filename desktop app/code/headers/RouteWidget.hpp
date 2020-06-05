#pragma once

#include <QWidget>
#include "ui_RouteWidget.h"

class RouteWidget : public QWidget
{
	Q_OBJECT

public:
	RouteWidget(QWidget *parent = Q_NULLPTR);
	~RouteWidget();

public:
	Ui::RouteWidget ui;
};
