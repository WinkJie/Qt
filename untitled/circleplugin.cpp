#include "circle.h"
#include "circleplugin.h"

#include <QtPlugin>

CirclePlugin::CirclePlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void CirclePlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool CirclePlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *CirclePlugin::createWidget(QWidget *parent)
{
    return new Circle(parent);
}

QString CirclePlugin::name() const
{
    return QLatin1String("Circle");
}

QString CirclePlugin::group() const
{
    return QLatin1String("");
}

QIcon CirclePlugin::icon() const
{
    return QIcon(QLatin1String(":/微信图片_20200709222313.jpg"));
}

QString CirclePlugin::toolTip() const
{
    return QLatin1String("");
}

QString CirclePlugin::whatsThis() const
{
    return QLatin1String("");
}

bool CirclePlugin::isContainer() const
{
    return false;
}

QString CirclePlugin::domXml() const
{
    return QLatin1String("<widget class=\"Circle\" name=\"circle\">\n</widget>\n");
}

QString CirclePlugin::includeFile() const
{
    return QLatin1String("circle.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(circleplugin, CirclePlugin)
#endif // QT_VERSION < 0x050000
