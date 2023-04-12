//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "Source.h"

Define_Module(Source);

Source::Source() // Called when the object is created
{
    timeoutEvent = nullptr;
    pkt = nullptr;
}

Source::~Source() // Called when the object is destroyed
{
    cancelAndDelete(timeoutEvent);
    delete pkt;
}

void Source::initialize()
{
    timeout = 1.0;
    timeoutEvent = new cMessage("timeoutEvent");
    EV << "Sending Initial Message" << endl;
    pkt = new cPacket("packet");
    pkt->setBitLength(10);
    // Duplicate the packet and send it to the destination
    send(pkt->dup(), "out");

    // Schedule the timeout event
    scheduleAt(simTime() + timeout, timeoutEvent);
}

void Source::handleMessage(cMessage *msg)
{
    // If the message is the timeout event, then send the packet
    if (msg == timeoutEvent)
    {
        EV << "Timeout expired, sending back message" << endl;
        send(pkt->dup(), "out");
    }
    else
    {
        // If the message is not the timeout event, then it is the
        // packet that was sent back from the destination
        cancelEvent(timeoutEvent); // Cancel the timeout event
        EV << "Received packet, deleting" << endl;
        delete msg;
        delete pkt;

        // Create and send a new packet
        pkt = new cPacket("packet");
        pkt->setBitLength(10);
        send(pkt->dup(), "out");
    }
    // Reschedule the timeout event
    scheduleAt(simTime() + timeout, timeoutEvent);
}
