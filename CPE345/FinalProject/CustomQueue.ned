import org.omnetpp.queueing.PassiveQueue;

simple CustomQueue extends PassiveQueue
{
    parameters:  
        bool priorityEffected = default(true);
    @class(CustomQueue);
}
