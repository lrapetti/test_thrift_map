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

    std::cerr << "In transmitter" << std::endl;

    Network yarp;
    // Port output;
    BufferedPort<Msg> output;
    output.open("/sender");


    int top = 100;
     for (int i=1; i<=top; i++) {
        // prepare a message
        Msg& myMsg = output.prepare();
        myMsg.names.resize(2);
        myMsg.names[0] = "name_0";
        myMsg.names[1] = "name_1";
        myMsg.values.resize(2);
        myMsg.values[0] = 0;
        myMsg.values[1] = 1;

        //map message
        myMsg.mapValues["map_2"] = 2;
        myMsg.mapValues["map_3"] = 3;
        
        // write adn wait
        output.write(true);
        Time::delay(1);
    }
    output.close();

    return 0;
}