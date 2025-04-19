#include "OrderObserver.h"

CustomerObserver::CustomerObserver(const std::string& n) : name(n) {}
void CustomerObserver::update(const std::string& message) {
    std::cout << "Customer [" << name << "] notified: " << message << std::endl;
}

StaffObserver::StaffObserver(const std::string& r) : role(r) {}
void StaffObserver::update(const std::string& message) {
    std::cout << "Staff [" << role << "] notified: " << message << std::endl;
}

void Subject::attach(Observer* obs) {
    observers.push_back(obs);
}
void Subject::detach(Observer* obs) {
    observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
}
void Subject::notify(const std::string& msg) {
    for (auto& obs : observers) {
        obs->update(msg);
    }
}
