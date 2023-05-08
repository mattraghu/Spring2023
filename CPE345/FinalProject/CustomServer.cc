#include "CustomServer.h"

Define_Module(CustomServer);

void CustomServer::handleMessage(cMessage *msg)
{
    EV << "Received mlkajd;flkjsdlkessage `" << msg->getName() << "', starting new one\n";

    Server::handleMessage(msg);
}
