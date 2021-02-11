#include <napi.h>
#include "fibonacci_worker.h"

using namespace Napi;

int FibonacciRecursiveLogic(int n) {
    if (n < 2) return n;
    return FibonacciRecursiveLogic(n - 1) + FibonacciRecursiveLogic(n - 2);
}

class FibonacciWorker : public AsyncWorker {
public:
    FibonacciWorker(int n, Function &callback)
        : AsyncWorker(callback), n(n) {}
    ~FibonacciWorker() {}

    void Execute() {
        result = FibonacciRecursiveLogic(n);
    }

    void OnOK() {
        Callback().Call({Env().Null(), Number::New(Env(), result)});
    }

private:
    int n;
    int result;
};

bool ArgumentsValidator(const CallbackInfo& info) {
    Env env = info.Env();
    if (info.Length() != 2) {
        TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return false;
    }
    if (!info[0].IsNumber() || !info[1].IsFunction()) {
        TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return false;
    }
    if (info[0].As<Number>().Int32Value() < 0 || info[0].As<Number>().Int32Value() > 46) {
        RangeError::New(env, "Argument(s) out of range").ThrowAsJavaScriptException();
        return false;
    }
    return true;
}

Value Calculate(const CallbackInfo& info) {
    Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    int n = info[0].As<Number>().Int32Value();
    Function callback = info[1].As<Function>();
    FibonacciWorker* fibonacciWorker = new FibonacciWorker(n, callback);
    fibonacciWorker->Queue();
    return env.Null();
}