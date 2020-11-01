#include "SteeringGear.h"
#include <QDebug>
SteeringGear::SteeringGear(unsigned int pwmPin,QObject* parent)
	:QObject(parent), pin(pwmPin), minValue(0), maxValue(255), stepValue(10), position(0)
{
	//pinMode(pin, PWM_OUTPUT);
	//pwmSetRange(255);
	//pwmSetClock(32);
}

void SteeringGear::myPwmWrite()
{
	if (!isDesValid(position))
	{
		if (position > maxValue) {
			position = maxValue;
		}
		else if (position < minValue) {
			position = minValue;
		}
	}
	qDebug() << position;
	//pwmWrite(pin, position);
}

void SteeringGear::moveTo(int des)
{
	position = des;
	myPwmWrite();
}

void SteeringGear::moveForward()
{
	position += stepValue;
	myPwmWrite();
}

void SteeringGear::moveBackward()
{
	position -= stepValue;
	myPwmWrite();
}

void SteeringGear::reset()
{
	position = minValue;
	myPwmWrite();
}
