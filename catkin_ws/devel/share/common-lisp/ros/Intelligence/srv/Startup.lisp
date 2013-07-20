; Auto-generated. Do not edit!


(cl:in-package Intelligence-srv)


;//! \htmlinclude Startup-request.msg.html

(cl:defclass <Startup-request> (roslisp-msg-protocol:ros-message)
  ((has_started
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
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Intelligence-srv:<Startup-request> is deprecated: use Intelligence-srv:Startup-request instead.")))

(cl:ensure-generic-function 'has_started-val :lambda-list '(m))
(cl:defmethod has_started-val ((m <Startup-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Intelligence-srv:has_started-val is deprecated.  Use Intelligence-srv:has_started instead.")
  (has_started m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Startup-request>) ostream)
  "Serializes a message object of type '<Startup-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'has_started) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Startup-request>) istream)
  "Deserializes a message object of type '<Startup-request>"
    (cl:setf (cl:slot-value msg 'has_started) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Startup-request>)))
  "Returns string type for a service object of type '<Startup-request>"
  "Intelligence/StartupRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Startup-request)))
  "Returns string type for a service object of type 'Startup-request"
  "Intelligence/StartupRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Startup-request>)))
  "Returns md5sum for a message object of type '<Startup-request>"
  "c43779d15e914b62a906df976f964862")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Startup-request)))
  "Returns md5sum for a message object of type 'Startup-request"
  "c43779d15e914b62a906df976f964862")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Startup-request>)))
  "Returns full string definition for message of type '<Startup-request>"
  (cl:format cl:nil "bool has_started~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Startup-request)))
  "Returns full string definition for message of type 'Startup-request"
  (cl:format cl:nil "bool has_started~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Startup-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Startup-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Startup-request
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
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Intelligence-srv:<Startup-response> is deprecated: use Intelligence-srv:Startup-response instead.")))

(cl:ensure-generic-function 'ready-val :lambda-list '(m))
(cl:defmethod ready-val ((m <Startup-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Intelligence-srv:ready-val is deprecated.  Use Intelligence-srv:ready instead.")
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
  "Intelligence/StartupResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Startup-response)))
  "Returns string type for a service object of type 'Startup-response"
  "Intelligence/StartupResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Startup-response>)))
  "Returns md5sum for a message object of type '<Startup-response>"
  "c43779d15e914b62a906df976f964862")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Startup-response)))
  "Returns md5sum for a message object of type 'Startup-response"
  "c43779d15e914b62a906df976f964862")
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
  "Intelligence/Startup")