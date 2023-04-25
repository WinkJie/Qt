#include "qpushbuttontest.h"

QPushButtonTest::QPushButtonTest(QWidget *parent)
{
    this->setParent(parent);
}

QPushButtonTest::QPushButtonTest()
{
    QSize a(160,160);
    SetSize(a);
}

QPushButtonTest::~QPushButtonTest()
{

}

void QPushButtonTest::SetNormalPixmap(QString strImagePath)
{
    m_NormalPix.load(strImagePath);
    m_iMask |= QPushButtonTestState::NORMAL;
}

void QPushButtonTest::SetHoverPixmap(QString strImagePath)
{
    m_HoverPix.load(strImagePath);
    m_iMask |= QPushButtonTestState::HOVER;
}

void QPushButtonTest::SetSelectedPixmap(QString strImagePath)
{
    m_SelectedPix.load(strImagePath);
    m_iMask |= QPushButtonTestState::SELECTED;
}

void QPushButtonTest::SetDisablePixmap(QString strImagePath)
{
    m_DisablePix.load(strImagePath);
    m_iMask |= QPushButtonTestState::DISABLE;
}

void QPushButtonTest::SetBtnState(QPushButtonTest::QPushButtonTestState state)
{
    m_lastState = m_curState;
    m_curState = state;
}

void QPushButtonTest::SetSize(QSize sz)
{
    m_NormalPix = m_NormalPix.scaled(sz);
    int iValue = m_iMask&QPushButtonTestState::HOVER;

    if (iValue != 0)
    {
        m_HoverPix = m_HoverPix.scaled(sz);
    }

    iValue = m_iMask&QPushButtonTestState::SELECTED;

    if (iValue != 0)
    {
        m_SelectedPix = m_SelectedPix.scaled(sz);
    }

    iValue = m_iMask&QPushButtonTestState::DISABLE;

    if (iValue != 0)
    {
        m_DisablePix = m_DisablePix.scaled(sz);
    }
}

void QPushButtonTest::paintEvent(QPaintEvent *event)
{
    //需要在paintEvent添加以下代码，否则设置按钮的样式表不起效果
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);

    //    QPixmap drawPix;
    //    if (m_curState == XBUTTONSTATE::NORMAL)
    //    {
    //        drawPix = m_NormalPix;
    //    }
    //    else if (m_curState == XBUTTONSTATE::HOVER)
    //    {
    //        int iValue = m_iMask&XBUTTONSTATE::HOVER;
    //        drawPix = (0 == iValue) ? m_NormalPix : m_HoverPix;
    //    }
    //    else if (m_curState == XBUTTONSTATE::SELECTED)
    //    {
    //        int iValue = m_iMask&XBUTTONSTATE::SELECTED;
    //        drawPix = (0 == iValue) ? m_NormalPix : m_SelectedPix;
    //    }
    //    else if (m_curState == XBUTTONSTATE::DISABLE)
    //    {
    //        int iValue = m_iMask&XBUTTONSTATE::DISABLE;
    //        drawPix = (0 == iValue) ? m_NormalPix : m_DisablePix;
    //    }
    //    QPainter painter(this);
    //    painter.drawPixmap(0, 0, drawPix);
}

void QPushButtonTest::enterEvent(QEvent *event)
{
    QApplication::setOverrideCursor(Qt::PointingHandCursor);
    //    SetBtnState(XBUTTONSTATE::HOVER);
    QPushButton::enterEvent(event);
    //    update();
}

void QPushButtonTest::mouseReleaseEvent(QMouseEvent *event)
{
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    //    m_curState =XBUTTONSTATE::NORMAL;
    QPushButton::mouseReleaseEvent(event);
    //    update();
}

void QPushButtonTest::mousePressEvent(QMouseEvent *event)
{
    QApplication::setOverrideCursor(Qt::PointingHandCursor);
    //   SetBtnState(XBUTTONSTATE::SELECTED);
    QPushButton::mousePressEvent(event);
    //   update();
}

void QPushButtonTest::leaveEvent(QEvent *event)
{
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    //    m_curState =XBUTTONSTATE::NORMAL;
    QPushButton::leaveEvent(event);
    //    update();
}

QPushButtonTest::QPushButtonTest(const QPushButtonTest &btn)
{

}

QPushButtonTest &QPushButtonTest::operator=(const QPushButtonTest &btn)
{
    return *this;
}
