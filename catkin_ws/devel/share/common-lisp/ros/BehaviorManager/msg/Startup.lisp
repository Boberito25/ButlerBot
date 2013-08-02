; Auto-generated. Do not edit!


(cl:in-package BehaviorManager-msg)


;//! \htmlinclude Startup.msg.html

(cl:defclass <Startup> (roslisp-msg-protocol:ros-message)
  ((behavior
    :reader behavior
    :initarg :behavior
    :type cl:string
    :initform ""))
)

(cl:defclass Startup (<Startup>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Startup>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Startup)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name BehaviorManager-msg:<Startup> is deprecated: use BehaviorManager-msg:Startup instead.")))

(cl:ensure-generic-function 'behavior-val :lambda-list '(m))
(cl:defmethod behavior-val ((m <Startup>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader BehaviorManager-msg:behavior-val is deprecated.  Use BehaviorManager-msg:behavior instead.")
  (behavior m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Startup>) ostream)
  "Serializes a message object of type '<Startup>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'behavior))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'behavior))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Startup>) istream)
  "Deserializes a message object of type '<Startup>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'behavior) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'behavior) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Startup>)))
  "Returns string type for a message object of type '<Startup>"
  "BehaviorManager/Startup")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Startup)))
  "Returns string type for a message object of type 'Startup"
  "BehaviorManager/Startup")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Startup>)))
  "Returns md5sum for a message object of type '<Startup>"
  "03729983c4b9be7a4f2b56846a7ccbdc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Startup)))
  "Returns md5sum for a message object of type 'Startup"
  "03729983c4b9be7a4f2b56846a7ccbdc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Startup>)))
  "Returns full string definition for message of type '<Startup>"
  (cl:format cl:nil "string behavior~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Startup)))
  "Returns full string definition for message of type 'Startup"
  (cl:format cl:nil "string behavior~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Startup>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'behavior))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Startup>))
  "Converts a ROS message object to a list"
  (cl:list 'Startup
    (cl:cons ':behavior (behavior msg))
))
