/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/msg/Startup.msg
 *
 */


#ifndef BEHAVIORMANAGER_MESSAGE_STARTUP_H
#define BEHAVIORMANAGER_MESSAGE_STARTUP_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace BehaviorManager
{
template <class ContainerAllocator>
struct Startup_
{
  typedef Startup_<ContainerAllocator> Type;

  Startup_()
    : behavior()  {
    }
  Startup_(const ContainerAllocator& _alloc)
    : behavior(_alloc)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _behavior_type;
  _behavior_type behavior;




  typedef boost::shared_ptr< ::BehaviorManager::Startup_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::BehaviorManager::Startup_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct Startup_

typedef ::BehaviorManager::Startup_<std::allocator<void> > Startup;

typedef boost::shared_ptr< ::BehaviorManager::Startup > StartupPtr;
typedef boost::shared_ptr< ::BehaviorManager::Startup const> StartupConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::BehaviorManager::Startup_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::BehaviorManager::Startup_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace BehaviorManager

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/groovy/share/std_msgs/msg'], 'BehaviorManager': ['/home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::BehaviorManager::Startup_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::BehaviorManager::Startup_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::BehaviorManager::Startup_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::BehaviorManager::Startup_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::BehaviorManager::Startup_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::BehaviorManager::Startup_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::BehaviorManager::Startup_<ContainerAllocator> >
{
  static const char* value()
  {
    return "03729983c4b9be7a4f2b56846a7ccbdc";
  }

  static const char* value(const ::BehaviorManager::Startup_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x03729983c4b9be7aULL;
  static const uint64_t static_value2 = 0x4f2b56846a7ccbdcULL;
};

template<class ContainerAllocator>
struct DataType< ::BehaviorManager::Startup_<ContainerAllocator> >
{
  static const char* value()
  {
    return "BehaviorManager/Startup";
  }

  static const char* value(const ::BehaviorManager::Startup_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::BehaviorManager::Startup_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string behavior\n\
\n\
";
  }

  static const char* value(const ::BehaviorManager::Startup_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::BehaviorManager::Startup_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.behavior);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Startup_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::BehaviorManager::Startup_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::BehaviorManager::Startup_<ContainerAllocator>& v)
  {
    s << indent << "behavior: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.behavior);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BEHAVIORMANAGER_MESSAGE_STARTUP_H