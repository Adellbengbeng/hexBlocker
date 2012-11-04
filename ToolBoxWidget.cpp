#include "ToolBoxWidget.h"
#include "ui_ToolBoxWidget.h"
#include "CreateBlockWidget.h"
#include "MoveVerticesWidget.h"
#include "SetBCsWidget.h"
#include <QWidget>

ToolBoxWidget::ToolBoxWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ToolBoxWidget)
{
    ui->setupUi(this);

    emptyPage = new QWidget;
    this-ui->stackedWidget->addWidget(emptyPage);
    createBlockW = new CreateBlockWidget;
    this->ui->stackedWidget->addWidget(createBlockW);
    moveVerticesW = new MoveVerticesWidget;
    this->ui->stackedWidget->addWidget(moveVerticesW);
    setBCsW = new SetBCsWidget;
    this->ui->stackedWidget->addWidget(setBCsW);
    this->ui->stackedWidget->setCurrentIndex(1);

    //connecta alla cancels till att köra setCurrentIndex(0)
    connect(createBlockW,SIGNAL(cancel()),this,SLOT(slotCancel()));
    connect(setBCsW,SIGNAL(done()),this,SLOT(slotCancel()));
    connect(moveVerticesW,SIGNAL(setStatusText(QString)),this,SLOT(slotSetStatusText(QString)));
    connect(createBlockW,SIGNAL(setStatusText(QString)),this,SLOT(slotSetStatusText(QString));
    connect(setBCsW,SIGNAL(setStatusText(QString)),this,SLOT(slotSetStatusText(QString)));

}

ToolBoxWidget::~ToolBoxWidget()
{
    delete ui;
}

void ToolBoxWidget::setCurrentIndex(int ind)
{
    this->ui->stackedWidget->setCurrentIndex(ind);
}

void ToolBoxWidget::slotCancel()
{
    this->ui->stackedWidget->setCurrentIndex(0);
    emit cancel();
}

void ToolBoxWidget::slotSetStatusText(QString text)
{
    emit setStatusText(text);
}
