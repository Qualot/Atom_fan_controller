#ifndef _ROS_SERVICE_HeaterServer_h
#define _ROS_SERVICE_HeaterServer_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace self_healing_bringup
{

static const char HEATERSERVER[] = "self_healing_bringup/HeaterServer";

  class HeaterServerRequest : public ros::Msg
  {
    public:
      uint32_t mode_length;
      typedef int16_t _mode_type;
      _mode_type st_mode;
      _mode_type * mode;
      uint32_t array_length;
      typedef int16_t _array_type;
      _array_type st_array;
      _array_type * array;

    HeaterServerRequest():
      mode_length(0), st_mode(), mode(nullptr),
      array_length(0), st_array(), array(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mode_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mode_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mode_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mode_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mode_length);
      for( uint32_t i = 0; i < mode_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_modei;
      u_modei.real = this->mode[i];
      *(outbuffer + offset + 0) = (u_modei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_modei.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->mode[i]);
      }
      *(outbuffer + offset + 0) = (this->array_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->array_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->array_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->array_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->array_length);
      for( uint32_t i = 0; i < array_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_arrayi;
      u_arrayi.real = this->array[i];
      *(outbuffer + offset + 0) = (u_arrayi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_arrayi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->array[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t mode_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      mode_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      mode_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      mode_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->mode_length);
      if(mode_lengthT > mode_length)
        this->mode = (int16_t*)realloc(this->mode, mode_lengthT * sizeof(int16_t));
      mode_length = mode_lengthT;
      for( uint32_t i = 0; i < mode_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_mode;
      u_st_mode.base = 0;
      u_st_mode.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_mode.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_mode = u_st_mode.real;
      offset += sizeof(this->st_mode);
        memcpy( &(this->mode[i]), &(this->st_mode), sizeof(int16_t));
      }
      uint32_t array_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      array_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      array_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      array_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->array_length);
      if(array_lengthT > array_length)
        this->array = (int16_t*)realloc(this->array, array_lengthT * sizeof(int16_t));
      array_length = array_lengthT;
      for( uint32_t i = 0; i < array_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_array;
      u_st_array.base = 0;
      u_st_array.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_array.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_array = u_st_array.real;
      offset += sizeof(this->st_array);
        memcpy( &(this->array[i]), &(this->st_array), sizeof(int16_t));
      }
     return offset;
    }

    virtual const char * getType() override { return HEATERSERVER; };
    virtual const char * getMD5() override { return "f027a6b8eecbcc3571fb00b7e1eaa56b"; };

  };

  class HeaterServerResponse : public ros::Msg
  {
    public:

    HeaterServerResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return HEATERSERVER; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class HeaterServer {
    public:
    typedef HeaterServerRequest Request;
    typedef HeaterServerResponse Response;
  };

}
#endif
