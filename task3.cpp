#include <unistd.h>
#include <sys/types.h>
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
  cout<<"PID: "<<getpid()<<" PPID: "<<getppid()<<endl;
  
  // argv[1] is a step for parent process in "./task2", argv[2] is a step for child process in
  execl("./task2", "./task2", argv[1], argv[2], NULL);
}
