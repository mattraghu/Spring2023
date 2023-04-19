//ARQ Network
network ARQ_Network
{
    parameters:
      @display("bgb=217,159");
    submodules:
        source: Source;
        destination: Destination {
            @display("p=168,61");
        0}
    connections:
        source.out --> {datarate = 10000 bps; ber = .01;} --> destination.in; 
        destination.out --> source.in;
}
