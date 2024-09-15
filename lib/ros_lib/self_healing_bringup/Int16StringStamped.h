#ifndef _ROS_self_healing_bringup_Int16StringStamped_h
#define _ROS_self_healing_bringup_Int16StringStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace self_healing_bringup
{

  class Int16StringStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _data_type;
      _data_type data;
      typedef const char* _comment_type;
      _comment_type comment;

    Int16StringStamped():
      header(),
      data(0),
      comment("")
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
      uint32_t length_comment = strlen(this->comment);
      varToArr(outbuffer + offset, length_comment);
      offset += 4;
      memcpy(outbuffer + offset, this->comment, length_comment);
      offset += length_comment;
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
      uint32_t length_comment;
      arrToVar(length_comment, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_comment; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_comment-1]=0;
      this->comment = (char *)(inbuffer + offset-1);
      offset += length_comment;
     return offset;
    }

    virtual const char * getType() override { return "self_healing_bringup/Int16StringStamped"; };
    virtual const char * getMD5() override { return "4b722c4bd2ba479ac486ed4ca35687b9"; };

  };

}
#endif
