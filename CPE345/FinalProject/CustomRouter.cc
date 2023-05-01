#include "CustomRouter.h"

Define_Module(CustomRouter);

void CustomRouter::initialize()
{
    Router::initialize();
}

void CustomRouter::handleMessage(cMessage *msg)
{
    Router::handleMessage(msg);
}
