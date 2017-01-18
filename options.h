#ifndef OPTIONS_H
#define OPTIONS_H

#include <list>
#include <string>
#include <time.h>
#include <qstringlist.h>
#include <QColor>
#include <QRect>

class Options 
{
public:
	Options();
	void Initialize();
    void checkStringListValues();
	void Save();

    QStringList geostationarylistlon;
    QStringList geostationarylistname;
    int geosatindex;
    bool isit;
}; 


#endif
