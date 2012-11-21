#include"observer.h"
#include"monitor.h"
#include<vector>
using std::vector;

#ifndef ACCUMULATING_OBSERVER_H_
#define ACCUMULATING_OBSERVER_H_
class AccumulatingObserver : public Observer
{
public:
	AccumulatingObserver();
	virtual void update(Observable *);
	void show_data();

private:
	vector<char> _subject;
	char _subchar;
};

#endif
