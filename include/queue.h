#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

class queue {
  node *front;
  node *back;
public:
  queue();
  void enqueue(const std::string &, double);
  void dequeue();
  node *Front();
  node *Back();
  bool isEmpty();
};

#endif
