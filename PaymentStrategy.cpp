#include "PaymentStrategy.h"

void CreditCardPayment::pay(double amount) {
    std::cout << "Paid BDT " << amount << " using Credit Card." << std::endl;
}

void CashPayment::pay(double amount) {
    std::cout << "Paid BDT " << amount << " using Cash." << std::endl;
}

void OnlinePayment::pay(double amount) {
    std::cout << "Paid BDT " << amount << " via Online Payment." << std::endl;
}
