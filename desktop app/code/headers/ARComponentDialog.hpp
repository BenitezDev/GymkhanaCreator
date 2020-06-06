#pragma once

#include <QWidget>
#include "ui_ARComponentDialog.h"

class ARComponentDialog : public QWidget
{
	Q_OBJECT

public:
	ARComponentDialog(QWidget *parent = Q_NULLPTR);
	~ARComponentDialog();

private:
	Ui::ARComponentDialog ui;
};
