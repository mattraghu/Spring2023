import org.omnetpp.queueing.PassiveQueue;
import org.omnetpp.queueing.Server;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;


network Design1
{
    submodules:
        customRouter: CustomRouter {
            @display("p=222,96");
        }
        server: CustomServer {
            @display("p=517,66");
        }
        customQueue: CustomQueue {
            @display("p=390,66");
        }
        sink: Sink {
            @display("p=596,96");
        }
        source: Source {
            @display("p=86,96");
        }
        attributeGiver: AttributeGiver {
            @display("p=139,96");
        }
    connections:
        customRouter.out++ --> customQueue.in++;
        customQueue.out++ --> server.in++;
        server.out --> sink.in++;
        source.out --> attributeGiver.in++;
        attributeGiver.out++ --> customRouter.in++;
}
