#include "options.h"

#include <QSettings>
#include <QDebug>


Options::Options() 
{
    qDebug() << "Initializing options";
}

void Options::Initialize()
{

    QSettings settings( "WhereIsTheMoon.ini", QSettings::IniFormat);

    geostationarylistlon = settings.value( "satellite/geostationarylistlon" ).value<QStringList>();
    geostationarylistname = settings.value( "satellite/geostationarylistname" ).value<QStringList>();
    geosatindex = settings.value( "satellite/geolastsat", 0).toInt();
    isit = settings.value( "satellite/isit", false).toBool();

    if(geostationarylistlon.count() == 0)
        checkStringListValues();

}

void Options::checkStringListValues()
{
    geostationarylistname.clear();
    geostationarylistlon.clear();
    geostationarylistname << "Meteosat-10" << "Meteosat-9"  << "Meteosat-8" << "Meteosat-7" << "FY2E" << "FY2G" << "GOES13" << "GOES15" << "Himawari-8";
    geostationarylistlon << "0.0" << "9.5" << "41.5" << "57" << "86.5" << "104.5" << "-74.9" << "-135.2" << "140.7";

}

void Options::Save()
{

    qDebug() << QString("Saving Options ");

    QSettings settings( "WhereIsTheMoon.ini", QSettings::IniFormat);

    settings.setValue( "satellite/geostationarylistlon", geostationarylistlon );
    settings.setValue( "satellite/geostationarylistname", geostationarylistname );
    settings.setValue( "satellite/geolastsat", geosatindex);
    settings.setValue( "satellite/isit", isit);

}

