#include <stdio.h>
#include <sys/syscall.h>

int main() {
    int x = syscall(345, 10);
    printf("%d\n", x); 
    return 0;

}
