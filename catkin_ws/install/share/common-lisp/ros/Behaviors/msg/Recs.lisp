; Auto-generated. Do not edit!


(cl:in-package Behaviors-msg)


;//! \htmlinclude Recs.msg.html

(cl:defclass <Recs> (roslisp-msg-protocol:ros-message)
  ((behavior
    :reader behavior
    :initarg :behavior
    :type cl:string
    :initform "")
   (priority
    :reader priority
    :initarg :priority
    :type cl:fixnum
    :initform 0)
   (recommendation
    :reader recommendation
    :initarg :recommendation
    :type cl:string
    :initform ""))
)

(cl:defclass Recs (<Recs>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Recs>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Recs)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Behaviors-msg:<Recs> is deprecated: use Behaviors-msg:Recs instead.")))

(cl:ensure-generic-function 'behavior-val :lambda-list '(m))
(cl:defmethod behavior-val ((m <Recs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Behaviors-msg:behavior-val is deprecated.  Use Behaviors-msg:behavior instead.")
  (behavior m))

(cl:ensure-generic-function 'priority-val :lambda-list '(m))
(cl:defmethod priority-val ((m <Recs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Behaviors-msg:priority-val is deprecated.  Use Behaviors-msg:priority instead.")
  (priority m))

(cl:ensure-generic-function 'recommendation-val :lambda-list '(m))
(cl:defmethod recommendation-val ((m <Recs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Behaviors-msg:recommendation-val is deprecated.  Use Behaviors-msg:recommendation instead.")
  (recommendation m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Recs>) ostream)
  "Serializes a message object of type '<Recs>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'behavior))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'behavior))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'recommendation))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'recommendation))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Recs>) istream)
  "Deserializes a message object of type '<Recs>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'behavior) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'behavior) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'recommendation) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'recommendation) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Recs>)))
  "Returns string type for a message object of type '<Recs>"
  "Behaviors/Recs")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Recs)))
  "Returns string type for a message object of type 'Recs"
  "Behaviors/Recs")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Recs>)))
  "Returns md5sum for a message object of type '<Recs>"
  "7876aadc4b52c34c6c94300ba5258e3b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Recs)))
  "Returns md5sum for a message object of type 'Recs"
  "7876aadc4b52c34c6c94300ba5258e3b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Recs>)))
  "Returns full string definition for message of type '<Recs>"
  (cl:format cl:nil "string behavior~%uint8 priority~%string recommendation~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Recs)))
  "Returns full string definition for message of type 'Recs"
  (cl:format cl:nil "string behavior~%uint8 priority~%string recommendation~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Recs>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'behavior))
     1
     4 (cl:length (cl:slot-value msg 'recommendation))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Recs>))
  "Converts a ROS message object to a list"
  (cl:list 'Recs
    (cl:cons ':behavior (behavior msg))
    (cl:cons ':priority (priority msg))
    (cl:cons ':recommendation (recommendation msg))
))
