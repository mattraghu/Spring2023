#include "CustomerRouter.h"

Define_Module(CustomerRouter);

void CustomerRouter::initialize()
{
    Router::initialize();
}

void CustomerRouter::handleMessage(cMessage *msg)
{
    // Collect statistics
    simtime_t delay = simTime() - msg->getCreationTime();
    histogram.collect(delay);

    // Determine the output channel based on the routing probabilities
    double probability = uniform(0.0, 1.0);
    EV << "Probability: " << probability << endl;
    if (probability < par("probability1").doubleValue())
    {
        send(msg, "out", 0);
    }
    else
    {
        send(msg, "out", 1);
    }
}
