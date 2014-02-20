; Auto-generated. Do not edit!


(cl:in-package controllers-srv)


;//! \htmlinclude armMove-request.msg.html

(cl:defclass <armMove-request> (roslisp-msg-protocol:ros-message)
  ((base
    :reader base
    :initarg :base
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (shoulder
    :reader shoulder
    :initarg :shoulder
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (elbow
    :reader elbow
    :initarg :elbow
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (wrist
    :reader wrist
    :initarg :wrist
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (wrot
    :reader wrot
    :initarg :wrot
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (grip
    :reader grip
    :initarg :grip
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
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

(cl:ensure-generic-function 'elbow-val :lambda-list '(m))
(cl:defmethod elbow-val ((m <armMove-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controllers-srv:elbow-val is deprecated.  Use controllers-srv:elbow instead.")
  (elbow m))

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
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'base))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'base))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'shoulder))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'shoulder))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'elbow))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'elbow))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'wrist))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'wrist))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'wrot))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'wrot))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'grip))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'grip))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <armMove-request>) istream)
  "Deserializes a message object of type '<armMove-request>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'base) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'base)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'shoulder) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'shoulder)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'elbow) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'elbow)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'wrist) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'wrist)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'wrot) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'wrot)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'grip) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'grip)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
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
  "12ec2c38c4b52f54cb430d38cc34d7d4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'armMove-request)))
  "Returns md5sum for a message object of type 'armMove-request"
  "12ec2c38c4b52f54cb430d38cc34d7d4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<armMove-request>)))
  "Returns full string definition for message of type '<armMove-request>"
  (cl:format cl:nil "float32[] base~%float32[] shoulder~%float32[] elbow~%float32[] wrist~%float32[] wrot~%float32[] grip~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'armMove-request)))
  "Returns full string definition for message of type 'armMove-request"
  (cl:format cl:nil "float32[] base~%float32[] shoulder~%float32[] elbow~%float32[] wrist~%float32[] wrot~%float32[] grip~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <armMove-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'base) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'shoulder) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'elbow) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'wrist) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'wrot) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'grip) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <armMove-request>))
  "Converts a ROS message object to a list"
  (cl:list 'armMove-request
    (cl:cons ':base (base msg))
    (cl:cons ':shoulder (shoulder msg))
    (cl:cons ':elbow (elbow msg))
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
  "12ec2c38c4b52f54cb430d38cc34d7d4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'armMove-response)))
  "Returns md5sum for a message object of type 'armMove-response"
  "12ec2c38c4b52f54cb430d38cc34d7d4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<armMove-response>)))
  "Returns full string definition for message of type '<armMove-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'armMove-response)))
  "Returns full string definition for message of type 'armMove-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
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