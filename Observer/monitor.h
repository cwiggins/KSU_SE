#include"observable.h"
#include"observer.h"
#include<iostream>
#include<vector>
#include<cctype>
using std::isupper;
using std::vector;

#ifndef MONITOR_H_
#define MONITOR_H_

class UpperCaseMonitor : public Observable {
	public:
		void attach(Observer *);
		void detach(Observer *);

		virtual void notify();

		virtual char get_state() {return _state;};
		virtual void set_state(char new_state) { _state = new_state; notify();};

		void watch(char);

	private:
		vector<Observer*> _observers;
		char _state;
};

#endif

