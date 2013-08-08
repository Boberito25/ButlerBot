
(cl:in-package :asdf)

(defsystem "ControllerManager-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ReleaseController" :depends-on ("_package_ReleaseController"))
    (:file "_package_ReleaseController" :depends-on ("_package"))
  ))