//
//  main.cpp
//  pthread_barrier
//
//  Created by Luciano Almeida on 24/11/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <pthread.h>

#define NUMBER_COUNT 6

void* sum_worker(void* arg);
void* factor_worker(void* arg);

int main(int argc, const char * argv[]) {
    
    pthread_t thread_sum;
    pthread_t thread_factor;
    
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    pthread_create(&thread_sum, 0, sum_worker, static_cast<void*>(numbers));
    pthread_create(&thread_factor, 0, factor_worker, static_cast<void*>(numbers));
    
    int * sum = NULL;
    int * fac = NULL;

    pthread_join(thread_sum, reinterpret_cast<void**>(&sum));
    pthread_join(thread_factor, reinterpret_cast<void**>(&fac));

    
    std::cout << "Sum: " << *sum << std::endl;
    std::cout << "Factorial: " << *fac << std::endl;

    delete sum;
    delete fac;
    
    return 0;
}

void* sum_worker(void* arg) {
    int* sum = new int;
    *sum = 0;
    int * numbers = static_cast<int*>(arg);
    for (int i = 0; i < NUMBER_COUNT; i++)
        *sum+= numbers[i];
    return reinterpret_cast<void*>(sum);
}

void* factor_worker(void* arg) {
    int* fac = new int;
    *fac = 1;
    int * numbers = static_cast<int*>(arg);
    for (int i = 0; i < NUMBER_COUNT; i++)
        *fac*= numbers[i];
    return reinterpret_cast<void*>(fac);
}
