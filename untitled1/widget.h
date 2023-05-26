#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QFile>
#include <QDebug>
#include <QSettings>

class Widget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    int value() const { return m_value; }
    void setValue(int value)
    {
        if (value != m_value)
        {
            m_value = value;
            emit valueChanged(m_value);
        }
    }

signals:
    void valueChanged(int newValue);

private:
    int m_value;
};

#endif // WIDGET_H
