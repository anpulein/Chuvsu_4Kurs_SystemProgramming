//
// Created by Dmitry Galkin on 02.02.2024.
//


#include "cpC_files.h"
#include <vector>
#include <sys/time.h>
using namespace Lab1;
using namespace std;

// Функция для измерения текущего времени в миллисекундах
long long File::getCurrentTimeMillis() {
    timeval tv{};
    gettimeofday(&tv, nullptr);
    return (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
}


string File::read_file() {

    string line;
    string data;
    ifstream in(IN_PATH_FILE, ios::binary);

    if (in.is_open()) {
        while (getline(in, line)) {
            data += line;
        }
    }

    in.close();

    return data;
}

string File::read_file(string nameFile) {

    string line;
    string data;
    ifstream in(IN_PATH_FILE + nameFile, ios::binary);

    if (in.is_open()) {
        while (getline(in, line)) {
            data += line;
        }
    }

    in.close();

    return data;
}

void File::write_file(string data) {

    ofstream out(OUT_PATH_FILE);
    if(out.is_open()) {
        out << data;
    }

    out.close();
}

void File::write_file(string data, string nameFile) {

    ofstream out(OUT_PATH_FILE + nameFile);
    if(out.is_open()) {
        out << data;
    }

    out.close();
}

