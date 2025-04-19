#include "MenuManager.h"

MenuManager::MenuManager() {
    menuItems = {"Pizza", "Burger", "Pasta"};
}

MenuManager& MenuManager::getInstance() {
    static MenuManager instance;
    return instance;
}

void MenuManager::displayMenu() {
    std::cout << "\n--- MENU ---\n";
    for (const auto& item : menuItems) {
        std::cout << item << std::endl;
    }
}
