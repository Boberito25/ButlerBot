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
 * Auto-generated by genmsg_cpp from file /home/vsunder/ButlerBot/catkin_ws/src/BehaviorManager/srv/Startup.srv
 *
 */


#ifndef BEHAVIORMANAGER_MESSAGE_STARTUPREQUEST_H
#define BEHAVIORMANAGER_MESSAGE_STARTUPREQUEST_H


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
struct StartupRequest_
{
  typedef StartupRequest_<ContainerAllocator> Type;

  StartupRequest_()
    : behavior()
    , has_started(false)  {
    }
  StartupRequest_(const ContainerAllocator& _alloc)
    : behavior(_alloc)
    , has_started(false)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _behavior_type;
  _behavior_type behavior;

   typedef uint8_t _has_started_type;
  _has_started_type has_started;




  typedef boost::shared_ptr< ::BehaviorManager::StartupRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::BehaviorManager::StartupRequest_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct StartupRequest_

typedef ::BehaviorManager::StartupRequest_<std::allocator<void> > StartupRequest;

typedef boost::shared_ptr< ::BehaviorManager::StartupRequest > StartupRequestPtr;
typedef boost::shared_ptr< ::BehaviorManager::StartupRequest const> StartupRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::BehaviorManager::StartupRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::BehaviorManager::StartupRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::BehaviorManager::StartupRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::BehaviorManager::StartupRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::BehaviorManager::StartupRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::BehaviorManager::StartupRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::BehaviorManager::StartupRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::BehaviorManager::StartupRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::BehaviorManager::StartupRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "eae809d9cb72a991e3e5041f0c0f24c4";
  }

  static const char* value(const ::BehaviorManager::StartupRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xeae809d9cb72a991ULL;
  static const uint64_t static_value2 = 0xe3e5041f0c0f24c4ULL;
};

template<class ContainerAllocator>
struct DataType< ::BehaviorManager::StartupRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "BehaviorManager/StartupRequest";
  }

  static const char* value(const ::BehaviorManager::StartupRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::BehaviorManager::StartupRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string behavior\n\
bool has_started\n\
\n\
";
  }

  static const char* value(const ::BehaviorManager::StartupRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::BehaviorManager::StartupRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.behavior);
      stream.next(m.has_started);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct StartupRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::BehaviorManager::StartupRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::BehaviorManager::StartupRequest_<ContainerAllocator>& v)
  {
    s << indent << "behavior: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.behavior);
    s << indent << "has_started: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.has_started);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BEHAVIORMANAGER_MESSAGE_STARTUPREQUEST_H
