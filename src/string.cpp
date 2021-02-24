#include <iostream>
#include <string>

int main() {
    std::cout << "please input your name: ";
    std::string name;
    std::cin >> name;

    const std::string message = "hello " + name + "!";
    const std::string::size_type cols = message.size();

    const std::string spaces(message.size(), ' ');
    const std::string second = "*" + spaces + "*";

    const std::string first(second.size(), '*');

    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << message << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
}
