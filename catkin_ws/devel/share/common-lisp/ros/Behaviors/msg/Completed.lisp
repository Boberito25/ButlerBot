; Auto-generated. Do not edit!


(cl:in-package Behaviors-msg)


;//! \htmlinclude Completed.msg.html

(cl:defclass <Completed> (roslisp-msg-protocol:ros-message)
  ((behavior
    :reader behavior
    :initarg :behavior
    :type cl:string
    :initform "")
   (error
    :reader error
    :initarg :error
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Completed (<Completed>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Completed>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Completed)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Behaviors-msg:<Completed> is deprecated: use Behaviors-msg:Completed instead.")))

(cl:ensure-generic-function 'behavior-val :lambda-list '(m))
(cl:defmethod behavior-val ((m <Completed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Behaviors-msg:behavior-val is deprecated.  Use Behaviors-msg:behavior instead.")
  (behavior m))

(cl:ensure-generic-function 'error-val :lambda-list '(m))
(cl:defmethod error-val ((m <Completed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Behaviors-msg:error-val is deprecated.  Use Behaviors-msg:error instead.")
  (error m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Completed>) ostream)
  "Serializes a message object of type '<Completed>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'behavior))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'behavior))
  (cl:let* ((signed (cl:slot-value msg 'error)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Completed>) istream)
  "Deserializes a message object of type '<Completed>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'behavior) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'behavior) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'error) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Completed>)))
  "Returns string type for a message object of type '<Completed>"
  "Behaviors/Completed")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Completed)))
  "Returns string type for a message object of type 'Completed"
  "Behaviors/Completed")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Completed>)))
  "Returns md5sum for a message object of type '<Completed>"
  "5360d8dc63ebb508e9d3b0ff75130e31")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Completed)))
  "Returns md5sum for a message object of type 'Completed"
  "5360d8dc63ebb508e9d3b0ff75130e31")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Completed>)))
  "Returns full string definition for message of type '<Completed>"
  (cl:format cl:nil "string behavior~%int8 error~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Completed)))
  "Returns full string definition for message of type 'Completed"
  (cl:format cl:nil "string behavior~%int8 error~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Completed>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'behavior))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Completed>))
  "Converts a ROS message object to a list"
  (cl:list 'Completed
    (cl:cons ':behavior (behavior msg))
    (cl:cons ':error (error msg))
))
