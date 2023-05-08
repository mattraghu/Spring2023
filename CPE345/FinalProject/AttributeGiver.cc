#include "AttributeGiver.h"

Define_Module(AttributeGiver);

void AttributeGiver::handleMessage(cMessage *msg)
{
    EV << "Handling message `" << msg->getName() << "'\n";


    // Generate a random value with a normal distribution with mean 7 minutes, std of 3 minutes
       double abandonmentTime;
    // Ensure the abandonment time isn't negative or 0
       do {
           abandonmentTime = normal(7.0*60, 3.0*60);

       } while (abandonmentTime <= 0);

       // Create a parameter object and set its value
       cPar *abandonmentTimePar = new cPar("abandonmentTime");
       abandonmentTimePar->setDoubleValue(abandonmentTime);

       // Add the parameter to the message
       msg->addPar(abandonmentTimePar);

       // Call the parent class's handleMessage() function
       Router::handleMessage(msg);
}
