import org.omnetpp.queueing.Sink;

simple My_Sink_ext extends Sink
{
    @class(My_Sink_ext); // this is the class name of the module. it makes it so that the module can be found by the name "My_Sink_ext" in the ini file
}
