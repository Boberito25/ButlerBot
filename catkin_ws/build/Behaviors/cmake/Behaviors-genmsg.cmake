# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "Behaviors: 1 messages, 1 services")

set(MSG_I_FLAGS "-IBehaviors:/home/vsunder/ButlerBot/catkin_ws/src/Behaviors/msg;-Istd_msgs:/opt/ros/groovy/share/std_msgs/msg")

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
_generate_msg_cpp(Behaviors
  /home/vsunder/ButlerBot/catkin_ws/src/Behaviors/msg/Recs.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Behaviors
)

### Generating Services
_generate_srv_cpp(Behaviors
  /home/vsunder/ButlerBot/catkin_ws/src/Behaviors/srv/ReserveBehavior.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Behaviors
)

### Generating Module File
_generate_module_cpp(Behaviors
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Behaviors
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(Behaviors_gencpp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(Behaviors
  /home/vsunder/ButlerBot/catkin_ws/src/Behaviors/msg/Recs.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Behaviors
)

### Generating Services
_generate_srv_lisp(Behaviors
  /home/vsunder/ButlerBot/catkin_ws/src/Behaviors/srv/ReserveBehavior.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Behaviors
)

### Generating Module File
_generate_module_lisp(Behaviors
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Behaviors
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(Behaviors_genlisp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(Behaviors
  /home/vsunder/ButlerBot/catkin_ws/src/Behaviors/msg/Recs.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Behaviors
)

### Generating Services
_generate_srv_py(Behaviors
  /home/vsunder/ButlerBot/catkin_ws/src/Behaviors/srv/ReserveBehavior.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Behaviors
)

### Generating Module File
_generate_module_py(Behaviors
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Behaviors
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(Behaviors_genpy ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)


debug_message(2 "Behaviors: Iflags=${MSG_I_FLAGS}")


if(gencpp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Behaviors
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(Behaviors_gencpp std_msgs_gencpp)

if(genlisp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Behaviors
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(Behaviors_genlisp std_msgs_genlisp)

if(genpy_INSTALL_DIR)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Behaviors\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Behaviors
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(Behaviors_genpy std_msgs_genpy)
