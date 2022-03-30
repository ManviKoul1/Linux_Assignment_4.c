/*
Q1.Write a pthread application where main task terminated but pending pthreads task still execute.
*/

#include<stdio.h>                 
#include<pthread.h>     

//Creating a  function to  execute  new thread// 
void* PrintHello(void* data)
{
    int my_data = (int)data;     	 

    pthread_detach(pthread_self());
    printf("New thread created %d\n", my_data);
    pthread_exit(NULL);		 
}


int main(int argc, char* argv[])
{
    int rc;         	                           
    pthread_t  thread_id;     	
    int t = 11;  //data passed to the new thread//

    //New thread that will execute 'PrintHello' //
    //pthreads are still executing
    rc = pthread_create(&thread_id, NULL, PrintHello, (void*)t);  
    if(rc)			/* could not create thread */
    {
        printf("\n ERROR: return code  is %d \n", rc);
        exit(1);
    }
    printf("\n Created new thread (%u) ... \n", thread_id);
    
    pthread_exit(NULL);		
}

