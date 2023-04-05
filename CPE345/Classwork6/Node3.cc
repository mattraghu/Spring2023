#include <omnetpp.h>

using namespace omnetpp;

class Node3 : public cSimpleModule
{
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
};

Define_Module(Node3);

void Node3::initialize()
{
    // Module initialization code here
    if (strcmp("node1", getName()) == 0)
    {
        // create and send first message on gate "out". "tictocMsg" is an
        // arbitrary string which will be the name of the message object.
        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
    }
}

// Handle messages arriving on gate "in"
void Node3::handleMessage(cMessage *msg)
{
    // Message processing code here
    send(msg, "out");
}

// Finish function
void Node3::finish()
{
    EV << "Node3: " << getName() << " finished" << endl;
}