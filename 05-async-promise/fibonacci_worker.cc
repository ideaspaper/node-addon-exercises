#include <napi.h>
#include "fibonacci_worker.h"
#include "fibonacci_helper.h"

FibonacciWorker::FibonacciWorker(int n, Napi::Env &env)
    : AsyncWorker(env), n(n), deferred(Napi::Promise::Deferred::New(Env())) {}

FibonacciWorker::~FibonacciWorker() {}

void FibonacciWorker::Execute() {
    result = FibonacciRecursiveLogic(n);
}

void FibonacciWorker::OnOK() {
    deferred.Resolve(Napi::Number::New(Env(), result));
}
