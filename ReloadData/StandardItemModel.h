#ifndef STANDARDITEMMODEL_H
#define STANDARDITEMMODEL_H
#include <QStandardItemModel>
#include <QObject>


static const char* DefQSReceiverInfoTableSize[20][3] =
{
    {"ID" , "130", "0"},
    {"Line" , "110", "0"},
    {"Point" , "110", "0"},
    {"Index" , "60", "0"},
    {"Type" , "60", "0"},
    {"X" , "120", "0"},
    {"Y" , "120", "0"},
    {"Z" , "120", "0"},
    {"Lat.-084" , "180", "0"},
    {"Long.-084" , "180", "0"},
    {"Elav.-84" , "180", "0"},
    {"Status" , "100", "0"},
    {"Point Depth" , "120", "0"},
    {"Water Depth" , "120", "0"},
    {"Seis Datum" , "150", "0"},
    {" " , "150", "0"},
    {" " , "150", "0"},
    {" " , "150", "0"},
    {" " , "150", "0"}
};


class StandardItemModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit StandardItemModel(QObject *parent = nullptr);
    ~StandardItemModel();
signals:

public slots:
    void CreateData(QString &i_path);
    void CreateDatas();

};

#endif // STANDARDITEMMODEL_H
