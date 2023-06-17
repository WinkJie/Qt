#ifndef CANVASRENAME_H
#define CANVASRENAME_H

#include <QWidget>
#include <QDialog>
#include <QStandardItem>
#include <QStringListModel>

namespace Ui {
class CanvasRename;
}

class CanvasRename : public QWidget
{
    Q_OBJECT

public:
    explicit CanvasRename(QWidget *parent = nullptr);
    ~CanvasRename();


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
    Ui::CanvasRename *ui;
};

#endif // CANVASRENAME_H
