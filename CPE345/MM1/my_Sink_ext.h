#ifndef __MM1_MY_SINK_EXT_H_
#define __MM1_MY_SINK_EXT_H_

#include <omnetpp.h>
#include <Sink.h>

using namespace omnetpp;

class My_Sink_ext : public queueing::Sink
{
protected:
  cHistogram histogram;
  virtual void initialize();
  virtual void handleMessage(cMessage *msg);
  // virtual void finish() override;
};

#endif
