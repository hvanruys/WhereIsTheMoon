#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AA+.h"
#include <cstdio>
#include <cmath>
#include <QDebug>
#include "options.h"

extern Options opts;

void HoursTohms(double inhours, int &hours, int &minutes, int &seconds)
{

    hours = (int)(inhours);
    double drest = inhours - hours;
    int bla = (int)(drest*3600.0);
    minutes = bla/60;
    seconds = bla%60;

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "opts.geolastsat = " << opts.geosatindex;

    scale = 20;
    scene = new GridScene(-1000, -1000, 2000, 2000, scale);

    z = new Graphics_view_zoom(ui->graphicsView);
    z->set_modifiers(Qt::NoModifier);

    ui->graphicsView->setScene(scene);
    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    QBrush moonBrush(Qt::yellow);
    QBrush earthBrush(Qt::blue);
    QPen blackpen(Qt::black);
    blackpen.setWidth(1);

    earth = scene->addEllipse(-8.7*scale, -8.7*scale, 17.4*scale, 17.4*scale,blackpen, earthBrush);
    earth->setZValue(-1);

    //CalcMoon(ui->calendarWidget->selectedDate());

     connect(ui->calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(CalcMoon(QDate)));

     SetupCombo();
     ui->cmbGeoSat->setCurrentIndex(opts.geosatindex);

     //QString strlon = opts.geostationarylistlon.at(ui->cmbGeoSat->currentIndex());

     QStringList::Iterator itslon = opts.geostationarylistlon.begin();
     while( itslon != opts.geostationarylistlon.end() )
     {
         // For AA+ longitudes West are positive, hence 180.0 - lon;
         //qDebug() << QString("name = %1").arg(*itsname);
         double opposietlong = CAACoordinateTransformation::MapToMinus180To180Range(180 - (*itslon).toFloat());
         qDebug() << "lon = " << (*itslon) << " opposietlong = " << opposietlong;
         geolonlist << opposietlong;
         ++itslon;
     }


}

void MainWindow::SetupCombo()
{
    QStringList items;

    for (int i = 0; i < opts.geostationarylistname.size(); ++i)
    {
        float lon = opts.geostationarylistlon.at(i).toFloat();
        QString eastwest = lon > 0 ? "E" : "W";
        items << QString("%1  %2 %3").arg(opts.geostationarylistname.at(i)).arg(fabs(lon)).arg(eastwest);
    }
    ui->cmbGeoSat->addItems(items);
}

void MainWindow::CalcMoon(QDate selected)
{
    double hours, minutes;
    int day, year, month;

    year = selected.year();
    month = selected.month();
    day = selected.day();

    QBrush moonBrush(Qt::yellow);
    QPen blackpen(Qt::black);
    blackpen.setWidth(1);

    while (!moonlist.isEmpty())
        scene->removeItem(moonlist.takeFirst());
    moonlist.clear();

    while (!textlist.isEmpty())
        scene->removeItem(textlist.takeFirst());
    scene->update();
    textlist.clear();


    qDebug() << QString("Calculating for satellite at %1°").arg(geolonlist.at(geosatindex));

    ui->listWidget->clear();

    for( int hours = 0; hours < 24; hours++)
    {
        for( int minutes = 0; minutes < 60; minutes += 10)
        {
            double dday =  static_cast<double>(day) + static_cast<double>(hours)/24.0 + static_cast<double>(minutes)/(24.0*60.0);
            double JD = CAADate::DateToJD(year, month, dday, true);

            double JDMoon = CAADynamicalTime::UTC2TT(JD);
            double MoonLong = CAAELP2000::EclipticLongitude(JDMoon);
            double MoonLat = CAAELP2000::EclipticLatitude(JDMoon);

            int MoonLongdeg, MoonLongmin, MoonLongsec;
            int MoonLatdeg, MoonLatmin, MoonLatsec;
            HoursTohms(MoonLong, MoonLongdeg, MoonLongmin, MoonLongsec);
            HoursTohms(MoonLat, MoonLatdeg, MoonLatmin, MoonLatsec);
            CAA2DCoordinate Equatorial = CAACoordinateTransformation::Ecliptic2Equatorial(MoonLong, MoonLat, CAANutation::TrueObliquityOfEcliptic(JDMoon));
            double MoonRad = CAAELP2000::RadiusVector(JDMoon);
            //MoonRad /= 149597870.691; //Convert KM to AU
            double AST = CAASidereal::ApparentGreenwichSiderealTime(JDMoon);
            double LongtitudeAsHourAngle = CAACoordinateTransformation::DegreesToHours( geolonlist.at(geosatindex) );
            double LocalHourAngle = AST - LongtitudeAsHourAngle - Equatorial.X;

            double LHA = CAACoordinateTransformation::MapTo0To24Range(LocalHourAngle);
            int LHAhour, LHAmin, LHAsec;
            HoursTohms(LHA, LHAhour, LHAmin, LHAsec);
            int DEdeg, DEmin, DEsec;
            HoursTohms(Equatorial.Y, DEdeg, DEmin, DEsec);
            int RAhour, RAmin, RAsec;
            HoursTohms(Equatorial.X, RAhour, RAmin, RAsec);
            //printf("%d/%d/%d %2d:%02d UTC Ecliptic long = %02d°%02d'%02d\" lat = %02d°%02d'%02d\" RA = %02dh%02dm%02ds localHourAngle = %02dh%02dm%02ds DE = %02d°%02d'%02d\" MoonRad = %f\n",
            //   year, month, day, hours, minutes, MoonLongdeg, MoonLongmin, MoonLongsec, MoonLatdeg, MoonLatmin, MoonLatsec, RAhour, RAmin, RAsec, LHAhour, LHAmin, LHAsec, DEdeg, DEmin, DEsec, MoonRad);

            double diffangle = 20.0;

            double HourAngleDegrees = CAACoordinateTransformation::MapToMinus180To180Range(CAACoordinateTransformation::HoursToDegrees(LHA));
            double DecLHA = sqrt(HourAngleDegrees * HourAngleDegrees + Equatorial.Y * Equatorial.Y);
            double parallax = 5.92 * sin(CAACoordinateTransformation::DegreesToRadians(DecLHA));
            double deltaY = Equatorial.Y*parallax/DecLHA;
            double deltaX = HourAngleDegrees*parallax/DecLHA;

            double illuminated_fraction = 0;
            double position_angle = 0;
            double phase_angle = 0;
            GetMoonIllumination(JD, true, illuminated_fraction, position_angle, phase_angle);

            if(HourAngleDegrees - deltaX > -diffangle && HourAngleDegrees - deltaX < diffangle && Equatorial.Y - deltaY < diffangle && Equatorial.Y - deltaY > -diffangle)
            {

                printf("==%d/%d/%d %2d:%02d UTC Ecliptic long = %f° lat = %f° RA = %fh DE = %f° localHourAngle = %f° AST = %f MoonRad = %f parallax = %f\n",
                       year, month, day, hours, minutes, MoonLong, MoonLat, Equatorial.X, Equatorial.Y, HourAngleDegrees, AST, MoonRad, parallax);
                fflush(stdout);

                int mooncoordX = (int)((HourAngleDegrees - deltaX) * scale);
                int mooncoordY = - (int)((Equatorial.Y - deltaY) * scale);

                moonlist.append(scene->addEllipse(mooncoordX - 0.25*scale, mooncoordY - 0.25*scale, 0.5*scale, 0.5*scale, blackpen, moonBrush));
                QGraphicsTextItem *text = scene->addText(QString("%1:%2").arg(hours, 2, 'f', 0, '0').arg(minutes, 2, 'f', 0, '0'));
                textlist.append(text);
                text->setPos(mooncoordX-scale, mooncoordY+0.5*scale);
                int ilfraction = static_cast<int>((illuminated_fraction * 100) + 0.5);

                ui->listWidget->addItem(new QListWidgetItem(QString("%1:%2 illumination = %3 ").arg(hours, 2, 'f', 0, '0').arg(minutes, 2, 'f', 0, '0').arg(ilfraction), ui->listWidget));

            }
//            else
//            {
//                printf("%d/%d/%d %2d:%02d UTC Ecliptic long = %f° lat = %f° RA = %fh DE = %f° localHourAngle = %f° AST = %f MoonRad = %f parallax = %f\n",
//                       year, month, day, hours, minutes, MoonLong, MoonLat, Equatorial.X, Equatorial.Y, HourAngleDegrees, AST, MoonRad, parallax);
//                fflush(stdout);
//            }

        }
    }

    ui->graphicsView->update();
}


