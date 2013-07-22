; Auto-generated. Do not edit!


(cl:in-package Behaviors-srv)


;//! \htmlinclude ReserveBehavior-request.msg.html

(cl:defclass <ReserveBehavior-request> (roslisp-msg-protocol:ros-message)
  ((behavior
    :reader behavior
    :initarg :behavior
    :type cl:string
    :initform "")
   (behaviors_reserved
    :reader behaviors_reserved
    :initarg :behaviors_reserved
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass ReserveBehavior-request (<ReserveBehavior-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReserveBehavior-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReserveBehavior-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Behaviors-srv:<ReserveBehavior-request> is deprecated: use Behaviors-srv:ReserveBehavior-request instead.")))

(cl:ensure-generic-function 'behavior-val :lambda-list '(m))
(cl:defmethod behavior-val ((m <ReserveBehavior-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Behaviors-srv:behavior-val is deprecated.  Use Behaviors-srv:behavior instead.")
  (behavior m))

(cl:ensure-generic-function 'behaviors_reserved-val :lambda-list '(m))
(cl:defmethod behaviors_reserved-val ((m <ReserveBehavior-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Behaviors-srv:behaviors_reserved-val is deprecated.  Use Behaviors-srv:behaviors_reserved instead.")
  (behaviors_reserved m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReserveBehavior-request>) ostream)
  "Serializes a message object of type '<ReserveBehavior-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'behavior))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'behavior))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'behaviors_reserved))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'behaviors_reserved))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReserveBehavior-request>) istream)
  "Deserializes a message object of type '<ReserveBehavior-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'behavior) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'behavior) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'behaviors_reserved) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'behaviors_reserved)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReserveBehavior-request>)))
  "Returns string type for a service object of type '<ReserveBehavior-request>"
  "Behaviors/ReserveBehaviorRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReserveBehavior-request)))
  "Returns string type for a service object of type 'ReserveBehavior-request"
  "Behaviors/ReserveBehaviorRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReserveBehavior-request>)))
  "Returns md5sum for a message object of type '<ReserveBehavior-request>"
  "36f8688ba68695f41095576c054c8604")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReserveBehavior-request)))
  "Returns md5sum for a message object of type 'ReserveBehavior-request"
  "36f8688ba68695f41095576c054c8604")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReserveBehavior-request>)))
  "Returns full string definition for message of type '<ReserveBehavior-request>"
  (cl:format cl:nil "string behavior~%string[] behaviors_reserved~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReserveBehavior-request)))
  "Returns full string definition for message of type 'ReserveBehavior-request"
  (cl:format cl:nil "string behavior~%string[] behaviors_reserved~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReserveBehavior-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'behavior))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'behaviors_reserved) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReserveBehavior-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ReserveBehavior-request
    (cl:cons ':behavior (behavior msg))
    (cl:cons ':behaviors_reserved (behaviors_reserved msg))
))
;//! \htmlinclude ReserveBehavior-response.msg.html

(cl:defclass <ReserveBehavior-response> (roslisp-msg-protocol:ros-message)
  ((done
    :reader done
    :initarg :done
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ReserveBehavior-response (<ReserveBehavior-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReserveBehavior-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReserveBehavior-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Behaviors-srv:<ReserveBehavior-response> is deprecated: use Behaviors-srv:ReserveBehavior-response instead.")))

(cl:ensure-generic-function 'done-val :lambda-list '(m))
(cl:defmethod done-val ((m <ReserveBehavior-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Behaviors-srv:done-val is deprecated.  Use Behaviors-srv:done instead.")
  (done m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReserveBehavior-response>) ostream)
  "Serializes a message object of type '<ReserveBehavior-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'done) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReserveBehavior-response>) istream)
  "Deserializes a message object of type '<ReserveBehavior-response>"
    (cl:setf (cl:slot-value msg 'done) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReserveBehavior-response>)))
  "Returns string type for a service object of type '<ReserveBehavior-response>"
  "Behaviors/ReserveBehaviorResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReserveBehavior-response)))
  "Returns string type for a service object of type 'ReserveBehavior-response"
  "Behaviors/ReserveBehaviorResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReserveBehavior-response>)))
  "Returns md5sum for a message object of type '<ReserveBehavior-response>"
  "36f8688ba68695f41095576c054c8604")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReserveBehavior-response)))
  "Returns md5sum for a message object of type 'ReserveBehavior-response"
  "36f8688ba68695f41095576c054c8604")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReserveBehavior-response>)))
  "Returns full string definition for message of type '<ReserveBehavior-response>"
  (cl:format cl:nil "bool done~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReserveBehavior-response)))
  "Returns full string definition for message of type 'ReserveBehavior-response"
  (cl:format cl:nil "bool done~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReserveBehavior-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReserveBehavior-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ReserveBehavior-response
    (cl:cons ':done (done msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ReserveBehavior)))
  'ReserveBehavior-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ReserveBehavior)))
  'ReserveBehavior-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReserveBehavior)))
  "Returns string type for a service object of type '<ReserveBehavior>"
  "Behaviors/ReserveBehavior")