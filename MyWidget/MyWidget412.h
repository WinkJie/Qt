#ifndef MYWIDGET412_H
#define MYWIDGET412_H

#include <QWidget>

class MyWidget412 : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget412(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;

protected:


    bool event(QEvent *event) override
        {
            if (event->type() == QEvent::MouseButtonPress) {
                QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
                QApplication::sendEvent(&obj, mouseEvent);
                return true;
            }
            return QWidget::event(event);
        }

signals:

public slots:
};

#endif // MYWIDGET412_H
