#include "DialogueWidget.hpp"
#include <MonologueWidget.hpp>
#include <QtWidgets\qplaintextedit.h>
#include <SentenceWidget.hpp>

DialogueWidget::DialogueWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

DialogueWidget::~DialogueWidget()
{
}

void DialogueWidget::add_monologue()
{
	MonologueWidget* monologue_widget = new MonologueWidget;
	ui.MonologueScrollArea->setWidget(monologue_widget);

	connect(monologue_widget->ui.AddSentenceButton, &QAbstractButton::clicked, this, [=]() { add_sentence(monologue_widget); });
}

void DialogueWidget::add_sentence(MonologueWidget* monologue_widget)
{
	SentenceWidget* sentence = new SentenceWidget;
	monologue_widget->ui.SentencesLayout->addWidget(sentence);
	
}
