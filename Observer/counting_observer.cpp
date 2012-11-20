#include"counting_observer.h"
#include<iostream>
using std::cout;
using std::endl;

CountingObserver::CountingObserver(UpperCaseMonitor *s) {
	_subject = s;
	_subject->attach(this);
}

CountingObserver::CountingObserver() {
	// default constructor
}

CountingObserver::~CountingObserver() {
	_subject->detach(this);
}

void CountingObserver::update(Observable *ChangedState) {
	if(ChangedState = _subject)
		show_data();
}

void CountingObserver::show_data() {
	char value = _subject->get_state();

	count+=1;

	cout << "Number of State Changes is: " << count << " and most recent state \
		change is: " << value << endl;
}
