FILE(REMOVE_RECURSE
  "../srv_gen"
  "../src/controllers/srv"
  "CMakeFiles/ROSBUILD_gensrv_cpp"
  "../srv_gen/cpp/include/controllers/arm_controller.h"
  "../srv_gen/cpp/include/controllers/armMove.h"
  "../srv_gen/cpp/include/controllers/TestService.h"
  "../srv_gen/cpp/include/controllers/BasicArmMove.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
