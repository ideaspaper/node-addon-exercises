#include <napi.h>
#include "fibonacci_worker.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "Calculate"), Napi::Function::New(env, Calculate));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)