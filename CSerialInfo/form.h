#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QToolTip>
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include <QVector>
#include <QtOpenGL/QtOpenGL>
#include <qopengl.h>
#include <QtOpenGL/QGLShader>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    QOpenGLBufferPrivate *s;
    bool enabled;
    bool isEnabled() const {return enabled;}
    void setEnabled(bool e){enabled = e;}


    void setData();

    void setLayoutAnd();

    QVector<QString> GetQrcListName();
    bool ConfirmPic(const QString &strName);
    QVector<QString> list;
    int numpic;
    bool setBackgroundLabel3();


public slots:
    void cellShow(int row,int colum);
private:
    Ui::Form *ui;
};

#endif // FORM_H
