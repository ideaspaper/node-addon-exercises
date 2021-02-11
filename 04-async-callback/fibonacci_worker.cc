#include <napi.h>
#include "fibonacci_worker.h"
#include "fibonacci_helper.h"

FibonacciWorker::FibonacciWorker(int n, Function &callback)
    : AsyncWorker(callback), n(n) {}

FibonacciWorker::~FibonacciWorker() {}

void FibonacciWorker::Execute() {
    result = FibonacciRecursiveLogic(n);
}

void FibonacciWorker::OnOK() {
    Callback().Call({Env().Null(), Number::New(Env(), result)});
}
