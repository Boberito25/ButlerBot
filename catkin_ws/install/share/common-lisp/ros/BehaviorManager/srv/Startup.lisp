; Auto-generated. Do not edit!


(cl:in-package BehaviorManager-srv)


;//! \htmlinclude Startup-request.msg.html

(cl:defclass <Startup-request> (roslisp-msg-protocol:ros-message)
  ((behavior
    :reader behavior
    :initarg :behavior
    :type cl:string
    :initform "")
   (has_started
    :reader has_started
    :initarg :has_started
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Startup-request (<Startup-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Startup-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Startup-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name BehaviorManager-srv:<Startup-request> is deprecated: use BehaviorManager-srv:Startup-request instead.")))

(cl:ensure-generic-function 'behavior-val :lambda-list '(m))
(cl:defmethod behavior-val ((m <Startup-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader BehaviorManager-srv:behavior-val is deprecated.  Use BehaviorManager-srv:behavior instead.")
  (behavior m))

(cl:ensure-generic-function 'has_started-val :lambda-list '(m))
(cl:defmethod has_started-val ((m <Startup-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader BehaviorManager-srv:has_started-val is deprecated.  Use BehaviorManager-srv:has_started instead.")
  (has_started m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Startup-request>) ostream)
  "Serializes a message object of type '<Startup-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'behavior))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'behavior))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'has_started) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Startup-request>) istream)
  "Deserializes a message object of type '<Startup-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'behavior) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'behavior) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'has_started) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Startup-request>)))
  "Returns string type for a service object of type '<Startup-request>"
  "BehaviorManager/StartupRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Startup-request)))
  "Returns string type for a service object of type 'Startup-request"
  "BehaviorManager/StartupRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Startup-request>)))
  "Returns md5sum for a message object of type '<Startup-request>"
  "bccc1c679fdd2d4249448e7f5e07e9e5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Startup-request)))
  "Returns md5sum for a message object of type 'Startup-request"
  "bccc1c679fdd2d4249448e7f5e07e9e5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Startup-request>)))
  "Returns full string definition for message of type '<Startup-request>"
  (cl:format cl:nil "string behavior~%bool has_started~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Startup-request)))
  "Returns full string definition for message of type 'Startup-request"
  (cl:format cl:nil "string behavior~%bool has_started~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Startup-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'behavior))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Startup-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Startup-request
    (cl:cons ':behavior (behavior msg))
    (cl:cons ':has_started (has_started msg))
))
;//! \htmlinclude Startup-response.msg.html

(cl:defclass <Startup-response> (roslisp-msg-protocol:ros-message)
  ((ready
    :reader ready
    :initarg :ready
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Startup-response (<Startup-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Startup-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Startup-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name BehaviorManager-srv:<Startup-response> is deprecated: use BehaviorManager-srv:Startup-response instead.")))

(cl:ensure-generic-function 'ready-val :lambda-list '(m))
(cl:defmethod ready-val ((m <Startup-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader BehaviorManager-srv:ready-val is deprecated.  Use BehaviorManager-srv:ready instead.")
  (ready m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Startup-response>) ostream)
  "Serializes a message object of type '<Startup-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'ready) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Startup-response>) istream)
  "Deserializes a message object of type '<Startup-response>"
    (cl:setf (cl:slot-value msg 'ready) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Startup-response>)))
  "Returns string type for a service object of type '<Startup-response>"
  "BehaviorManager/StartupResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Startup-response)))
  "Returns string type for a service object of type 'Startup-response"
  "BehaviorManager/StartupResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Startup-response>)))
  "Returns md5sum for a message object of type '<Startup-response>"
  "bccc1c679fdd2d4249448e7f5e07e9e5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Startup-response)))
  "Returns md5sum for a message object of type 'Startup-response"
  "bccc1c679fdd2d4249448e7f5e07e9e5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Startup-response>)))
  "Returns full string definition for message of type '<Startup-response>"
  (cl:format cl:nil "bool ready~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Startup-response)))
  "Returns full string definition for message of type 'Startup-response"
  (cl:format cl:nil "bool ready~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Startup-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Startup-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Startup-response
    (cl:cons ':ready (ready msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Startup)))
  'Startup-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Startup)))
  'Startup-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Startup)))
  "Returns string type for a service object of type '<Startup>"
  "BehaviorManager/Startup")