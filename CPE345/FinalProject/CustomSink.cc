#include "CustomSink.h"

Define_Module(CustomSink);

void CustomSink::initialize()
{
    Sink::initialize();
    histogram.setName("Histogram");
    numAbandoned = 0;
    numTotal = 0;
}

void CustomSink::handleMessage(cMessage *msg)
{

    simtime_t delay = simTime() - msg->getCreationTime();
    histogram.collect(delay);

    numTotal++;

    if (msg->par("abandoned").boolValue())
    {
        numAbandoned++;
    }
    Sink::handleMessage(msg);
}

void CustomSink::finish()
{
    recordScalar("numTotal", numTotal);
    recordScalar("numAbandoned", numAbandoned);
    recordScalar("Abandonment Rate", (double)numAbandoned / numTotal);
    Sink::finish();
}
