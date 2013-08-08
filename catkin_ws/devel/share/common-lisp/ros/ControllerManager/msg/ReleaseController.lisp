; Auto-generated. Do not edit!


(cl:in-package ControllerManager-msg)


;//! \htmlinclude ReleaseController.msg.html

(cl:defclass <ReleaseController> (roslisp-msg-protocol:ros-message)
  ((controller
    :reader controller
    :initarg :controller
    :type cl:string
    :initform ""))
)

(cl:defclass ReleaseController (<ReleaseController>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReleaseController>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReleaseController)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ControllerManager-msg:<ReleaseController> is deprecated: use ControllerManager-msg:ReleaseController instead.")))

(cl:ensure-generic-function 'controller-val :lambda-list '(m))
(cl:defmethod controller-val ((m <ReleaseController>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ControllerManager-msg:controller-val is deprecated.  Use ControllerManager-msg:controller instead.")
  (controller m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReleaseController>) ostream)
  "Serializes a message object of type '<ReleaseController>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'controller))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'controller))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReleaseController>) istream)
  "Deserializes a message object of type '<ReleaseController>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'controller) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'controller) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReleaseController>)))
  "Returns string type for a message object of type '<ReleaseController>"
  "ControllerManager/ReleaseController")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReleaseController)))
  "Returns string type for a message object of type 'ReleaseController"
  "ControllerManager/ReleaseController")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReleaseController>)))
  "Returns md5sum for a message object of type '<ReleaseController>"
  "36383e0f0fa46585abbab8aedd87321a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReleaseController)))
  "Returns md5sum for a message object of type 'ReleaseController"
  "36383e0f0fa46585abbab8aedd87321a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReleaseController>)))
  "Returns full string definition for message of type '<ReleaseController>"
  (cl:format cl:nil "string controller~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReleaseController)))
  "Returns full string definition for message of type 'ReleaseController"
  (cl:format cl:nil "string controller~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReleaseController>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'controller))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReleaseController>))
  "Converts a ROS message object to a list"
  (cl:list 'ReleaseController
    (cl:cons ':controller (controller msg))
))
