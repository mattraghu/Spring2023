#ifndef __FINALPROJECT_CUSTOMSOURCE_H_
#define __FINALPROJECT_CUSTOMSOURCE_H_

#include <omnetpp.h>
#include <Source.h>

using namespace omnetpp;

class CustomSource : public queueing::Source
{
protected:
  virtual void handleMessage(cMessage *msg) override;
};

#endif
