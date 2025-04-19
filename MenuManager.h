#ifndef MENUMANAGER_H
#define MENUMANAGER_H
#include <iostream>
#include <vector>
#include <string>

class MenuManager {
private:
    std::vector<std::string> menuItems;
    MenuManager();

public:
    MenuManager(const MenuManager&) = delete;
    MenuManager& operator=(const MenuManager&) = delete;
    static MenuManager& getInstance();
    void displayMenu();
};

#endif
