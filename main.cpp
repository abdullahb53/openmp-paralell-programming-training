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
#include <sys/time.h>

using namespace std;
int N = 100000;
int count_e = 0;
//binary tersi bulup dogrudan karsilastirip degeri bulabiliyor.
bool plandormmu(unsigned n)
{
    unsigned ters = 0;
    unsigned k=n;
    while(k)
    {
        //ters binary format olusturuldu
        ters = (ters << 1)| (k&1);
        //k saga kayarak tersi bir sonraki dongude oldurmaya vesile oluyor
        k = k >> 1;
    }

    return ters == n;
}


void decToBinary(int n)
{
    omp_set_num_threads(8);

    #pragma omp parallel for schedule(dynamic)
    for(unsigned int k = 0; k<n; k++)
    {
        if(plandormmu(k) == true ){
            #pragma omp critical
            {
                count_e++;
            }
        }
    }

}

int main()
{

    timeval tim;
    gettimeofday(&tim,NULL);
    double t1 = 1.0e6 * tim.tv_sec + tim.tv_usec;
    //FUNC
    decToBinary(N);
    //FUNC
    gettimeofday(&tim,NULL);
    double t2 = 1.0e6 * tim.tv_sec + tim.tv_usec;

    double facelessVoid = (t2-t1);

    printf("\n countReal= %d ______ VoidTime = %.0f",count_e,facelessVoid);
    getchar();
    return 0;
}

