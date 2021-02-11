#ifndef FIBONACCI_WORKER_H_
#define FIBONACCI_WORKER_H_

#include <napi.h>

class FibonacciWorker : public Napi::AsyncWorker {
private:
    int n;
    int result;
public:
    FibonacciWorker(int n, Napi::Env &env);
    ~FibonacciWorker();
    void Execute();
    void OnOK();
    Napi::Promise::Deferred deferred;
};

#endif
