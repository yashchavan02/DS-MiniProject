#include "stack.h"

stack::stack() { top = nullptr; }

void stack::push(const std::string &name, double amount) {
  node *ns = new node;
  if (!ns)
    return;
  ns->bill_name = name;
  ns->bill_amount = amount;
  ns->next = top;
  top = ns;
}

void stack::pop() {
  if (!top)
    return;
  node *temp = top;
  top = top->next;
  delete temp;
}

node *stack::Top() { return top; }

bool stack::isEmpty() { return top == nullptr; }