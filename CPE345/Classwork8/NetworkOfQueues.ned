import org.omnetpp.queueing.PassiveQueue;
import org.omnetpp.queueing.Router;
import org.omnetpp.queueing.Server;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;


network NetworkOfQueues
{
    submodules:
        source1: Source {
            @display("p=59,55");
        }
        source2: Source {
            @display("p=59,139");
        }
        router1: CustomerRouter {
            @display("p=312,61");
            probability1 = 0.4;
        }
        router2: CustomerRouter {
            @display("p=312,139");
            probability1 = 1;
        }
        router3: CustomerRouter {
            @display("p=491,139");
            probability1 = 1;
        }
        sink: CustomSink { 
            @display("p=491,61");
        }
        source2Router: CustomerRouter {
            @display("p=135,139");
            probability1 = .2;
        }
        server1: Server {
            @display("p=262,61");
            serviceTime = exponential(0.25s);

        }
        server2: Server {
            @display("p=260,139");
            serviceTime = exponential(0.25s);
        }
        server3: Server {
            @display("p=442,139");
            serviceTime = exponential(0.25s);
        }
        queue1: PassiveQueue {
            @display("p=210,61");
        }
        queue2: PassiveQueue {
            @display("p=210,139");
        }
        queue3: PassiveQueue {
            @display("p=392,139");
        }
    connections:
        router1.out++ --> sink.in++;
        source2.out --> source2Router.in++;
        source1.out --> queue1.in++;
        source2Router.out++ --> queue1.in++;
        source2Router.out++ --> queue2.in++;
        router1.out++ --> queue3.in++;
        router2.out++ --> queue3.in++;
        router3.out++ --> sink.in++;
        server3.out --> router3.in++;
        server2.out --> router2.in++;
        queue1.out++ --> server1.in++;
        server1.out --> router1.in++;
        queue2.out++ --> server2.in++;
        queue3.out++ --> server3.in++;
}
