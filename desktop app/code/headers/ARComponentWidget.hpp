#pragma once

#include <QWidget>
#include "ui_ARComponentWidget.h"

class ARComponentWidget : public QWidget
{
	Q_OBJECT

public:
	ARComponentWidget(QWidget *parent = Q_NULLPTR);
	~ARComponentWidget();

private:
	Ui::ARComponentWidget ui;
};
