#ifndef _GENERIC_THREAD_USER_HPP_
#define _GENERIC_THREAD_USER_HPP_

#include "thread_pool_interface.hpp"

#include <string>

namespace thread_pool_example
{

class GenericThreadUser
{
public:
    GenericThreadUser() = delete;
    GenericThreadUser(std::string&, ThreadPoolInterface&);
    virtual ~GenericThreadUser();
private:
    std::string& _user_name; 
    ThreadPoolInterface& _thread_pool_interface;
};

} // namespace thread_pool_example

#endif // _GENERIC_THREAD_USER_HPP_