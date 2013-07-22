
(cl:in-package :asdf)

(defsystem "BehaviorManager-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Deactivate" :depends-on ("_package_Deactivate"))
    (:file "_package_Deactivate" :depends-on ("_package"))
  ))