import org.omnetpp.queueing.Server;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;


network Design3
{
    submodules:
        customRouter: CustomRouter {
            @display("p=222,96");
        }
        server1: CustomServer {
            @display("p=470,66");
            expertise = 10;
        }
        customQueue1: CustomQueue {
            @display("p=336,96");
            priorityEffected = false;
        }
        customSink: CustomSink {
            @display("p=636,96");
        }
        source: Source {
            @display("p=86,96");
        }
        attributeGiver: AttributeGiver {
            @display("p=139,96");
        }
        server2: CustomServer {
            @display("p=470,149");
            expertise = 10;
        }
        server3: CustomServer {
            @display("p=470,223");
            expertise = 10;
        }
    connections:
        customQueue1.out++ --> server1.in++;
        server1.out --> customSink.in++;
        source.out --> attributeGiver.in++;
        attributeGiver.out++ --> customRouter.in++;
        server2.out --> customSink.in++;
        server3.out --> customSink.in++;
        customRouter.Complexity1 --> customQueue1.in++;
        customQueue1.out++ --> server2.in++;
        customQueue1.out++ --> server3.in++;
}
