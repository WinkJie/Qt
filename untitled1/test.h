#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QWidget>
#include "widget.h"

class Test : public QWidget
{
    Q_OBJECT
public:
    explicit Test(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // TEST_H
