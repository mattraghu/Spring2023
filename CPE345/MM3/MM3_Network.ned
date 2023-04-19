import org.omnetpp.queueing.PassiveQueue;
import org.omnetpp.queueing.Server;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;


network MM3_Network
{
    submodules:
        server1: Server {
            @display("p=213,86");
        }
        server2: Server {
            @display("p=213,148");
        }
        server3: Server {
            @display("p=213,208");
        }
        sink: Sink {
            @display("p=316,148");
        }
        passiveQueue: PassiveQueue {
            @display("p=128,148");
        }
        source: Source {
            @display("p=54,148");
        }
    connections:
        passiveQueue.out++ --> server1.in++;
        passiveQueue.out++ --> server2.in++;
        passiveQueue.out++ --> server3.in++;
        server1.out --> sink.in++;
        server2.out --> sink.in++;
        server3.out --> sink.in++;
        source.out --> passiveQueue.in++;
}
