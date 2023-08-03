extern "C" {
#include<stdio.h>
int hello_c();
int hello_lib();
int hello_aaa();

// int hello_lib() {
//     printf("Hello, not lib %s\n", __FILE__);
//     return 0;
// }

int hello_weak();
// __attribute__((weak)) int hello_weak() {
//     printf("Hello, weak %s\n", __FILE__);
//     return 0;
// }
}



int main() {
    hello_c();
    hello_lib();
    hello_aaa();
    hello_weak();
    return 0;
}
