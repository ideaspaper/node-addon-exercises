#ifndef FIBONACCI_HELPER_H_
#define FIBONACCI_HELPER_H_

#include <napi.h>

int FibonacciRecursiveLogic(int);
bool ArgumentsValidator(const Napi::CallbackInfo&);

#endif
