#include "CustomRouter.h"

Define_Module(CustomRouter);

void CustomRouter::initialize()
{
    Router::initialize();
}

void CustomRouter::handleMessage(cMessage *msg)
{

    int complexity = msg->par("difficulty");

    EV << "Message `" << msg->getName() << "' has complexity " << complexity << endl;

    // Route the message to the appropriate problem queue
    if (complexity <= 3)
    {
        send(msg, "Complexity1");
    }
    else if (complexity <= 6)
    {
        send(msg, "Complexity2");
    }
    else
    {
        send(msg, "Complexity3");
    }
}
