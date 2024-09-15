#ifndef _ROS_self_healing_bringup_Heater_h
#define _ROS_self_healing_bringup_Heater_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace self_healing_bringup
{

  class Heater : public ros::Msg
  {
    public:
      uint32_t mode_length;
      typedef int16_t _mode_type;
      _mode_type st_mode;
      _mode_type * mode;
      uint32_t cmd_length;
      typedef int16_t _cmd_type;
      _cmd_type st_cmd;
      _cmd_type * cmd;

    Heater():
      mode_length(0), st_mode(), mode(nullptr),
      cmd_length(0), st_cmd(), cmd(nullptr)
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
      *(outbuffer + offset + 0) = (this->cmd_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cmd_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cmd_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cmd_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cmd_length);
      for( uint32_t i = 0; i < cmd_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_cmdi;
      u_cmdi.real = this->cmd[i];
      *(outbuffer + offset + 0) = (u_cmdi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cmdi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cmd[i]);
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
      uint32_t cmd_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cmd_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cmd_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cmd_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cmd_length);
      if(cmd_lengthT > cmd_length)
        this->cmd = (int16_t*)realloc(this->cmd, cmd_lengthT * sizeof(int16_t));
      cmd_length = cmd_lengthT;
      for( uint32_t i = 0; i < cmd_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_cmd;
      u_st_cmd.base = 0;
      u_st_cmd.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cmd.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_cmd = u_st_cmd.real;
      offset += sizeof(this->st_cmd);
        memcpy( &(this->cmd[i]), &(this->st_cmd), sizeof(int16_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "self_healing_bringup/Heater"; };
    virtual const char * getMD5() override { return "bf2fc5105c68816e171b6b9fceb73b6f"; };

  };

}
#endif
