#include "AttributeGiver.h"

Define_Module(AttributeGiver);

void AttributeGiver::randomPrint()
{
}
void AttributeGiver::handleMessage(cMessage *msg)
{
    EV << "Handling message `" << msg->getName() << "'\n";
    Router::handleMessage(msg);
}
