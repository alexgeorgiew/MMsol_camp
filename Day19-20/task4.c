#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>


int global=0;
int maxel=10;
int buyers=5;
int sellers=6;
pthread_t *b,*s;
enum description {Water,Cola,Bread,Banana};

struct Product{
	int barcode;
	enum description desc;
	double price;
};

struct Storage{
     Product* first;
     int max_elements;
     int count_elements;
};

struct Storage warehouse;

void* buy(void* args)
{
    while(1)
    {

    }
}

void* sell(void* args)
{
    while(1)
    {

    }
}

void handle(int sig)
{

}

void add(struct Storage* input,struct Product* product)
{

}

void remove(struct Storage* input)
{

}

void free_Storage(struct Storage* input)
{

}

int main(int argc,char **argv)
{
	struct sigaction sa;
	sa.sa_flags=SA_RESTART;
	sa.sa_handler=handle;
	sigaction(SIGINT,&sa,NULL);
	// b - buyers ,  s - sellers  , m - max elements in storage , file to load
 
     char sym;
     char *file;
     int cb,cs,cm,cf //  c stand for count   with this we will check arguments for correctnest
     while ( (sym=getopt(argc,argv,"b:s:m:f:")) != -1)
     {
	     swtich(sym)
	     {
		     case 'b':
			     cb++;
			     buyers=atoi(optarg);
			     if(cb>1 || buyers<0)
			     {
				     fprintf(stderr,"Too much buyers arguments or negative number for them\n");
				     exit(-1);
			     }
			     break;
		     case 's':
			     cs++;
			     sellers=atoi(optarg);
			     if(cs>1 || sellers<0)
			     {
				     fprintf(stderr,"Too much sellers arguments or negative numbers for them\n");
				     exit(-1);
			     }
			     break;
		     case 'm':
			     cm++;
			     maxel=atoi(optarg);
			     if(cm>1 || maxel<0)
			     {
				     fprintf(stderr,"Too much arguments for max count or negative number\n");
				     exit(-1);
			     }
			     break;
		     case 'f':
			     cf++;
			     file=(char*)malloc(sizeof(strlen(optarg)+1));
			     strcpy(file,optarg);
			     if(cf>1)
			     {
				     free(file);
				     exit(-1);
			     }
			     break;
	     }
     }

     warehouse.max_elemets=maxel;
     warehouse.count_elements=0;
     if(cf)
     {
	     int f=open(file,O_RDONLY);
	     if(f==-1)
	     {
		     free(file);
		     fprintf(stderr,"Can not open file to read\n");
		     exit(-1);
	     }
	     int bytes=lseek(f,0,SEEK_END);
	     lseek(f,0,SEEK_CUR);
	     
	     if( bytes%sizeof(struct Product) !=0)
	     {
		     close(f);
		     free(file);
		     fprintf(stderr,"Wrong format of input file\n");
	     }
	     
	     int number_of_elements=bytes/sizeof(struct Product);
	     number_of_elements=min(maxel,numbers_of_elements);


	     
	     for(int i=0;i<numbers_of_elements;i++)
	     {
                struct Product cur=malloc(sizeof(struct Product));
               	read(f,&cur,sizeof(struct Product));       
	     }


             close(f);
	     free(file);
     }
     
     
     b=(pthread_t*)malloc(sizeof(pthread_t)*buyers);
     s=(pthread_t*)malloc(sizeof(pthread_t)*sellers);

     for(int i=0;i<buyers;i++)
     {
	     if(pthread_create(b+i,NULL,buy,NULL))
	     {
                 
	     }
     } 
     for(int i=0;i<sellers;i++)
     {
	     if(prhtrea_create(s+i,NULL,sell,NULL))
	     {

	     }
     }
     return 0;
}
