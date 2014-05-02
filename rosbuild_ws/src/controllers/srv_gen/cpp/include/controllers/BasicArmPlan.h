/* Auto-generated by genmsg_cpp for file /home/peter/ButlerBot/rosbuild_ws/src/controllers/srv/BasicArmPlan.srv */
#ifndef CONTROLLERS_SERVICE_BASICARMPLAN_H
#define CONTROLLERS_SERVICE_BASICARMPLAN_H
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
struct BasicArmPlanRequest_ {
  typedef BasicArmPlanRequest_<ContainerAllocator> Type;

  BasicArmPlanRequest_()
  : theta0(0.0)
  , theta1(0.0)
  , theta2(0.0)
  , theta3(0.0)
  , x(0.0)
  , y(0.0)
  , z(0.0)
  , alpha(0.0)
  {
  }

  BasicArmPlanRequest_(const ContainerAllocator& _alloc)
  : theta0(0.0)
  , theta1(0.0)
  , theta2(0.0)
  , theta3(0.0)
  , x(0.0)
  , y(0.0)
  , z(0.0)
  , alpha(0.0)
  {
  }

  typedef double _theta0_type;
  double theta0;

  typedef double _theta1_type;
  double theta1;

  typedef double _theta2_type;
  double theta2;

  typedef double _theta3_type;
  double theta3;

  typedef double _x_type;
  double x;

  typedef double _y_type;
  double y;

  typedef double _z_type;
  double z;

  typedef double _alpha_type;
  double alpha;


  typedef boost::shared_ptr< ::controllers::BasicArmPlanRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::controllers::BasicArmPlanRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct BasicArmPlanRequest
typedef  ::controllers::BasicArmPlanRequest_<std::allocator<void> > BasicArmPlanRequest;

typedef boost::shared_ptr< ::controllers::BasicArmPlanRequest> BasicArmPlanRequestPtr;
typedef boost::shared_ptr< ::controllers::BasicArmPlanRequest const> BasicArmPlanRequestConstPtr;



template <class ContainerAllocator>
struct BasicArmPlanResponse_ {
  typedef BasicArmPlanResponse_<ContainerAllocator> Type;

  BasicArmPlanResponse_()
  : theta0s()
  , theta1s()
  , theta2s()
  , theta3s()
  {
  }

  BasicArmPlanResponse_(const ContainerAllocator& _alloc)
  : theta0s(_alloc)
  , theta1s(_alloc)
  , theta2s(_alloc)
  , theta3s(_alloc)
  {
  }

  typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _theta0s_type;
  std::vector<double, typename ContainerAllocator::template rebind<double>::other >  theta0s;

  typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _theta1s_type;
  std::vector<double, typename ContainerAllocator::template rebind<double>::other >  theta1s;

  typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _theta2s_type;
  std::vector<double, typename ContainerAllocator::template rebind<double>::other >  theta2s;

  typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _theta3s_type;
  std::vector<double, typename ContainerAllocator::template rebind<double>::other >  theta3s;


  typedef boost::shared_ptr< ::controllers::BasicArmPlanResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::controllers::BasicArmPlanResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct BasicArmPlanResponse
typedef  ::controllers::BasicArmPlanResponse_<std::allocator<void> > BasicArmPlanResponse;

typedef boost::shared_ptr< ::controllers::BasicArmPlanResponse> BasicArmPlanResponsePtr;
typedef boost::shared_ptr< ::controllers::BasicArmPlanResponse const> BasicArmPlanResponseConstPtr;


struct BasicArmPlan
{

typedef BasicArmPlanRequest Request;
typedef BasicArmPlanResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct BasicArmPlan
} // namespace controllers

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::controllers::BasicArmPlanRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::controllers::BasicArmPlanRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::controllers::BasicArmPlanRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a9e438f4373793bc76143bd190869f5f";
  }

  static const char* value(const  ::controllers::BasicArmPlanRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xa9e438f4373793bcULL;
  static const uint64_t static_value2 = 0x76143bd190869f5fULL;
};

template<class ContainerAllocator>
struct DataType< ::controllers::BasicArmPlanRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "controllers/BasicArmPlanRequest";
  }

  static const char* value(const  ::controllers::BasicArmPlanRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::controllers::BasicArmPlanRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "float64 theta0\n\
float64 theta1\n\
float64 theta2\n\
float64 theta3\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 alpha\n\
\n\
";
  }

  static const char* value(const  ::controllers::BasicArmPlanRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::controllers::BasicArmPlanRequest_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::controllers::BasicArmPlanResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::controllers::BasicArmPlanResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::controllers::BasicArmPlanResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "c4856a6d99985c1840acf83ef0ee42d0";
  }

  static const char* value(const  ::controllers::BasicArmPlanResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xc4856a6d99985c18ULL;
  static const uint64_t static_value2 = 0x40acf83ef0ee42d0ULL;
};

template<class ContainerAllocator>
struct DataType< ::controllers::BasicArmPlanResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "controllers/BasicArmPlanResponse";
  }

  static const char* value(const  ::controllers::BasicArmPlanResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::controllers::BasicArmPlanResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "float64[] theta0s\n\
float64[] theta1s\n\
float64[] theta2s\n\
float64[] theta3s\n\
\n\
\n\
";
  }

  static const char* value(const  ::controllers::BasicArmPlanResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::controllers::BasicArmPlanRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.theta0);
    stream.next(m.theta1);
    stream.next(m.theta2);
    stream.next(m.theta3);
    stream.next(m.x);
    stream.next(m.y);
    stream.next(m.z);
    stream.next(m.alpha);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct BasicArmPlanRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::controllers::BasicArmPlanResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.theta0s);
    stream.next(m.theta1s);
    stream.next(m.theta2s);
    stream.next(m.theta3s);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct BasicArmPlanResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<controllers::BasicArmPlan> {
  static const char* value() 
  {
    return "6eab4c1dc1d1346d061f4b0cb119419d";
  }

  static const char* value(const controllers::BasicArmPlan&) { return value(); } 
};

template<>
struct DataType<controllers::BasicArmPlan> {
  static const char* value() 
  {
    return "controllers/BasicArmPlan";
  }

  static const char* value(const controllers::BasicArmPlan&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<controllers::BasicArmPlanRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "6eab4c1dc1d1346d061f4b0cb119419d";
  }

  static const char* value(const controllers::BasicArmPlanRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<controllers::BasicArmPlanRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "controllers/BasicArmPlan";
  }

  static const char* value(const controllers::BasicArmPlanRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<controllers::BasicArmPlanResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "6eab4c1dc1d1346d061f4b0cb119419d";
  }

  static const char* value(const controllers::BasicArmPlanResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<controllers::BasicArmPlanResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "controllers/BasicArmPlan";
  }

  static const char* value(const controllers::BasicArmPlanResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // CONTROLLERS_SERVICE_BASICARMPLAN_H

