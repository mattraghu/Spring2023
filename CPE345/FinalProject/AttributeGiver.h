#ifndef __FINALPROJECT_ATTRIBUTEGIVER_H_
#define __FINALPROJECT_ATTRIBUTEGIVER_H_

#include <omnetpp.h>
#include <Router.h>

using namespace omnetpp;

class AttributeGiver : public queueing::Router
{
protected:
  virtual void handleMessage(cMessage *msg) override;
};

#endif
