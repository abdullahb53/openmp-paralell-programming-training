//OPENMP-PARALELL-PROGRAMMING-TASK
//OPENMP PARALEL PROGRAMLAMA

//*****ENVIRONMENT-VARIABLES*******
// OMP_SCHEDULE     :PAYLASMA TURU
// OMP_NUM_THREADS  :THREAD SAYISI
// OMP_DYNAMIC
// OMP_NESTED
// OMP_THREAD_LIMIT
// OMP_STACK_SIZE
//_________________________________

//**********DIRECTIVES*************
// #pragma omp paralel
//
//
//_________________________________

#include <stdio.h>
#include <omp.h>

using namespace std;



unsigned int N = 100000;
unsigned int count=0;


bool isPalindrome(unsigned n)
{
    unsigned rev = 0;
    unsigned k = n;
    while (k)
    {
        rev = (rev << 1) | (k & 1);
        k = k >> 1;     // drop last bit
    }
    return n == rev;
}


void decToBinary(int n)
{
    omp_set_num_threads(8);
    #pragma omp parallel for schedule(static)
    for(int k = 0; k<n; k++)
    {

        if(isPalindrome(k) == false ){

        }
        else{
            #pragma omp critical
            {
                count++;
            }
        }

    }

}

int main()
{
        decToBinary(N-1);
     printf("\n countReal= %d",count);
    getchar();
    return 0;
}

