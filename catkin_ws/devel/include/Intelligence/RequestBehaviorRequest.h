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
 * Auto-generated by genmsg_cpp from file /home/vsunder/ButlerBot/catkin_ws/src/Intelligence/srv/RequestBehavior.srv
 *
 */


#ifndef INTELLIGENCE_MESSAGE_REQUESTBEHAVIORREQUEST_H
#define INTELLIGENCE_MESSAGE_REQUESTBEHAVIORREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace Intelligence
{
template <class ContainerAllocator>
struct RequestBehaviorRequest_
{
  typedef RequestBehaviorRequest_<ContainerAllocator> Type;

  RequestBehaviorRequest_()
    : behavior()
    , params()  {
    }
  RequestBehaviorRequest_(const ContainerAllocator& _alloc)
    : behavior(_alloc)
    , params(_alloc)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _behavior_type;
  _behavior_type behavior;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _params_type;
  _params_type params;




  typedef boost::shared_ptr< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct RequestBehaviorRequest_

typedef ::Intelligence::RequestBehaviorRequest_<std::allocator<void> > RequestBehaviorRequest;

typedef boost::shared_ptr< ::Intelligence::RequestBehaviorRequest > RequestBehaviorRequestPtr;
typedef boost::shared_ptr< ::Intelligence::RequestBehaviorRequest const> RequestBehaviorRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace Intelligence

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'Intelligence': ['/home/vsunder/ButlerBot/catkin_ws/src/Intelligence/msg'], 'std_msgs': ['/opt/ros/groovy/share/std_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "21aa9db2d3610b5442ceef9214241d8b";
  }

  static const char* value(const ::Intelligence::RequestBehaviorRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x21aa9db2d3610b54ULL;
  static const uint64_t static_value2 = 0x42ceef9214241d8bULL;
};

template<class ContainerAllocator>
struct DataType< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Intelligence/RequestBehaviorRequest";
  }

  static const char* value(const ::Intelligence::RequestBehaviorRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string behavior\n\
string params\n\
\n\
";
  }

  static const char* value(const ::Intelligence::RequestBehaviorRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.behavior);
      stream.next(m.params);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct RequestBehaviorRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::Intelligence::RequestBehaviorRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::Intelligence::RequestBehaviorRequest_<ContainerAllocator>& v)
  {
    s << indent << "behavior: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.behavior);
    s << indent << "params: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.params);
  }
};

} // namespace message_operations
} // namespace ros

#endif // INTELLIGENCE_MESSAGE_REQUESTBEHAVIORREQUEST_H
