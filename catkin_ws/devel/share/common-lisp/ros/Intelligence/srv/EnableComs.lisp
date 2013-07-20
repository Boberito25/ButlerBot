; Auto-generated. Do not edit!


(cl:in-package Intelligence-srv)


;//! \htmlinclude EnableComs-request.msg.html

(cl:defclass <EnableComs-request> (roslisp-msg-protocol:ros-message)
  ((enable_comlink
    :reader enable_comlink
    :initarg :enable_comlink
    :type cl:fixnum
    :initform 0))
)

(cl:defclass EnableComs-request (<EnableComs-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EnableComs-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EnableComs-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Intelligence-srv:<EnableComs-request> is deprecated: use Intelligence-srv:EnableComs-request instead.")))

(cl:ensure-generic-function 'enable_comlink-val :lambda-list '(m))
(cl:defmethod enable_comlink-val ((m <EnableComs-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Intelligence-srv:enable_comlink-val is deprecated.  Use Intelligence-srv:enable_comlink instead.")
  (enable_comlink m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EnableComs-request>) ostream)
  "Serializes a message object of type '<EnableComs-request>"
  (cl:let* ((signed (cl:slot-value msg 'enable_comlink)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EnableComs-request>) istream)
  "Deserializes a message object of type '<EnableComs-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'enable_comlink) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EnableComs-request>)))
  "Returns string type for a service object of type '<EnableComs-request>"
  "Intelligence/EnableComsRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EnableComs-request)))
  "Returns string type for a service object of type 'EnableComs-request"
  "Intelligence/EnableComsRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EnableComs-request>)))
  "Returns md5sum for a message object of type '<EnableComs-request>"
  "0376114d6a21b0b97ee0d71bfca6c78e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EnableComs-request)))
  "Returns md5sum for a message object of type 'EnableComs-request"
  "0376114d6a21b0b97ee0d71bfca6c78e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EnableComs-request>)))
  "Returns full string definition for message of type '<EnableComs-request>"
  (cl:format cl:nil "int8 enable_comlink~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EnableComs-request)))
  "Returns full string definition for message of type 'EnableComs-request"
  (cl:format cl:nil "int8 enable_comlink~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EnableComs-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EnableComs-request>))
  "Converts a ROS message object to a list"
  (cl:list 'EnableComs-request
    (cl:cons ':enable_comlink (enable_comlink msg))
))
;//! \htmlinclude EnableComs-response.msg.html

(cl:defclass <EnableComs-response> (roslisp-msg-protocol:ros-message)
  ((ready
    :reader ready
    :initarg :ready
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass EnableComs-response (<EnableComs-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EnableComs-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EnableComs-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Intelligence-srv:<EnableComs-response> is deprecated: use Intelligence-srv:EnableComs-response instead.")))

(cl:ensure-generic-function 'ready-val :lambda-list '(m))
(cl:defmethod ready-val ((m <EnableComs-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Intelligence-srv:ready-val is deprecated.  Use Intelligence-srv:ready instead.")
  (ready m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EnableComs-response>) ostream)
  "Serializes a message object of type '<EnableComs-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'ready) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EnableComs-response>) istream)
  "Deserializes a message object of type '<EnableComs-response>"
    (cl:setf (cl:slot-value msg 'ready) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EnableComs-response>)))
  "Returns string type for a service object of type '<EnableComs-response>"
  "Intelligence/EnableComsResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EnableComs-response)))
  "Returns string type for a service object of type 'EnableComs-response"
  "Intelligence/EnableComsResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EnableComs-response>)))
  "Returns md5sum for a message object of type '<EnableComs-response>"
  "0376114d6a21b0b97ee0d71bfca6c78e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EnableComs-response)))
  "Returns md5sum for a message object of type 'EnableComs-response"
  "0376114d6a21b0b97ee0d71bfca6c78e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EnableComs-response>)))
  "Returns full string definition for message of type '<EnableComs-response>"
  (cl:format cl:nil "bool ready~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EnableComs-response)))
  "Returns full string definition for message of type 'EnableComs-response"
  (cl:format cl:nil "bool ready~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EnableComs-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EnableComs-response>))
  "Converts a ROS message object to a list"
  (cl:list 'EnableComs-response
    (cl:cons ':ready (ready msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'EnableComs)))
  'EnableComs-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'EnableComs)))
  'EnableComs-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EnableComs)))
  "Returns string type for a service object of type '<EnableComs>"
  "Intelligence/EnableComs")