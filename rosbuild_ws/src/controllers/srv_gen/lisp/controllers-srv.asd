
(cl:in-package :asdf)

(defsystem "controllers-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "BasicArmPlan" :depends-on ("_package_BasicArmPlan"))
    (:file "_package_BasicArmPlan" :depends-on ("_package"))
    (:file "armMove" :depends-on ("_package_armMove"))
    (:file "_package_armMove" :depends-on ("_package"))
    (:file "TestService" :depends-on ("_package_TestService"))
    (:file "_package_TestService" :depends-on ("_package"))
    (:file "armAngles" :depends-on ("_package_armAngles"))
    (:file "_package_armAngles" :depends-on ("_package"))
  ))