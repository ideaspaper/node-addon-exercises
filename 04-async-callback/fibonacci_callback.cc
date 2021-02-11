#include <napi.h>
#include "fibonacci_worker.h"
#include "fibonacci_helper.h"

Napi::Value Calculate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    int n = info[0].As<Napi::Number>().Int32Value();
    Napi::Function callback = info[1].As<Napi::Function>();
    FibonacciWorker* fibonacciWorker = new FibonacciWorker(n, callback);
    fibonacciWorker->Queue();
    return env.Null();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "Calculate"), Napi::Function::New(env, Calculate));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)