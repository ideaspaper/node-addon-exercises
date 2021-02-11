#ifndef FIBONACCI_WORKER_H_
#define FIBONACCI_WORKER_H_

#include <napi.h>

Napi::Value Calculate(const Napi::CallbackInfo& info);

#endif
