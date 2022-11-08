#ifndef TRANSFERDAEMON_H
#define TRANSFERDAEMON_H
#include "Account.h"

// frequency of the automatic transfers
enum Frequency {
    WEEKLY,
    MONTHLY,
    ANNUALLY
};

// class which stores information about automatic transfers from one account to another
class TransferDaemon {
public:
    TransferDaemon(const Account& from, const Account& to, double sum, Frequency freq=MONTHLY);
    void start();
    void cancel();
    ~TransferDaemon();
};

#endif // TRANSFERDAEMON_H
