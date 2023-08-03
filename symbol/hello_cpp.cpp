#include<iostream>

extern "C"
{
    int hello_cpp();
}
int hello_cpp() {
    std::cout << "Hello, cpp " << __FILE__ << std::endl;
    return 0;
}
