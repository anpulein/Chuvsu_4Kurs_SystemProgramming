//
// Created by Dmitry Galkin on 07.02.2024.
//

#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include <iostream>
#include <string>
#include <stdarg.h> // Для работы с переменным числом аргументов

// Объявление функции для вывода строк
bool PrintStrings(std::ostream& out, ...);

// Объявление функции для вывода приглашения и чтения ответа
bool ConsolePrompt(const std::string& promptMsg, std::string& response, size_t maxLen, bool echo);

// Объявление функции для вывода одного сообщения
bool PrintMsg(std::ostream& out, const std::string& msg);

#endif //CONSOLE_UTILS_H
