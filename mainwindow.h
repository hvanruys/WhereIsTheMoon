#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gridscene.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include "graphicsviewzoom.h"
#include <QDate>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void GetMoonIllumination(double JD, bool bHighPrecision, double& illuminated_fraction, double& position_angle, double& phase_angle);
    void GetLunarRaDecByJulian(double JD, double& RA, double& Dec);
    void GetSolarRaDecByJulian(double JD, bool bHighPrecision, double& RA, double& Dec);

    ~MainWindow();
private:
    void SetupCombo();
    Graphics_view_zoom* z;
public slots:
    void CalcMoon(QDate selected);

private slots:
    void on_actionExit_triggered();

    void on_cmbGeoSat_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    GridScene *scene;
    QGraphicsEllipseItem *earth;
    QGraphicsEllipseItem *moon;
    QGraphicsTextItem *text;
    QList<QGraphicsEllipseItem *> moonlist;
    QList<QGraphicsTextItem *> textlist;
    int scale;
    QList<double> geolonlist;
    int geosatindex;

};

#endif // MAINWINDOW_H
