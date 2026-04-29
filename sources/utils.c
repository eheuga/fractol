#include "fractol.h"


int	print_usage(void)
{
	write(1, "Usage:\n", 7);
	write(1, "  ./fractol mandelbrot\n", 23);
	write(1, "  ./fractol julia <cx> <cy>\n", 28);
	write(1, "    cx and cy are floats, e.g. -0.7 0.27015\n", 44);
	return (1);
}

double ft_atof(char *str)
{
    double  result;
    double  decimal;
    int     sign;
    int     i;

    result = 0;
    decimal = 1;
    sign = 1;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
    {
        i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
            decimal /= 10;
            result += (str[i] - '0') * decimal;
            i++;
        }
    }
    return (result * sign);
}