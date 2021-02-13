#ifndef HELPER_H_
#define HELPER_H_

#include <napi.h>

int FibonacciRecursiveLogic(int n);
bool ArgumentsValidator(const Napi::CallbackInfo&);

#endif
