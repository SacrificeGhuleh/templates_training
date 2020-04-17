#include <iostream>
#include <utils.h>

void print(int value) {
  printf("Value is %d\n", value);
}

void print(double value) {
  printf("Value is %f\n", value);
}

void print(const char *value) {
  printf("Value is %s\n", value);
}


//template <typename T>
template<class T>
void templatePrint(T value, const char *format) {
  printf("Value is: ");
  printf(format, value);
  printf("\n");
}

//template<class T>
//void willYouSpotError(T value, const char *format) {
//  printf("Value is: ");
//  printf(fomrat, value);
//  printf("\n");
//}

int main(int argc, char **argv) {
  
  print(10);
  print(3.14);
  print("Hello, ZF");
  
  printf("\n");
  
  templatePrint<int>(10, "%d");
  templatePrint<double>(3.14, "%f");
  templatePrint<const char *>("Hello, ZF", "%s");
  
  printf("\n");
  
  // C++ compilers are able to deduce types, so it is not necessary to explicitly write type.
  // IMHO it is more robust in debugging to explicitly write a type.
  
  templatePrint<>(10, "%d");
  templatePrint(3.14, "%f");
  templatePrint("Hello, ZF", "%d");
  
  printf("\nWhy is the last print incorrect?");
  
  return 0;
}