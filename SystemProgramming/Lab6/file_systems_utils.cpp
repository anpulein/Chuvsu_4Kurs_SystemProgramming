//
// Created by Dmitry Galkin on 16.02.2024.
//

#include "file_systems_utils.h"
#include <iostream>
#include <string>
#include <filesystem> // Требуется для C++17 и выше
#include <fstream>

namespace fs = std::filesystem;
const fs::path PATH_FILES_LAB6 = "../Lab6/resources/";

void printHelp() {
    std::cout << "TestFileDir - прzограмма для демонстрации работы с файлами и каталогами.\n";
    std::cout << "Использование: TestFileDir Имя1 Имя2\n";
    std::cout << "Команды:\n";
    std::cout << "1 - Создать файл/каталог\n";
    std::cout << "2 - Удалить файл/каталог\n";
    std::cout << "3 - Копировать файл/каталог\n";
    std::cout << "4 - Переименовать файл/каталог\n";
    std::cout << "5 - Выйти из программы\n";
    std::cout << "Для получения справки используйте ключ /?.\n";
}

void create(const std::string& name) {
    fs::path PATH_FILES_lAB6;
    // Проверяем, требуется ли создать каталог или файл
    if (fs::is_directory(PATH_FILES_LAB6 / name) || name.find('.') == std::string::npos) {
        // Пытаемся создать каталог
        try {
            if (fs::create_directory(PATH_FILES_LAB6 / name)) {
                std::cout << "Каталог создан: " << name << std::endl;
            } else {
                std::cout << "Не удалось создать каталог: " << name << std::endl;
            }
        } catch (const fs::filesystem_error& e) {
            std::cout << "Ошибка при создании каталога: " << e.what() << std::endl;
        }
    } else {
        // Пытаемся создать файл
        // Проверяем, существует ли каталог
        if (!fs::exists(PATH_FILES_LAB6)) {
            std::cout << "Каталог для создания файла не существует: " << PATH_FILES_LAB6 << std::endl;
        } else {
            std::ofstream file(PATH_FILES_LAB6 / name);
            if (file) {
                std::cout << "Файл создан: " << (PATH_FILES_LAB6 / name) << std::endl;
                file.close();
            } else {
                std::cout << "Не удалось создать файл: " << (PATH_FILES_LAB6 / name) << std::endl;
            }
        }
    }
}

void remove(const std::string& name) {
    try {
        if (fs::remove_all(PATH_FILES_LAB6 / name)) {
            std::cout << "Файл или каталог удален: " << name << std::endl;
        } else {
            std::cout << "Файл или каталог не найден: " << name << std::endl;
        }
    } catch (const fs::filesystem_error& e) {
        std::cout << "Ошибка при удалении: " << e.what() << std::endl;
    }
}

void copy(const std::string& source, const std::string& destination) {
    fs::path PATH_FILES_lAB6;
    try {
        fs::copy(PATH_FILES_LAB6 / source, PATH_FILES_LAB6 / destination, fs::copy_options::recursive);
        std::cout << "Файл или каталог скопирован из " << source << " в " << destination << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cout << "Ошибка при копировании: " << e.what() << std::endl;
    }
}

void rename(const std::string& oldName, const std::string& newName) {
    try {
        fs::rename(PATH_FILES_LAB6 / oldName, PATH_FILES_LAB6 / newName);
        std::cout << "Файл или каталог переименован из " << oldName << " в " << newName << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cout << "Ошибка при переименовании: " << e.what() << std::endl;
    }
}


