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
        server1: CustomServer {
            @display("p=470,66");
            expertise = 3;
        }
        customQueue1: CustomQueue {
            @display("p=390,66");
        }
        sink: Sink {
            @display("p=636,96");
        }
        source: Source {
            @display("p=86,96");
        }
        attributeGiver: AttributeGiver {
            @display("p=139,96");
        }
        customQueue2: CustomQueue {
            @display("p=390,149");
        }
        server2: CustomServer {
            @display("p=470,149");
            expertise = 6;
        }
        customQueue3: CustomQueue {
            @display("p=390,223");
        }
        server3: CustomServer {
            @display("p=470,223");
            expertise = 10;
        }
    connections:
        customQueue1.out++ --> server1.in++;
        server1.out --> sink.in++;
        source.out --> attributeGiver.in++;
        attributeGiver.out++ --> customRouter.in++;
        customQueue2.out++ --> server2.in++;
        customQueue3.out++ --> server3.in++;
        server2.out --> sink.in++;
        server3.out --> sink.in++;
        customRouter.Complexity1 --> customQueue1.in++;
        customRouter.Complexity2 --> customQueue2.in++;
        customRouter.Complexity3 --> customQueue3.in++;
}
