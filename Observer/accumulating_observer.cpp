#include"accumulating_observer.h"
#include<vector>
#include<iostream>
using std::cout;
using std::endl;


AccumulatingObserver::AccumulatingObserver() {

}

void AccumulatingObserver::update(Observable *ChangedState) {
	_subject.push_back(ChangedState->get_state());
}

void AccumulatingObserver::show_data() {

	cout << "Maintained States: " << endl;

	for(int i = 0; i < _subject.size(); i++)
		cout << _subject[i];

	cout << endl;
}
