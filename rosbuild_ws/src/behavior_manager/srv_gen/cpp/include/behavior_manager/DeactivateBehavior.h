/* Auto-generated by genmsg_cpp for file /home/vsunder/ButlerBot/rosbuild_ws/src/behavior_manager/srv/DeactivateBehavior.srv */
#ifndef BEHAVIOR_MANAGER_SERVICE_DEACTIVATEBEHAVIOR_H
#define BEHAVIOR_MANAGER_SERVICE_DEACTIVATEBEHAVIOR_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "ros/service_traits.h"




namespace behavior_manager
{
template <class ContainerAllocator>
struct DeactivateBehaviorRequest_ {
  typedef DeactivateBehaviorRequest_<ContainerAllocator> Type;

  DeactivateBehaviorRequest_()
  : behavior()
  {
  }

  DeactivateBehaviorRequest_(const ContainerAllocator& _alloc)
  : behavior(_alloc)
  {
  }

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _behavior_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  behavior;


  typedef boost::shared_ptr< ::behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct DeactivateBehaviorRequest
typedef  ::behavior_manager::DeactivateBehaviorRequest_<std::allocator<void> > DeactivateBehaviorRequest;

typedef boost::shared_ptr< ::behavior_manager::DeactivateBehaviorRequest> DeactivateBehaviorRequestPtr;
typedef boost::shared_ptr< ::behavior_manager::DeactivateBehaviorRequest const> DeactivateBehaviorRequestConstPtr;


template <class ContainerAllocator>
struct DeactivateBehaviorResponse_ {
  typedef DeactivateBehaviorResponse_<ContainerAllocator> Type;

  DeactivateBehaviorResponse_()
  : error(0)
  {
  }

  DeactivateBehaviorResponse_(const ContainerAllocator& _alloc)
  : error(0)
  {
  }

  typedef int8_t _error_type;
  int8_t error;


  typedef boost::shared_ptr< ::behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct DeactivateBehaviorResponse
typedef  ::behavior_manager::DeactivateBehaviorResponse_<std::allocator<void> > DeactivateBehaviorResponse;

typedef boost::shared_ptr< ::behavior_manager::DeactivateBehaviorResponse> DeactivateBehaviorResponsePtr;
typedef boost::shared_ptr< ::behavior_manager::DeactivateBehaviorResponse const> DeactivateBehaviorResponseConstPtr;

struct DeactivateBehavior
{

typedef DeactivateBehaviorRequest Request;
typedef DeactivateBehaviorResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct DeactivateBehavior
} // namespace behavior_manager

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "03729983c4b9be7a4f2b56846a7ccbdc";
  }

  static const char* value(const  ::behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x03729983c4b9be7aULL;
  static const uint64_t static_value2 = 0x4f2b56846a7ccbdcULL;
};

template<class ContainerAllocator>
struct DataType< ::behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "behavior_manager/DeactivateBehaviorRequest";
  }

  static const char* value(const  ::behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "string behavior\n\
\n\
";
  }

  static const char* value(const  ::behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "99e53bce000fb6e8448591149afae401";
  }

  static const char* value(const  ::behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x99e53bce000fb6e8ULL;
  static const uint64_t static_value2 = 0x448591149afae401ULL;
};

template<class ContainerAllocator>
struct DataType< ::behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "behavior_manager/DeactivateBehaviorResponse";
  }

  static const char* value(const  ::behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int8 error\n\
\n\
\n\
";
  }

  static const char* value(const  ::behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.behavior);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct DeactivateBehaviorRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.error);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct DeactivateBehaviorResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<behavior_manager::DeactivateBehavior> {
  static const char* value() 
  {
    return "8a564d1bf308e3c8c7ab8c65c54c3e75";
  }

  static const char* value(const behavior_manager::DeactivateBehavior&) { return value(); } 
};

template<>
struct DataType<behavior_manager::DeactivateBehavior> {
  static const char* value() 
  {
    return "behavior_manager/DeactivateBehavior";
  }

  static const char* value(const behavior_manager::DeactivateBehavior&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "8a564d1bf308e3c8c7ab8c65c54c3e75";
  }

  static const char* value(const behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "behavior_manager/DeactivateBehavior";
  }

  static const char* value(const behavior_manager::DeactivateBehaviorRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "8a564d1bf308e3c8c7ab8c65c54c3e75";
  }

  static const char* value(const behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "behavior_manager/DeactivateBehavior";
  }

  static const char* value(const behavior_manager::DeactivateBehaviorResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // BEHAVIOR_MANAGER_SERVICE_DEACTIVATEBEHAVIOR_H

