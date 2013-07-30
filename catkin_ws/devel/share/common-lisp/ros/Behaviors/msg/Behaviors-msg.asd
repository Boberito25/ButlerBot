
(cl:in-package :asdf)

(defsystem "Behaviors-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Completed" :depends-on ("_package_Completed"))
    (:file "_package_Completed" :depends-on ("_package"))
    (:file "Recs" :depends-on ("_package_Recs"))
    (:file "_package_Recs" :depends-on ("_package"))
  ))