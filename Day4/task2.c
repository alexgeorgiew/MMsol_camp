#include <stdio.h>
#include <stdint.h>



int main()
{
	uint32_t mask=0;
        printf("Enter 0 to exit program \nEnter 1 to set attendance\nEnter 2 to clear attendance\nEnter 3 to see who is in classroom\nEnter 4 to see ho is missing\nEnter 5 to change status of student\n");
	int option=0,bit=0;
	while(1)
	{
		printf("Please enter option: ");
		scanf("%d",&option);

		if(option==0)
		{
                  return 0;
		}
		else if(option==1)
                {
			printf("Enter number of student who is attending class :");
			scanf("%d",&bit);
			if(bit<1 || bit>32)
			{
				printf("You entered wrong number of student!!!!!!\n");
				return 0;
			}
			mask=mask|(1ull<<(bit-1));
		}
		else if(option==2)
		{
			printf("Enter number of student who is missing class :");
			scanf("%d",&bit);
			if(bit<1 || bit>32)
			{
				printf("You enter wrong number of student !!!!!\n");
				return 0;
			}
			mask=mask&~(1ull<<(bit-1));

		}
		else if(option==3)
		{
                       printf("Students that are in class are : ");
		       for(int i=0;i<32;i++)
		       {
			       if(!!(mask&(1ull<<i)))printf("%d ",i+1);
		       }
		       printf("\n");
		}
		else if(option==4)
		{
			printf("Students that are missing class are : ");
			for(int i=0;i<32;i++)
			{
				if(!!(mask&(1ull<<i))==0)printf("%d ",i+1);
			}
			printf("\n");

		}
		else if(option==5)
		{
			printf("Enter student number to change his status : ");
			scanf("%d",&bit);
			if(bit<1 || bit>32)
			{
				printf("There is no such student number \n");
				return 0;
			}

			mask=mask^(1ull<<(bit-1));

		}
		else
		{
			printf("You enter wrong option !!!!!\n");
			return 0;
		}
	}
	return 0;
}
