#ifndef _ROS_self_healing_bringup_Int16Stamped_h
#define _ROS_self_healing_bringup_Int16Stamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace self_healing_bringup
{

  class Int16Stamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _data_type;
      _data_type data;

    Int16Stamped():
      header(),
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_data.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_data.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data = u_data.real;
      offset += sizeof(this->data);
     return offset;
    }

    virtual const char * getType() override { return "self_healing_bringup/Int16Stamped"; };
    virtual const char * getMD5() override { return "98610943e4af5bf18c39a51dd08ed69d"; };

  };

}
#endif
