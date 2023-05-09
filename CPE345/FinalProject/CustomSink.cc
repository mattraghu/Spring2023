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
    Sink::handleMessage(msg);
    simtime_t delay = simTime() - msg->getCreationTime();
    histogram.collect(delay);

    if (cPacket *pkt = dynamic_cast<cPacket*>(msg)) {
        simtime_t delay = simTime() - pkt->getCreationTime();
        histogram.collect(delay);

        numTotal++;

        if (pkt->hasPar("abandoned") && pkt->par("abandoned").boolValue())
            numAbandoned++;
    }
}

void CustomSink::finish()
{
    recordScalar("Abandonment Rate", (double)numAbandoned/numTotal);
    Sink::finish();
}




