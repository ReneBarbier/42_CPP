#include "harl.hpp"

Harl::Harl(void)
{
    std::cout << "Hi, I'm Harl" << std::endl;
}

Harl::~Harl(void)
{
}

void Harl::debug()
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my ";
    std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.";
    std::cout << "I really do!\n" << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money.";
    std::cout << "You didn't put enough! If you did I would not have to ask for it!";
    std::cout << "\n" << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.";
    std::cout << "I've been coming here for years and you just started working here last month.";
    std::cout << "\n" << std::endl;
}

void Harl::error()
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable. I want to speak to the manager.";
    std::cout << "\n" << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*complaint[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"debug", "info", "warning", "error"};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*complaint[i])();
            return ;
        }
    }
}