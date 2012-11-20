//  Interface for Observable and its observer
//

#ifndef OBSERVER_H
#define OBSERVER_H

//===========================================================================
class Observable;

//===========================================================================
class Observer
{
  public:
    virtual void update(Observable*) = 0;
};

#endif

