#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
    int fd = open ("txt", O_RDWR); // 3
    int fd1 = open ("txt", O_RDWR); // 3
    printf ("another is 4 or 3 : %d\n", fd);
    printf ("another is 4 or 3 : %d\n", fd1);
    while (1);
}