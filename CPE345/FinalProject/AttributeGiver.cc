#include "AttributeGiver.h"

Define_Module(AttributeGiver);

void AttributeGiver::randomPrint()
{
}
void AttributeGiver::handleMessage(cMessage *msg)
{
    EV << "Handling message `" << msg->getName() << "'\n";

    if (msg->isSelfMessage())
    {
        randomPrint();
    }
    else
    {
        // Schedule Print

        scheduleAt(simTime() + 1, msg);
        Router::handleMessage(msg);
    }
}
