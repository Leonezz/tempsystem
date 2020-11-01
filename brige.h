#pragma once

#include <QObject>

#include "widget.h"
/*
	This is a brige class between clint and HTML page.
*/

class Brige :public QObject
{
	Q_OBJECT
public:
	Brige(Widget* widget, QObject* parent = nullptr)
		:QObject(parent), m_widget(widget)
	{
		QObject::connect(widget, &Widget::sendMsg, this, &Brige::sendMsg);
	}
signals:
	void sendMsg(const QString& text);
		/*
			this signal will emit from c++ side and be recieved on the HTML side.
		*/

	
	
public slots:
	/*
		this slot will be called by the HTML side.
	*/
	void receiveMsg(const QString& text)
	{
		return;
	}

private:
	Widget* m_widget;
};






