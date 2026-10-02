#include <iostream>
#include <vector>
#include <limits>
#include "truck.h"

void printMenu();
std::vector<Truck>::iterator findTruckWithMaxTax(std::vector<Truck>& trucks, double baseRate);

int main() {
    std::vector<Truck> trucks;
    int choice;

    std::cout << "┌─ ЛР № 4 ───────────────┐\n";
    std::cout << "│  Группа: 6111          │\n";
    std::cout << "│   Автор: Иванов Сергей │\n";
    std::cout << "│ Вариант: 1             │\n";
    std::cout << "└────────────────────────┘\n\n";

    while (true) {
        std::cout << "Грузовики: [";
        for (size_t i = 0; i < trucks.size(); ++i) {
            std::cout << trucks[i];
            if (i != trucks.size() - 1) std::cout << "; ";
        }
        std::cout << "]\n";

        printMenu();
        std::cout << "Выберите пункт меню: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            std::cout << "Неверный ввод\n";
            continue;
        }

        if (choice == 1) {
            int index;
            std::string model;
            double volume, tonnage;

            std::cout << "Введите индекс вставки: ";
            std::cin >> index;

            if (index < 0 || index > static_cast<int>(trucks.size())) {
                std::cout << "Неверный индекс\n";
                continue;
            }

            std::cout << "Введите модель, объем двигателя(в литрах) и тоннаж(в тоннах): ";
            std::cin >> model >> volume >> tonnage;

            Truck truck(model, volume, tonnage);
            trucks.insert(trucks.begin() + index, truck);

        } else if (choice == 2) {
            int index;
            std::cout << "Введите индекс удаления: ";
            std::cin >> index;

            if (index < 0 || index >= static_cast<int>(trucks.size())) {
                std::cout << "Неверный индекс\n";
                continue;
            }

            trucks.erase(trucks.begin() + index);

        } else if (choice == 3) {
            double baseRate;
            std::cout << "Введите базовую ставку налога: ";
            std::cin >> baseRate;

            auto it = findTruckWithMaxTax(trucks, baseRate);
            if (it != trucks.end()) {
                int idx = std::distance(trucks.begin(), it);
                std::cout << "Грузовик с максимальным налогом:\n";
                std::cout << "- Индекс: " << idx << "\n";
                std::cout << "- Модель: " << it->getModel() << "\n";
                std::cout << "- Объем двигателя: " << it->getEngineVolume() << "\n";
                std::cout << "- Тоннаж: " << it->getTonnage() << "\n";
                std::cout << "- Налог: " << it->calculateTax(baseRate) << "\n";
            } else {
                std::cout << "Список грузовиков пуст\n";
            }

        } else if (choice == 4) {
            std::cout << "До свидания!\n";
            break;
        } else {
            std::cout << "Неверный пункт меню\n";
        }

        std::cout << std::endl;
    }

    return 0;
}

void printMenu() {
    std::cout << "[1] Вставить новый грузовик\n";
    std::cout << "[2] Удалить грузовик\n";
    std::cout << "[3] Найти грузовик с максимальным налогом\n";
    std::cout << "[4] Выход\n";
}

std::vector<Truck>::iterator findTruckWithMaxTax(std::vector<Truck>& trucks, double baseRate) {
    if (trucks.empty()) return trucks.end();

    auto maxIt = trucks.begin();
    for (auto it = trucks.begin(); it != trucks.end(); ++it) {
        if (it->calculateTax(baseRate) > maxIt->calculateTax(baseRate)) {
            maxIt = it;
        }
    }
    return maxIt;
}