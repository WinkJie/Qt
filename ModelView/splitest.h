#ifndef SPLITEST_H
#define SPLITEST_H


#include <QMainWindow>
#include <QWidget>
#include <QSplitter>
#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <string.h>
#include <QDebug>
#include <QTextCodec>
#include <QEventLoop>

#include "nouiinterface.h"

class SpliTest:public QSplitter
{
    Q_OBJECT
public:
    //SpliTest(QWidget *parent = nullptr);
    SpliTest();
    void ops();



};

#endif // SPLITEST_H
