#include <limits.h>
#include <signal.h>
#include <unistd.h>

void	ft_conv(int n, int pid)
{
	int i;

    i = 8;
    while(i--)
    {
		if((n % 2) == 1)
            kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
        n /= 2;
	}
}

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

int main(int argc, char **argv)
{
    int i;
    int pid;

    if(argc != 3)
        return (write(1, "Wrong number of arguments\n", 26));
    pid = ft_atoi(argv[1]);
    if(pid <= 0)
        return (write(1, "Invalid PID\n", 12));
    i = -1;
    while(argv[2][++i])
        ft_conv(argv[2][i], pid);
}

/// Create a function that gets PID and sends it in the end of the string