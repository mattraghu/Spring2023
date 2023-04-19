import org.omnetpp.queueing.*;

network PQ_Network
{
    submodules:
        source1: Source {
            @display("p=50,50");
        }
        source2: Source {
            @display("p=50,200");
        }
        classifier: Classifier {
            @display("p=200,125");
        }
        queue1: PassiveQueue {
            @display("p=350,50");
        }
        queue2: PassiveQueue {
            @display("p=350,200");
        }
        server: Server {
            @display("p=500,125");
        }
        sink: Sink {
            @display("p=650,125");
        }
    connections:
        source1.out --> classifier.in++;
        source2.out --> classifier.in++;
        classifier.out++ --> queue1.in++;
        classifier.out++ --> queue2.in++;
        queue1.out++ --> server.in++;
        queue2.out++ --> server.in++;
        server.out --> sink.in++;
        classifier.rest --> sink.in++;
}
