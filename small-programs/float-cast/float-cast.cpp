#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
    //Simple byte to float
    uint8_t byte_a = 'a';
    float float_of_a = byte_a;
    float_of_a += 0.5;
    std::cout << "Assign 'a' to a float and add 0.5: " << float_of_a << "\n\n";

    //abcd byte array
    uint8_t byte_arr[4];
    for (size_t i = 0; i < 4; ++i)
    {
        byte_arr[i] = 'a' + i;
    }
    float float_of_elem = *(byte_arr+2);
    float_of_elem += 0.5;
    std::cout << "Assign byte_array[2] to a float and add 0.5: " << float_of_elem << "\n\n";

    //Floats to bytes
    std::cout << "Cast 99.5 to uint8_t: " << static_cast<uint8_t>(float_of_elem) << "\n";
    std::cout << "Cast 99.5 to uint16_t: " << static_cast<uint16_t>(float_of_elem) << "\n";
    std::cout << "Cast 99.5 to uint32_t: " << static_cast<uint32_t>(float_of_elem) << "\n\n";

    //uint8_mx, wrapping
    std::cout << "The max uint8_t is: " << UINT8_MAX << "\n";
    uint8_t uint8max_plus1_plusa = UINT8_MAX + 1 + 97;
    std::cout << "The max uint8_t + 1 + 97 is: " << uint8max_plus1_plusa << "\n\n";

    //uint32_max, assignment to float
    uint32_t uint32_max = UINT32_MAX;
    std::cout << "The max uint32_t is: " << uint32_max << "\n";
    float uint32max_float = UINT32_MAX;
    std::cout << std::setiosflags(std::ios::fixed) << "Assign max of uint32_t to float: " << uint32max_float << "\n\n";

    //memcpy from uint8 to uint32
    uint32_t byte_array_to_uint32 = 0;
    memcpy(&byte_array_to_uint32, &byte_arr[0], 4);
    std::cout << "memcpy a byte array (4-long) to uint32: " << byte_array_to_uint32 << "\n";
    
    //uint32 to float
    double byte_array_float = byte_array_to_uint32;
    std::cout << "Assignment of a uint32 to a float: " << (byte_array_float) << "\n";
    
    //float to uint32
    uint32_t convert_from_float = byte_array_float;
    std::cout << "Assignment of float to uint32: " << convert_from_float << "\n";
    
    //float to byte-array
    *byte_arr = static_cast<uint32_t>(byte_array_float);
    std::cout << "Cast float to uint32_t and assign to 4-long byte array: " << byte_arr[0] << byte_arr[1] << byte_arr[2] << byte_arr[3] << "\n\n";

    //size of float
    std::cout << "The size of a float is " << sizeof(uint32max_float) << std::endl;
    std::cout << "The size of a double is " << sizeof(double) << std::endl;

    return 0;
}
