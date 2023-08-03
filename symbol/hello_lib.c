#include <stdio.h>

int hello_lib() {
    printf("Hello, lib %s\n", __FILE__);
    return 0;
}

int hello_aaa() {
    printf("Hello, aaa %s\n", __FILE__);
    hello_lib();
    return 0;
}

__attribute__((weak)) int hello_weak(){
    printf("Hello, weak lib %s\n", __FILE__);
    return 0;
}
