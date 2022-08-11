#include <stdio.h>
#include <stdlib.h>



int**  generate()
{
  int** arr=(int**)malloc(rows*sizeof(int*));
  for(int i=0;i<rows;i++)
  {
	  arr[i]=(int*)malloc(sizeof(int)*(i+1));
	  for(int j=0;j<=i;j++)
	  {
		  arr[i][j]=j+1;
	  }
  }
  return arr;

}

void print(int** arr)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<=i;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

void myfree(int** arr)
{
	for(int i=0;i<rows;i++)
	{
		free(arr[i]);
	}
	free(arr);
}

int main()
{
	int **nums=generate();
	print(nums);
	myfree(nums);

	return 0;
}
