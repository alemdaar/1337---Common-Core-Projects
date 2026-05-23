#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this == &other)
        return *this;
    _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("could not open database file.");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string rateStr;

        std::getline(ss, date, ',');
        std::getline(ss, rateStr);

        float rate = std::atof(rateStr.c_str());
        _db[date] = rate;
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value, float& result) {
    std::stringstream ss(value);
    ss >> result;

    if (ss.fail())
        return false;
    if (result < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (result > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

float BitcoinExchange::getRate(const std::string& date) {
    std::map<std::string, float>::iterator it = _db.lower_bound(date);

    if (it == _db.end() || it->first != date) {
        if (it == _db.begin())
            throw std::runtime_error("date out of range.");
        --it;
    }
    return it->second;
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("could not open file.");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t pipe = line.find('|');
        if (pipe == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date  = line.substr(0, pipe - 1);
        std::string value = line.substr(pipe + 2);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float amount;
        if (!isValidValue(value, amount))
            continue;

        try {
            float rate = getRate(date);
            std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    file.close();
}