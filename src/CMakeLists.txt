add_executable(transmitter transmitter/transmitter.cpp)
target_link_libraries(transmitter ${YARP_LIBRARIES}
                                  Msg
                                  MsgMap)

add_executable(receiver receiver/receiver.cpp)
target_link_libraries(receiver ${YARP_LIBRARIES}
                               Msg
                               MsgMap)

add_executable(receiver_no_map receiver/receiver_no_map.cpp)
target_link_libraries(receiver_no_map ${YARP_LIBRARIES}
                               Msg)
