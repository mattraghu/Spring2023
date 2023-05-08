#include "AbandonmentChecker.h"

Define_Module(AbandonmentChecker);

void AbandonmentChecker::handleMessage(cMessage *msg)
{
    Router::handleMessage(msg);
}

// void CustomServer::handleMessage(cMessage *msg)
// {
//     // // Testing: Set the abandonment time to -1 to see if the message is abandoned
//     msg->par("abandonmentTime").setDoubleValue(-1);
//     // EV << "Message `" << msg->getName() << "` :" << strcmp(msg->getName(), "end-service") << endl;
//     // if (strcmp(msg->getName(), "end-service") != 0)
//     // {
//     //     msg->addPar("abandonmentTime").setDoubleValue(-1);
//     // }

//     if (msg->hasPar("abandonmentTime"))
//     {

//         simtime_t currentTime = simTime();
//         EV << msg->addPar("abandonmentTime").setDoubleValue(-1) << endl;
//         simtime_t abandonmentTime = msg->getCreationTime() + msg->par("abandonmentTime").doubleValue();

//         if (abandonmentTime <= currentTime)
//         {
//             // EV << "Message `" << msg->getName() << "' has been abandoned\n";
//             send(msg, "out");
//         }
//         else
//         {
//             Server::handleMessage(msg);
//         }
//     }
//     else
//     {
//         // EV << "Message `" << msg->getName() << "' has no abandonment time\n";
//         Server::handleMessage(msg);
//     }
// }
