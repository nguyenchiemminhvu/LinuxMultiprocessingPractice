#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>
using namespace std;

void execute_child_process()
{
    char buffer[255] = { 0 };
    sprintf(buffer, "PID of child process %d\n", getpid());
    write(1, buffer, strlen(buffer));
}

void execute_parent_process()
{
    char buffer[255] = { 0 };
    sprintf(buffer, "PID of parent process %d\n", getpid());
    write(1, buffer, strlen(buffer));
} 

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        execute_child_process();
    }
    else
    {
        execute_parent_process();
    }

    return 0;
}