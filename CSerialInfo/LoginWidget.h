#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QDirIterator>
#include <QVector>
#include <QLabel>
#include <QMessageBox>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

    bool readStyleSheet(const QString &s);

    bool setBackgroundLabel3();

    QVector<QString> GetQrcListName();
    bool ConfirmPic(const QString &strName);

    QVector<QString> list;
    int numpic;
public slots:
    void emiso();


signals:
    void slo();

private:
    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H
