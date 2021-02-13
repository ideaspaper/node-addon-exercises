#ifndef USER_H_
#define USER_H_

#include <napi.h>

// 1. Inherit ObjectWrap
class User : public Napi::ObjectWrap<User> {
public:
    // 2. Create constructor
    User(const Napi::CallbackInfo&);
    // 3. Declare the methods needed
    Napi::Value Greet(const Napi::CallbackInfo&);
    Napi::Value GetName(const Napi::CallbackInfo&);
    Napi::Value GetAge(const Napi::CallbackInfo&);
    Napi::Value GetJob(const Napi::CallbackInfo&);
    Napi::Value SetJob(const Napi::CallbackInfo&);
    // 4. Create GetClass method to be used in Init
    static Napi::Function GetClass(Napi::Env);
private:
    std::string name;
    std::uint32_t age;
    std::string job;
};

#endif
