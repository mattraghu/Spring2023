#ifndef __CLASSWORK8_CUSTOMERROUTER_H_
#define __CLASSWORK8_CUSTOMERROUTER_H_

#include <omnetpp.h>
#include <Router.h>

using namespace omnetpp;

class CustomerRouter : public queueing::Router
{
protected:
  virtual void initialize() override;
  virtual void handleMessage(cMessage *msg) override;
};

#endif
