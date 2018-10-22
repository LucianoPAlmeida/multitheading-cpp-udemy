//
//  main.cpp
//  mutex-lock
//
//  Created by Luciano Almeida on 21/10/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <pthread.h>

#define NUM_THREADS 5

void* worker(void* arg);

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


int main(int argc, const char * argv[]) {
    
    pthread_t threads[NUM_THREADS];
    int threadArgs[NUM_THREADS];
    int resultCode = 0;
    
    for (int i=0; i < NUM_THREADS; i++) {
        threadArgs[i] = i;
        resultCode = pthread_create(threads + i, 0, worker, static_cast<void*>(threadArgs +i));
    }
    
    for (int i=0; i < NUM_THREADS; i++) {
        resultCode = pthread_join(threads[i], 0);
    }
    
    return 0;
    
}



void* worker(void* arg) {
    pthread_mutex_lock(&mutex);
    int value = *static_cast<int*>(arg);
    std::cout << value << std::endl;
    pthread_mutex_unlock(&mutex);

    return 0;
}
