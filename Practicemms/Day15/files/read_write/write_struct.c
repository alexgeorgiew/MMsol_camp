#include <stdio.h>

struct Student
{
	double grade;
	char name[7];
	char age;
};


int main()
{
	struct Student arr[5];
	arr[0]=(struct Student){5.3,"BOBI",(char)48};
	arr[1]=(struct Student){5.5,"IVAN",(char)14};
	arr[2]=(struct Student){2.4,"EVGENI",(char)15};
	arr[3]=(struct Student){3.4,"DRAGO",(char)16};
	arr[4]=(struct Student){4.4,"PEPI",(char)17};

	FILE* f=fopen("binary_struct","w");

	fwrite(arr,sizeof(struct Student),5,f);

	fclose(f);

	FILE* f2=fopen("binary_struct","r");
	fread(arr,sizeof(struct Student),5,f2);

	for(int i=0;i<5;i++)
	{
		char g=arr[i].age;
		printf("age:%d grade:%lf , name:%s\n",g,arr[i].grade,arr[i].name);
	}
	fclose(f2);
	return 0;
}
