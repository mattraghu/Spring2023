#include "CustomSink.h"

Define_Module(CustomSink);

void CustomSink::initialize()
{
    Sink::initialize();
    histogram.setName("Histogram");
}

void CustomSink::handleMessage(cMessage *msg)
{
    Sink::handleMessage(msg);
    simtime_t delay = simTime() - msg->getCreationTime();
    histogram.collect(delay);
}




