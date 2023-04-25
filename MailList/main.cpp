#include "maillist.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MailList w;
    w.show();

    return a.exec();
}
