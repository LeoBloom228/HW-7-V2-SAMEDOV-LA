#include <iostream>
#include <cstddef>  
#include <cstring>  

//task 1
void task1() 
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

}

//task 2
// The function of removing all adjacent identical characters
char* removeadjacentduplicates(char* str) 
{
    size_t len = strlen(str);
    if (len < 2) return str;

    // Allocating a buffer with a reserve (max length of the original string)
    char* result = new char[len + 1];
    char* write = result;
    char* read = str;

    while (*read != '\0') 
    {
        // If the current and next symbols are the same - skip both
        if (*(read + 1) != '\0' && *read == *(read + 1)) 
        {
            // Skip the same pair
            char curr = *read;
            while (*read == curr && *(read + 1) == curr) 
            {
                ++read;
            }
            // Skip the last of the pair
            ++read;
        }
        else 
        {
            *write = *read;
            ++write;
            ++read;
        }
    }

    *write = '\0'; // completing the line

    // reallocating memory to the new length
    size_t newLen = strlen(result);
    char* compressed = new char[newLen + 1];
    strcpy_s(compressed, newLen + 1, result);

    delete[] result;
    delete[] str; // Deleteing the old line

    return compressed;
}

void task2() 
{
    // Allocating memory for the original string
    char* str = new char[256];

    std::cout << "Please, enter a string: ";
    std::cin.getline(str, 256);

    // Removing adjacent pairs
    str = removeadjacentduplicates(str);

    std::cout << "The result is: " << str << std::endl;

    delete[] str; // Releasing memory

}

int main()
{
    task1();
    task2();

    return 0;

}