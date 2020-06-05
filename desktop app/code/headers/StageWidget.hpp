#pragma once

#include <QWidget>
#include "ui_StageWidget.h"

class StageWidget : public QWidget
{
	Q_OBJECT

public:
	StageWidget(QWidget *parent = Q_NULLPTR);
	~StageWidget();

private:
	Ui::StageWidget ui;
};
