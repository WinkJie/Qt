#include <QApplication>
#include "splitest.h"
#include "nouiinterface.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QTime>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //SpliTest *w=new SpliTest;
#if 0
    MainWindow w;
    w.show();
#endif
#if 1
    NoUiInterface w;
    w.typeInt=NoUiInterface::TypeInterface::HOVER;
    w.show();
#endif

#if 0
    SpliTest w ;
    w.ops();
#endif

    return a.exec();
}


/*

1、身份证、毕业证及职称证等相关证件的原件及复印件一份；

 2、毕业证验证证明《教育部学历证书电子注册备案表》复印件一份；

3、与最后一家单位解除劳动关系的证明材料原件；

4、请准备 1 寸照片 3 张及电子档照片一份。要求：1 寸、深色上衣的白底彩照；像素为 295*413 左右，
大小在 500K 以内；照片格式为 JPG；

5、以个人名义开户的中国银行储蓄卡复印件一份，在空白处将卡号抄写一遍，并由本人在复印件上
签名确认；

6、请在早上期间带一张一寸照片到所在地市（县）或区级以上医院空腹参加入职常规体检，并于报
到当天提交体检单原件。

7、 如需办理社保、公积金相关转移，请提交相关转移单据手续办理。

8、 请入职前三天邮件查收并填写人力中心《完善入职信息登记表》，并按第 4 条的要求上传电子档 1
寸照片。如在“开户网点”一栏无法搜查到开户网点，请按照以下两个步骤操作：
（1） 请选择支行的上一级，到市级分行。
举例:找不到“中国建设银行厦门莲前支行”，就选择“中国建设银行股份有限公司厦门市分行”。
（2） 若是第（1）步骤仍选择不到相关分行，再选择"未提供”。

*/
