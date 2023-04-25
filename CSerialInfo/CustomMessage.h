#ifndef CUSTOMMESSAGE_H
#define CUSTOMMESSAGE_H
#include "QDialog"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QString>

enum MsgBoxType
{
    MsgBoxType_Warn = 0,
    MsgBoxType_Info = 1,
    MsgBoxType_Error = 2
};

class CustomMessage : public QDialog
{
    Q_OBJECT
public:
    explicit CustomMessage(QWidget *parent, MsgBoxType type, QString text);


    void initState();

    void initWarn(const QString &text);
    void initError(const QString &text);
    void initInfo(const QString &text);

signals:

public slots:
    void dealbtnSureClicked();
    void dealbtnCancelClicked();

private:
    QLabel *labPic;
    QLabel *labNote;
    QPushButton *btnSure;
    QPushButton *btnCancle;
};

#endif // CUSTOMMESSAGE_H
