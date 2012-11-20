#include"monitor.h"
#include<cctype>
using std::isupper;

void UpperCaseMonitor::attach(Observer* obs) {
	_observers.push_back(obs);
}

void UpperCaseMonitor::detach(Observer* obs) {
	int count = _observers.size();
    int i;
	for(i = 0; i < count; i++) {
		if(_observers[i] == obs)
			break;
	 }
	if(i < count)
		_observers.erase(_observers.begin() + i);
}

void UpperCaseMonitor::notify() {
	int count = _observers.size();

	for(int i = 0; i < count; i++)
		(_observers[i])->update(this);
}

void UpperCaseMonitor::watch(char chr) {
	if(isupper(chr)) {
		set_state(chr);
	}
}
