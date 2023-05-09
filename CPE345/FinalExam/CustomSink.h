#ifndef __CLASSWORK8_CUSTOMSINK_H_
#define __CLASSWORK8_CUSTOMSINK_H_

#include <omnetpp.h>
#include <Sink.h>

using namespace omnetpp;

class CustomSink : public queueing::Sink
{
protected:
  cHistogram histogram;
  virtual void initialize();
  virtual void handleMessage(cMessage *msg);
  // virtual void finish() override;
};

#endif
