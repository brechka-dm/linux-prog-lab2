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
    cout<<"PID: "<<pid<<" PPID:"<<ppid<<" x: "<<x<<" tg(x): "<<tan(x)<<endl;
    x+=step;
  }
}

void childProcess(float step, pid_t pid, pid_t ppid)
{
  float x =0;
  while (x<=1)
  {
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
      
      // argv[2] is a step for child process.
      childProcess(atof(argv[2]), getpid(), getppid());
      break;
    default:
      
      // argv[1] is a step for parent process.
      mainProcess(atof(argv[1]), getpid(), getppid());
      
      // Whait for child process.
      // If the parent process terminates first, the child process will turn into a zombie
      wait(0);
  }
}

/*
TASK

Напишите программу, порождающую дочерний процесс.
Родительский процесс должен вычислять значения функции tg(x) в
интервале [0, 1] с шагом, задаваемым пользователем через первый
параметр коммандной строки. Дочерний процесс должен вычислять
значение функции ctg(x) в том же интервале с шагом, задаваемым
пользователем через второй параметр коммандной строки. При выводе
результатов процессы также должны выводить свои PID и PPID в одну
строку с результатом работы.
*/
