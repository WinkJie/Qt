#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QTableWidget>
#include <QThread>
#include <QTableView>
#include <qdebug.h>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void Start();
signals:
    void startRunning(QString &);
    void startRunnings();
private:
    QTableView *m_pTestView=nullptr;
    QThread m_thread;
};

#endif // WIDGET_H
