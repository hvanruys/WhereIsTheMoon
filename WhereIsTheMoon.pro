#-------------------------------------------------
#
# Project created by QtCreator 2017-01-13T14:11:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WhereIsTheMoon
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    gridscene.cpp \
    graphicsviewzoom.cpp \
  AAAberration.cpp \
  AAAngularSeparation.cpp \
  AABinaryStar.cpp \
  AACoordinateTransformation.cpp \
  AADate.cpp \
  AADiameters.cpp \
  AADynamicalTime.cpp \
  AAEarth.cpp \
  AAEaster.cpp \
  AAEclipses.cpp \
  AAEclipticalElements.cpp \
  AAElementsPlanetaryOrbit.cpp \
  AAElliptical.cpp \
  AAELP2000.cpp \
  AAEquationOfTime.cpp \
  AAEquinoxesAndSolstices.cpp \
  AAFK5.cpp \
  AAGalileanMoons.cpp \
  AAGlobe.cpp \
  AAIlluminatedFraction.cpp \
  AAInterpolate.cpp \
  AAJewishCalendar.cpp \
  AAJupiter.cpp \
  AAKepler.cpp \
  AAMars.cpp \
  AAMercury.cpp \
  AAMoon.cpp \
  AAMoonIlluminatedFraction.cpp \
  AAMoonMaxDeclinations.cpp \
  AAMoonNodes.cpp \
  AAMoonPerigeeApogee.cpp \
  AAMoonPhases.cpp \
  AAMoslemCalendar.cpp \
  AANearParabolic.cpp \
  AANeptune.cpp \
  AANodes.cpp \
  AANutation.cpp \
  AAParabolic.cpp \
  AAParallactic.cpp \
  AAParallax.cpp \
  AAPhysicalJupiter.cpp \
  AAPhysicalMars.cpp \
  AAPhysicalMoon.cpp \
  AAPhysicalSun.cpp \
  AAPlanetPerihelionAphelion.cpp \
  AAPlanetaryPhenomena.cpp \
  AAPluto.cpp \
  AAPrecession.cpp \
  AARefraction.cpp \
  AARiseTransitSet.cpp \
  AASaturn.cpp \
  AASaturnMoons.cpp \
  AASaturnRings.cpp \
  AASidereal.cpp \
  AAStellarMagnitudes.cpp \
  AASun.cpp \
  AAUranus.cpp \
  AAVenus.cpp \
  AAVSOP87.cpp \
  AAVSOP87A_EAR.cpp \
  AAVSOP87A_EMB.cpp \
  AAVSOP87A_JUP.cpp \
  AAVSOP87A_MAR.cpp \
  AAVSOP87A_MER.cpp \
  AAVSOP87A_NEP.cpp \
  AAVSOP87A_SAT.cpp \
  AAVSOP87A_URA.cpp \
  AAVSOP87A_VEN.cpp \
  AAVSOP87B_EAR.cpp \
  AAVSOP87B_JUP.cpp \
  AAVSOP87B_MAR.cpp \
  AAVSOP87B_MER.cpp \
  AAVSOP87B_NEP.cpp \
  AAVSOP87B_SAT.cpp \
  AAVSOP87B_URA.cpp \
  AAVSOP87B_VEN.cpp \
  AAVSOP87C_EAR.cpp \
  AAVSOP87C_JUP.cpp \
  AAVSOP87C_MAR.cpp \
  AAVSOP87C_MER.cpp \
  AAVSOP87C_NEP.cpp \
  AAVSOP87C_SAT.cpp \
  AAVSOP87C_URA.cpp \
  AAVSOP87C_VEN.cpp \
  AAVSOP87D_EAR.cpp \
  AAVSOP87D_JUP.cpp \
  AAVSOP87D_MAR.cpp \
  AAVSOP87D_MER.cpp \
  AAVSOP87D_NEP.cpp \
  AAVSOP87D_SAT.cpp \
  AAVSOP87D_URA.cpp \
  AAVSOP87D_VEN.cpp \
  AAVSOP87E_EAR.cpp \
  AAVSOP87E_JUP.cpp \
  AAVSOP87E_MAR.cpp \
  AAVSOP87E_MER.cpp \
  AAVSOP87E_NEP.cpp \
  AAVSOP87E_SAT.cpp \
  AAVSOP87E_SUN.cpp \
  AAVSOP87E_URA.cpp \
  AAVSOP87E_VEN.cpp \
  AAVSOP87_EMB.cpp \
  AAVSOP87_JUP.cpp \
  AAVSOP87_MAR.cpp \
  AAVSOP87_MER.cpp \
  AAVSOP87_NEP.cpp \
  AAVSOP87_SAT.cpp \
  AAVSOP87_URA.cpp \
  AAVSOP87_VEN.cpp \
  stdafx.cpp \
    options.cpp



