#ifndef CSERIALINFO_H
#define CSERIALINFO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTableView>
#include <QStandardItemModel>
#include <QList>
#include <QDebug>
#include <QHeaderView>
#include <QFile>
#include <QCoreApplication>
#include <QDir>
#include <QComboBox>
#include <QMessageBox>
#include <QToolButton>
#include <QSplitter>

#include <QScreen>
#include <windows.h>
#include "search_box.h"
#include "Widget.h"
#include "form.h"
#include "drawDemo.h"
#include "WidgetPlus.h"


//namespace SerialData
//{

struct reSerialData
{
    QString s_name;
    QString s_ip;
    QString s_a;
    QString s_b;
    QString s_c;
    QString s_d;
};


class CSerialInfo : public QWidget
{
    Q_OBJECT

public:
    CSerialInfo(QWidget *parent = nullptr);
    ~CSerialInfo();
public:
    QList<reSerialData *> data;
    /*测试*/
public:
    //void newAnalogData();
public:
    bool readStyleSheet(const QString &s);
    void AllLayout();
    void setAllLayout();
    void setQPushButtonstyle();
    void createListSerial();
    void createListNet();
private:
    QVBoxLayout *l_thislayout; //列
    QHBoxLayout *l_tablelayout; //行
    QHBoxLayout *l_navilayout; //行
    QHBoxLayout *l_table1layout; //行
    QHBoxLayout *l_tailLayout;
    QLabel      *l_label;
    QLabel      *l_labeltable;
    QLabel      *l_labeltable1;
    QLineEdit   *e_edittable;
    QLineEdit   *e_edittable1;
    QWidget     *e_editwidget;
    QHBoxLayout *l_editlayout;
    QLineEdit   *e_edit;
    search_box   *myedit;
    QPushButton *e_pushbutton;
    QComboBox   *c_box;
    QTableView *t_tableview;
    QStandardItemModel *m_model;
    QTableView *t_tableview1;
    QStandardItemModel *m_model1;
    QPushButton *b_add;
    QPushButton *b_reset;
    QPushButton *b_return;
    QPushButton *b_edit;
     WidgetPlus *s;
public slots:

signals:


};
//}

#endif // CSERIALINFO_H
