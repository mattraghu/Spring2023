#ifndef __CLASSWORK8_CustomRouter_H_
#define __CLASSWORK8_CustomRouter_H_

#include <omnetpp.h>
#include <Router.h>

using namespace omnetpp;

class CustomRouter : public queueing::Router
{
protected:
  virtual void initialize() override;
  virtual void handleMessage(cMessage *msg) override;
  cHistogram histogram;
};

#endif
