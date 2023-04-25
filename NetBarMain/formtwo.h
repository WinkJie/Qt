#ifndef FORMTWO_H
#define FORMTWO_H

#include <QWidget>

namespace Ui {
class FormTwo;
}

class FormTwo : public QWidget
{
    Q_OBJECT

public:
    explicit FormTwo(QWidget *parent = nullptr);
    ~FormTwo();

private:
    Ui::FormTwo *ui;
};

#endif // FORMTWO_H
