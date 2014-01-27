; Auto-generated. Do not edit!


(cl:in-package controllers-srv)


;//! \htmlinclude armMove-request.msg.html

(cl:defclass <armMove-request> (roslisp-msg-protocol:ros-message)
  ((base
    :reader base
    :initarg :base
    :type cl:fixnum
    :initform 0)
   (shoulder
    :reader shoulder
    :initarg :shoulder
    :type cl:fixnum
    :initform 0)
   (shoulder1
    :reader shoulder1
    :initarg :shoulder1
    :type cl:fixnum
    :initform 0)
   (elbow
    :reader elbow
    :initarg :elbow
    :type cl:fixnum
    :initform 0)
   (elbow1
    :reader elbow1
    :initarg :elbow1
    :type cl:fixnum
    :initform 0)
   (wrist
    :reader wrist
    :initarg :wrist
    :type cl:fixnum
    :initform 0)
   (wrot
    :reader wrot
    :initarg :wrot
    :type cl:fixnum
    :initform 0)
   (grip
    :reader grip
    :initarg :grip
    :type cl:fixnum
    :initform 0))
)

(cl:defclass armMove-request (<armMove-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <armMove-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'armMove-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name controllers-srv:<armMove-request> is deprecated: use controllers-srv:armMove-request instead.")))

(cl:ensure-generic-function 'base-val :lambda-list '(m))
(cl:defmethod base-val ((m <armMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:base-val is deprecated.  Use controllers-srv:base instead.")
  (base m))

(cl:ensure-generic-function 'shoulder-val :lambda-list '(m))
(cl:defmethod shoulder-val ((m <armMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:shoulder-val is deprecated.  Use controllers-srv:shoulder instead.")
  (shoulder m))

(cl:ensure-generic-function 'shoulder1-val :lambda-list '(m))
(cl:defmethod shoulder1-val ((m <armMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:shoulder1-val is deprecated.  Use controllers-srv:shoulder1 instead.")
  (shoulder1 m))

(cl:ensure-generic-function 'elbow-val :lambda-list '(m))
(cl:defmethod elbow-val ((m <armMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:elbow-val is deprecated.  Use controllers-srv:elbow instead.")
  (elbow m))

(cl:ensure-generic-function 'elbow1-val :lambda-list '(m))
(cl:defmethod elbow1-val ((m <armMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:elbow1-val is deprecated.  Use controllers-srv:elbow1 instead.")
  (elbow1 m))

(cl:ensure-generic-function 'wrist-val :lambda-list '(m))
(cl:defmethod wrist-val ((m <armMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:wrist-val is deprecated.  Use controllers-srv:wrist instead.")
  (wrist m))

(cl:ensure-generic-function 'wrot-val :lambda-list '(m))
(cl:defmethod wrot-val ((m <armMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:wrot-val is deprecated.  Use controllers-srv:wrot instead.")
  (wrot m))

(cl:ensure-generic-function 'grip-val :lambda-list '(m))
(cl:defmethod grip-val ((m <armMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:grip-val is deprecated.  Use controllers-srv:grip instead.")
  (grip m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <armMove-request>) ostream)
  "Serializes a message object of type '<armMove-request>"
  (cl:let* ((signed (cl:slot-value msg 'base)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'shoulder)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'shoulder1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'elbow)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'elbow1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'wrist)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'wrot)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'grip)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <armMove-request>) istream)
  "Deserializes a message object of type '<armMove-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'base) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'shoulder) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'shoulder1) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'elbow) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'elbow1) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'wrist) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'wrot) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'grip) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<armMove-request>)))
  "Returns string type for a service object of type '<armMove-request>"
  "controllers/armMoveRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'armMove-request)))
  "Returns string type for a service object of type 'armMove-request"
  "controllers/armMoveRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<armMove-request>)))
  "Returns md5sum for a message object of type '<armMove-request>"
  "407a8b06ff8c582b34020cd9a18a6609")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'armMove-request)))
  "Returns md5sum for a message object of type 'armMove-request"
  "407a8b06ff8c582b34020cd9a18a6609")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<armMove-request>)))
  "Returns full string definition for message of type '<armMove-request>"
  (cl:format cl:nil "int16 base~%int16 shoulder~%int16 shoulder1~%int16 elbow~%int16 elbow1~%int16 wrist~%int16 wrot~%int16 grip~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'armMove-request)))
  "Returns full string definition for message of type 'armMove-request"
  (cl:format cl:nil "int16 base~%int16 shoulder~%int16 shoulder1~%int16 elbow~%int16 elbow1~%int16 wrist~%int16 wrot~%int16 grip~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <armMove-request>))
  (cl:+ 0
     2
     2
     2
     2
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <armMove-request>))
  "Converts a ROS message object to a list"
  (cl:list 'armMove-request
    (cl:cons ':base (base msg))
    (cl:cons ':shoulder (shoulder msg))
    (cl:cons ':shoulder1 (shoulder1 msg))
    (cl:cons ':elbow (elbow msg))
    (cl:cons ':elbow1 (elbow1 msg))
    (cl:cons ':wrist (wrist msg))
    (cl:cons ':wrot (wrot msg))
    (cl:cons ':grip (grip msg))
))
;//! \htmlinclude armMove-response.msg.html

(cl:defclass <armMove-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass armMove-response (<armMove-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <armMove-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'armMove-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name controllers-srv:<armMove-response> is deprecated: use controllers-srv:armMove-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <armMove-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:success-val is deprecated.  Use controllers-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <armMove-response>) ostream)
  "Serializes a message object of type '<armMove-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <armMove-response>) istream)
  "Deserializes a message object of type '<armMove-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<armMove-response>)))
  "Returns string type for a service object of type '<armMove-response>"
  "controllers/armMoveResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'armMove-response)))
  "Returns string type for a service object of type 'armMove-response"
  "controllers/armMoveResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<armMove-response>)))
  "Returns md5sum for a message object of type '<armMove-response>"
  "407a8b06ff8c582b34020cd9a18a6609")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'armMove-response)))
  "Returns md5sum for a message object of type 'armMove-response"
  "407a8b06ff8c582b34020cd9a18a6609")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<armMove-response>)))
  "Returns full string definition for message of type '<armMove-response>"
  (cl:format cl:nil "bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'armMove-response)))
  "Returns full string definition for message of type 'armMove-response"
  (cl:format cl:nil "bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <armMove-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <armMove-response>))
  "Converts a ROS message object to a list"
  (cl:list 'armMove-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'armMove)))
  'armMove-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'armMove)))
  'armMove-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'armMove)))
  "Returns string type for a service object of type '<armMove>"
  "controllers/armMove")