#include "CustomRouter.h"

Define_Module(CustomRouter);

void CustomRouter::initialize()
{
    Router::initialize();
}

void CustomRouter::handleMessage(cMessage *msg)
{
    // Collect statistics
    simtime_t delay = simTime() - msg->getCreationTime();
    histogram.collect(delay);

    // Determine the output channel based on the routing probabilities
    double probability = uniform(0.0, 1.0);
    EV << "Probability: " << probability << endl;
    if (probability < par("probability1").doubleValue())
    {
        send(msg, "P1");
    }
    else
    {
        send(msg, "P2");
    }
}
