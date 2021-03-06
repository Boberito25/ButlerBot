/* Auto-generated by genmsg_cpp for file /home/peter/ButlerBot/rosbuild_ws/src/controllers/srv/TestService.srv */
#ifndef CONTROLLERS_SERVICE_TESTSERVICE_H
#define CONTROLLERS_SERVICE_TESTSERVICE_H
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




namespace controllers
{
template <class ContainerAllocator>
struct TestServiceRequest_ {
  typedef TestServiceRequest_<ContainerAllocator> Type;

  TestServiceRequest_()
  : input(0)
  {
  }

  TestServiceRequest_(const ContainerAllocator& _alloc)
  : input(0)
  {
  }

  typedef int32_t _input_type;
  int32_t input;


  typedef boost::shared_ptr< ::controllers::TestServiceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::controllers::TestServiceRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct TestServiceRequest
typedef  ::controllers::TestServiceRequest_<std::allocator<void> > TestServiceRequest;

typedef boost::shared_ptr< ::controllers::TestServiceRequest> TestServiceRequestPtr;
typedef boost::shared_ptr< ::controllers::TestServiceRequest const> TestServiceRequestConstPtr;



template <class ContainerAllocator>
struct TestServiceResponse_ {
  typedef TestServiceResponse_<ContainerAllocator> Type;

  TestServiceResponse_()
  : output(0)
  {
  }

  TestServiceResponse_(const ContainerAllocator& _alloc)
  : output(0)
  {
  }

  typedef int32_t _output_type;
  int32_t output;


  typedef boost::shared_ptr< ::controllers::TestServiceResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::controllers::TestServiceResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct TestServiceResponse
typedef  ::controllers::TestServiceResponse_<std::allocator<void> > TestServiceResponse;

typedef boost::shared_ptr< ::controllers::TestServiceResponse> TestServiceResponsePtr;
typedef boost::shared_ptr< ::controllers::TestServiceResponse const> TestServiceResponseConstPtr;


struct TestService
{

typedef TestServiceRequest Request;
typedef TestServiceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct TestService
} // namespace controllers

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::controllers::TestServiceRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::controllers::TestServiceRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::controllers::TestServiceRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "350f8291236c5b6fb3b8cfcb1672a02e";
  }

  static const char* value(const  ::controllers::TestServiceRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x350f8291236c5b6fULL;
  static const uint64_t static_value2 = 0xb3b8cfcb1672a02eULL;
};

template<class ContainerAllocator>
struct DataType< ::controllers::TestServiceRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "controllers/TestServiceRequest";
  }

  static const char* value(const  ::controllers::TestServiceRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::controllers::TestServiceRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int32 input\n\
\n\
";
  }

  static const char* value(const  ::controllers::TestServiceRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::controllers::TestServiceRequest_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::controllers::TestServiceResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::controllers::TestServiceResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::controllers::TestServiceResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "d5fc6b37f5643970fe87c91f31f11e4a";
  }

  static const char* value(const  ::controllers::TestServiceResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xd5fc6b37f5643970ULL;
  static const uint64_t static_value2 = 0xfe87c91f31f11e4aULL;
};

template<class ContainerAllocator>
struct DataType< ::controllers::TestServiceResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "controllers/TestServiceResponse";
  }

  static const char* value(const  ::controllers::TestServiceResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::controllers::TestServiceResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int32 output\n\
\n\
\n\
";
  }

  static const char* value(const  ::controllers::TestServiceResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::controllers::TestServiceResponse_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::controllers::TestServiceRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.input);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct TestServiceRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::controllers::TestServiceResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.output);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct TestServiceResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<controllers::TestService> {
  static const char* value() 
  {
    return "21d8f69e8f1621953b39ae17e934f4f0";
  }

  static const char* value(const controllers::TestService&) { return value(); } 
};

template<>
struct DataType<controllers::TestService> {
  static const char* value() 
  {
    return "controllers/TestService";
  }

  static const char* value(const controllers::TestService&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<controllers::TestServiceRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "21d8f69e8f1621953b39ae17e934f4f0";
  }

  static const char* value(const controllers::TestServiceRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<controllers::TestServiceRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "controllers/TestService";
  }

  static const char* value(const controllers::TestServiceRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<controllers::TestServiceResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "21d8f69e8f1621953b39ae17e934f4f0";
  }

  static const char* value(const controllers::TestServiceResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<controllers::TestServiceResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "controllers/TestService";
  }

  static const char* value(const controllers::TestServiceResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // CONTROLLERS_SERVICE_TESTSERVICE_H

