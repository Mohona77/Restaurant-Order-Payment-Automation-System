#ifndef ORDERDECORATOR_H
#define ORDERDECORATOR_H
#include <iostream>
#include <memory>

class BaseOrder {
public:
    virtual void prepare() = 0;
    virtual ~BaseOrder() {}
};

class SimpleOrder : public BaseOrder {
public:
    void prepare() override;
};

class OrderDecorator : public BaseOrder {
protected:
    std::shared_ptr<BaseOrder> wrappee;
public:
    OrderDecorator(std::shared_ptr<BaseOrder> o);
};

class DiscountDecorator : public OrderDecorator {
public:
    DiscountDecorator(std::shared_ptr<BaseOrder> o);
    void prepare() override;
};

class SpecialRequestDecorator : public OrderDecorator {
public:
    SpecialRequestDecorator(std::shared_ptr<BaseOrder> o);
    void prepare() override;
};

#endif
