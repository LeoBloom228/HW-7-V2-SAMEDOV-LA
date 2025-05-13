#include <iostream>
#include <cstddef>  
#include <cstring>  


int main() 
{
    
    char* str = new char[256];

    std::cout << "Enter a line (a line must not exeed 255 symbols): ";
    std::cin.getline(str, 256);

    
    char* p = str;

    while (*p != '\0') 
    {
        if (*p >= '0' && *p <= '9') 
        {
            *p = 'a' + (*p - '0'); 
        }
        ++p;
    }

    std::cout << "Results is as follows: " << str << std::endl;

    delete[] str; // Releasing memory

    return 0;
}
