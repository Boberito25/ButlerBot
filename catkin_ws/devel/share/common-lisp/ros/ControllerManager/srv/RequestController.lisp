; Auto-generated. Do not edit!


(cl:in-package ControllerManager-srv)


;//! \htmlinclude RequestController-request.msg.html

(cl:defclass <RequestController-request> (roslisp-msg-protocol:ros-message)
  ((controller
    :reader controller
    :initarg :controller
    :type cl:string
    :initform ""))
)

(cl:defclass RequestController-request (<RequestController-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RequestController-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RequestController-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ControllerManager-srv:<RequestController-request> is deprecated: use ControllerManager-srv:RequestController-request instead.")))

(cl:ensure-generic-function 'controller-val :lambda-list '(m))
(cl:defmethod controller-val ((m <RequestController-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ControllerManager-srv:controller-val is deprecated.  Use ControllerManager-srv:controller instead.")
  (controller m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RequestController-request>) ostream)
  "Serializes a message object of type '<RequestController-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'controller))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'controller))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RequestController-request>) istream)
  "Deserializes a message object of type '<RequestController-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RequestController-request>)))
  "Returns string type for a service object of type '<RequestController-request>"
  "ControllerManager/RequestControllerRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RequestController-request)))
  "Returns string type for a service object of type 'RequestController-request"
  "ControllerManager/RequestControllerRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RequestController-request>)))
  "Returns md5sum for a message object of type '<RequestController-request>"
  "57cf6126b2c87e559f87a64cffffed90")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RequestController-request)))
  "Returns md5sum for a message object of type 'RequestController-request"
  "57cf6126b2c87e559f87a64cffffed90")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RequestController-request>)))
  "Returns full string definition for message of type '<RequestController-request>"
  (cl:format cl:nil "string controller~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RequestController-request)))
  "Returns full string definition for message of type 'RequestController-request"
  (cl:format cl:nil "string controller~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RequestController-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'controller))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RequestController-request>))
  "Converts a ROS message object to a list"
  (cl:list 'RequestController-request
    (cl:cons ':controller (controller msg))
))
;//! \htmlinclude RequestController-response.msg.html

(cl:defclass <RequestController-response> (roslisp-msg-protocol:ros-message)
  ((owner
    :reader owner
    :initarg :owner
    :type cl:string
    :initform ""))
)

(cl:defclass RequestController-response (<RequestController-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RequestController-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RequestController-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ControllerManager-srv:<RequestController-response> is deprecated: use ControllerManager-srv:RequestController-response instead.")))

(cl:ensure-generic-function 'owner-val :lambda-list '(m))
(cl:defmethod owner-val ((m <RequestController-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ControllerManager-srv:owner-val is deprecated.  Use ControllerManager-srv:owner instead.")
  (owner m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RequestController-response>) ostream)
  "Serializes a message object of type '<RequestController-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'owner))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'owner))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RequestController-response>) istream)
  "Deserializes a message object of type '<RequestController-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'owner) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'owner) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RequestController-response>)))
  "Returns string type for a service object of type '<RequestController-response>"
  "ControllerManager/RequestControllerResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RequestController-response)))
  "Returns string type for a service object of type 'RequestController-response"
  "ControllerManager/RequestControllerResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RequestController-response>)))
  "Returns md5sum for a message object of type '<RequestController-response>"
  "57cf6126b2c87e559f87a64cffffed90")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RequestController-response)))
  "Returns md5sum for a message object of type 'RequestController-response"
  "57cf6126b2c87e559f87a64cffffed90")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RequestController-response>)))
  "Returns full string definition for message of type '<RequestController-response>"
  (cl:format cl:nil "string owner~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RequestController-response)))
  "Returns full string definition for message of type 'RequestController-response"
  (cl:format cl:nil "string owner~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RequestController-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'owner))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RequestController-response>))
  "Converts a ROS message object to a list"
  (cl:list 'RequestController-response
    (cl:cons ':owner (owner msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'RequestController)))
  'RequestController-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'RequestController)))
  'RequestController-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RequestController)))
  "Returns string type for a service object of type '<RequestController>"
  "ControllerManager/RequestController")