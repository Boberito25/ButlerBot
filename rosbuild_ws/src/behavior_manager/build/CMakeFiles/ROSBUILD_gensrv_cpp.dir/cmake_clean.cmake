FILE(REMOVE_RECURSE
  "../srv_gen"
  "../src/behavior_manager/srv"
  "CMakeFiles/ROSBUILD_gensrv_cpp"
  "../srv_gen/cpp/include/behavior_manager/RequestBehavior.h"
  "../srv_gen/cpp/include/behavior_manager/Initialize.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
