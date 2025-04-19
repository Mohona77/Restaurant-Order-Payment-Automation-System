#ifndef ORDERFACTORY_H
#define ORDERFACTORY_H

#include <memory>
#include <string>

class Order {
public:
    virtual void process() = 0;
    virtual std::string getOrderType() const = 0;  // Declaration of the method
    virtual ~Order() = default;
};

class DineInOrder : public Order {
public:
    void process() override;
    std::string getOrderType() const override { return "DineIn"; }
};

class TakeawayOrder : public Order {
public:
    void process() override;
    std::string getOrderType() const override { return "TakeAway"; }
};

class DeliveryOrder : public Order {
public:
    void process() override;
    std::string getOrderType() const override { return "Delivery"; }
};

class OrderFactory {
public:
    static std::unique_ptr<Order> createOrder(const std::string& type);
};

#endif
