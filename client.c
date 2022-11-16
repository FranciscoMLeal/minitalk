#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <signal.h>

int ft_atoi(const char *str)
{
    int i;
    long num;
    long signal;
    
    i = 0;
    num = 0;
    signal = 1;
    while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
        if (str[i++] == '-')
            signal = -1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = (num * 10) + signal * (str[i++] - '0');
        if ((num < 0) || num > INT_MAX)
            return (-1);
    }
    return (num);
}

void    client(int pid, int val)
{
    int i = -1;
    int div = 128;

    while (i++ < 7)
    {
        if(val >= div)
        {
            val -= div;
            kill(pid,SIGUSR2);
        }
        else
            kill(pid,SIGUSR1);
        div = div / 2;
        usleep(300);
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;
    if(argc !=3)
        return(write(1,"You can only use 2 arguments",29));
    pid = ft_atoi(argv[1]);
    i = -1;
    while(argv[2][++i])
        client(pid, argv[2][i]);


    ///Falta criar um conversor de char para binario para enviar a msg

//   kill(pid, SIGUSR2);
//   usleep(200);
//   kill(pid, SIGUSR1);
//   usleep(200);
//   kill(pid, SIGUSR1);
//   usleep(200);
//   kill(pid, SIGUSR1);
//   usleep(200);
//   kill(pid, SIGUSR1);
//   usleep(200);
//   kill(pid, SIGUSR2);
//   usleep(200);
//   kill(pid, SIGUSR2);
    //usleep(100);
    //kill(pid, SIGUSR1);
    //printf("I'M fhere and I already killed before\nmy pid is : %i\n",pid);
}