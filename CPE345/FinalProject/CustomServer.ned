import org.omnetpp.queueing.Server;
simple CustomServer extends Server
{
    parameters:  //Add the complexity parameter
        int expertise = default(10);
    @class(CustomServer); // this is needed for the @class() annotation to work
        
}