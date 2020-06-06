#pragma once

#include <QDialog>
#include "ui_AddStageComponentDialog.h"

class AddStageComponentDialog : public QDialog
{
	Q_OBJECT

public:
	AddStageComponentDialog(QWidget *parent = Q_NULLPTR);
	~AddStageComponentDialog();

public:
	Ui::AddStageComponentDialog ui;
};
