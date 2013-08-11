FILE(REMOVE_RECURSE
  "../srv_gen"
  "../src/behavior_manager/srv"
  "CMakeFiles/ROSBUILD_gensrv_py"
  "../src/behavior_manager/srv/__init__.py"
  "../src/behavior_manager/srv/_DeactivateBehavior.py"
  "../src/behavior_manager/srv/_RequestBehavior.py"
  "../src/behavior_manager/srv/_Initialize.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
