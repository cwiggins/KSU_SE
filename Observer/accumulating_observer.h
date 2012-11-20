#include"observer.h"
#include"monitor.h"

#ifndef ACCUMULATING_OBSERVER_H_
#define ACCUMULATING_OBSERVER_H_
class AccumulatingObserver : public Observer
{
public:
	AccumulatingObserver(UpperCaseMonitor *);
	AccumulatingObserver();
	~AccumulatingObserver();
	virtual void update(Observable *);
	void show_data();

private:
	UpperCaseMonitor *_subject;
};

#endif
