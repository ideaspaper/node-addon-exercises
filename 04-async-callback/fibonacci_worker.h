#ifndef FIBONACCI_WORKER_H_
#define FIBONACCI_WORKER_H_

#include <napi.h>

// 1. Inherit from Napi::AsyncWorker
class FibonacciWorker : public Napi::AsyncWorker {
private:
    int n;
    int result;
public:
    // 2. Create constructor and do initialization list as well (see fibonacci_worker.cc file)
    FibonacciWorker(int n, Napi::Function &callback);
    // 3. Create destructor
    ~FibonacciWorker();
    // 4. Override Execute method of Napi::AsyncWorker
    void Execute();
    // 5. Override OnOK method of Napi::AsyncWorker
    void OnOK();
};

#endif