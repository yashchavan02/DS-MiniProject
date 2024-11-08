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
  if (!front && !back) {
    front = nq;
    back = nq;
    return;
  }
  front->next = nq;
  front = nq;
}

void queue::dequeue() {
  if (!back) {
    return;
  }
  node *temp = back;
  back = back->next;
  if (!back) {
    front = nullptr;
  }
  delete temp;
}

node *queue::Front() { return front; }

node *queue::Back() { return back; }

bool queue::isEmpty() { return front == nullptr; }