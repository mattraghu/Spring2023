import org.omnetpp.queueing.PassiveQueue;
import org.omnetpp.queueing.Router;
import org.omnetpp.queueing.Server;
import org.omnetpp.queueing.Source;


network FinalExam
{
    submodules:
        passiveQueue1: PassiveQueue {
            @display("p=175,96");
        }
        server1: Server {
            @display("p=227,96");
        }
        passiveQueue2: PassiveQueue {
            @display("p=395,96");
        }
        server2: Server {
            @display("p=452,96");
        }
        passiveQueue3: PassiveQueue {
            @display("p=395,165");
        }
        server3: Server {
            @display("p=452,165");
        }
        passiveQueue4: PassiveQueue {
            @display("p=597,135");
        }
        server4: Server {
            @display("p=654,135");
        }
        source1: Source {
            @display("p=53,54");
        }
        source2: Source {
            @display("p=53,126");
        }
        source3: Source {
            @display("p=395,259");
        }
        customRouter: CustomRouter {
            @display("p=280,96");
            probability1 = 0.5;
        }
        customSink: CustomSink {
            @display("p=754,135");
        }
    connections:
        source1.out --> passiveQueue1.in++;
        source2.out --> passiveQueue1.in++;
        passiveQueue1.out++ --> server1.in++;
        passiveQueue2.out++ --> server2.in++;
        passiveQueue3.out++ --> server3.in++;
        source3.out --> passiveQueue3.in++;
        server2.out --> passiveQueue4.in++;
        server3.out --> passiveQueue4.in++;
        passiveQueue4.out++ --> server4.in++;
        server1.out --> customRouter.in++;
        customRouter.P1 --> passiveQueue2.in++;
        customRouter.P2 --> passiveQueue3.in++;
        server4.out --> customSink.in++;
}
