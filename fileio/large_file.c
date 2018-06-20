#define _LARGEFILE64_SOURCE
#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
        int fd;
        off64_t off;

        if(argc != 3 || strcmp(argv[1], "--help") == 0)
                usageErr("%s pathname offset", argv[0]);

        fd = open64(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRWXG);
        if(-1 == fd)
                errExit("open64");

        off = atoll(argv[2]);
        if(lseek64(fd, off, SEEK_SET) == -1)
                errExit("lseek");

        /* write function is true on 32 or 64 system */
        if(write(fd, "test", sizeof("test")) == -1)
                errExit("write64");

        exit(EXIT_SUCCESS);
}
