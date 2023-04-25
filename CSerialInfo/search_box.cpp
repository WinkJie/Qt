#include "search_box.h"
#include <QIcon>
#include <QHBoxLayout>
#include <QString>

search_box::search_box(QWidget *parent) : QWidget(parent)
{
    this->setWindowIcon(QIcon(":/image/搜索.png"));
    this->resize(600, 600);
    this->setWindowTitle("自定义搜索框");
    setMinimumHeight(50);
    //方法一

    //搜索按钮
    search_btn = new QPushButton(this);
    search_btn->setFixedSize(32, 32);//设置固定大小
    search_btn->setFlat(true);//去掉按钮边框
    search_btn->setToolTip("搜索");//设置鼠标悬浮的提示
    search_btn->setStyleSheet("QPushButton {background-image: url(:/image/搜索.png)}");//设置样式表

    connect(search_btn, &QPushButton::clicked, [&](){
        text->append(QString("第一个搜索框输入的内容为: %1").arg(search_edit1->text()));
    });

    //第一个编辑框
    search_edit1 = new QLineEdit(this);
    search_edit1->setGeometry(100, 50, 400, 50);//设置编辑框位置大小
    search_edit1->setPlaceholderText("请输入你想要搜索的内容");//设置编辑框没有输入内容时的友好提示
    search_edit1->setTextMargins(0, 0, search_btn->width(), 0);//设置编辑框文字的边距，防止文字写到按钮上 参数：左 上 右 下

    //水平布局
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addStretch();
    hlayout->addWidget(search_btn);
    hlayout->setContentsMargins(0, 0, 0, 0);//设置布局的边距

    //第一个编辑框添加布局（将按钮放在编辑框上）
    search_edit1->setLayout(hlayout);

//    //方法二

//    //QAction
//    search_action = new QAction;
//    search_action->setToolTip("搜索");//设置鼠标悬浮的提示
//    search_action->setIcon(QIcon(":/image/搜索.png"));//加载显示图片
//    connect(search_action, &QAction::triggered, [&](){
//        text->append(QString("第二个搜索框输入的内容为: %1").arg(search_edit2->text()));
//    });

//    //第二个编辑框
//    search_edit2 = new QLineEdit(this);
//    search_edit2->setGeometry(100, 150, 400, 50);//设置编辑框位置大小
//    search_edit2->setPlaceholderText("请输入你想要搜索的内容");//设置编辑框没有输入内容时的友好提示

//    //TrailingPosition:将action放置在右边
//    search_edit2->addAction(search_action, QLineEdit::TrailingPosition);
//    //LeadingPosition:将action放置在左边
//    //search_edit2->addAction(search_action, QLineEdit::LeadingPosition);

//    //初始化QTextBrowser
//    text = new QTextBrowser(this);
//    text->setGeometry(100, 250, 400, 300);

}
