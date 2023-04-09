#include "interface.h"
#include "rotor.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //                           ABCDEFGHIJKLMNOPQRSTUVWXYZ
    std::vector<Rotor> r {Rotor{"BDFHJLCPRTXVZNYEIWGAKMUSQO"}, 
                          Rotor{"AJDKSIRUXBLHWTMCQGZNPYFVOE"}, 
                          Rotor{"EKMFLGDQVZNTOWYHXUSPAIBRCJ"}};

    Rotor refl {"YRUHQSLDPXNGOKMIEBFZCWVJAT"};

    Interface m1 {r, refl};
    Interface m2 {r, refl};

    std::string c{};
    std::string message{};
    std::string decoded{};

    std::cin >> message;

    for (auto const& a : message)
    {
        char b = m1.Encode(a);
        c += b;
    }

    std::cout << c << std::endl;

    for (auto const& a : c)
    {
        decoded += m2.Encode(a);
    }
    
    std::cout << std::endl;
    std::cout << decoded << std::endl;

    m1.Print();

    return 0;
}