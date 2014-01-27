"""autogenerated by genpy from controllers/armMoveRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class armMoveRequest(genpy.Message):
  _md5sum = "ac905efe303267c46f982709d9b792e6"
  _type = "controllers/armMoveRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int16 base
int16 shoulder
int16 shoulder1
int16 elbow
int16 elbow1
int16 wrist
int16 wrot
int16 grip

"""
  __slots__ = ['base','shoulder','shoulder1','elbow','elbow1','wrist','wrot','grip']
  _slot_types = ['int16','int16','int16','int16','int16','int16','int16','int16']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       base,shoulder,shoulder1,elbow,elbow1,wrist,wrot,grip

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(armMoveRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.base is None:
        self.base = 0
      if self.shoulder is None:
        self.shoulder = 0
      if self.shoulder1 is None:
        self.shoulder1 = 0
      if self.elbow is None:
        self.elbow = 0
      if self.elbow1 is None:
        self.elbow1 = 0
      if self.wrist is None:
        self.wrist = 0
      if self.wrot is None:
        self.wrot = 0
      if self.grip is None:
        self.grip = 0
    else:
      self.base = 0
      self.shoulder = 0
      self.shoulder1 = 0
      self.elbow = 0
      self.elbow1 = 0
      self.wrist = 0
      self.wrot = 0
      self.grip = 0

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
      buff.write(_struct_8h.pack(_x.base, _x.shoulder, _x.shoulder1, _x.elbow, _x.elbow1, _x.wrist, _x.wrot, _x.grip))
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
      end += 16
      (_x.base, _x.shoulder, _x.shoulder1, _x.elbow, _x.elbow1, _x.wrist, _x.wrot, _x.grip,) = _struct_8h.unpack(str[start:end])
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
      buff.write(_struct_8h.pack(_x.base, _x.shoulder, _x.shoulder1, _x.elbow, _x.elbow1, _x.wrist, _x.wrot, _x.grip))
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
      end += 16
      (_x.base, _x.shoulder, _x.shoulder1, _x.elbow, _x.elbow1, _x.wrist, _x.wrot, _x.grip,) = _struct_8h.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_8h = struct.Struct("<8h")
"""autogenerated by genpy from controllers/armMoveResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class armMoveResponse(genpy.Message):
  _md5sum = "358e233cde0c8a8bcfea4ce193f8fc15"
  _type = "controllers/armMoveResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """bool success

"""
  __slots__ = ['success']
  _slot_types = ['bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       success

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(armMoveResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.success is None:
        self.success = False
    else:
      self.success = False

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
      buff.write(_struct_B.pack(self.success))
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
      end += 1
      (self.success,) = _struct_B.unpack(str[start:end])
      self.success = bool(self.success)
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
      buff.write(_struct_B.pack(self.success))
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
      end += 1
      (self.success,) = _struct_B.unpack(str[start:end])
      self.success = bool(self.success)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_B = struct.Struct("<B")
class armMove(object):
  _type          = 'controllers/armMove'
  _md5sum = '407a8b06ff8c582b34020cd9a18a6609'
  _request_class  = armMoveRequest
  _response_class = armMoveResponse
