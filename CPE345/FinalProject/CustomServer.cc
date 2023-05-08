#include "CustomServer.h"

Define_Module(CustomServer);

void CustomServer::handleMessage(cMessage *msg)
{
    // // Testing: Set the abandonment time to -1 to see if the message is abandoned
    // EV << "Message `" << msg->getName() << "` :" << strcmp(msg->getName(), "end-service") << endl;
    // if (strcmp(msg->getName(), "end-service") != 0)
    // {
    //     msg->addPar("abandonmentTime").setDoubleValue(-1);
    // }

    if (msg->hasPar("abandonmentTime"))
    {
        // msg->par("abandonmentTime").setDoubleValue(-1);

        simtime_t currentTime = simTime();
        simtime_t abandonmentTime = msg->getCreationTime() + msg->par("abandonmentTime").doubleValue();

        if (abandonmentTime <= currentTime)
        {
            EV << "Message `" << msg->getName() << "' has been abandoned\n";
            // scheduleAt(simTime() + 0, endServiceMsg);
            send(msg, "out");

            allocated = false;
            emit(busySignal, false);
        }
        else
        {
            Server::handleMessage(msg);
        }
    }
    else
    {
        // EV << "Message `" << msg->getName() << "' has no abandonment time\n";
        Server::handleMessage(msg);
    }
}