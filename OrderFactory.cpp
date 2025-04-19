#include "OrderFactory.h"
#include <iostream>

// Process methods for different order types
void DineInOrder::process() {
    std::cout << "Processing dine-in order..." << std::endl;
}

void TakeawayOrder::process() {
    std::cout << "Processing takeaway order..." << std::endl;
}

void DeliveryOrder::process() {
    std::cout << "Processing delivery order..." << std::endl;
}

// Factory method to create the correct order based on the type
std::unique_ptr<Order> OrderFactory::createOrder(const std::string& type) {
    if (type == "DineIn") return std::make_unique<DineInOrder>();
    if (type == "Takeaway") return std::make_unique<TakeawayOrder>();
    if (type == "Delivery") return std::make_unique<DeliveryOrder>();
    return nullptr;  // Invalid order type
}
