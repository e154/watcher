/** Copyright (C), DeltaSync Studios, 2010-2014. All rights reserved.
 * ------------------------------------------------------------------
 * File name:   systemtray.h
 * Version:     v1.00
 * Created:     21:41:56 / 22 авг. 2015 г.
 * Author:      delta54 <support@e154.ru>
 * 
 * Your use and or redistribution of this software in source and / or
 * binary form, with or without modification, is subject to: (i) your
 * ongoing acceptance of and compliance with the terms and conditions of
 * the DeltaSync License Agreement; and (ii) your inclusion of this notice
 * in any version of this software that you use or redistribute.
 * A copy of the DeltaSync License Agreement is available by contacting
 * DeltaSync Studios. at http://www.inet-print.ru/
 *
 * Description: 
 * ------------------------------------------------------------------
 * History:
 *
 */

#ifndef SYSTEMTRAY_H_
#define SYSTEMTRAY_H_

#include <QSystemTrayIcon>
#include <QGridLayout>
#include <QDialog>
#include <iostream>
#include <map>

const int SECOND = 1;
const int MINUTE = 60 * SECOND;
const int HOUR = 60 * MINUTE;

class QRadioButton;

typedef std::map<int, QAction*> actionStates;

class SystemTray : public QDialog
{
	Q_OBJECT

private:
	QMenu *mMainMenu;
	QMenu *mAlarmMenu;
	QMenu *mTimerMenu;

	QGridLayout *mainLayout;
	QAction *exitAction;
	QAction *runAtStartUpAction;
	QAction *dTimerAction;
	QAction *AlarmSoundAction;
	QAction *helpAction;
	QAction *alarmInfo;

	QGridLayout *timeLayout;
	QAction *time4hAction;
	QAction *time3hAction;
	QAction *time2hAction;
	QAction *time1hAction;
	QAction *time45mAction;
	QAction *time30mAction;
	QAction *time25mAction;
	QAction *time20mAction;
	QAction *time15mAction;
	QAction *time10mAction;
	QAction *time5mAction;

	QGridLayout *dTimeLayout;
	QRadioButton *dTime4hRadio;
	QRadioButton *dTime3hRadio;
	QRadioButton *dTime2hRadio;
	QRadioButton *dTime1hRadio;
	QRadioButton *dTime45mRadio;
	QRadioButton *dTime30mRadio;
	QRadioButton *dTime25mRadio;
	QRadioButton *dTime20mRadio;
	QRadioButton *dTime15mRadio;
	QRadioButton *dTime10mRadio;
	QRadioButton *dTime5mRadio;

	QSystemTrayIcon *mTrayIcon;
	QGridLayout *alarmLayout;
	QRadioButton *alarmRadio1;
	QRadioButton *alarmRadio2;
	QRadioButton *alarmRadio3;

public:
	SystemTray();

	void init();

	inline QSystemTrayIcon *GetTrayPtr() { return mTrayIcon; }
	inline QMenu *GetMenuPtr() { return mMainMenu; }

	static SystemTray* getSingletonPtr();
	void setTrayIcon(char *icon) { mTrayIcon->setIcon(QIcon(icon)); }
	void setTrayToolTip(char *tooltip) { mTrayIcon->setToolTip(QString(tooltip)); }
	void setTrayVisible(bool trigger) { mTrayIcon->setVisible(trigger); }
	void showMessage(const QString &title, const QString &msg,
	                     QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int msecs = 10000) {
		mTrayIcon->showMessage(title, msg, icon, msecs);
	}

	// time
	void setTimer(int time = 0, QAction *action = 0);
	int getTime() { return mCurrentTimeLimit; }
	void setTimeCallback(void* callback) {
		mTimeCallback = callback;
	}

private slots:
	void trayAboutToShow();
	void iconActivated(QSystemTrayIcon::ActivationReason reason);
	void setDefaultTimer(int state, int value);
	void setAlarm(int state, int value);
	void showHelp();
	void setRunAtStartUp();

	inline void set4hTime() { setTimer(0, time4hAction); }
	inline void set3hTime() { setTimer(0, time3hAction); }
	inline void set2hTime() { setTimer(0, time2hAction); }
	inline void set1hTime() { setTimer(0, time1hAction); }
	inline void set45mTime() { setTimer(0, time45mAction); }
	inline void set30mTime() { setTimer(0, time30mAction); }
	inline void set25mTime() { setTimer(0, time25mAction); }
	inline void set20mTime() { setTimer(0, time20mAction); }
	inline void set15mTime() { setTimer(0, time15mAction); }
	inline void set10mTime() { setTimer(0, time10mAction); }
	inline void set5mTime() { setTimer(0, time5mAction); }

private:
	void createTrayIcon();
	void createActions();

	static SystemTray *mSystemTray;

protected:
	void* mTimeCallback;
	actionStates mTimeStates;
	int mCurrentTimeLimit;
	int mCurrentDefaultTime;

};

#endif /* SYSTEMTRAY_H_ */
