#ifndef QPUSHBUTTONTEST_H
#define QPUSHBUTTONTEST_H
#include <QBitmap>
#include <QPainter>
#include <QDebug>
#include <QStyleOption>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class QPushButtonTest : public QPushButton
{
    Q_OBJECT
public:

    enum QPushButtonTestState
    {
        NORMAL = 0X01,//正常状态
        HOVER = 0X02,//鼠标滑过状态
        SELECTED = 0X04,//选中状态
        DISABLE = 0X08//禁止点击状态
    };

    explicit QPushButtonTest(QWidget *parent = Q_NULLPTR);
    QPushButtonTest();
    ~QPushButtonTest();


    //设置正常图标
    void SetNormalPixmap(QString strImagePath);
    //设置鼠标滑动图片
    void SetHoverPixmap(QString strImagePath);
    //设置选中状态图片
    void SetSelectedPixmap(QString strImagePath);
    //设置禁止点击图标
    void SetDisablePixmap(QString strImagePath);
    //设置按钮当前状态
    void SetBtnState(QPushButtonTestState state);
    //设置图片大小
    void SetSize(QSize sz);
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void enterEvent(QEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void leaveEvent(QEvent *event);
private:
    QPushButtonTest(const QPushButtonTest& btn);
    QPushButtonTest& operator=(const QPushButtonTest& btn);
private:
    QPixmap m_NormalPix;//正常图标
    QPixmap m_HoverPix;//鼠标滑动图标
    QPixmap m_SelectedPix;//选中状态图标
    QPixmap m_DisablePix;//禁止点击图标
    //包含1则启动正常图标，包含2启用滑动图标，
    //包含4启用选中状态图标，包含8启用禁止点击图标，默认标为1.
    int m_iMask;
    QPushButtonTestState m_curState;//当前状态
    QPushButtonTestState m_lastState;//上一次状态


signals:

public slots:
};

#endif // QPUSHBUTTONTEST_H


