; Auto-generated. Do not edit!


(cl:in-package Behaviors-msg)


;//! \htmlinclude Completed.msg.html

(cl:defclass <Completed> (roslisp-msg-protocol:ros-message)
  ((error
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

(cl:ensure-generic-function 'error-val :lambda-list '(m))
(cl:defmethod error-val ((m <Completed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Behaviors-msg:error-val is deprecated.  Use Behaviors-msg:error instead.")
  (error m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Completed>) ostream)
  "Serializes a message object of type '<Completed>"
  (cl:let* ((signed (cl:slot-value msg 'error)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Completed>) istream)
  "Deserializes a message object of type '<Completed>"
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
  "99e53bce000fb6e8448591149afae401")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Completed)))
  "Returns md5sum for a message object of type 'Completed"
  "99e53bce000fb6e8448591149afae401")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Completed>)))
  "Returns full string definition for message of type '<Completed>"
  (cl:format cl:nil "int8 error~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Completed)))
  "Returns full string definition for message of type 'Completed"
  (cl:format cl:nil "int8 error~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Completed>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Completed>))
  "Converts a ROS message object to a list"
  (cl:list 'Completed
    (cl:cons ':error (error msg))
))
