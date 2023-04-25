#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QImage>
#include <QPushButton>

class showwidget : public QWidget
{
       Q_OBJECT
public:
    explicit showwidget(QWidget *parent = 0);
    QPushButton *button1;

private:

signals:

private slots:
    void getxml();

};

#endif // SHOWWIDGET_H
