#ifndef FIBONACCI_WORKER_H_
#define FIBONACCI_WORKER_H_

#include <napi.h>

using namespace Napi;

class FibonacciWorker : public AsyncWorker {
private:
    int n;
    int result;
public:
    FibonacciWorker(int n, Function &callback);
    ~FibonacciWorker();
    void Execute();
    void OnOK();
};

#endif