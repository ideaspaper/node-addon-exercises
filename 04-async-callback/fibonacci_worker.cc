#include <napi.h>
#include "fibonacci_worker.h"
#include "fibonacci_helper.h"

// Since AsyncWorker has no default constructor, decide which constructor to be called with initialization list
// Use initialization list to set FibonacciWorker properties as well
FibonacciWorker::FibonacciWorker(int n, Napi::Function &callback)
    : AsyncWorker(callback), n(n) {}

FibonacciWorker::~FibonacciWorker() {}

void FibonacciWorker::Execute() {
    result = FibonacciRecursiveLogic(n);
}

void FibonacciWorker::OnOK() {
    Callback().Call({Env().Null(), Napi::Number::New(Env(), result)});
}
