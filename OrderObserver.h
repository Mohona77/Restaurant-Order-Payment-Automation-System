#ifndef ORDEROBSERVER_H
#define ORDEROBSERVER_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class CustomerObserver : public Observer {
    std::string name;
public:
    CustomerObserver(const std::string& n);
    void update(const std::string& message) override;
};

class StaffObserver : public Observer {
    std::string role;
public:
    StaffObserver(const std::string& r);
    void update(const std::string& message) override;
};

class Subject {
protected:
    std::vector<Observer*> observers;
public:
    void attach(Observer* obs);
    void detach(Observer* obs);
    void notify(const std::string& msg);
};

class OrderNotifier : public Subject {};

#endif
