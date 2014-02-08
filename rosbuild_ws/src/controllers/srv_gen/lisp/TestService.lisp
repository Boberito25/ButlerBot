; Auto-generated. Do not edit!


(cl:in-package controllers-srv)


;//! \htmlinclude TestService-request.msg.html

(cl:defclass <TestService-request> (roslisp-msg-protocol:ros-message)
  ((input
    :reader input
    :initarg :input
    :type cl:integer
    :initform 0))
)

(cl:defclass TestService-request (<TestService-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TestService-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TestService-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name controllers-srv:<TestService-request> is deprecated: use controllers-srv:TestService-request instead.")))

(cl:ensure-generic-function 'input-val :lambda-list '(m))
(cl:defmethod input-val ((m <TestService-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:input-val is deprecated.  Use controllers-srv:input instead.")
  (input m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TestService-request>) ostream)
  "Serializes a message object of type '<TestService-request>"
  (cl:let* ((signed (cl:slot-value msg 'input)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TestService-request>) istream)
  "Deserializes a message object of type '<TestService-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'input) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TestService-request>)))
  "Returns string type for a service object of type '<TestService-request>"
  "controllers/TestServiceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TestService-request)))
  "Returns string type for a service object of type 'TestService-request"
  "controllers/TestServiceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TestService-request>)))
  "Returns md5sum for a message object of type '<TestService-request>"
  "21d8f69e8f1621953b39ae17e934f4f0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TestService-request)))
  "Returns md5sum for a message object of type 'TestService-request"
  "21d8f69e8f1621953b39ae17e934f4f0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TestService-request>)))
  "Returns full string definition for message of type '<TestService-request>"
  (cl:format cl:nil "int32 input~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TestService-request)))
  "Returns full string definition for message of type 'TestService-request"
  (cl:format cl:nil "int32 input~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TestService-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TestService-request>))
  "Converts a ROS message object to a list"
  (cl:list 'TestService-request
    (cl:cons ':input (input msg))
))
;//! \htmlinclude TestService-response.msg.html

(cl:defclass <TestService-response> (roslisp-msg-protocol:ros-message)
  ((output
    :reader output
    :initarg :output
    :type cl:integer
    :initform 0))
)

(cl:defclass TestService-response (<TestService-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TestService-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TestService-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name controllers-srv:<TestService-response> is deprecated: use controllers-srv:TestService-response instead.")))

(cl:ensure-generic-function 'output-val :lambda-list '(m))
(cl:defmethod output-val ((m <TestService-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:output-val is deprecated.  Use controllers-srv:output instead.")
  (output m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TestService-response>) ostream)
  "Serializes a message object of type '<TestService-response>"
  (cl:let* ((signed (cl:slot-value msg 'output)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TestService-response>) istream)
  "Deserializes a message object of type '<TestService-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'output) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TestService-response>)))
  "Returns string type for a service object of type '<TestService-response>"
  "controllers/TestServiceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TestService-response)))
  "Returns string type for a service object of type 'TestService-response"
  "controllers/TestServiceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TestService-response>)))
  "Returns md5sum for a message object of type '<TestService-response>"
  "21d8f69e8f1621953b39ae17e934f4f0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TestService-response)))
  "Returns md5sum for a message object of type 'TestService-response"
  "21d8f69e8f1621953b39ae17e934f4f0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TestService-response>)))
  "Returns full string definition for message of type '<TestService-response>"
  (cl:format cl:nil "int32 output~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TestService-response)))
  "Returns full string definition for message of type 'TestService-response"
  (cl:format cl:nil "int32 output~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TestService-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TestService-response>))
  "Converts a ROS message object to a list"
  (cl:list 'TestService-response
    (cl:cons ':output (output msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'TestService)))
  'TestService-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'TestService)))
  'TestService-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TestService)))
  "Returns string type for a service object of type '<TestService>"
  "controllers/TestService")