# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "Intelligence: 0 messages, 2 services")

set(MSG_I_FLAGS "-IIntelligence:/home/vsunder/ButlerBot/catkin_ws/src/Intelligence/msg;-Istd_msgs:/opt/ros/groovy/share/std_msgs/msg")

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

### Generating Services
_generate_srv_cpp(Intelligence
  /home/vsunder/ButlerBot/catkin_ws/src/Intelligence/srv/Startup.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Intelligence
)
_generate_srv_cpp(Intelligence
  /home/vsunder/ButlerBot/catkin_ws/src/Intelligence/srv/EnableComs.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Intelligence
)

### Generating Module File
_generate_module_cpp(Intelligence
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Intelligence
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(Intelligence_gencpp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(Intelligence
  /home/vsunder/ButlerBot/catkin_ws/src/Intelligence/srv/Startup.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Intelligence
)
_generate_srv_lisp(Intelligence
  /home/vsunder/ButlerBot/catkin_ws/src/Intelligence/srv/EnableComs.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Intelligence
)

### Generating Module File
_generate_module_lisp(Intelligence
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Intelligence
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(Intelligence_genlisp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(Intelligence
  /home/vsunder/ButlerBot/catkin_ws/src/Intelligence/srv/Startup.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Intelligence
)
_generate_srv_py(Intelligence
  /home/vsunder/ButlerBot/catkin_ws/src/Intelligence/srv/EnableComs.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Intelligence
)

### Generating Module File
_generate_module_py(Intelligence
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Intelligence
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(Intelligence_genpy ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)


debug_message(2 "Intelligence: Iflags=${MSG_I_FLAGS}")


if(gencpp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Intelligence
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(Intelligence_gencpp std_msgs_gencpp)

if(genlisp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Intelligence
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(Intelligence_genlisp std_msgs_genlisp)

if(genpy_INSTALL_DIR)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Intelligence\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Intelligence
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(Intelligence_genpy std_msgs_genpy)
