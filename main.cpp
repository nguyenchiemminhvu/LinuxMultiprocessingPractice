#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
    char buffer[255] = {0};

    int cid = getpid();
    std::cout << cid << std::endl;

    int fid = fork();

    for (int i = 0; i < 10; i++)
    {
        sprintf(buffer, "%d\n", getpid());
        write(1, buffer, strlen(buffer));
    }

    return 0;
}