/* Auto-generated by genmsg_cpp for file /home/vsunder/ButlerBot/rosbuild_ws/src/controllers/srv/BasicArmMove.srv */
#ifndef CONTROLLERS_SERVICE_BASICARMMOVE_H
#define CONTROLLERS_SERVICE_BASICARMMOVE_H
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
struct BasicArmMoveRequest_ {
  typedef BasicArmMoveRequest_<ContainerAllocator> Type;

  BasicArmMoveRequest_()
  : theta1(0)
  , theta2(0)
  , theta3(0)
  , x(0.0)
  , z(0.0)
  , alpha(0.0)
  {
  }

  BasicArmMoveRequest_(const ContainerAllocator& _alloc)
  : theta1(0)
  , theta2(0)
  , theta3(0)
  , x(0.0)
  , z(0.0)
  , alpha(0.0)
  {
  }

  typedef int16_t _theta1_type;
  int16_t theta1;

  typedef int16_t _theta2_type;
  int16_t theta2;

  typedef int16_t _theta3_type;
  int16_t theta3;

  typedef double _x_type;
  double x;

  typedef double _z_type;
  double z;

  typedef double _alpha_type;
  double alpha;


  typedef boost::shared_ptr< ::controllers::BasicArmMoveRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::controllers::BasicArmMoveRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct BasicArmMoveRequest
typedef  ::controllers::BasicArmMoveRequest_<std::allocator<void> > BasicArmMoveRequest;

typedef boost::shared_ptr< ::controllers::BasicArmMoveRequest> BasicArmMoveRequestPtr;
typedef boost::shared_ptr< ::controllers::BasicArmMoveRequest const> BasicArmMoveRequestConstPtr;


template <class ContainerAllocator>
struct BasicArmMoveResponse_ {
  typedef BasicArmMoveResponse_<ContainerAllocator> Type;

  BasicArmMoveResponse_()
  : theta1s()
  , theta2s()
  , theta3s()
  {
  }

  BasicArmMoveResponse_(const ContainerAllocator& _alloc)
  : theta1s(_alloc)
  , theta2s(_alloc)
  , theta3s(_alloc)
  {
  }

  typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _theta1s_type;
  std::vector<double, typename ContainerAllocator::template rebind<double>::other >  theta1s;

  typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _theta2s_type;
  std::vector<double, typename ContainerAllocator::template rebind<double>::other >  theta2s;

  typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _theta3s_type;
  std::vector<double, typename ContainerAllocator::template rebind<double>::other >  theta3s;


  typedef boost::shared_ptr< ::controllers::BasicArmMoveResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::controllers::BasicArmMoveResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct BasicArmMoveResponse
typedef  ::controllers::BasicArmMoveResponse_<std::allocator<void> > BasicArmMoveResponse;

typedef boost::shared_ptr< ::controllers::BasicArmMoveResponse> BasicArmMoveResponsePtr;
typedef boost::shared_ptr< ::controllers::BasicArmMoveResponse const> BasicArmMoveResponseConstPtr;

struct BasicArmMove
{

typedef BasicArmMoveRequest Request;
typedef BasicArmMoveResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct BasicArmMove
} // namespace controllers

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::controllers::BasicArmMoveRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::controllers::BasicArmMoveRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::controllers::BasicArmMoveRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "76e26c94ce5cffc03b3b0c6496dc35a5";
  }

  static const char* value(const  ::controllers::BasicArmMoveRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x76e26c94ce5cffc0ULL;
  static const uint64_t static_value2 = 0x3b3b0c6496dc35a5ULL;
};

template<class ContainerAllocator>
struct DataType< ::controllers::BasicArmMoveRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "controllers/BasicArmMoveRequest";
  }

  static const char* value(const  ::controllers::BasicArmMoveRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::controllers::BasicArmMoveRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int16 theta1\n\
int16 theta2\n\
int16 theta3\n\
float64 x\n\
float64 z\n\
float64 alpha\n\
\n\
";
  }

  static const char* value(const  ::controllers::BasicArmMoveRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::controllers::BasicArmMoveRequest_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::controllers::BasicArmMoveResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::controllers::BasicArmMoveResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::controllers::BasicArmMoveResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "18e3a90f77e24c0cbc4e00ff30645cc1";
  }

  static const char* value(const  ::controllers::BasicArmMoveResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x18e3a90f77e24c0cULL;
  static const uint64_t static_value2 = 0xbc4e00ff30645cc1ULL;
};

template<class ContainerAllocator>
struct DataType< ::controllers::BasicArmMoveResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "controllers/BasicArmMoveResponse";
  }

  static const char* value(const  ::controllers::BasicArmMoveResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::controllers::BasicArmMoveResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "float64[] theta1s\n\
float64[] theta2s\n\
float64[] theta3s\n\
\n\
";
  }

  static const char* value(const  ::controllers::BasicArmMoveResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::controllers::BasicArmMoveRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.theta1);
    stream.next(m.theta2);
    stream.next(m.theta3);
    stream.next(m.x);
    stream.next(m.z);
    stream.next(m.alpha);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct BasicArmMoveRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::controllers::BasicArmMoveResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.theta1s);
    stream.next(m.theta2s);
    stream.next(m.theta3s);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct BasicArmMoveResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<controllers::BasicArmMove> {
  static const char* value() 
  {
    return "f13f6e651c1b99ea55d2255b79e1beda";
  }

  static const char* value(const controllers::BasicArmMove&) { return value(); } 
};

template<>
struct DataType<controllers::BasicArmMove> {
  static const char* value() 
  {
    return "controllers/BasicArmMove";
  }

  static const char* value(const controllers::BasicArmMove&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<controllers::BasicArmMoveRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "f13f6e651c1b99ea55d2255b79e1beda";
  }

  static const char* value(const controllers::BasicArmMoveRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<controllers::BasicArmMoveRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "controllers/BasicArmMove";
  }

  static const char* value(const controllers::BasicArmMoveRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<controllers::BasicArmMoveResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "f13f6e651c1b99ea55d2255b79e1beda";
  }

  static const char* value(const controllers::BasicArmMoveResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<controllers::BasicArmMoveResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "controllers/BasicArmMove";
  }

  static const char* value(const controllers::BasicArmMoveResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // CONTROLLERS_SERVICE_BASICARMMOVE_H
