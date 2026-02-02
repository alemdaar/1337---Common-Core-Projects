#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
    int another_fd = open ("another", O_CREAT | O_RDWR, 0777); // 3
    int fd = open ("txt", O_RDWR); // 4
    printf ("another is 3 : %d\n", another_fd);
    printf ("another is 4 : %d\n", fd);
    while (1);
}