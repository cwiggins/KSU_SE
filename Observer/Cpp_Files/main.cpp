/* Driver for Observer testing.
 */

#include "monitor.h"
#include "counting_observer.h"
#include "accumulating_observer.h"
#include <iostream>
using std::cin;
using std::cout;

//==============================================================================
void process_input(char chr);

//==============================================================================
int main()
{
    // Monitor for uppercase chars
    UpperCaseMonitor     uc_monitor;

    // Want to be notified when there's an upper case char
    CountingObserver     observer1;
    AccumulatingObserver observer2;

    // Get registered
    uc_monitor.attach(&observer1);
    uc_monitor.attach(&observer2);

    // Prompt
    cout << "Enter some text, type ^d when done.\n";

    // Process text
    char chr;
    while (cin.get(chr))
    {
        uc_monitor.watch(chr);
        process_input(chr);
    }

    // See what observers know
    observer1.show_data();
    observer2.show_data();
}


//==============================================================================
void process_input(char chr)
{
    // Maybe do something with the input
}

