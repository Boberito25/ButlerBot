; Auto-generated. Do not edit!


(cl:in-package BehaviorManager-srv)


;//! \htmlinclude Activate-request.msg.html

(cl:defclass <Activate-request> (roslisp-msg-protocol:ros-message)
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

(cl:defclass Activate-request (<Activate-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Activate-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Activate-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name BehaviorManager-srv:<Activate-request> is deprecated: use BehaviorManager-srv:Activate-request instead.")))

(cl:ensure-generic-function 'behavior-val :lambda-list '(m))
(cl:defmethod behavior-val ((m <Activate-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader BehaviorManager-srv:behavior-val is deprecated.  Use BehaviorManager-srv:behavior instead.")
  (behavior m))

(cl:ensure-generic-function 'params-val :lambda-list '(m))
(cl:defmethod params-val ((m <Activate-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader BehaviorManager-srv:params-val is deprecated.  Use BehaviorManager-srv:params instead.")
  (params m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Activate-request>) ostream)
  "Serializes a message object of type '<Activate-request>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Activate-request>) istream)
  "Deserializes a message object of type '<Activate-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Activate-request>)))
  "Returns string type for a service object of type '<Activate-request>"
  "BehaviorManager/ActivateRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Activate-request)))
  "Returns string type for a service object of type 'Activate-request"
  "BehaviorManager/ActivateRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Activate-request>)))
  "Returns md5sum for a message object of type '<Activate-request>"
  "11d95555e1f4634f94fca3ef9bf47c98")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Activate-request)))
  "Returns md5sum for a message object of type 'Activate-request"
  "11d95555e1f4634f94fca3ef9bf47c98")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Activate-request>)))
  "Returns full string definition for message of type '<Activate-request>"
  (cl:format cl:nil "string behavior~%string params~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Activate-request)))
  "Returns full string definition for message of type 'Activate-request"
  (cl:format cl:nil "string behavior~%string params~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Activate-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'behavior))
     4 (cl:length (cl:slot-value msg 'params))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Activate-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Activate-request
    (cl:cons ':behavior (behavior msg))
    (cl:cons ':params (params msg))
))
;//! \htmlinclude Activate-response.msg.html

(cl:defclass <Activate-response> (roslisp-msg-protocol:ros-message)
  ((done
    :reader done
    :initarg :done
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Activate-response (<Activate-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Activate-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Activate-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name BehaviorManager-srv:<Activate-response> is deprecated: use BehaviorManager-srv:Activate-response instead.")))

(cl:ensure-generic-function 'done-val :lambda-list '(m))
(cl:defmethod done-val ((m <Activate-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader BehaviorManager-srv:done-val is deprecated.  Use BehaviorManager-srv:done instead.")
  (done m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Activate-response>) ostream)
  "Serializes a message object of type '<Activate-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'done) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Activate-response>) istream)
  "Deserializes a message object of type '<Activate-response>"
    (cl:setf (cl:slot-value msg 'done) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Activate-response>)))
  "Returns string type for a service object of type '<Activate-response>"
  "BehaviorManager/ActivateResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Activate-response)))
  "Returns string type for a service object of type 'Activate-response"
  "BehaviorManager/ActivateResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Activate-response>)))
  "Returns md5sum for a message object of type '<Activate-response>"
  "11d95555e1f4634f94fca3ef9bf47c98")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Activate-response)))
  "Returns md5sum for a message object of type 'Activate-response"
  "11d95555e1f4634f94fca3ef9bf47c98")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Activate-response>)))
  "Returns full string definition for message of type '<Activate-response>"
  (cl:format cl:nil "bool done~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Activate-response)))
  "Returns full string definition for message of type 'Activate-response"
  (cl:format cl:nil "bool done~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Activate-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Activate-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Activate-response
    (cl:cons ':done (done msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Activate)))
  'Activate-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Activate)))
  'Activate-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Activate)))
  "Returns string type for a service object of type '<Activate>"
  "BehaviorManager/Activate")