FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/behaviors/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/behaviors/msg/__init__.py"
  "../src/behaviors/msg/_Deactivate.py"
  "../src/behaviors/msg/_Completed.py"
  "../src/behaviors/msg/_Startup.py"
  "../src/behaviors/msg/_Activate.py"
  "../src/behaviors/msg/_Recs.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
