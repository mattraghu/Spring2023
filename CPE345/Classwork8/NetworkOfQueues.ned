import org.omnetpp.queueing.Router;
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
            @display("p=217,55");

            probability1 = 0.5;
        }
        router2: CustomerRouter {
            @display("p=217,139");
        }
        router3: CustomerRouter {
            @display("p=345,139");
        }
        sink: Sink {
            @display("p=345,55");
        }
        source2Router: Router {
            @display("p=135,139");
        }
    connections:
        router1.out++ --> sink.in++;
        source2.out --> source2Router.in++;
        source1.out --> router1.in++;
        source2Router.out++ --> router1.in++;
        source2Router.out++ --> router2.in++;
        router1.out++ --> router3.in++;
        router2.out++ --> router3.in++;
        router3.out++ --> sink.in++;
}
