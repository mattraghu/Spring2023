import org.omnetpp.queueing.Router;

simple CustomRouter extends Router
{

    parameters: double probability1 = default(1);
    @class(CustomRouter); // this is needed for the @class() annotation to work

    gates:
        output P1;
        output P2;

    
}
