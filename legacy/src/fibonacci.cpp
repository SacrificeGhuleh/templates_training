#include <cstdio>

template <int I>
struct Fibonacci{
  static void print(){};
  static const int value = Fibonacci<I-1>::value + Fibonacci<I-2>::value;
};

template <>
struct Fibonacci<0>{
  static void print(){};
  static const int value = 0;
};

template <>
struct Fibonacci<1>{
  static void print(){};
  static const int value = 1;
};

long long int fibonacci(int val){
  switch (val) {
    case 0:
      return Fibonacci<0>::value;
    case 1:
      return Fibonacci<1>::value;
    case 2:
      return Fibonacci<2>::value;
  }
  return 0;
}

int main() {
  fibonacci(1);
  Fibonacci<7>::print();
  
  printf("Fibonacci: %d", Fibonacci<45>::value);
}