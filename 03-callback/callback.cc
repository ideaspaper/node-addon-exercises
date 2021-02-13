#include <napi.h>
#include <thread>
#include <chrono>

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
    if (info[0].As<Napi::Number>().Int32Value() < 0 || info[0].As<Napi::Number>().Int32Value() > 5) {
        Napi::RangeError::New(env, "Argument(s) out of range").ThrowAsJavaScriptException();
        return false;
    }
    return true;
}

Napi::Value Callback(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    Napi::Function callback = info[1].As<Napi::Function>();

    for (int i = 0; i < info[0].As<Napi::Number>().Int32Value(); i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    callback.Call(env.Global(), {Napi::String::New(env, "String from Addon - Hello World!")});
    return env.Null();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "Callback"), Napi::Function::New(env, Callback));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
