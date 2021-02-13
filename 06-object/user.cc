#include <napi.h>
#include "user.h"

User::User(const Napi::CallbackInfo &info)
    : ObjectWrap(info) {
    Napi::Env env = info.Env();

    if (info.Length() != 3) {
        Napi::TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsString() || !info[1].IsNumber() || !info[2].IsString()) {
        Napi::TypeError::New(env, "Wrong argument(s)").ThrowAsJavaScriptException();
        return;
    }

    this->name = info[0].As<Napi::String>().Utf8Value();
    this->age = info[1].As<Napi::Number>().Uint32Value();
    this->job = info[2].As<Napi::String>().Utf8Value();
}

Napi::Value User::Greet(const Napi::CallbackInfo &info) {
    return Napi::String::New(info.Env(), "Greeting! My name is " + this->name + ", my Age is " + std::to_string(this->age) + ", and my job is " + this->job);
}

Napi::Value User::GetName(const Napi::CallbackInfo &info) {
    return Napi::String::New(info.Env(), this->name);
}

Napi::Value User::GetAge(const Napi::CallbackInfo &info) {
    return Napi::Number::New(info.Env(), this->age);
}

Napi::Value User::GetJob(const Napi::CallbackInfo &info) {
    return Napi::String::New(info.Env(), this->job);
}

Napi::Value User::SetJob(const Napi::CallbackInfo &info) {
    if (info.Length() != 1) {
        Napi::TypeError::New(info.Env(), "Wrong Argument(s)").ThrowAsJavaScriptException();
        return info.Env().Null();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(info.Env(), "Wrong Argument(s)").ThrowAsJavaScriptException();
        return info.Env().Null();
    }

    this->job = info[0].As<Napi::String>().Utf8Value();
    return info.Env().Null();
}

Napi::Function User::GetClass(Napi::Env env) {
    // JavaScript code will have access to the methods listed here
    return DefineClass(env, "User", {
        User::InstanceMethod("Greet", &User::Greet),
        User::InstanceMethod("GetName", &User::GetName),
        User::InstanceMethod("GetAge", &User::GetAge),
        User::InstanceMethod("GetJob", &User::GetJob),
        User::InstanceMethod("SetJob", &User::SetJob)
    });
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "User"), User::GetClass(env));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
