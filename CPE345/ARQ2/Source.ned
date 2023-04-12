//ARQ Source
simple Source
{
    parameters:
        @display("i=block/source");
        int limit = default(10000);
    gates:
        input in;
        output out;
}
