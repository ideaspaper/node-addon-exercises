#include <napi.h>
#include "fibonacci_helper.h"

int FibonacciRecursiveLogic(int n) {
    if (n < 2) return n;
    return FibonacciRecursiveLogic(n - 1) + FibonacciRecursiveLogic(n - 2);
}

bool ArgumentsValidator(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return false;
    }
    if (!info[0].IsNumber() || !info[1].IsFunction()) {
        Napi::TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return false;
    }
    if (info[0].As<Napi::Number>().Int32Value() < 0 || info[0].As<Napi::Number>().Int32Value() > 46) {
        Napi::RangeError::New(env, "Argument(s) out of range").ThrowAsJavaScriptException();
        return false;
    }
    return true;
}
