//  Interface for Observable and its observer
//

#ifndef OBSERVABLE_H
#define OBSERVABLE_H

//===========================================================================
class Observer;

//===========================================================================
class Observable
{
  public:
    virtual void attach(Observer*)  = 0;
    virtual void detach(Observer*)  = 0;
    virtual void notify()           = 0;

    // Can we get rid of these?
    virtual char get_state()     = 0;
    virtual void set_state(char) = 0;
};

#endif

