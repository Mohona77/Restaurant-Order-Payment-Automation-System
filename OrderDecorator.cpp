#include "OrderDecorator.h"

void SimpleOrder::prepare() {
    std::cout << "Preparing base order..." << std::endl;
}

OrderDecorator::OrderDecorator(std::shared_ptr<BaseOrder> o) : wrappee(o) {}

DiscountDecorator::DiscountDecorator(std::shared_ptr<BaseOrder> o) : OrderDecorator(o) {}
void DiscountDecorator::prepare() {
    wrappee->prepare();
    std::cout << "Applying discount to the order..." << std::endl;
}

SpecialRequestDecorator::SpecialRequestDecorator(std::shared_ptr<BaseOrder> o) : OrderDecorator(o) {}
void SpecialRequestDecorator::prepare() {
    wrappee->prepare();
    std::cout << "Adding special request to the order..." << std::endl;
}
