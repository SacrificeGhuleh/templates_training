# Templates training
## What are templates?
If you are familiar with other languages like **Java** or **C#**, you may see templates as some kind of generics.
 
``` Java
public interface List<E> { 
  void add(E x);
  Iterator<E> iterator();
}

public interface Iterator<E> { 
  E next();
  boolean hasNext();
}
```
Templates in C++ are completely different _(Well, not completely, but they are different a lot.)_. You may look at templates as some kind of macro. WIth templates, you can do pretty much anything. Templates are really extensive topic and we don´t have any chance to cover all functionality in one lecture. 

Template is... well template, that will be compiled dynamically, according to usage. Basically, compiler is writing code with some set of rules (pre-defined source in template).

## Use cases
### I want to have mostly same function, but with different types
Let's say, I want to print various data types, each slightly differently. I may implement overloaded functions, but most of the code would be redundant. It is good practice avoid code redundancy to minimum. One of the problems we may be dealing in the future is possible need for refactoring. For example, API may have changed and we would have to manually change our code in all overloaded functions (Let's assume here, we do not use automatic refactoring tools). 

This could be simplified using template. Take a look at _/legacy/src/example01.cpp_

Actually, templates are not actual code, templates gets created during compilation. Each combination of parameter is going to create separate function. If you have compiled example code (with gcc), you can take a look, which functions were compiled.
 ```
nm -A -C templates_98_example01.exe  > dump.log
```
 And here's interesting fact, msvc compiler does not compile unused template and all. This means, if you make syntax error in template and you never use it, your program will compile just fine. On the other hand, gcc checks for error even in non-used templates.

### Replacement of macro functions
The two worst and most dangerous things in the Earth are macros **MIN** and **MAX**. According to **Effective C++**, you should definitely stay away from macro functions.  
First problem with macro functions is that macro functions does not check types. This may lead to undefined behaviour.
Second problem is that macros are not really functions. They are copy & paste tool for the compiler. This can be very powerful, but also very dangerous. 
### When should I use templates? 
Well, this is complicated question. Templates are really powerful, but they can get really messy really quickly. There are some people who claims, you should never **ever** use templates. Well, in my personal opinion, you cannot be more wrong :) If you have for example some function that takes every possible data type, do you really want to write every possible overload? Really? Well, good luck with that, but I would automate it with templates.

On the other hand, there is certain point, where templates will get too complex and debugging will become a nightmare. If you have created some monsterous templates and you are at the point, where you don't know what exactly is compiling, you have gone too far. 

## Interesting use cases
### Compile time computation
In practice useless example, but great to think through. 
#### Fibonacci number
Common method how to compute fibonacci is following code: 
``` cpp
int fibonacci(int val){
  if(val == 0) return 0;
  if(val == 1) return 1;
  return fibonacci(val - 1) + fibonacci(val - 2);
}
```
This method is certainly **NOT** effective. Better solution is to cache fibonacci values and create them at initialization, or at compile time. This can be done by googling list  of fibonacci numbers, or by computing it at compile time. 

Take a look at _/legacy/src/fibonacci.cpp_

##### Homework
Create implementation of template factorial.

## Static variables and templates
Each initialization of template has its own static variables. This could lead to unwanted bahaviour, but also it can be used in our favor. 

Take a look at _/legacy/src/example04.cpp_ and _/legacy/src/example05.cpp_ 
### Homework
When creating new instance, instance counter prints object ID. Print also datatype when creating instance using provided `TypePrinter` class.
