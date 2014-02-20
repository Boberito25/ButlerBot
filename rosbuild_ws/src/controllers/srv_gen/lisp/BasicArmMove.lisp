; Auto-generated. Do not edit!


(cl:in-package controllers-srv)


;//! \htmlinclude BasicArmMove-request.msg.html

(cl:defclass <BasicArmMove-request> (roslisp-msg-protocol:ros-message)
  ((theta1
    :reader theta1
    :initarg :theta1
    :type cl:fixnum
    :initform 0)
   (theta2
    :reader theta2
    :initarg :theta2
    :type cl:fixnum
    :initform 0)
   (theta3
    :reader theta3
    :initarg :theta3
    :type cl:fixnum
    :initform 0)
   (x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (z
    :reader z
    :initarg :z
    :type cl:float
    :initform 0.0)
   (alpha
    :reader alpha
    :initarg :alpha
    :type cl:float
    :initform 0.0))
)

(cl:defclass BasicArmMove-request (<BasicArmMove-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BasicArmMove-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BasicArmMove-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name controllers-srv:<BasicArmMove-request> is deprecated: use controllers-srv:BasicArmMove-request instead.")))

(cl:ensure-generic-function 'theta1-val :lambda-list '(m))
(cl:defmethod theta1-val ((m <BasicArmMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:theta1-val is deprecated.  Use controllers-srv:theta1 instead.")
  (theta1 m))

(cl:ensure-generic-function 'theta2-val :lambda-list '(m))
(cl:defmethod theta2-val ((m <BasicArmMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:theta2-val is deprecated.  Use controllers-srv:theta2 instead.")
  (theta2 m))

(cl:ensure-generic-function 'theta3-val :lambda-list '(m))
(cl:defmethod theta3-val ((m <BasicArmMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:theta3-val is deprecated.  Use controllers-srv:theta3 instead.")
  (theta3 m))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <BasicArmMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:x-val is deprecated.  Use controllers-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <BasicArmMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:z-val is deprecated.  Use controllers-srv:z instead.")
  (z m))

(cl:ensure-generic-function 'alpha-val :lambda-list '(m))
(cl:defmethod alpha-val ((m <BasicArmMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:alpha-val is deprecated.  Use controllers-srv:alpha instead.")
  (alpha m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BasicArmMove-request>) ostream)
  "Serializes a message object of type '<BasicArmMove-request>"
  (cl:let* ((signed (cl:slot-value msg 'theta1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'theta2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'theta3)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'alpha))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BasicArmMove-request>) istream)
  "Deserializes a message object of type '<BasicArmMove-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'theta1) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'theta2) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'theta3) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'alpha) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BasicArmMove-request>)))
  "Returns string type for a service object of type '<BasicArmMove-request>"
  "controllers/BasicArmMoveRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BasicArmMove-request)))
  "Returns string type for a service object of type 'BasicArmMove-request"
  "controllers/BasicArmMoveRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BasicArmMove-request>)))
  "Returns md5sum for a message object of type '<BasicArmMove-request>"
  "f13f6e651c1b99ea55d2255b79e1beda")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BasicArmMove-request)))
  "Returns md5sum for a message object of type 'BasicArmMove-request"
  "f13f6e651c1b99ea55d2255b79e1beda")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BasicArmMove-request>)))
  "Returns full string definition for message of type '<BasicArmMove-request>"
  (cl:format cl:nil "int16 theta1~%int16 theta2~%int16 theta3~%float64 x~%float64 z~%float64 alpha~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BasicArmMove-request)))
  "Returns full string definition for message of type 'BasicArmMove-request"
  (cl:format cl:nil "int16 theta1~%int16 theta2~%int16 theta3~%float64 x~%float64 z~%float64 alpha~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BasicArmMove-request>))
  (cl:+ 0
     2
     2
     2
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BasicArmMove-request>))
  "Converts a ROS message object to a list"
  (cl:list 'BasicArmMove-request
    (cl:cons ':theta1 (theta1 msg))
    (cl:cons ':theta2 (theta2 msg))
    (cl:cons ':theta3 (theta3 msg))
    (cl:cons ':x (x msg))
    (cl:cons ':z (z msg))
    (cl:cons ':alpha (alpha msg))
))
;//! \htmlinclude BasicArmMove-response.msg.html

(cl:defclass <BasicArmMove-response> (roslisp-msg-protocol:ros-message)
  ((theta1s
    :reader theta1s
    :initarg :theta1s
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (theta2s
    :reader theta2s
    :initarg :theta2s
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (theta3s
    :reader theta3s
    :initarg :theta3s
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass BasicArmMove-response (<BasicArmMove-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BasicArmMove-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BasicArmMove-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name controllers-srv:<BasicArmMove-response> is deprecated: use controllers-srv:BasicArmMove-response instead.")))

(cl:ensure-generic-function 'theta1s-val :lambda-list '(m))
(cl:defmethod theta1s-val ((m <BasicArmMove-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:theta1s-val is deprecated.  Use controllers-srv:theta1s instead.")
  (theta1s m))

(cl:ensure-generic-function 'theta2s-val :lambda-list '(m))
(cl:defmethod theta2s-val ((m <BasicArmMove-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:theta2s-val is deprecated.  Use controllers-srv:theta2s instead.")
  (theta2s m))

(cl:ensure-generic-function 'theta3s-val :lambda-list '(m))
(cl:defmethod theta3s-val ((m <BasicArmMove-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:theta3s-val is deprecated.  Use controllers-srv:theta3s instead.")
  (theta3s m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BasicArmMove-response>) ostream)
  "Serializes a message object of type '<BasicArmMove-response>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'theta1s))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'theta1s))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'theta2s))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'theta2s))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'theta3s))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'theta3s))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BasicArmMove-response>) istream)
  "Deserializes a message object of type '<BasicArmMove-response>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'theta1s) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'theta1s)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'theta2s) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'theta2s)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'theta3s) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'theta3s)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BasicArmMove-response>)))
  "Returns string type for a service object of type '<BasicArmMove-response>"
  "controllers/BasicArmMoveResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BasicArmMove-response)))
  "Returns string type for a service object of type 'BasicArmMove-response"
  "controllers/BasicArmMoveResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BasicArmMove-response>)))
  "Returns md5sum for a message object of type '<BasicArmMove-response>"
  "f13f6e651c1b99ea55d2255b79e1beda")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BasicArmMove-response)))
  "Returns md5sum for a message object of type 'BasicArmMove-response"
  "f13f6e651c1b99ea55d2255b79e1beda")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BasicArmMove-response>)))
  "Returns full string definition for message of type '<BasicArmMove-response>"
  (cl:format cl:nil "float64[] theta1s~%float64[] theta2s~%float64[] theta3s~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BasicArmMove-response)))
  "Returns full string definition for message of type 'BasicArmMove-response"
  (cl:format cl:nil "float64[] theta1s~%float64[] theta2s~%float64[] theta3s~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BasicArmMove-response>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'theta1s) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'theta2s) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'theta3s) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BasicArmMove-response>))
  "Converts a ROS message object to a list"
  (cl:list 'BasicArmMove-response
    (cl:cons ':theta1s (theta1s msg))
    (cl:cons ':theta2s (theta2s msg))
    (cl:cons ':theta3s (theta3s msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'BasicArmMove)))
  'BasicArmMove-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'BasicArmMove)))
  'BasicArmMove-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BasicArmMove)))
  "Returns string type for a service object of type '<BasicArmMove>"
  "controllers/BasicArmMove")