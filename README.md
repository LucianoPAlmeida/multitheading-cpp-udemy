# Mastering Multithreading with C++

My code tests and notes for the [Mastering Multithreading with C++](https://www.udemy.com/share/100m8mBUsZd15VQXw=/)

## Notes
* Section 2 
    * Lesson 4:
        * Process: One or more threads
        * Process communicate with each other by the IPC Inter Process Communication provide by the OS.
        * An application binary data is loaded in a executable format such as ELF Executable and Linkable  Format used by linux. 
        * With ELF the sections .bss, .data , .rodata and .text sections are always present.
            * The .bss section contains uninitialised data such as empty arrays.
            * The .data section contains initialised data such as variables and global tables.
            * The .rodata is the same of .data but read-only. Store things like hard coded strings.
            * The .text section is where the instructions are. 
    * Lesson 5:
        * Intel Hyper Threading implemented on x86 processors. When the HT is enabled each core on the CPU is presented to the OS as two virtual cores and the hardware manages the task to these cores. It provides a performance improvement without any application or OS optimisation.
    * Lesson 6:
        * Mutual Exclusion or Exclusive Access 
            * Can be implemented by hardware or software. 
            * Hardware: Atomic reads and writes where only one task can obtain access to a shared memory.
            * Software based metal exclusions only work if out-of-order execution of code is disabled. Out-of-Order means that the hardware actively reorders incoming instructions to optimise their execution.
* Section 3:
    * POSIX Threads
        * Pthread rwlock is similar to a mutex except that it allows infinite simultaneous reads and only blocks writes calls.
        * Pthread barrier implements read/write locks and synchronisation barriers. Barriers are sincronization objects that works with a thread count by locking a execution until the thread count number of threads call pthread_barrier _wait()
    * Conditional Variables
        * Allows thread execution to be controlled by another thread.
    * TLS Thread Local Storage
        * Thread local storage are a way to set data associated with a thread using thread specific key.  
* Section 4:
    * The Scheduler
        * Example of how to setup a dispatcher then schedule and synchronise worker threads using mutex and condition variables.
    * Sharing data using rwlocks and shared pointers.
* Section 5:
    * High level abstractions on std lib: Thread, Mutex, Condition Variable, Future and Promise.
    
## Certificate

<p align="center">
  <img src="https://github.com/LucianoPAlmeida/multitheading-cpp-udemy/blob/master/UC-KJZN04FO.jpg" title="Certificate">
</p>

