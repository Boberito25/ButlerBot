FILE(REMOVE_RECURSE
  "../srv_gen"
  "../srv_gen"
  "../src/controllers/srv"
  "CMakeFiles/ROSBUILD_gensrv_py"
  "../src/controllers/srv/__init__.py"
  "../src/controllers/srv/_TestService.py"
  "../src/controllers/srv/_armAngles.py"
  "../src/controllers/srv/_BasicArmPlan.py"
  "../src/controllers/srv/_armMove.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
