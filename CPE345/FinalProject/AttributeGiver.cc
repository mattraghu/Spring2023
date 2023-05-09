#include "AttributeGiver.h"

Define_Module(AttributeGiver);

void AttributeGiver::handleMessage(cMessage *msg)
{
    EV << "Handling message `" << msg->getName() << "'\n";


    long difficulty = uniform(1,10);

    //set difficulty between 1 and 10
    msg->addPar("difficulty").setLongValue(difficulty);

    //default abandoned to false for later use
    msg->addPar("abandoned").setBoolValue(false);

    // Generate a random value with a normal distribution with mean 7 minutes, std of 3 minutes
       double abandonmentTime;
    // Ensure the abandonment time isn't negative or 0
       do {
           abandonmentTime = normal(7, 3);

       } while (abandonmentTime <= 0);

       // Create a parameter object and set its value
       msg->addPar("abandonmentTime").setDoubleValue(abandonmentTime);

       EV << "Abandonment Time: " << msg->par("abandonmentTime") << "'\n";
       // Call the parent class's handleMessage() function
       Router::handleMessage(msg);
}
