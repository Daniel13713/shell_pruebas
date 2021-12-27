#include <stdio.h>

int main(void)
{
	printf("%s\n" , PATH);
	return 0;
}

/**
 * _isdigit - checks for a digit 0 through 9
 *
 * @c: number
 * Return: (1) if 0<c<9, (0) otherwise
 */

int _isdigit(char *str)
{
	int i = 0;

	if (!str)
	{
		return (0);
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

/**
 * _atoi - convert string to integer
 *
 * @str: string
 * Return: Number
 */
int _atoi(char *str)
{
    int res = 0; 
    int sign = 1;
    int i = 0;
 
    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; i++)
        res = res * 10 + str[i] - '0'; 
    return sign * res;
}
