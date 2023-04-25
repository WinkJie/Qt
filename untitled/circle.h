#ifndef CIRCLE_H
#define CIRCLE_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT Circle : public QWidget
{
    Q_OBJECT

public:
    Circle(QWidget *parent = nullptr);
};

#endif
