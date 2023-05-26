#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{




    QString pathName = "param.ini";
    QSettings settings(pathName,QSettings::IniFormat);
    QVector<double> speeds;
    speeds.clear();
    speeds.resize(9);
    QString SpeedList = "SpeedList/speed";
    QString SpeedSum="";
    for(int i=0;i<speeds.size();i++)
    {
        SpeedSum=SpeedList+QString::number(i).toStdString().c_str();
        speeds[i]=settings.value(SpeedSum).toDouble();
        if(QString::number(speeds[i]).toInt() == 0)
        {
            switch (i)
            {
            case 8:
                settings.setValue(SpeedSum,21.48);
                break;
            case 7:
                settings.setValue(SpeedSum,18.17);
                break;
            case 6:
                settings.setValue(SpeedSum,13.45);
                break;
            case 5:
                settings.setValue(SpeedSum,8.9);
                break;
            case 4:
                settings.setValue(SpeedSum,6.2);
                break;
            default:
                settings.setValue(SpeedSum,0);
                break;
            }
        }
    }
    qDebug()<<speeds<<endl;




    //    QFile file("my_file.ini");
    //    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    //    {
    //        qDebug() << "Failed to open the file:" << file.errorString();
    //        return ;
    //    }

    //    // 读取文件内容
    //    QByteArray content = file.readAll();
    //    qDebug() << "File content:" << content;

    //    // 在文件中写入内容
    //    QByteArray newData = "Hello, world!";
    //    qint64 bytesWritten = file.write(newData);
    //    qDebug() << "Bytes written:" << bytesWritten;

    ///////

//    QString filePath = "config.ini";
//    // 读取配置文件
//    QSettings settings(filePath, QSettings::IniFormat);
//    QString value1 = settings.value("section1/option1").toString();
//    int value2 = settings.value("section1/option2").toInt();
//    qreal value3 = settings.value("section2/option3").toReal();

//    qDebug() << "value1:" << value1;
//    qDebug() << "value2:" << value2;
//    qDebug() << "value3:" << value3;


//    if(value1.isEmpty())
//    {
//        // 写入配置文件
//        settings.setValue("section1/option1", "new_value");
//        settings.setValue("section1/option2", 12345);
//        settings.setValue("section2/option3", 3.14159265359);

//    }

}

Widget::~Widget()
{

}
