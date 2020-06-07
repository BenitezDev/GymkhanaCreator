#pragma once

#include <QDialog>
#include "ui_AddRouteDialog.h"

class AddRouteDialog : public QDialog
{
	Q_OBJECT

public:
	AddRouteDialog(QWidget *parent = Q_NULLPTR);
	~AddRouteDialog();

public:
	Ui::AddRouteDialog ui;
};
