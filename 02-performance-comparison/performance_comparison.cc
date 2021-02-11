#include <napi.h>

bool ArgumentsValidator(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() != 1) {
        Napi::TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return false;
    }
    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return false;
    };
    return true;
}

int FibonacciRecursiveLogic(int n) {
    if (n < 2) return n;
    return FibonacciRecursiveLogic(n - 1) + FibonacciRecursiveLogic(n - 2);
}

Napi::Value FibonacciRecursive(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    int result = FibonacciRecursiveLogic(info[0].As<Napi::Number>().Int32Value());
    return Napi::Number::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "FibonacciRecursive"), Napi::Function::New(env, FibonacciRecursive));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
