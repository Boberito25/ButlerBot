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
 * Auto-generated by genmsg_cpp from file /home/vsunder/ButlerBot/catkin_ws/src/Behaviors/srv/ReserveBehavior.srv
 *
 */


#ifndef BEHAVIORS_MESSAGE_RESERVEBEHAVIORREQUEST_H
#define BEHAVIORS_MESSAGE_RESERVEBEHAVIORREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace Behaviors
{
template <class ContainerAllocator>
struct ReserveBehaviorRequest_
{
  typedef ReserveBehaviorRequest_<ContainerAllocator> Type;

  ReserveBehaviorRequest_()
    : behavior()
    , behaviors_reserved()  {
    }
  ReserveBehaviorRequest_(const ContainerAllocator& _alloc)
    : behavior(_alloc)
    , behaviors_reserved(_alloc)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _behavior_type;
  _behavior_type behavior;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _behaviors_reserved_type;
  _behaviors_reserved_type behaviors_reserved;




  typedef boost::shared_ptr< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct ReserveBehaviorRequest_

typedef ::Behaviors::ReserveBehaviorRequest_<std::allocator<void> > ReserveBehaviorRequest;

typedef boost::shared_ptr< ::Behaviors::ReserveBehaviorRequest > ReserveBehaviorRequestPtr;
typedef boost::shared_ptr< ::Behaviors::ReserveBehaviorRequest const> ReserveBehaviorRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace Behaviors

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'Behaviors': ['/home/vsunder/ButlerBot/catkin_ws/src/Behaviors/msg'], 'std_msgs': ['/opt/ros/groovy/share/std_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3323f778db96d30e7ba69cb451a1a2a2";
  }

  static const char* value(const ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3323f778db96d30eULL;
  static const uint64_t static_value2 = 0x7ba69cb451a1a2a2ULL;
};

template<class ContainerAllocator>
struct DataType< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Behaviors/ReserveBehaviorRequest";
  }

  static const char* value(const ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string behavior\n\
string[] behaviors_reserved\n\
\n\
";
  }

  static const char* value(const ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.behavior);
      stream.next(m.behaviors_reserved);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ReserveBehaviorRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::Behaviors::ReserveBehaviorRequest_<ContainerAllocator>& v)
  {
    s << indent << "behavior: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.behavior);
    s << indent << "behaviors_reserved[]" << std::endl;
    for (size_t i = 0; i < v.behaviors_reserved.size(); ++i)
    {
      s << indent << "  behaviors_reserved[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.behaviors_reserved[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // BEHAVIORS_MESSAGE_RESERVEBEHAVIORREQUEST_H
