#ifndef HELPER_H_
#define HELPER_H_

#include <napi.h>

using namespace Napi;

int FibonacciRecursiveLogic(int n);
bool ArgumentsValidator(const CallbackInfo& info);

#endif