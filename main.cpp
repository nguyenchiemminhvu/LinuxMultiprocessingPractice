#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <iostream>
using namespace std;

void func_in_child_process_1()
{
    pid_t p = fork();
    
    char buffer[255] = { 0 };
    sprintf(buffer, "func_in_child_process_1 called\n");
    write(1, buffer, strlen(buffer));
}

void func_in_child_process_2()
{
    char buffer[255] = { 0 };
    sprintf(buffer, "func_in_child_process_2 called\n");
    write(1, buffer, strlen(buffer));
}

void execute_child_process()
{
    sleep(1);

    char buffer[255] = { 0 };
    sprintf(buffer, "PID of child process %d\n", getpid());
    write(1, buffer, strlen(buffer));
    
    sleep(1);
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

        std::cout << "In child process, do something more..." << std::endl;
        
        func_in_child_process_1();
        func_in_child_process_2();
    }
    else
    {
        int status;
        wait(&status);
        execute_parent_process();
    }

    return 0;
}