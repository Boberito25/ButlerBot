; Auto-generated. Do not edit!


(cl:in-package Intelligence-srv)


;//! \htmlinclude RequestBehavior-request.msg.html

(cl:defclass <RequestBehavior-request> (roslisp-msg-protocol:ros-message)
  ((behavior
    :reader behavior
    :initarg :behavior
    :type cl:string
    :initform "")
   (params
    :reader params
    :initarg :params
    :type cl:string
    :initform "")
   (priority
    :reader priority
    :initarg :priority
    :type cl:fixnum
    :initform 0))
)

(cl:defclass RequestBehavior-request (<RequestBehavior-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RequestBehavior-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RequestBehavior-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Intelligence-srv:<RequestBehavior-request> is deprecated: use Intelligence-srv:RequestBehavior-request instead.")))

(cl:ensure-generic-function 'behavior-val :lambda-list '(m))
(cl:defmethod behavior-val ((m <RequestBehavior-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Intelligence-srv:behavior-val is deprecated.  Use Intelligence-srv:behavior instead.")
  (behavior m))

(cl:ensure-generic-function 'params-val :lambda-list '(m))
(cl:defmethod params-val ((m <RequestBehavior-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Intelligence-srv:params-val is deprecated.  Use Intelligence-srv:params instead.")
  (params m))

(cl:ensure-generic-function 'priority-val :lambda-list '(m))
(cl:defmethod priority-val ((m <RequestBehavior-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Intelligence-srv:priority-val is deprecated.  Use Intelligence-srv:priority instead.")
  (priority m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RequestBehavior-request>) ostream)
  "Serializes a message object of type '<RequestBehavior-request>"
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
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RequestBehavior-request>) istream)
  "Deserializes a message object of type '<RequestBehavior-request>"
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
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RequestBehavior-request>)))
  "Returns string type for a service object of type '<RequestBehavior-request>"
  "Intelligence/RequestBehaviorRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RequestBehavior-request)))
  "Returns string type for a service object of type 'RequestBehavior-request"
  "Intelligence/RequestBehaviorRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RequestBehavior-request>)))
  "Returns md5sum for a message object of type '<RequestBehavior-request>"
  "8c622a6f499ac0556a7e3ed8206e23ac")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RequestBehavior-request)))
  "Returns md5sum for a message object of type 'RequestBehavior-request"
  "8c622a6f499ac0556a7e3ed8206e23ac")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RequestBehavior-request>)))
  "Returns full string definition for message of type '<RequestBehavior-request>"
  (cl:format cl:nil "string behavior~%string params~%uint8 priority~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RequestBehavior-request)))
  "Returns full string definition for message of type 'RequestBehavior-request"
  (cl:format cl:nil "string behavior~%string params~%uint8 priority~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RequestBehavior-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'behavior))
     4 (cl:length (cl:slot-value msg 'params))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RequestBehavior-request>))
  "Converts a ROS message object to a list"
  (cl:list 'RequestBehavior-request
    (cl:cons ':behavior (behavior msg))
    (cl:cons ':params (params msg))
    (cl:cons ':priority (priority msg))
))
;//! \htmlinclude RequestBehavior-response.msg.html

(cl:defclass <RequestBehavior-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass RequestBehavior-response (<RequestBehavior-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RequestBehavior-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RequestBehavior-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Intelligence-srv:<RequestBehavior-response> is deprecated: use Intelligence-srv:RequestBehavior-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <RequestBehavior-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Intelligence-srv:success-val is deprecated.  Use Intelligence-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RequestBehavior-response>) ostream)
  "Serializes a message object of type '<RequestBehavior-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RequestBehavior-response>) istream)
  "Deserializes a message object of type '<RequestBehavior-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RequestBehavior-response>)))
  "Returns string type for a service object of type '<RequestBehavior-response>"
  "Intelligence/RequestBehaviorResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RequestBehavior-response)))
  "Returns string type for a service object of type 'RequestBehavior-response"
  "Intelligence/RequestBehaviorResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RequestBehavior-response>)))
  "Returns md5sum for a message object of type '<RequestBehavior-response>"
  "8c622a6f499ac0556a7e3ed8206e23ac")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RequestBehavior-response)))
  "Returns md5sum for a message object of type 'RequestBehavior-response"
  "8c622a6f499ac0556a7e3ed8206e23ac")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RequestBehavior-response>)))
  "Returns full string definition for message of type '<RequestBehavior-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RequestBehavior-response)))
  "Returns full string definition for message of type 'RequestBehavior-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RequestBehavior-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RequestBehavior-response>))
  "Converts a ROS message object to a list"
  (cl:list 'RequestBehavior-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'RequestBehavior)))
  'RequestBehavior-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'RequestBehavior)))
  'RequestBehavior-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RequestBehavior)))
  "Returns string type for a service object of type '<RequestBehavior>"
  "Intelligence/RequestBehavior")