//
// Created by Dmitry Galkin on 07.02.2024.
//
#include "console_utils.h"
#include <iostream>
#include <string>
#include <stdarg.h>
#include <termios.h>
#include <unistd.h>

bool PrintStrings(std::ostream& out, ...) {
    va_list args;
    va_start(args, out);
    const char* str;
    while ((str = va_arg(args, const char*)) != nullptr) {
        if (out.fail()) {
            va_end(args);
            return false; // В случае ошибки ввода/вывода возвращаем false
        }
        out << str;
    }
    va_end(args);
    return !out.fail(); // Проверяем, не произошла ли ошибка ввода/вывода
}

bool ConsolePrompt(const std::string& promptMsg, std::string& response, size_t maxLen, bool echo) {
    struct termios oldt, newt;

    std::cout << promptMsg;
    if (!echo) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    }

    std::getline(std::cin, response);
    if (response.length() > maxLen) {
        response = response.substr(0, maxLen); // Обрезаем строку, если она слишком длинная
    }

    if (!echo) {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
    return !std::cin.fail(); // Проверяем, не произошла ли ошибка ввода
}

bool PrintMsg(std::ostream& out, const std::string& msg) {
    out << msg << std::endl;
    return !out.fail(); // Проверяем, не произошла ли ошибка ввода/вывода
}


