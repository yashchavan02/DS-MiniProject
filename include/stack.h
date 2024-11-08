#ifndef STACK_H
#define STACK_H

#include "node.h"

class stack {
  node *top;
public:
  stack();
  void push(const std::string &, double);
  void pop();
  node *Top();
  bool isEmpty();
};

#endif
