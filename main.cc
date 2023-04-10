#include "interface.h"
#include "rotor.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //                           ABCDEFGHIJKLMNOPQRSTUVWXYZ
    std::vector<Rotor> r {Rotor{"EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A'}, 
                          Rotor{"AJDKSIRUXBLHWTMCQGZNPYFVOE", 'A'}, 
                          Rotor{"BDFHJLCPRTXVZNYEIWGAKMUSQO", 'A'}};

                    Rotor refl {"YRUHQSLDPXNGOKMIEBFZCWVJAT", 'A'};

    Interface m1 {r, refl};
    Interface m2 {r, refl};

    std::string c{};
    std::string message{};
    std::string decoded{};

    std::cout << "Write rotor start positions: " << std::endl;
    std::cin >> c;
    m1.SetStartPos(c);

    std::cout << "Write messsage: " << std::endl;
    std::cin >> message;
    
    c.clear();
    for (auto a : message)
    {
        c += m1.Encode(a);
    }
    
    std::cout << std::endl;
    std::cout << c << std::endl;

    return 0;
}