FILE(REMOVE_RECURSE
  "../srv_gen"
  "../srv_gen"
  "../src/controllers/srv"
  "CMakeFiles/ROSBUILD_gensrv_lisp"
  "../srv_gen/lisp/BasicArmPlan.lisp"
  "../srv_gen/lisp/_package.lisp"
  "../srv_gen/lisp/_package_BasicArmPlan.lisp"
  "../srv_gen/lisp/armMove.lisp"
  "../srv_gen/lisp/_package.lisp"
  "../srv_gen/lisp/_package_armMove.lisp"
  "../srv_gen/lisp/TestService.lisp"
  "../srv_gen/lisp/_package.lisp"
  "../srv_gen/lisp/_package_TestService.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
