#ifndef __FINALPROJECT_CUSTOMROUTER_H_
#define __FINALPROJECT_CUSTOMROUTER_H_

#include <omnetpp.h>
#include <Router.h>

using namespace omnetpp;

class CustomRouter : public queueing::Router
{
protected:
  virtual void initialize() override;
  virtual void handleMessage(cMessage *msg) override;
};

#endif
