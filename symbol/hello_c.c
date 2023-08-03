#include <stdio.h>

extern int hello_cpp();

int hello_c() {
    hello_cpp(__FILE__);
    printf("Hello, c %s\n", __FILE__);
    return 0;
}

// __attribute__((weak)) int hello_weak(){
//     printf("Hello, weak lib %s\n", __FILE__);
//     return 0;
// }
