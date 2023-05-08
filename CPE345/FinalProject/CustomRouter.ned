import org.omnetpp.queueing.Router;
simple CustomRouter extends Router
{
    @class(CustomRouter); // this is needed for the @class() annotation to work

    gates:
        output Problem1;
        output Problem2;
        output Problem3;
}
