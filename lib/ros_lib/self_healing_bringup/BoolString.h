#ifndef _ROS_SERVICE_BoolString_h
#define _ROS_SERVICE_BoolString_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace self_healing_bringup
{

static const char BOOLSTRING[] = "self_healing_bringup/BoolString";

  class BoolStringRequest : public ros::Msg
  {
    public:
      typedef bool _data_type;
      _data_type data;
      typedef const char* _comment_type;
      _comment_type comment;

    BoolStringRequest():
      data(0),
      comment("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
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
      union {
        bool real;
        uint8_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
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

    virtual const char * getType() override { return BOOLSTRING; };
    virtual const char * getMD5() override { return "8a17b6de945bb582cb0995f4522f91f0"; };

  };

  class BoolStringResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    BoolStringResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return BOOLSTRING; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class BoolString {
    public:
    typedef BoolStringRequest Request;
    typedef BoolStringResponse Response;
  };

}
#endif
