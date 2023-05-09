#include "AttributeGiver.h"

Define_Module(AttributeGiver);

void AttributeGiver::handleMessage(cMessage *msg)
{
    EV << "Handling message `" << msg->getName() << "'\n";


    long difficulty = uniform(1,10);

    msg->addPar("difficulty").setLongValue(difficulty);

    // Generate a random value with a normal distribution with mean 7 minutes, std of 3 minutes
       double abandonmentTime;
    // Ensure the abandonment time isn't negative or 0
       do {
           abandonmentTime = normal(7.0*60, 3.0*60);

       } while (abandonmentTime <= 0);

       // Create a parameter object and set its value
       msg->addPar("abandonmentTime").setDoubleValue(abandonmentTime);

       // Call the parent class's handleMessage() function
       Router::handleMessage(msg);
}
