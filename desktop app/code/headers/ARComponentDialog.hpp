#pragma once

#include <QDialog>
#include "ui_ARComponentDialog.h"

class ARComponentDialog : public QDialog
{
	Q_OBJECT

public:
	ARComponentDialog(QWidget *parent = Q_NULLPTR);
	~ARComponentDialog();

public:
	Ui::ARComponentDialog ui;
};
