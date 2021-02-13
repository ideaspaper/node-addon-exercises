#include <napi.h>

Napi::String Hello(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "Hello");
}

Napi::String World(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "World");
}

// Bagian ini adalah bagian export seperti module.exports pada JavaScript.
Napi::Object Init(Napi::Env env, Napi::Object exports) {
    // Bagian set key-value dari module yang akan di-export.
    // Pada bagian ini yang kita export adalah function.
    exports.Set(Napi::String::New(env, "Hello"), Napi::Function::New(env, Hello));
    exports.Set(Napi::String::New(env, "World"), Napi::Function::New(env, World));
    return exports;
}
// Registrasi addon menggunakan INIT function.
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
