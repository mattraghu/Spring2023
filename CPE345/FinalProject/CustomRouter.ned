import org.omnetpp.queueing.Router;
simple CustomRouter extends Router
{
    @class(CustomRouter); // this is needed for the @class() annotation to work

    gates:
        output Complexity1;
        output Complexity2;
        output Complexity3;
}
