#include "thread_pool_interface.hpp"
#include "specific_thread_user.hpp"

#include <iostream>

using namespace thread_pool_example;

int main()
{
    // Create a single thread pool
    ThreadPoolInterface main_thread_pool_interface(4);

    SpecificThreadUser user_array[] = 
    {
        {"Empress Xina",   main_thread_pool_interface},
        {"Tigress Scout",  main_thread_pool_interface},
        {"Valkyrie Bhavs", main_thread_pool_interface}
    };

    std::cout << std::endl;

    for ( int i = 0; i < 3; ++i )
    {
        user_array[i].generateMessages();
    }

    std::cout << "We are waiting for the demands of our queens." << std::endl;

    int obtained_messages = 0;
    while ( obtained_messages < 12 )
    {
        for ( int i = 0; i < 3; ++i )
        {
            if ( user_array[i].hasOutboundMessages() )
            {
                ThreadUserMessage new_message;
                user_array[i].getOldestMessage(new_message);
                if ( new_message._is_important )
                {
                    std::cout << "Important: ";
                }
                std::cout << new_message._payload;
                user_array[i].notifyUsageOfOldestMessage();
                ++obtained_messages;
            }
        }
    }

    return 0;
}