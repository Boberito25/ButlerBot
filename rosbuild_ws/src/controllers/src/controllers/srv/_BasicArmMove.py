"""autogenerated by genpy from controllers/BasicArmMoveRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class BasicArmMoveRequest(genpy.Message):
  _md5sum = "76e26c94ce5cffc03b3b0c6496dc35a5"
  _type = "controllers/BasicArmMoveRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int16 theta1
int16 theta2
int16 theta3
float64 x
float64 z
float64 alpha

"""
  __slots__ = ['theta1','theta2','theta3','x','z','alpha']
  _slot_types = ['int16','int16','int16','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       theta1,theta2,theta3,x,z,alpha

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(BasicArmMoveRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.theta1 is None:
        self.theta1 = 0
      if self.theta2 is None:
        self.theta2 = 0
      if self.theta3 is None:
        self.theta3 = 0
      if self.x is None:
        self.x = 0.
      if self.z is None:
        self.z = 0.
      if self.alpha is None:
        self.alpha = 0.
    else:
      self.theta1 = 0
      self.theta2 = 0
      self.theta3 = 0
      self.x = 0.
      self.z = 0.
      self.alpha = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_3h3d.pack(_x.theta1, _x.theta2, _x.theta3, _x.x, _x.z, _x.alpha))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 30
      (_x.theta1, _x.theta2, _x.theta3, _x.x, _x.z, _x.alpha,) = _struct_3h3d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_3h3d.pack(_x.theta1, _x.theta2, _x.theta3, _x.x, _x.z, _x.alpha))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 30
      (_x.theta1, _x.theta2, _x.theta3, _x.x, _x.z, _x.alpha,) = _struct_3h3d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_3h3d = struct.Struct("<3h3d")
"""autogenerated by genpy from controllers/BasicArmMoveResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class BasicArmMoveResponse(genpy.Message):
  _md5sum = "18e3a90f77e24c0cbc4e00ff30645cc1"
  _type = "controllers/BasicArmMoveResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float64[] theta1s
float64[] theta2s
float64[] theta3s

"""
  __slots__ = ['theta1s','theta2s','theta3s']
  _slot_types = ['float64[]','float64[]','float64[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       theta1s,theta2s,theta3s

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(BasicArmMoveResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.theta1s is None:
        self.theta1s = []
      if self.theta2s is None:
        self.theta2s = []
      if self.theta3s is None:
        self.theta3s = []
    else:
      self.theta1s = []
      self.theta2s = []
      self.theta3s = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      length = len(self.theta1s)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.pack(pattern, *self.theta1s))
      length = len(self.theta2s)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.pack(pattern, *self.theta2s))
      length = len(self.theta3s)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.pack(pattern, *self.theta3s))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      end += struct.calcsize(pattern)
      self.theta1s = struct.unpack(pattern, str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      end += struct.calcsize(pattern)
      self.theta2s = struct.unpack(pattern, str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      end += struct.calcsize(pattern)
      self.theta3s = struct.unpack(pattern, str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      length = len(self.theta1s)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.theta1s.tostring())
      length = len(self.theta2s)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.theta2s.tostring())
      length = len(self.theta3s)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.theta3s.tostring())
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      end += struct.calcsize(pattern)
      self.theta1s = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      end += struct.calcsize(pattern)
      self.theta2s = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      end += struct.calcsize(pattern)
      self.theta3s = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
class BasicArmMove(object):
  _type          = 'controllers/BasicArmMove'
  _md5sum = 'f13f6e651c1b99ea55d2255b79e1beda'
  _request_class  = BasicArmMoveRequest
  _response_class = BasicArmMoveResponse