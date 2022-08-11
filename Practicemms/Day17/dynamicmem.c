#include <stdlib.h>
#include <stdio.h>


int main()
{
	int n;
	scanf("%d",&n);
	double *arr=(double*)malloc(n*(sizeof(double)));
	if(arr==NULL)
	{
		fprintf(stderr,"Can not allocate memroy\n");
		return -1;
	}
	for(int i=0;i<n;i++)
	{
		arr[i]= (rand()%11)/10.;
	}
	
	int m;
	scanf("%d",&m);

	arr=(double*)realloc(arr,(n+m)*(sizeof(double)));
	if(arr==NULL)
	{
		fprintf(stderr,"Can not allocate memory\n");
		return -1;
	}
	for(int i=n;i<n+m;i++)
	{
		arr[i]=(10+rand()%11)/10.;
	}

	int p;
	scanf("%d",&p);
	
	arr=(double*)realloc(arr,(n+m+p)*sizeof(double));
	if(arr==NULL)
	{
		fprintf(stderr,"Can not allocate memory\n");
		return -1;
	}
	for(int i=n+m;i<n+m+p;i++)
	{
		arr[i]=(20+rand()%11)/10.;
	}		
	printf("Numbers are\n");

	for(int i=0;i<p;i++)
	{
		printf("%.1lf ",arr[i]);
	}

	free(arr);
	return 0;

}
