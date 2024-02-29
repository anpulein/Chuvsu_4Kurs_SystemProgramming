//
// Created by Dmitry Galkin on 20.02.2024.
//
#include "text_utils.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

void tail(const std::string& filename) {
    std::string full_path = PATH_FILES_lAB7 + filename;
    std::ifstream file(full_path, std::ios::binary | std::ios::ate); // Открываем файл в конце
    if (!file) {
        std::cerr << "Не удается открыть файл: " << filename << std::endl;
        return;
    }

    std::streamsize size = file.tellg(); // Получаем размер файла
    std::vector<std::string> lines; // Вектор для хранения последних строк
    std::string current_line;
    int line_count = 0;

    // Позиционирование с конца файла
    for (std::streamoff i = 1; i <= size && line_count < NUM_LINES + 1; ++i) {
        file.seekg(-i, std::ios::end); // Перемещаем указатель файла
        char c;
        file.read(&c, 1); // Читаем один символ

        // Проверяем символы конца строки (Windows - CR LF, Unix - LF)
        if (c == '\n' || c == '\r' || file.tellg() <= 1) {
            if (!current_line.empty()) {
                lines.push_back(current_line); // Сохраняем строку
                current_line.clear();
                line_count++;
            }
        } else {
            current_line = c + current_line; // Собираем строку в обратном порядке
        }
    }

    // Если файл начинается без новой строки, добавляем последнюю строку в список
    if (!current_line.empty() && lines.size() < NUM_LINES) {
        lines.push_back(current_line);
    }

    // Выводим сохраненные строки
    std::reverse(lines.begin(), lines.end()); // Переворачиваем строки в правильном порядке
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }
}


void getLines(const std::string& filename, int startLine, int numLines) {
    std::string full_path = PATH_FILES_lAB7 + filename;
    std::ifstream file(full_path);
    if (!file) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    std::string line;
    int currentLine = 1; // Номер текущей строки

    // Пропускаем строки до начальной
    while (currentLine < startLine && std::getline(file, line)) {
        ++currentLine;
    }

    // Читаем и выводим нужное количество строк
    while (currentLine < startLine + numLines && std::getline(file, line)) {
        std::cout << line << std::endl;
        ++currentLine;
    }
}
