#ifndef SEARCH_BOX_H
#define SEARCH_BOX_H

#include <QWidget>
#include <QAction>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTextBrowser>

class search_box : public QWidget
{
    Q_OBJECT
public:
    explicit search_box(QWidget *parent = nullptr);

private:
    QLineEdit *search_edit1, *search_edit2;
    QAction *search_action;
    QPushButton *search_btn;
    QTextBrowser *text;

signals:

public slots:

};

#endif // SEARCH_BOX_H
