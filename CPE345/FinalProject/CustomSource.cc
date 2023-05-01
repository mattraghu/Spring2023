#include "CustomSource.h"

Define_Module(CustomSource);

void CustomSource::handleMessage(cMessage *msg)
{
    EV << "Received message `" << msg->getName() << "', starting new one\n";

    Source::handleMessage(msg);
}
