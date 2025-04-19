#include <iostream>
#include <memory>
#include <gtest/gtest.h>
#include "MenuManager.h"
#include "OrderFactory.h"
#include "OrderObserver.h"
#include "PaymentStrategy.h"
#include "ThirdPartyAdapter.h"
#include "OrderDecorator.h"

// Function to demonstrate Singleton Pattern
void demonstrateSingleton() {
    std::cout << "\n--- Singleton Pattern Demonstration ---\n";
    MenuManager& manager1 = MenuManager::getInstance();
    MenuManager& manager2 = MenuManager::getInstance();
    std::cout << "Manager 1 and Manager 2 are the same instance: " 
              << (&manager1 == &manager2 ? "Yes" : "No") << std::endl;
}

// Function to demonstrate Factory Pattern
void demonstrateFactory() {
    std::cout << "\n--- Factory Pattern Demonstration ---\n";
    std::string orderType;
    std::cout << "Enter order type (DineIn / Takeaway / Delivery): ";
    std::cin >> orderType;
    
    auto order = OrderFactory::createOrder(orderType);
    if (order) {
        std::cout << "Created order: " << order->getOrderType() << std::endl;
        order->process();  // Process the order
    } else {
        std::cout << "Invalid order type!" << std::endl;
    }
}

// Function to demonstrate Observer Pattern
void demonstrateObserver() {
    std::cout << "\n--- Observer Pattern Demonstration ---\n";
    OrderNotifier notifier;
    std::string customerName;
    std::cout << "Enter customer name for notification: ";
    std::cin >> customerName;
    
    CustomerObserver customer(customerName);
    notifier.attach(&customer);
    notifier.notify("Order ready");
}

// Function to demonstrate Strategy Pattern
void demonstrateStrategy() {
    std::cout << "\n--- Strategy Pattern Demonstration ---\n";
    int amount;
    std::cout << "Enter the payment amount: ";
    std::cin >> amount;

    std::string paymentMethod;
    std::cout << "Enter payment method (Cash / Card) or type 'Quit' to exit: ";
    std::cin >> paymentMethod;
    
    // If user enters "Quit", exit the function or break out of a loop
    if (paymentMethod == "Quit") {
        std::cout << "Exiting program...\n";
        return; // This will exit the function
    }

    std::shared_ptr<PaymentStrategy> paymentStrategy;
    if (paymentMethod == "Cash") {
        paymentStrategy = std::make_shared<CashPayment>();
    } else if (paymentMethod == "Card") {
        paymentStrategy = std::make_shared<CreditCardPayment>();
    }

    if (paymentStrategy) {
        paymentStrategy->pay(amount);
    } else {
        std::cout << "Invalid payment method!" << std::endl;
    }
}

// Function to demonstrate Adapter Pattern
void demonstrateAdapter() {
    std::cout << "\n--- Adapter Pattern Demonstration ---\n";
    int amount;
    std::cout << "Enter the payment amount using third-party gateway: ";
    std::cin >> amount;

    ThirdPartyPayment thirdParty;
    PaymentAdapter adapter(&thirdParty);
    adapter.pay(amount);
}

// Function to demonstrate Decorator Pattern
void demonstrateDecorator() {
    std::cout << "\n--- Decorator Pattern Demonstration ---\n";
    std::shared_ptr<BaseOrder> simpleOrder = std::make_shared<SimpleOrder>();
    std::shared_ptr<BaseOrder> specialOrder = std::make_shared<SpecialRequestDecorator>(simpleOrder);
    
    specialOrder->prepare();
}







// Test case for Singleton Pattern
TEST(SingletonTest, SingletonInstance) {
    MenuManager& m1 = MenuManager::getInstance();
    MenuManager& m2 = MenuManager::getInstance();
    ASSERT_EQ(&m1, &m2);
}

// Test case for Factory Pattern
TEST(FactoryTest, CreateDineInOrder) {
    auto order = OrderFactory::createOrder("DineIn");
    ASSERT_NE(order, nullptr);
}

// Test case for Observer Pattern
TEST(ObserverTest, NotifyCustomer) {
    OrderNotifier notifier;
    CustomerObserver customer("Mohona");
    notifier.attach(&customer);
    testing::internal::CaptureStdout();
    notifier.notify("Order ready");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Customer [Mohona] notified: Order ready\n");
}

// Test case for Strategy Pattern
TEST(StrategyTest, CashPayment) {
    CashPayment cash;
    testing::internal::CaptureStdout();
    cash.pay(200);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Paid BDT 200 using Cash.\n");
}

// Test case for Adapter Pattern
TEST(AdapterTest, AdapterPayment) {
    ThirdPartyPayment thirdParty;
    PaymentAdapter adapter(&thirdParty);
    testing::internal::CaptureStdout();
    adapter.pay(300);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Paid BDT 300 using Third Party Gateway.\n");
}

// Test case for Decorator Pattern
TEST(DecoratorTest, SpecialRequest) {
    std::shared_ptr<BaseOrder> simple = std::make_shared<SimpleOrder>();
    std::shared_ptr<BaseOrder> special = std::make_shared<SpecialRequestDecorator>(simple);
    testing::internal::CaptureStdout();
    special->prepare();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Preparing base order...\nAdding special request to the order...\n");
}









// Main function for demonstration and test execution
int main(int argc, char** argv) {
    // Run the Google Test framework
    ::testing::InitGoogleTest(&argc, argv);
    
    // Display menu to the user
    int choice;
    do {
        std::cout << "\n==== Design Pattern Demonstration ====\n";
        std::cout << "1. Singleton Pattern\n";
        std::cout << "2. Factory Pattern\n";
        std::cout << "3. Observer Pattern\n";
        std::cout << "4. Strategy Pattern\n";
        std::cout << "5. Adapter Pattern\n";
        std::cout << "6. Decorator Pattern\n";
        std::cout << "7. Run Tests\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                demonstrateSingleton();
                break;
            case 2:
                demonstrateFactory();
                break;
            case 3:
                demonstrateObserver();
                break;
            case 4:
                demonstrateStrategy();
                break;
            case 5:
                demonstrateAdapter();
                break;
            case 6:
                demonstrateDecorator();
                break;
            case 7:
            std::cout << "\nRunning all tests...\n";
            std::cout << "Tests will now be executed...\n"; // Debug message
            return RUN_ALL_TESTS();
              
            case 8:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 8);

    // Return 0 to indicate successful program execution
    return 0;
}
