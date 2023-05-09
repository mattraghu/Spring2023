#ifndef __FINALPROJECT_CUSTOMSERVER_H_
#define __FINALPROJECT_CUSTOMSERVER_H_

#include <omnetpp.h>
#include <Server.h>

using namespace omnetpp;

class CustomServer : public queueing::Server
{
protected:
  virtual void handleMessage(cMessage *msg) override;
  virtual void initialize() override;
};

#endif
