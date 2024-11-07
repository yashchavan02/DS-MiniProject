#include "queue.h"

queue::queue() {
  front = nullptr;
  back = nullptr;
}

void queue::enqueue(const std::string &name, double amount) {
  node *nq = new node;
  if (!nq)
    return;
  nq->bill_name = name;
  nq->bill_amount = amount;
  nq->next = nullptr;

  if (!back) {
    back = nq;
    front = nq;
  } else {
    back->next = nq;
    back = nq;
  }
}

void queue::dequeue() {
  if (!front)
    return;
  node *temp = front;
  front = front->next;
  if (!front) {
    back = nullptr;
  }
  delete temp;
}

node *queue::Front() { return front; }

node *queue::Back() { return back; }

bool queue::isEmpty() { return front == nullptr; }