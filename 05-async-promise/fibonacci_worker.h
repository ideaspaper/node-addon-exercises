#ifndef FIBONACCI_WORKER_H_
#define FIBONACCI_WORKER_H_

#include <napi.h>

// 1. Inherit AsyncWorker
class FibonacciWorker : public Napi::AsyncWorker {
private:
    int n;
    int result;
public:
    // 2. Create constructor
    FibonacciWorker(int n, Napi::Env&);
    // 3. Create destructor
    ~FibonacciWorker();
    // 4. Override Execute
    void Execute();
    // 5. Override OnOK
    void OnOK();
    // 6. Create Napi::Promise::Defered, this will be returned
    Napi::Promise::Deferred deferred;
};

#endif
