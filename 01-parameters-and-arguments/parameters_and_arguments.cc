#include <napi.h>

bool ArgumentsValidator(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() != 2) {
        Napi::TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return false;
    };
    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return false;
    }
    return true;
}

Napi::Value Add(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    double val1 = info[0].As<Napi::Number>().DoubleValue();
    double val2 = info[1].As<Napi::Number>().DoubleValue();
    return Napi::Number::New(env, val1 + val2);
}

Napi::Value Sub(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    double val1 = info[0].As<Napi::Number>().DoubleValue();
    double val2 = info[1].As<Napi::Number>().DoubleValue();
    return Napi::Number::New(env, val1 - val2);
}

Napi::Value Mul(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    double val1 = info[0].As<Napi::Number>().DoubleValue();
    double val2 = info[1].As<Napi::Number>().DoubleValue();
    return Napi::Number::New(env, val1 * val2);
}

Napi::Value Div(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    double val1 = info[0].As<Napi::Number>().DoubleValue();
    double val2 = info[1].As<Napi::Number>().DoubleValue();
    return Napi::Number::New(env, val1 / val2);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "Add"), Napi::Function::New(env, Add));
    exports.Set(Napi::String::New(env, "Sub"), Napi::Function::New(env, Sub));
    exports.Set(Napi::String::New(env, "Mul"), Napi::Function::New(env, Mul));
    exports.Set(Napi::String::New(env, "Div"), Napi::Function::New(env, Div));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);