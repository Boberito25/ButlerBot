; Auto-generated. Do not edit!


(cl:in-package BehaviorManager-msg)


;//! \htmlinclude Activate.msg.html

(cl:defclass <Activate> (roslisp-msg-protocol:ros-message)
  ((behavior
    :reader behavior
    :initarg :behavior
    :type cl:string
    :initform "")
   (params
    :reader params
    :initarg :params
    :type cl:string
    :initform ""))
)

(cl:defclass Activate (<Activate>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Activate>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Activate)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name BehaviorManager-msg:<Activate> is deprecated: use BehaviorManager-msg:Activate instead.")))

(cl:ensure-generic-function 'behavior-val :lambda-list '(m))
(cl:defmethod behavior-val ((m <Activate>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader BehaviorManager-msg:behavior-val is deprecated.  Use BehaviorManager-msg:behavior instead.")
  (behavior m))

(cl:ensure-generic-function 'params-val :lambda-list '(m))
(cl:defmethod params-val ((m <Activate>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader BehaviorManager-msg:params-val is deprecated.  Use BehaviorManager-msg:params instead.")
  (params m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Activate>) ostream)
  "Serializes a message object of type '<Activate>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'behavior))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'behavior))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'params))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'params))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Activate>) istream)
  "Deserializes a message object of type '<Activate>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'behavior) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'behavior) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'params) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'params) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Activate>)))
  "Returns string type for a message object of type '<Activate>"
  "BehaviorManager/Activate")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Activate)))
  "Returns string type for a message object of type 'Activate"
  "BehaviorManager/Activate")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Activate>)))
  "Returns md5sum for a message object of type '<Activate>"
  "21aa9db2d3610b5442ceef9214241d8b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Activate)))
  "Returns md5sum for a message object of type 'Activate"
  "21aa9db2d3610b5442ceef9214241d8b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Activate>)))
  "Returns full string definition for message of type '<Activate>"
  (cl:format cl:nil "string behavior~%string params~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Activate)))
  "Returns full string definition for message of type 'Activate"
  (cl:format cl:nil "string behavior~%string params~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Activate>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'behavior))
     4 (cl:length (cl:slot-value msg 'params))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Activate>))
  "Converts a ROS message object to a list"
  (cl:list 'Activate
    (cl:cons ':behavior (behavior msg))
    (cl:cons ':params (params msg))
))