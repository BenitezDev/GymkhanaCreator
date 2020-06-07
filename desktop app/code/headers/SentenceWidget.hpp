#pragma once

#include <QWidget>
#include "ui_SentenceWidget.h"

class SentenceWidget : public QWidget
{
	Q_OBJECT

public:
	SentenceWidget(QWidget *parent = Q_NULLPTR);
	~SentenceWidget();

public:
	Ui::SentenceWidget ui;
};
