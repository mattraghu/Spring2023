#ifndef CUSTOMSINK_H_
#define CUSTOMSINK_H_

#include <omnetpp.h>
#include <Sink.h>

using namespace omnetpp;

class CustomSink : public queueing::Sink {
protected:
    cHistogram histogram;
    int numAbandoned;
    int numTotal;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
};

#endif /* CUSTOMSINK_H_ */
