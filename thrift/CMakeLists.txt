### Msg without Map

yarp_add_idl(MSG_FILES msg.thrift)

add_library(Msg ${MSG_FILES} msg.thrift)
target_link_libraries(Msg YARP::YARP_OS YARP::YARP_sig)

target_include_directories(Msg PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>)

install(TARGETS Msg
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

### Msg with Map

yarp_add_idl(MSGMAP_FILES msgMap.thrift)

add_library(MsgMap ${MSGMAP_FILES} msgMap.thrift)
target_link_libraries(MsgMap YARP::YARP_OS YARP::YARP_sig)

target_include_directories(MsgMap PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>)

install(TARGETS MsgMap
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})