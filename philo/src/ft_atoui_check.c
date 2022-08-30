#include <stdio.h>
#include <unistd.h>
#include <limits.h>

unsigned int	ft_atoui_check(const char *str)
{
	unsigned int	nb;
	int	power;
	nb = 0;
	power = 0;
	while (*str == ' ')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9' && power < 9)
		{
			nb = (nb * 10) + (*str - 48);
			power++;
			printf("nb : %d, power: %d\n", nb, power);
		}
		else if (power == 9 && nb == 429496729 && *str >= '0' && *str <= '5')
		{
			nb = (nb * 10) + (*str - 48);
			printf("int max %u\n", UINT_MAX);
			printf("nb : %u, power: %d\n", nb, power);
		}
			
		else if (power == 9 && nb < 429496729 && *str >= '0' && *str <= '9')
			nb = (nb * 10) + (*str - 48);
		else
		{
			write(1, "Please write the different timings in correct Unsigned Int format\n", 67);
			return (0);
		}
		str++;
	}
	return (nb);
}

int main(int argc, char **argv)
{
	char *nb = argv[argc - 1];
	printf("nb= %u\n", ft_atoui_check(nb));
	return (0);
}