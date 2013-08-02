# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "BehaviorManager: 3 messages, 0 services")

set(MSG_I_FLAGS "-IBehaviorManager:/home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/msg;-Istd_msgs:/opt/ros/groovy/share/std_msgs/msg")

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
_generate_msg_cpp(BehaviorManager
  /home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/msg/Deactivate.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/BehaviorManager
)
_generate_msg_cpp(BehaviorManager
  /home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/msg/Activate.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/BehaviorManager
)
_generate_msg_cpp(BehaviorManager
  /home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/msg/Startup.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/BehaviorManager
)

### Generating Services

### Generating Module File
_generate_module_cpp(BehaviorManager
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/BehaviorManager
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(BehaviorManager_gencpp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(BehaviorManager
  /home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/msg/Deactivate.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/BehaviorManager
)
_generate_msg_lisp(BehaviorManager
  /home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/msg/Activate.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/BehaviorManager
)
_generate_msg_lisp(BehaviorManager
  /home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/msg/Startup.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/BehaviorManager
)

### Generating Services

### Generating Module File
_generate_module_lisp(BehaviorManager
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/BehaviorManager
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(BehaviorManager_genlisp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(BehaviorManager
  /home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/msg/Deactivate.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/BehaviorManager
)
_generate_msg_py(BehaviorManager
  /home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/msg/Activate.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/BehaviorManager
)
_generate_msg_py(BehaviorManager
  /home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/msg/Startup.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/BehaviorManager
)

### Generating Services

### Generating Module File
_generate_module_py(BehaviorManager
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/BehaviorManager
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(BehaviorManager_genpy ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)


debug_message(2 "BehaviorManager: Iflags=${MSG_I_FLAGS}")


if(gencpp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/BehaviorManager
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(BehaviorManager_gencpp std_msgs_gencpp)

if(genlisp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/BehaviorManager
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(BehaviorManager_genlisp std_msgs_genlisp)

if(genpy_INSTALL_DIR)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/BehaviorManager\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/BehaviorManager
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(BehaviorManager_genpy std_msgs_genpy)
