#include "CustomerRouter.h"

Define_Module(CustomerRouter);

void CustomerRouter::initialize()
{
    Router::initialize();
}

void CustomerRouter::handleMessage(cMessage *msg)
{
    Router::handleMessage(msg);
}
