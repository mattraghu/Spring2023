#include "my_Sink_ext.h"

Define_Module(My_Sink_ext);

void My_Sink_ext::initialize()
{
    Sink::initialize();
    histogram.setName("Histogram");
}

void My_Sink_ext::handleMessage(cMessage *msg)
{
    Sink::handleMessage(msg);
    simtime_t delay = simTime() - msg->getCreationTime();
    histogram.collect(delay);
}

// void My_Sink_ext::finish()
// {
//     Sink::finish();
//     histogram.recordAs("Histogram");
// }
