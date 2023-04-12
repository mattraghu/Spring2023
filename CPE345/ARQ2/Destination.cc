#include "Destination.h"

Define_Module(Destination);

void Destination::initialize()
{
}

void Destination::handleMessage(cMessage *msg)
{
    // Cast the message to a packet
    cPacket *pkt = check_and_cast<cPacket *>(msg);

    // Check for bit error using hasBitError()
    if (pkt->hasBitError())
    {
        EV << "Packet has bit error, deleting" << endl;
        bubble("Packet has bit error, deleting");
        delete pkt;
    }
    else
    {
        // Collect the delay statistics
        simtime_t delay = simTime() - pkt->getCreationTime();
        delayHistogram.collect(delay);

        // If there is no bit error, then send the packet back to the source
        EV << "Packet received, sending back" << endl;
        send(pkt, "out");
    }
}

void Destination::finish()
{
    // Print the delay statistics
    EV << "Delay Histogram:" << endl;
    delayHistogram.record();
}
