#include <iostream>
#include <chrono>
using namespace std;
#include <omp.h>

void hello_openmp()
{
	omp_set_num_threads(8);
#pragma omp_parallel
	{
#pragma omp critical
		cout << "Hello, OpenMP " << omp_get_thread_num() << "/" << omp_get_num_threads() << endl;
	}
}
int main(int argc, char* argv[])
{
	hello_openmp();
	getchar();
	return 0;
}