HEADERS  += mainwindow.h \
    gridscene.h \
    graphicsviewzoom.h \
  AA2DCoordinate.h \
  AA3DCoordinate.h \
  AAAberration.h \
  AAAngularSeparation.h \
  AABinaryStar.h \
  AACoordinateTransformation.h \
  AADate.h \
  AADiameters.h \
  AADynamicalTime.h \
  AAEarth.h \
  AAEaster.h \
  AAEclipses.h \
  AAEclipticalElements.h \
  AAElementsPlanetaryOrbit.h \
  AAElliptical.h \
  AAEquationOfTime.h \
  AAEquinoxesAndSolstices.h \
  AAFK5.h \
  AAGalileanMoons.h \
  AAGlobe.h \
  AAIlluminatedFraction.h \
  AAInterpolate.h \
  AAJewishCalendar.h \
  AAJupiter.h \
  AAKepler.h \
  AAMars.h \
  AAMercury.h \
  AAMoon.h \
  AAMoonIlluminatedFraction.h \
  AAMoonMaxDeclinations.h \
  AAMoonNodes.h \
  AAMoonPerigeeApogee.h \
  AAMoonPhases.h \
  AAMoslemCalendar.h \
  AANeptune.h \
  AANodes.h \
  AANutation.h \
  AAParabolic.h \
  AAParallactic.h \
  AAParallax.h \
  AAPhysicalJupiter.h \
  AAPhysicalMars.h \
  AAPhysicalMoon.h \
  AAPhysicalSun.h \
  AAPlanetPerihelionAphelion.h \
  AAPlanetaryPhenomena.h \
  AAPluto.h \
  AAPrecession.h \
  AARefraction.h \
  AARiseTransitSet.h \
  AASaturn.h \
  AASaturnMoons.h \
  AASaturnRings.h \
  AASidereal.h \
  AAStellarMagnitudes.h \
  AASun.h \
  AAUranus.h \
  AAVenus.h \
  AAVSOP87.h \
  AAVSOP87A_EAR.h \
  AAVSOP87A_EMB.h \
  AAVSOP87A_JUP.h \
  AAVSOP87A_MAR.h \
  AAVSOP87A_MER.h \
  AAVSOP87A_NEP.h \
  AAVSOP87A_SAT.h \
  AAVSOP87A_URA.h \
  AAVSOP87A_VEN.h \
  AAVSOP87B_EAR.h \
  AAVSOP87B_JUP.h \
  AAVSOP87B_MAR.h \
  AAVSOP87B_MER.h \
  AAVSOP87B_NEP.h \
  AAVSOP87B_SAT.h \
  AAVSOP87B_URA.h \
  AAVSOP87B_VEN.h \
  AAVSOP87C_EAR.h \
  AAVSOP87C_JUP.h \
  AAVSOP87C_MAR.h \
  AAVSOP87C_MER.h \
  AAVSOP87C_NEP.h \
  AAVSOP87C_SAT.h \
  AAVSOP87C_URA.h \
  AAVSOP87C_VEN.h \
  AAVSOP87D_EAR.h \
  AAVSOP87D_JUP.h \
  AAVSOP87D_MAR.h \
  AAVSOP87D_MER.h \
  AAVSOP87D_NEP.h \
  AAVSOP87D_SAT.h \
  AAVSOP87D_URA.h \
  AAVSOP87D_VEN.h \
  AAVSOP87E_EAR.h \
  AAVSOP87E_JUP.h \
  AAVSOP87E_MAR.h \
  AAVSOP87E_MER.h \
  AAVSOP87E_NEP.h \
  AAVSOP87E_SAT.h \
  AAVSOP87E_SUN.h \
  AAVSOP87E_URA.h \
  AAVSOP87E_VEN.h \
  AAVSOP87_EMB.h \
  AAVSOP87_JUP.h \
  AAVSOP87_MAR.h \
  AAVSOP87_MER.h \
  AAVSOP87_NEP.h \
  AAVSOP87_SAT.h \
  AAVSOP87_URA.h \
  AAVSOP87_VEN.h \
  stdafx.h \
    options.h

FORMS    += mainwindow.ui

DISTFILES += \
    README.md
