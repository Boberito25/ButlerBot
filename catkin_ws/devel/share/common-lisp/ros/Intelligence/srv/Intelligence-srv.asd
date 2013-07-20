
(cl:in-package :asdf)

(defsystem "Intelligence-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "EnableComs" :depends-on ("_package_EnableComs"))
    (:file "_package_EnableComs" :depends-on ("_package"))
    (:file "Startup" :depends-on ("_package_Startup"))
    (:file "_package_Startup" :depends-on ("_package"))
  ))