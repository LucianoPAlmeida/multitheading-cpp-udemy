//
//  main.cpp
//  mutex-lock
//
//  Created by Luciano Almeida on 21/10/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <pthread.h>
#include <future>

#define NUM_THREADS 5

void* worker(void* arg);
void its_odd(std::future<int>& fut, bool* is_odd);
void test_promise_and_future();

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

void its_odd(std::future<int>& fut, bool* is_odd) {
    int i = fut.get();
    *is_odd = i % 2 != 0;
}

void test_promise_and_future() {
    std::promise<int> p;
    std::future<int> f = p.get_future();
    bool is_odd;
    std::thread t(its_odd, std::ref(f), &is_odd);
    
    p.set_value(3);
    
    t.join();
    
    std::cout << "Is odd? " << (is_odd ? "Yes" : "No") << std::endl;
}

void* worker(void* arg) {
    pthread_mutex_lock(&mutex);
    int value = *static_cast<int*>(arg);
    std::cout << value << std::endl;
    pthread_mutex_unlock(&mutex);

    return 0;
}
