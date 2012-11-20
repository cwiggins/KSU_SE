#include"accumulating_observer.h"
#include<list>
#include<iostream>
using std::cout;
using std::endl;
using std::list;

AccumulatingObserver::AccumulatingObserver(UpperCaseMonitor *s) {
	_subject = s;
	_subject->attach(this);
}

AccumulatingObserver::AccumulatingObserver() {

}

AccumulatingObserver::~AccumulatingObserver() {
	_subject->detach(this);
}

void AccumulatingObserver::update(Observable *ChangedState) {
	if(ChangedState == _subject)
		show_data();
}

void AccumulatingObserver::show_data() {
	char value = _subject->get_state();

	list<char> charList;
	for(int i = 0; i < 10; i++) {
		charList.push_front(value);
	}

	cout << "Maintained States: " << endl;
	//Display List
	list<char>::iterator it;
	for(it = charList.begin(); it != charList.end(); it++) {
		cout << *it;
	}
}
