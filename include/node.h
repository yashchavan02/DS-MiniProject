#ifndef NODE_H
#define NODE_H

#include <string>

struct node {
    std::string bill_name;
    double bill_amount;
    node* next;
};

#endif 
