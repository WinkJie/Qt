#ifndef MAILLIST_H
#define MAILLIST_H

#include <string.h>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHeaderView>
#include <QList>
#include <QVector>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <qdebug.h>

#include <iostream>

class MailList : public QWidget
{
    Q_OBJECT
public:
    MailList(QWidget *parent = nullptr);
    ~MailList();

    void setLayout();
    void CreateList();
    void InsertDataList();
    void readDataFromText();

    struct Person
    {
        QString id;
        QString name;
        QString addr;
        QString tele;
        QString sex;
        QString age;
    }person;



private:
    QTableWidget *tableWidget;
    QPushButton  *btn1;
    QPushButton  *btn2;
    QPushButton  *btn3;
    QPushButton  *btn4;
    QLabel       *label;
    QLineEdit    *editSearch;
    QPushButton  *Searchbtn;
    QPushButton  *CancelSearchbtn;
    QHBoxLayout  *naviLayout;
    QHBoxLayout  *layHBox;
    QVBoxLayout  *layVBox;
    QGridLayout  *layGriBox;

    QList<Person> personList;

public slots:
    //void CatBtn();
    void GetPosXY();
    void TextChanged(const QString &s);



};

#endif // MAILLIST_H
