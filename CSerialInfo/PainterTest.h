#ifndef PAINTERTEST_H
#define PAINTERTEST_H

#include <QWidget>

class PainterTest : public QWidget
{
    Q_OBJECT
public:
    explicit PainterTest(QWidget *parent = nullptr);




    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // PAINTERTEST_H
