import org.omnetpp.queueing.Router;

simple CustomerRouter extends Router
{

    parameters: double probability1 = default(1);
    @class(CustomerRouter); // this is needed for the @class() annotation to work

    
}
