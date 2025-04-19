#ifndef THIRDPARTYADAPTER_H
#define THIRDPARTYADAPTER_H
#include "PaymentStrategy.h"

class ThirdPartyPayment {
public:
    void executePayment(double amount);
};

class PaymentAdapter : public PaymentStrategy {
    ThirdPartyPayment* adaptee;
public:
    PaymentAdapter(ThirdPartyPayment* p);
    void pay(double amount) override;
};

#endif
