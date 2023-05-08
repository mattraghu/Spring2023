import org.omnetpp.queueing.Server;
simple CustomServer extends Server
{
    @class(CustomServer); // this is needed for the @class() annotation to work
}