#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <yarp/os/BufferedPort.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/Time.h>
#include <stdio.h>
#include <iostream>

#include <Msg.h>

using namespace yarp::os;

int main(int argc, char *argv[]) {

    std::cerr << "In Receiver" << std::endl;

    Network yarp;
    // Port output;
    BufferedPort<Msg> input;
    input.open("/receiver");
    Network::connect("/sender","/receiver");


    int top = 100;
     for (int i=1; i<=top; i++) {
        // prepare a message
        Msg* myMsg;
        myMsg = input.read(true);

        std::cerr << "my message is: " 
                  << myMsg->names[0] << " " << myMsg->values[0] << " "
                  << myMsg->names[1] << " " << myMsg->values[1] << " "
                  << " map_2 " << myMsg->mapValues["map_2"]
                  << " map_3 " << myMsg->mapValues["map_3"]
                  << std::endl;

        // wait a while
        Time::delay(1);
    }
    input.close();

    return 0;
}