#include"observer.h"
#include"monitor.h"

#ifndef _COUNTING_OBSERVER_H_
#define _COUNTING_OBSERVER_H_
class CountingObserver : public Observer {
	public:
		CountingObserver();
		virtual void update(Observable *);
		void show_data();

private:
		int count;
};

#endif


