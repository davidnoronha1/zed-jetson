# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_msgs:msg/Commands.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Commands(type):
    """Metaclass of message 'Commands'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_msgs.msg.Commands')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__commands
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__commands
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__commands
            cls._TYPE_SUPPORT = module.type_support_msg__msg__commands
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__commands

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Commands(metaclass=Metaclass_Commands):
    """Message class 'Commands'."""

    __slots__ = [
        '_mode',
        '_arm',
        '_pitch',
        '_roll',
        '_thrust',
        '_yaw',
        '_forward',
        '_lateral',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'mode': 'string',
        'arm': 'int32',
        'pitch': 'int32',
        'roll': 'int32',
        'thrust': 'int32',
        'yaw': 'int32',
        'forward': 'int32',
        'lateral': 'int32',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mode = kwargs.get('mode', str())
        self.arm = kwargs.get('arm', int())
        self.pitch = kwargs.get('pitch', int())
        self.roll = kwargs.get('roll', int())
        self.thrust = kwargs.get('thrust', int())
        self.yaw = kwargs.get('yaw', int())
        self.forward = kwargs.get('forward', int())
        self.lateral = kwargs.get('lateral', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.mode != other.mode:
            return False
        if self.arm != other.arm:
            return False
        if self.pitch != other.pitch:
            return False
        if self.roll != other.roll:
            return False
        if self.thrust != other.thrust:
            return False
        if self.yaw != other.yaw:
            return False
        if self.forward != other.forward:
            return False
        if self.lateral != other.lateral:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'mode' field must be of type 'str'"
        self._mode = value

    @builtins.property
    def arm(self):
        """Message field 'arm'."""
        return self._arm

    @arm.setter
    def arm(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'arm' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'arm' field must be an integer in [-2147483648, 2147483647]"
        self._arm = value

    @builtins.property
    def pitch(self):
        """Message field 'pitch'."""
        return self._pitch

    @pitch.setter
    def pitch(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'pitch' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'pitch' field must be an integer in [-2147483648, 2147483647]"
        self._pitch = value

    @builtins.property
    def roll(self):
        """Message field 'roll'."""
        return self._roll

    @roll.setter
    def roll(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'roll' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'roll' field must be an integer in [-2147483648, 2147483647]"
        self._roll = value

    @builtins.property
    def thrust(self):
        """Message field 'thrust'."""
        return self._thrust

    @thrust.setter
    def thrust(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'thrust' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'thrust' field must be an integer in [-2147483648, 2147483647]"
        self._thrust = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'yaw' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'yaw' field must be an integer in [-2147483648, 2147483647]"
        self._yaw = value

    @builtins.property
    def forward(self):
        """Message field 'forward'."""
        return self._forward

    @forward.setter
    def forward(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'forward' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'forward' field must be an integer in [-2147483648, 2147483647]"
        self._forward = value

    @builtins.property
    def lateral(self):
        """Message field 'lateral'."""
        return self._lateral

    @lateral.setter
    def lateral(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'lateral' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lateral' field must be an integer in [-2147483648, 2147483647]"
        self._lateral = value
