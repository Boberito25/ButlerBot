FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/behaviors/msg"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/behaviors/Deactivate.h"
  "../msg_gen/cpp/include/behaviors/Completed.h"
  "../msg_gen/cpp/include/behaviors/Startup.h"
  "../msg_gen/cpp/include/behaviors/Activate.h"
  "../msg_gen/cpp/include/behaviors/Shutdown.h"
  "../msg_gen/cpp/include/behaviors/Recs.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
