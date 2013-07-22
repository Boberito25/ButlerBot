
(cl:in-package :asdf)

(defsystem "Behaviors-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ReserveBehavior" :depends-on ("_package_ReserveBehavior"))
    (:file "_package_ReserveBehavior" :depends-on ("_package"))
  ))