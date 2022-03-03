#include <math.h>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void mainProcess(float step, pid_t pid, pid_t ppid)
{
  float x =0;
  while (x<=1)
  {
    
    // If parent process exits, child may become zombie.
    if(x==0.5) exit(pid);
    cout<<"PID: "<<pid<<" PPID:"<<ppid<<" x: "<<x<<" tg(x): "<<tan(x)<<endl;
    x+=step;
  }
}

void childProcess(float step, pid_t pid, pid_t ppid)
{
  float x =0;
  while (x<=1)
  {
    if(x==0.5) exit(pid);
    cout<<"PID: "<<pid<<" PPID:"<<ppid<<" x: "<<x<<" ctg(x): "<<1/tan(x)<<endl;
    x+=step;
  }
}

int main(int argc, char* argv[])
{
  pid_t pid = fork();
  switch(pid)
  {
    case -1:
      cout<<"Create process error"<<endl;
      exit(-1);
      break;
    case 0:
      childProcess(atof(argv[2]), getpid(), getppid());
      break;
    default:
      mainProcess(atof(argv[1]), getpid(), getppid());
      wait(0);
  }
}

/*
TASK

Модифицируйте программу из задания 1 так, чтобы при достижении
аргументом значения 0,5 происходил системный вызов exit().
*/
