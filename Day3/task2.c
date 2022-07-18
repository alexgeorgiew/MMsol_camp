#include <stdio.h>
#include <math.h>
#include <float.h>

int floatCompare1(float a,float b);
int floatCompare1(float a,float b)
{
	return a==b;
}

int floatComapre2(float a,float b);
int floatCompare2(float a,float b)
{
	return fabs(a-b)<1.0e-5f;
}

int floatCompare2_1(float a,float b);
int floatCompare2_1(float a,float b)
{
	return fabs(a-b)<1.0e-2f;
}

int floatCompare3(float a,float b);
int floatCompare3(float a,float b)
{
	return fabs(a-b)<1.0e-5f*fmax(fabs(a),fabs(b));
}

int doubleCompare2(double a,double b);
int doubleCompare2(double a,double b)
{
	return fabs(a-b)<1.0e-5f;
}

int floatCompare4(float a,float b);
int floatCompare4(float a,float b)
{
	if(fabs(a-b)<FLT_EPSILON)return 1;
	return 0;
}

int doubleCompare4(double a,double b);
int doubleCompare4(double a,double b)
{
	if(fabs(a-b)<FLT_EPSILON)return 1;
	return 0;
}

int main()
{
        float a=1000.0f*0.1f;
	float b=0.0f;
        double c=1000.0*0.1;
	double d=0.0;
	for(int i=0;i<1000;i++,b+=0.1f,d+=0.1);

	if(floatCompare1(a,b))
	{
		printf("== Equals\n");
	}
	else
	{
		printf("== Not equals\n");
	}

	if(floatCompare2(a,b))
	{
		printf("fixed E: Equals\n");
	}
	else
	{
		printf("fixed E: Not equals\n");
	}

        if(doubleCompare2(c,d))
	{
		printf("fixed E double: Equals\n");
	}
	else
	{
                printf("fixed E double : Not Equals\n");
	}

	if(floatCompare2_1(a,b))
	{
		printf("fixed E 2_1: Equals\n");
	}
	else
	{
		printf("fixed E 2_1: Not Equals\n");
	}

	if(floatCompare3(a,b))
	{
		printf("adaptive E: Equals\n");
	}
	else
	{
		printf("adaptive E: not equals\n");
	}

	if(floatCompare4(a,b))
	{
		printf("flt_epsilon: equals \n");
	}
	else
	{
		printf(" flt_epsilon: not equals\n");
	}

	if(doubleCompare4(c,d))
	{
		printf("flt_epsilon double: equals\n");

	}
	else
	{
		printf("flt_epsilon double: not equals\n");
	}
	return 0;
}

