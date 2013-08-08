FILE(REMOVE_RECURSE
  "../msg_gen"
  "../srv_gen"
  "../src/controller_manager/msg"
  "../src/controller_manager/srv"
  "CMakeFiles/test-results-run"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/test-results-run.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
