#include <napi.h>

using namespace Napi;

String Hello(const CallbackInfo& info) {
    Env env = info.Env();
    return String::New(env, "Hello");
}

String World(const CallbackInfo& info) {
    Env env = info.Env();
    return String::New(env, "World");
}

// Bagian ini adalah bagian export seperti module.exports pada JavaScript.
Object Init(Env env, Object exports) {
    // Bagian set key-value dari module yang akan di-export.
    // Pada bagian ini yang kita export adalah function.
    exports.Set(String::New(env, "Hello"), Function::New(env, Hello));
    exports.Set(String::New(env, "World"), Function::New(env, World));
    return exports;
}
// Registrasi addon menggunakan INIT function.
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
