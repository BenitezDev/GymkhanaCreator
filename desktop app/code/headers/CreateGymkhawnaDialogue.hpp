#pragma once

#include <QDialog>
#include "ui_CreateGymkhawnaDialogue.h"

class CreateGymkhawnaDialogue : public QDialog
{
	Q_OBJECT

public:
	CreateGymkhawnaDialogue(QWidget *parent = Q_NULLPTR);
	~CreateGymkhawnaDialogue();

public:
	Ui::CreateGymkhawnaDialogue ui;
};
