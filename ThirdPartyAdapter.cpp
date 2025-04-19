#include "ThirdPartyAdapter.h"
#include <iostream>

void ThirdPartyPayment::executePayment(double amount) {
    std::cout << "Paid BDT " << amount << " using Third Party Gateway." << std::endl;
}

PaymentAdapter::PaymentAdapter(ThirdPartyPayment* p) : adaptee(p) {}
void PaymentAdapter::pay(double amount) {
    adaptee->executePayment(amount);
}
