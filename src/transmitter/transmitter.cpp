#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <yarp/os/BufferedPort.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/Time.h>
#include <stdio.h>
#include <iostream>

#include <Msg.h>
#include <MsgMap.h>

using namespace yarp::os;

int main(int argc, char *argv[]) {

    std::cerr << "In transmitter" << std::endl;

    Network yarp;

    // Port output not using map;
    BufferedPort<Msg> output;
    output.open("/sender");

    BufferedPort<MsgMap> outputMap;
    outputMap.open("/senderMap");


    int top = 100;
     for (int i=1; i<=top; i++) {
        // prepare meassge without map
        Msg& myMsg = output.prepare();
        myMsg.names.resize(2);
        myMsg.names[0] = "name_0";
        myMsg.names[1] = "name_1";
        myMsg.values.resize(2);
        myMsg.values[0] = 0;
        myMsg.values[1] = 1;

        // prepare msg with map
        MsgMap& myMsgMap = outputMap.prepare();
        myMsgMap.mapValues["map_2"] = 2;
        myMsgMap.mapValues["map_3"] = 3;
        
        // write adn wait
        output.write(true);
        outputMap.write(true);
        Time::delay(1);
    }
    output.close();

    return 0;
}