#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int getlen(int pid)
{
	int ret;

	ret = 0;
	while(pid > 0)
	{
		pid = pid/10;
		ret++;
	}
	return(ret);
}

char	*print_pid(int pid, int pid_len, int pid_len_saved)
{
	char	ret[pid_len];
	char	*retu;

	if(pid <= 0)
	{
		write(1,"Something is not right",22);
		return(NULL);
	}
	else
	{
		while(pid_len)
		{
			ret[pid_len - 1] = (pid % 10) + '0';
			pid = pid / 10;
			pid_len--;
		}
		retu = &ret[0];
		return(retu);
	}
}

void	*bintodec(char	*sign)
{
	int i;
	int ret;
	void	*chrval;

	i = 9;
	while(i--)
	{
		ret += (sign[i] - 48) * 2 ^ i;
	}
	chrval = &ret;
	return(chrval);
}

void server(int signal)
{
	static char	sign[8];
	static	int	i;
	void *wrt;

	if(signal == SIGUSR1)
		sign[i] = 0;
	if(signal == SIGUSR2)
		sign[i] = 1;
	i++;
	if(i == 8)
	{
		wrt = bintodec(sign);
		write(1,wrt,1);
		i = 0;
	}
}
void	testeapagar(int signal)
{
	printf("%s","ITS FICKING WORKING");
	write(1,'1',1);
}

int main()
{
	int pid;
	int pid_len;
	int	i;
	char *pid_char;

	i = 0;
	pid = getpid();
	pid_len = getlen(pid);
	pid_char = print_pid(pid,pid_len,pid_len);
	write(1,"PID:",4);
	write(1,pid_char,pid_len);
	write(1, "\n", 1);
    ///signal(SIGUSR2, server);
    signal(SIGUSR1, testeapagar);
	signal(SIGUSR2, testeapagar);
	while (1)
		pause();	
}