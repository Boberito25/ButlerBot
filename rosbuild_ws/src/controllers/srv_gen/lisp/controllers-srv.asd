
(cl:in-package :asdf)

(defsystem "controllers-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "armMove" :depends-on ("_package_armMove"))
    (:file "_package_armMove" :depends-on ("_package"))
    (:file "TestService" :depends-on ("_package_TestService"))
    (:file "_package_TestService" :depends-on ("_package"))
    (:file "BasicArmMove" :depends-on ("_package_BasicArmMove"))
    (:file "_package_BasicArmMove" :depends-on ("_package"))
  ))