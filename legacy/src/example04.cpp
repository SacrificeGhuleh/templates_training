#include <cstdio>
#include <stdint.h>

class InstanceCounter {
public:
  InstanceCounter() : objectID(getInstanceCounter()) {
    printf("%d. instance created\n", objectID);
  }
  
  ~InstanceCounter() {
    printf("%d. instance removed\n", objectID);
  }
  
  static uint32_t getInstanceCounter() {
    static int instanceCounter = 0;
    return instanceCounter++;
  }
  
  const int objectID;
};

template<class T>
class TemplateClass : InstanceCounter {
};

int main() {
  TemplateClass<int> intTemplateInstance;
  TemplateClass<double> dblTemplateInstance;
  
  return 0;
};