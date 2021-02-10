#include <napi.h>

using namespace Napi;

bool ArgumentsValidator(const CallbackInfo& info) {
    Env env = info.Env();
    if (info.Length() != 1) {
        TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return false;
    }
    if (!info[0].IsNumber()) {
        TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return false;
    };
    return true;
}

int FibonacciRecursiveLogic(int n) {
    if (n < 2) return n;
    return FibonacciRecursiveLogic(n - 1) + FibonacciRecursiveLogic(n - 2);
}

Value FibonacciRecursive(const CallbackInfo& info) {
    Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    int result = FibonacciRecursiveLogic(info[0].As<Number>().Int32Value());
    return Number::New(env, result);
}

Object Init(Env env, Object exports) {
    exports.Set(String::New(env, "FibonacciRecursive"), Function::New(env, FibonacciRecursive));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
