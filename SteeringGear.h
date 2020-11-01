#pragma once
#include <qobject.h>
#include "wiringPi/wiringPi.h"
#include "wiringPi/wiringPi.h"
class SteeringGear :public QObject
{
	Q_OBJECT
public:
	explicit SteeringGear(unsigned int pwmPin, QObject* parent = nullptr);

public slots:
	void moveTo(int des);
	void moveForward();
	void moveBackward();
	void reset();
private:
	void myPwmWrite();
	bool isDesValid(int des)
	{
		return des >= minValue && des <= maxValue;
	}
private:
	int position;
	int pin;
	int maxValue;
	int minValue;
	int stepValue;
};

