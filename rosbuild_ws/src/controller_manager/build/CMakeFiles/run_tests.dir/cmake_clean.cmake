FILE(REMOVE_RECURSE
  "../msg_gen"
  "../srv_gen"
  "../src/controller_manager/msg"
  "../src/controller_manager/srv"
  "CMakeFiles/run_tests"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/run_tests.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)