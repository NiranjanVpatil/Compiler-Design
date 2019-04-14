
#include <iostream> 
#include <pthread.h> 
#include <time.h> 
  

#define MAX 20 
  

#define THREAD_MAX 4 
  
using namespace std ; 
  
 
int a[MAX] = { 83 , 86 , 77 , 15 , 93 , 35 , 86 , 92 , 49 , 21 , 
         62 , 27 , 90 , 59 , 63 , 26 , 40 , 26 , 72 , 36 }; 
int part = 0 ; 

int main () 
{ 
    
    for (int i = 0; i < MAX; i++) 
        a[i] = rand() % 100; 
  
   
    clock_t t1, t2; 
  
    t1 = clock(); 
    pthread_t threads[THREAD_MAX]; 
  
   
    for (int i = 0; i < THREAD_MAX; i++) 
        pthread_create(&threads[i], NULL, merge_sort, 
                                        (void*)NULL); 
  
    
    for (int i = 0; i < 4; i++) 
        pthread_join(threads[i], NULL); 
  
   
    merge(0, (MAX / 2 - 1) / 2, MAX / 2 - 1); 
    merge(MAX / 2, MAX/2 + (MAX-1-MAX/2)/2, MAX - 1); 
    merge(0, (MAX - 1)/2, MAX - 1); 
  
    t2 = clock(); 
  
  
    cout << "Sorted array: "; 
    for (int i = 0; i < MAX; i++) 
        cout << a[i] << " "; 
  
   
    cout << "Time taken: " << (t2 - t1) /  
              (double)CLOCKS_PER_SEC << endl; 
  
    return 0; 
}

