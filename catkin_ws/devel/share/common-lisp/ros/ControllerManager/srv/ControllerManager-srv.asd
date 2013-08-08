
(cl:in-package :asdf)

(defsystem "ControllerManager-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "RequestController" :depends-on ("_package_RequestController"))
    (:file "_package_RequestController" :depends-on ("_package"))
  ))