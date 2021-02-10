#include <napi.h>
#include <thread>
#include <chrono>

using namespace Napi;

bool ArgumentsValidator(const CallbackInfo& info) {
    Env env = info.Env();
    if (info.Length() != 2) {
        TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return false;
    }
    if (!info[0].IsNumber() || !info[1].IsFunction()) {
        TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return false;
    }
    if (info[0].As<Number>().Int32Value() < 0 || info[0].As<Number>().Int32Value() > 5) {
        RangeError::New(env, "Argument out of range").ThrowAsJavaScriptException();
        return false;
    }
    return true;
}

Value Callback(const CallbackInfo& info) {
    Env env = info.Env();
    if (!ArgumentsValidator(info)) {
        return env.Null();
    }

    Function callback = info[1].As<Function>();

    for (int i = 0; i < info[0].As<Number>().Int32Value(); i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    callback.Call(env.Global(), {Napi::String::New(env, "String from Addon - Hello World!")});
    return env.Null();
}

Object Init(Env env, Object exports) {
    exports.Set(String::New(env, "Callback"), Function::New(env, Callback));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
