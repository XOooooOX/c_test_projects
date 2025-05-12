#include <stdio.h>
#include <string.h>

void  print_stack_value(){
    int x = 42;
    printf("x = %d (address: %p)\n",x,(void*)&x);
}

void test() {
    char buf[32];
    strcpy(buf, "SECRET-DATA");
    printf("buf = %s\n", buf);
}

void test2() {
    int x = 48;
    printf("x = %d, addr = %p\n", x, (void*)&x);
}

int main() {

    puts("-------");
    int *p;
    test2();
    p = (int*)__builtin_frame_address(0) - 1;  // اشاره به آدرس نزدیک پایین‌تر
    printf("value at p = %d\n", *p);
    puts("-------");

    puts("-------");
    test();
    char another_buf[32];
    printf("another_buf = %s\n", another_buf);
    puts("-------");

    puts("-------");
    print_stack_value();
    int y;
    printf("y = %d (address: %p)\n",y,(void*)&y);
    puts("-------");

    return 0;
}
