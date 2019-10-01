#include <stdio.h>
#include <stdint.h>
#include <omp.h>

#define SIZE 1000

void fill_array(float vec[SIZE])
{
	for(int i=0; i<SIZE; i++)
	{
		vec[i]=1.0;
	}
}

void print_vec(float vec[SIZE])
{
	for(int i=0; i<SIZE; i++)
	{
		printf("%f ", vec[i]);
	}
	putchar('\n');
}

int main(int argc, char* argv[])
{
	float a[SIZE],b[SIZE],c[SIZE],d[SIZE];
	fill_array(a);
	fill_array(b);
	fill_array(c);
	fill_array(d);
	#pragma omp parallel default(none) shared(a,b,c,d)
	{
		#pragma omp sections nowait
		{
			#pragma omp section
			for(int i=0; i<SIZE-1; i++)
			{
				b[i]=(a[i]+a[i+1])/2;
			}
			#pragma omp section
			for(int i=0; i<SIZE; i++)
			{
				d[i]=1.0/c[i];
			}
		}
	}
	print_vec(b);
	print_vec(d);
	return 0;
}
