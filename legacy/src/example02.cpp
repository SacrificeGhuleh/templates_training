#include <iostream>
#include <utils.h>
#include <cstdlib>

const static unsigned long seed = 120;

namespace macros {
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
#define SQR(a) a * a
};

template<class T>
T tmax(T a, T b) {
  return a > b ? a : b;
}

template<class T>
T tmin(T a, T b) {
  return a < b ? a : b;
}

template<class T>
T tsqr(T a) {
  return a * a;
}

int main(int argc, char **argv) {
  //////////////////////////////////////////////////////////////////////////////
  // Print 15 random integers, 10 or higher.
  //////////////////////////////////////////////////////////////////////////////
  srand(seed);
  for (int i = 0; i < 15; i++) {
    printf("%d  ", MAX(random(0, 20), 10));
  }
  
  printf("\nWhat happened here?\n\n");
  printf("Know your API :] \n\n");
  
  srand(seed);
  for (int i = 0; i < 15; i++) {
    printf("%d  ", MAX((int) random(0, 20), 10));
  }
  /*
   * Macro MAX will get expanded into this:
   * 1. MAX(a, b) a > b ? a : b
   * 2. random(0, 20) > 10 ? random(0, 20) : 10
   *
   * Ternary operator is making following decision:
   *
   * if(random(0, 20) > 10)
   *   return random(0, 20);
   * else
   *   return 10;
   *
   *   Random function is called twice!
   */
  
  printf("\n\nWhy are values smaller than 10 printed?\n\n");
  
  srand(seed);
  for (int i = 0; i < 15; i++) {
    printf("%d  ", tmax<int>(random(0, 20), 10));
  }
  
  printf("\n\n");
  
  //////////////////////////////////////////////////////////////////////////////
  // Print square if integers 2 - 9
  //////////////////////////////////////////////////////////////////////////////
  
  int valToBeSquared = 2;
  while (valToBeSquared <= 9) {
    printf("Value: %d, ", valToBeSquared);
    printf("Square: %d\n", SQR(valToBeSquared++));
  }
  
  printf("\nWhy are values incorrect?\n\n");
  
  valToBeSquared = 2;
  while (valToBeSquared <= 9) {
    printf("Value: %d, ", valToBeSquared);
    printf("Square: %d\n", tsqr(valToBeSquared++));
  }
  
  //////////////////////////////////////////////////////////////////////////////
  // Print another square
  //////////////////////////////////////////////////////////////////////////////
  
  printf("Square of 3 + 2 = %d\n", SQR(3 + 2));
  printf("Square of 3 + 2 = %d\n", tsqr(3 + 2));
  
  /*
   * SQR macro is expanded into this:
   * 1. SQR(a) a * a
   * 2. 3 + 2 * 3 + 2
   * */
}