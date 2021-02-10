#include <napi.h>

using namespace Napi;

bool ArgumentsValidator(const CallbackInfo& info) {
    Env env = info.Env();
    if (info.Length() != 2) {
        TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return false;
    };
    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return false;
    }
    return true;
}

Value Add(const CallbackInfo& info) {
    Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    double val1 = info[0].As<Number>().DoubleValue();
    double val2 = info[1].As<Number>().DoubleValue();
    return Number::New(env, val1 + val2);
}

Value Sub(const CallbackInfo& info) {
    Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    double val1 = info[0].As<Number>().DoubleValue();
    double val2 = info[1].As<Number>().DoubleValue();
    return Number::New(env, val1 - val2);
}

Value Mul(const CallbackInfo& info) {
    Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    double val1 = info[0].As<Number>().DoubleValue();
    double val2 = info[1].As<Number>().DoubleValue();
    return Number::New(env, val1 * val2);
}

Value Div(const CallbackInfo& info) {
    Env env = info.Env();
    if (!ArgumentsValidator(info)) return env.Null();

    double val1 = info[0].As<Number>().DoubleValue();
    double val2 = info[1].As<Number>().DoubleValue();
    return Number::New(env, val1 / val2);
}

Object Init(Env env, Object exports) {
    exports.Set(String::New(env, "Add"), Function::New(env, Add));
    exports.Set(String::New(env, "Sub"), Function::New(env, Sub));
    exports.Set(String::New(env, "Mul"), Function::New(env, Mul));
    exports.Set(String::New(env, "Div"), Function::New(env, Div));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);