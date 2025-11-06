#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

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
