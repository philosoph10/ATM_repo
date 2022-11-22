#ifndef DAEMONCONTROLLER_H
#define DAEMONCONTROLLER_H
#include "TransferDaemon.h"

// class which performs automatic transfers
// it contains all the set transfer daemons
class DaemonController
{
    DaemonController();
    ~DaemonController();
    void addDaemon(const TransferDaemon&);
    void removeDaemon(const TransferDaemon&);
};

#endif // DAEMONCONTROLLER_H
