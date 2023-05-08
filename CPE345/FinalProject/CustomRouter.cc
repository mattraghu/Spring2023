#include "CustomRouter.h"

Define_Module(CustomRouter);

void CustomRouter::initialize()
{
    Router::initialize();
}

void CustomRouter::handleMessage(cMessage *msg)
{
    // Add the "ProblemType" parameter if it's not already present
    if (!msg->hasPar("ProblemType"))
    {
        int randomProblemType = intuniform(1, 3);
        msg->addPar("ProblemType");
        msg->par("ProblemType").setLongValue(randomProblemType);
        EV << "Added ProblemType parameter with value " << randomProblemType << " to message" << endl;
    }

    int problemType = msg->par("ProblemType");

    if (problemType == 1)
    {
        send(msg, "Problem1");
    }
    else if (problemType == 2)
    {
        send(msg, "Problem2");
    }
    else if (problemType == 3)
    {
        send(msg, "Problem3");
    }
    else
    {
        EV << "Unknown problem type: " << problemType << endl;
        delete msg;
    }
}
