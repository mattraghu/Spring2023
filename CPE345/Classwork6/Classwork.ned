// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

simple Node3
{
    parameters:
        @display("i=block/routing"); // add a default icon
        int num_msgs = 10;
    gates:
        input in;
        output out;
}





network Classwork
{
    @display("bgb=342,184");

    types: 
        channel C extends ned.DelayChannel {
            parameters:
                @display("i=block/clock");
                delay = 50ms;
        }
    submodules:
        node1: Node3 {
            parameters:
                @display("i=,cyan;p=38,69"); // do not change the icon (first arg of i=) just colorize it
        }

        node2: Node3 {
            parameters:
                @display("i=,gold;p=154,69"); // here too
        }
        node3: Node3 {
            parameters:
                @display("i=,red;p=154,143"); // here too
        }
    connections:
        //Add a 100ms delay to the connection between node1 and node2
        node1.out --> {delay = 100ms;} --> node2.in;
        node2.out --> C --> node3.in;
        node3.out --> C --> node1.in;
}


