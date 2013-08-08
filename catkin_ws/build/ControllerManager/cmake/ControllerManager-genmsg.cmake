# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "ControllerManager: 1 messages, 1 services")

set(MSG_I_FLAGS "-IControllerManager:/home/vsunder/ButlerBot/catkin_ws/src/ControllerManager/msg;-Istd_msgs:/opt/ros/groovy/share/std_msgs/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

#better way to handle this?
set (ALL_GEN_OUTPUT_FILES_cpp "")

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(ControllerManager
  /home/vsunder/ButlerBot/catkin_ws/src/ControllerManager/msg/ReleaseController.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ControllerManager
)

### Generating Services
_generate_srv_cpp(ControllerManager
  /home/vsunder/ButlerBot/catkin_ws/src/ControllerManager/srv/RequestController.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ControllerManager
)

### Generating Module File
_generate_module_cpp(ControllerManager
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ControllerManager
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(ControllerManager_gencpp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(ControllerManager
  /home/vsunder/ButlerBot/catkin_ws/src/ControllerManager/msg/ReleaseController.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ControllerManager
)

### Generating Services
_generate_srv_lisp(ControllerManager
  /home/vsunder/ButlerBot/catkin_ws/src/ControllerManager/srv/RequestController.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ControllerManager
)

### Generating Module File
_generate_module_lisp(ControllerManager
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ControllerManager
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(ControllerManager_genlisp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(ControllerManager
  /home/vsunder/ButlerBot/catkin_ws/src/ControllerManager/msg/ReleaseController.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ControllerManager
)

### Generating Services
_generate_srv_py(ControllerManager
  /home/vsunder/ButlerBot/catkin_ws/src/ControllerManager/srv/RequestController.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ControllerManager
)

### Generating Module File
_generate_module_py(ControllerManager
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ControllerManager
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(ControllerManager_genpy ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)


debug_message(2 "ControllerManager: Iflags=${MSG_I_FLAGS}")


if(gencpp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ControllerManager
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(ControllerManager_gencpp std_msgs_gencpp)

if(genlisp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ControllerManager
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(ControllerManager_genlisp std_msgs_genlisp)

if(genpy_INSTALL_DIR)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ControllerManager\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ControllerManager
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(ControllerManager_genpy std_msgs_genpy)
