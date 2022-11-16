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

void server(int signal)
{
	int pwrvl[8] = {128,64,32,16,8,4,2,1};
	static	int	i;
	static int wrt;

	if(signal == SIGUSR2)
		wrt += pwrvl[i];
	//write(1,&sign[i],1);///APAGAR
	i++;
	if(i == 8)
	{
		write(1,&wrt,1);
		i = wrt = 0;
	}
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
    signal(SIGUSR1, server);
	signal(SIGUSR2, server);
	while (1)
		pause();	
}