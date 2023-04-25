#ifndef NOUIINTERFACE_H
#define NOUIINTERFACE_H
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>


class NoUiInterface:public QMainWindow
{
    Q_OBJECT
public:
    explicit NoUiInterface(QWidget *parent=nullptr);
    ~NoUiInterface();
    void setupUi();
    void SetUpUi();

    enum TypeInterface
    {/*使用枚举控制界面的变化*/
        NORMAL = 0X01,//正常状态
        HOVER = 0X02,//鼠标滑过状态
        SELECTED = 0X04,//选中状态
        DISABLE = 0X08//禁止点击状态
    };
public:
    int typeInt;


private:
    QWidget *widget;
    QVBoxLayout *vLayout;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
private:
    QString m_filePath;
    QMenuBar *m_menuBar;
    QMenu *m_fileMenu;
    QTextEdit *textEdit;
    //Ui::MainWindow *ui;
public slots:
    void openFileSlot();
    void saveFileSlot();
    void newFileSlot();
    bool saveAsSlot();




};

#endif // NOUIINTERFACE_H
