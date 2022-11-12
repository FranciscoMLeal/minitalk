#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void    ft_putnbr(int n)
{
    if(n > 9)
        ft_putnbr(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}

void	handler(int signal)
{
	static char	ascii;
	static int	power;
	static int	i;

	if(i == 0)
		power = 1;
	if(signal == SIGUSR2)
		ascii += power;
	power *= 2;
	i++;
	if(i == 8)
	{
		write(1, &ascii, 1);
		i = 0;
		ascii = 0;
	}
}

int     main(void)
{
    write(1, "PID: ", 5);
    ft_putnbr(getpid());
    write(1, "\n", 1);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1)
        pause();
}

/// Create function that separate last numbers as PID for confirmation
/// Create that sends a confirmation