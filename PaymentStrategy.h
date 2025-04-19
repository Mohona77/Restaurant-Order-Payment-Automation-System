#ifndef PAYMENTSTRATEGY_H
#define PAYMENTSTRATEGY_H
#include <iostream>

class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};

class CreditCardPayment : public PaymentStrategy {
public:
    void pay(double amount) override;
};

class CashPayment : public PaymentStrategy {
public:
    void pay(double amount) override;
};

class OnlinePayment : public PaymentStrategy {
public:
    void pay(double amount) override;
};

#endif
