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
 * Auto-generated by gensrv_cpp from file /home/vsunder/ButlerBot/catkin_ws/src/Intelligence/srv/Startup.srv
 *
 */


#ifndef INTELLIGENCE_MESSAGE_STARTUP_H
#define INTELLIGENCE_MESSAGE_STARTUP_H

#include <ros/service_traits.h>


#include <Intelligence/StartupRequest.h>
#include <Intelligence/StartupResponse.h>


namespace Intelligence
{

struct Startup
{

typedef StartupRequest Request;
typedef StartupResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Startup
} // namespace Intelligence


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::Intelligence::Startup > {
  static const char* value()
  {
    return "c43779d15e914b62a906df976f964862";
  }

  static const char* value(const ::Intelligence::Startup&) { return value(); }
};

template<>
struct DataType< ::Intelligence::Startup > {
  static const char* value()
  {
    return "Intelligence/Startup";
  }

  static const char* value(const ::Intelligence::Startup&) { return value(); }
};


// service_traits::MD5Sum< ::Intelligence::StartupRequest> should match 
// service_traits::MD5Sum< ::Intelligence::Startup > 
template<>
struct MD5Sum< ::Intelligence::StartupRequest>
{
  static const char* value()
  {
    return MD5Sum< ::Intelligence::Startup >::value();
  }
  static const char* value(const ::Intelligence::StartupRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::Intelligence::StartupRequest> should match 
// service_traits::DataType< ::Intelligence::Startup > 
template<>
struct DataType< ::Intelligence::StartupRequest>
{
  static const char* value()
  {
    return DataType< ::Intelligence::Startup >::value();
  }
  static const char* value(const ::Intelligence::StartupRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::Intelligence::StartupResponse> should match 
// service_traits::MD5Sum< ::Intelligence::Startup > 
template<>
struct MD5Sum< ::Intelligence::StartupResponse>
{
  static const char* value()
  {
    return MD5Sum< ::Intelligence::Startup >::value();
  }
  static const char* value(const ::Intelligence::StartupResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::Intelligence::StartupResponse> should match 
// service_traits::DataType< ::Intelligence::Startup > 
template<>
struct DataType< ::Intelligence::StartupResponse>
{
  static const char* value()
  {
    return DataType< ::Intelligence::Startup >::value();
  }
  static const char* value(const ::Intelligence::StartupResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // INTELLIGENCE_MESSAGE_STARTUP_H