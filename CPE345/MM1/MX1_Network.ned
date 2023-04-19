import org.omnetpp.queueing.PassiveQueue;
import org.omnetpp.queueing.Server;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;

network MX1_Network
{
    submodules:
        server: Server {
            @display("p=213,148");
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
        passiveQueue.out++ --> server.in++;
        server.out --> sink.in++;
        source.out --> passiveQueue.in++;
}
