#include <cstdio>
#include <stdint.h>

template<int I>
struct Fibonacci {
  static void print() {
    printf("%d. fib number is %d\n", I, value);
  };
  static const uint64_t value = Fibonacci<I - 1>::value + Fibonacci<I - 2>::value;
};

template<>
struct Fibonacci<0> {
  static void print() {
    printf("%d. fib number is %d\n", 0, value);
  };
  static const uint64_t value = 0;
};

template<>
struct Fibonacci<1> {
  static void print() {
    printf("%d. fib number is %d\n", 1, value);
  };
  static const uint64_t value = 1;
};

uint64_t fibonacci(int val) {
  switch (val) {
    case 0:return Fibonacci<0>::value;
    case 1:return Fibonacci<1>::value;
    case 2:return Fibonacci<2>::value;
  }
  return 0;
}

static uint64_t fibonacciArray[] = {
    Fibonacci<0>::value,
    Fibonacci<1>::value,
    Fibonacci<2>::value,
    Fibonacci<3>::value,
    Fibonacci<4>::value,
    Fibonacci<5>::value
};

int main() {
  fibonacci(1);
  Fibonacci<7>::print();
  
  printf("Fibonacci: %d", Fibonacci<45>::value);
}