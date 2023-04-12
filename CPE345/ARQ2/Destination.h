#ifndef __ARQ2_DESTINATION_H_
#define __ARQ2_DESTINATION_H_

#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Destination : public cSimpleModule
{
protected:
  virtual void initialize() override;
  virtual void handleMessage(cMessage *msg) override;
  virtual void finish() override;

public:
  // Histogram
  cHistogram delayHistogram;
};

#endif
