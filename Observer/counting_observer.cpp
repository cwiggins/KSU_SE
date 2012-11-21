#include"counting_observer.h"
#include<iostream>
using std::cout;
using std::endl;

CountingObserver::CountingObserver() {
	count = 0;
}

void CountingObserver::update(Observable *ChangedState) {
	count+=1;
}

void CountingObserver::show_data() {

	cout << endl << "Number of State Changes is: " << count << endl;
}
