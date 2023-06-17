#ifndef CANVAS_H
#define CANVAS_H

#include <QDialog>
#include <QStandardItem>
#include <QStringListModel>
#include <QWidget>

namespace Ui {
class CanVas;
}

class CanVas : public QDialog
{
    Q_OBJECT
public:
    explicit CanVas(QWidget *parent = nullptr);
    ~CanVas();

public: //table
    void InitSum();
    void InitListView();
    void InitTreeView();
    void InitTableView();
    void InitGraphicsView();
    void InitColumnView();
    void InitOpenGLWidget();
    void InitCalendarWidget();
    void InitQuickWidget();
    void InitListWidget();
    void InitTreeWidget();
    void InitTableWidget();
    void InitTabWidget();
    void InitStackedWidget();
private:
    Ui::CanVas *ui;
};

#endif // CANVAS_H
