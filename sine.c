#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[])
{
	int	angle_degree;
	double	angle_radian, pi, value;


	printf ("\nCompute a table of the sine function\n\n");


	pi = 4.0*atan(1.0);
	printf ( " Value of pi = %f \n\n", pi );

	printf ( " angle	Sine \n" );

	angle_degree=0;

	while ( angle_degree <= 360 )
	{
		angle_radian = pi * angle_degree/180.0 ;
		value = sin(angle_radian);
		printf ( "  %3d	%f \n ", angle_degree, value );

		angle_degree = angle_degree + 10;
	}
	return 0;
}
