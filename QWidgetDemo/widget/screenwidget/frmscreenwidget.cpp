#include "frmscreenwidget.h"
#include "ui_frmscreenwidget.h"
#include "screenwidget.h"

frmScreenWidget::frmScreenWidget(QWidget *parent) : QWidget(parent), ui(new Ui::frmScreenWidget)
{
    ui->setupUi(this);
    ui->pushButton->setText(tr("截图"));
    ui->label->setText(tr("说明："));
    ui->pushButton->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_A));
}

frmScreenWidget::~frmScreenWidget()
{
    delete ui;
    exit(0); 
}

void frmScreenWidget::on_pushButton_clicked()
{
    ScreenWidget::Instance()->showFullScreen();
}
