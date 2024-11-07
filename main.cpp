#include "queue.h"
#include "stack.h"

#include <iostream>
using namespace std;

stack s;
queue q;

double remaining_amount = 0;
double paid_amount = 0;

void display(node *n) {
  cout << endl << "$ Bill Name   : " << n->bill_name << " Bill." << endl;
  cout << "$ Bill Ammout : " << n->bill_amount << " Rs." << endl;
}

void generate_bill() {
  int bill_choice;
  string bill[] = {"Electricity", "Water",     "Gas",   "Internet",
                   "Cable/TV",    "Insurance", "Custom"};
  cout << endl;
  int size = sizeof(bill) / sizeof(string);
  for (int i = 0; i < size; i++) {
    cout << i + 1 << ". " << bill[i] << " Bill" << endl;
  }
  cout << endl << "? input here : ";
  cin >> bill_choice;
  if (bill_choice <= 0 || bill_choice >= size) {
    bill_choice = size;
    cout << endl << "$ Enter Custom Bill Name : ";
    cin >> bill[bill_choice - 1];
  }
  string name = bill[bill_choice - 1];
  double ammount;
  cout << "$ Enter " << name << " Bill Ammount In Rs. : ";
  cin >> ammount;
  cout << endl;
  q.enqueue(name, ammount);
  remaining_amount += ammount;
}

void pay_bill() {
  if (!q.Back()) {
    cout << endl << "$ There is no payment remaining to pay " << endl << endl;
    return;
  }
  node *n = q.Back();
  display(n);
  paid_amount += n->bill_amount;
  remaining_amount -= n->bill_amount;
  if (remaining_amount < 0) {
    remaining_amount = 0;
  }
  if (paid_amount < 0) {
    paid_amount = 0;
  }
  cout << endl << "$ Payment Successful" << endl << endl;
  s.push(n->bill_name, n->bill_amount);
  q.dequeue();
}

void view_pending_bill() {
  node *n = q.Back();
  if (!n) {
    cout << endl << "$ There is no pending payment" << endl << endl;
    return;
  }
  cout << endl << "-------< pending payments >-------" << endl;
  while (n) {
    display(n);
    n = n->next;
  }
  cout << endl << "----------------------------------" << endl;
}

void view_paid_bill() {
  node *n = s.Top();
  if (!n) {
    cout << endl << "$ There is no paid payment" << endl << endl;
    return;
  }
  cout << endl << "-------< paid payments >-------" << endl;
  while (n) {
    display(n);
    n = n->next;
  }
  cout << endl << "----------------------------------" << endl;
}

void check_pending_bill_amout() {
  if (!remaining_amount) {
    cout << endl << "$ There is no pending bill" << endl << endl;
    return;
  }
  cout << endl
       << "$ The pending bill amount is " << remaining_amount << " Rs." << endl
       << endl;
}

void check_paid_bill_amout() {
  if (!paid_amount) {
    cout << endl << "$ There is no paid bill amount" << endl << endl;
    return;
  }
  cout << endl
       << "$ The paid bill amount is " << paid_amount << " Rs." << endl
       << endl;
}

void delete_bill_payment_history() {
  node *n = s.Top();
  if (!n) {
    cout << endl << "$ There is no bill payment history exist" << endl << endl;
    return;
  }
  while (n) {
    s.pop();
    n = s.Top();
  }
  paid_amount = 0;
  cout << endl << "$ The bill payment history is cleared successful." << endl;
}

int main() {
  char start;
  cout << endl << "--------< Welcome To Bill Tracker >--------" << endl << endl;
  cout << "$ Please Press 's' To Start Track The Bills." << endl;
  while (true) {
    cout << "? input here : ";
    cin >> start;
    if (start == 's' || start == 'S')
      break;
    cout << "$ invalid input | please try again." << endl;
  }
  int ui;
  while (true) {
    cout << endl
         << endl
         << "--------< Main Menu >--------" << endl
         << endl
         << "1. Generate Bill" << endl
         << "2. Pay Bill" << endl
         << "3. View Pending Bill" << endl
         << "4. View Paid Bill" << endl
         << "5. Check Pending Bill Ammout" << endl
         << "6. Check Paid Bill Ammout" << endl
         << "7. Delete Bill Payment History" << endl
         << "8. Exit" << endl
         << endl;
    cout << "? main input here : ";
    cin >> ui;
    switch (ui) {
    case 1:
      generate_bill();
      break;
    case 2:
      pay_bill();
      break;
    case 3:
      view_pending_bill();
      break;
    case 4:
      view_paid_bill();
      break;
    case 5:
      check_pending_bill_amout();
      break;
    case 6:
      check_paid_bill_amout();
      break;
    case 7:
      delete_bill_payment_history();
      break;
    default:
      cout << endl << "$ Thank's For Visit Our Platform." << endl << endl;
      return 0;
    }
  }
}