void MainWindow::GetMoonIllumination(double JD, bool bHighPrecision, double& illuminated_fraction, double& position_angle, double& phase_angle)
{
  double moon_alpha = 0;
  double moon_delta = 0;
  GetLunarRaDecByJulian(JD, moon_alpha, moon_delta);
  double sun_alpha = 0;
  double sun_delta = 0;
  GetSolarRaDecByJulian(JD, bHighPrecision, sun_alpha, sun_delta);
  double geo_elongation = CAAMoonIlluminatedFraction::GeocentricElongation(moon_alpha, moon_delta, sun_alpha, sun_delta);

  position_angle = CAAMoonIlluminatedFraction::PositionAngle(sun_alpha, sun_delta, moon_alpha, moon_delta);
  phase_angle = CAAMoonIlluminatedFraction::PhaseAngle(geo_elongation, 368410.0, 149971520.0);
  illuminated_fraction = CAAMoonIlluminatedFraction::IlluminatedFraction(phase_angle);
}

void MainWindow::GetLunarRaDecByJulian(double JD, double& RA, double& Dec)
{
  double JDMoon = CAADynamicalTime::UTC2TT(JD);
  double lambda = CAAMoon::EclipticLongitude(JDMoon);
  double beta = CAAMoon::EclipticLatitude(JDMoon);
  double epsilon = CAANutation::TrueObliquityOfEcliptic(JDMoon);
  CAA2DCoordinate Lunarcoord = CAACoordinateTransformation::Ecliptic2Equatorial(lambda, beta, epsilon);
  RA = Lunarcoord.X;
  Dec = Lunarcoord.Y;
}

void MainWindow::GetSolarRaDecByJulian(double JD, bool bHighPrecision, double& RA, double& Dec)
{
  double JDSun = CAADynamicalTime::UTC2TT(JD);
  double lambda = CAASun::ApparentEclipticLongitude(JDSun, bHighPrecision);
  double beta = CAASun::ApparentEclipticLatitude(JDSun, bHighPrecision);
  double epsilon = CAANutation::TrueObliquityOfEcliptic(JDSun);
  CAA2DCoordinate Solarcoord = CAACoordinateTransformation::Ecliptic2Equatorial(lambda, beta, epsilon);
  RA = Solarcoord.X;
  Dec = Solarcoord.Y;
}

MainWindow::~MainWindow()
{
    opts.geosatindex = ui->cmbGeoSat->currentIndex();

    opts.Save();
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_cmbGeoSat_currentIndexChanged(int index)
{
    geosatindex = index;
    qDebug() << "on_cmbGeoSat geolastsat = " << index;
}
