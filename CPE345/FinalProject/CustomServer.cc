#include "CustomServer.h"
#include "SelectionStrategies.h"
#include "IPassiveQueue.h"

Define_Module(CustomServer);

void CustomServer::initialize()
{
    Server::initialize();
}
void CustomServer::handleMessage(cMessage *msg)
{
    // // Testing: Set the abandonment time to -1 to see if the message is abandoned
    // EV << "Message `" << msg->getName() << "` :" << strcmp(msg->getName(), "end-service") << endl;
    // if (strcmp(msg->getName(), "end-service") != 0)
    // {
    //     msg->addPar("abandonmentTime").setDoubleValue(-1);
    // }
    // EV_INFO << "Message difficulty: " << msg->par("difficulty") << endl;
    if (msg->hasPar("abandonmentTime"))
    {
        // msg->par("abandonmentTime").setDoubleValue(-1);

        simtime_t currentTime = simTime();
        simtime_t abandonmentTime = msg->getCreationTime() + msg->par("abandonmentTime").doubleValue();

        if (abandonmentTime <= currentTime)
        {
            EV << "Message `" << msg->getName() << "' has been abandoned\n";
            msg->par("abandoned").setBoolValue(true);
            send(msg, "out");
            allocated = false;
            emit(busySignal, false);
            // examine all input queues, and request a new job from a non empty queue
            int k = selectionStrategy->select();
            if (k >= 0)
            {
                EV << "requesting job from queue " << k << endl;
                cGate *gate = selectionStrategy->selectableGate(k);
                check_and_cast<queueing::IPassiveQueue *>(gate->getOwnerModule())->request(gate->getIndex());
            }
        }
        else
        {
            // Check if the message is out of range for the server's expertise
            if (msg->hasPar("difficulty"))
            {
                int difficulty = msg->par("difficulty");
                int serverExpertise = par("expertise");

                // if (difficulty > serverExpertise)
                // {
                //     EV << "Message `" << msg->getName() << "' has been abandoned because it is out of range for the server's expertise\n";
                //     msg->par("abandoned").setBoolValue(true);
                //     send(msg, "out");

                //     allocated = false;
                //     emit(busySignal, false);
                //     return;
                // }

                // Set the server speed multiplier based on the difficulty and the server's expertise
                msg->addPar("speedMultiplier").setDoubleValue((double)serverExpertise / difficulty);
            }
            Server::handleMessage(msg);
        }
    }
    else
    {

        // EV << "Message `" << msg->getName() << "' has no abandonment time\n";
        Server::handleMessage(msg);
    }
}
