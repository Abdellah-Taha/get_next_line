#include <fcntl.h>    // for open()
#include <stdio.h>    // for printf()
#include <stdlib.h>   // for free()
#include "get_next_line.h"  // your header file

int main(void)
{
    int fd;
    char *line;
    int i = 0;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return -1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line%d : %s\n", i, line);
        i++;
    }
    
}
