#ifndef __FINALPROJECT_ABANDONMENTCHECKER_H_
#define __FINALPROJECT_ABANDONMENTCHECKER_H_

#include <omnetpp.h>
#include <Router.h>

using namespace omnetpp;

class AbandonmentChecker : public queueing::Router
{
protected:
  virtual void handleMessage(cMessage *msg) override;
};

#endif
