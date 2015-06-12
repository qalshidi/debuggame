#pragma once

#include "../States/State.h"

#include <string>
#include <memory>

using namespace std;

namespace Engine
{
    class IEntity : public enable_shared_from_this<IEntity>
    {
    protected:
        unsigned short          m_gid;      //Unique GlobalID
        string                  m_id;       //Name of the entity
        string                  m_type;     //Type of entity eg "character"

        static unsigned short   next_gid;

    public:
        IEntity(){next_gid++; m_gid=next_gid;}
        unsigned int    get_gid() {return m_gid;}
        string          get_type() {return m_type;}
        string          get_id() {return m_id;}

        virtual void    on_start(const StatePtr& state)=0;
        virtual void    on_exit()=0;
        virtual void    update()=0;
    };
}



