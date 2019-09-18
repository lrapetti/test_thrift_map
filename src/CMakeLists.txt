add_executable(transmitter transmitter/transmitter.cpp)
target_link_libraries(transmitter ${YARP_LIBRARIES}
                                  Msg
                                  MsgMap)

add_executable(receiver receiver/receiver.cpp)
target_link_libraries(receiver ${YARP_LIBRARIES}
                               Msg
                               MsgMap)