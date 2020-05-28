#include <cstdio>
#include <stdint.h>

template<class T>
class TypePrinter {
};

template<>
class TypePrinter<int> {
public:
  static const char *getType() {
    return "int";
  }
};

template<>
class TypePrinter<float> {
public:
  static const char *getType() {
    return "float";
  }
};

template<>
class TypePrinter<double> {
public:
  static const char *getType() {
    return "double";
  }
};

template<class T>
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
class TemplateClass : InstanceCounter<TemplateClass<T> > {
};

int main() {
  printf("Creating integers\n");
  TemplateClass<int> intTemplateInstance;
  TemplateClass<int> intAnotherTemplateInstance;
  printf("\nCreating doubles\n");
  TemplateClass<double> dblTemplateInstance;
  TemplateClass<double> dblAnotherTemplateInstance;
  
  
  printf("\nCreating floats\n");
  TemplateClass<float> arrayOf20Floats[20];
  
  printf("\n");
  return 0;
}
