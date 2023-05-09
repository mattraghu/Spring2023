#ifndef CUSTOMSINK_H_
#define CUSTOMSINK_H_

#include <omnetpp.h>

#include <omnetpp.h>
#include <Sink.h>

using namespace omnetpp;

class CustomSink : public queueing::Sink {
protected:
  cHistogram histogram;
  virtual void initialize();
  virtual void handleMessage(cMessage *msg);
};




#endif /* CUSTOMSINK_H_ */
