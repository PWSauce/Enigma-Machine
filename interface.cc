#include "interface.h"
#include "rotor_types.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

Interface::Interface()
    : rotors(), plugs()
{}

Interface::Interface(std::vector<Rotor> const& rotors, Rotor const& refl)
    : rotors(rotors), plugs(), reflector(refl)
{}

Interface::Interface(std::vector<Rotor> const& rotors, std::vector<Plug> const& plugs, Rotor const& refl)
    : rotors(rotors), plugs(plugs), reflector(refl)
{}

char Interface::Encode(char a)
{
    for (Plug & b : plugs)
    {
        std::string p {b.Get_Conn()};

        if (p.at(0) == a)
        {
            a = p.at(1);
            break;
        }
        if (p.at(1) == a)
        {
            a = p.at(0);
            break;
        }
    }

    Rotate();

    a = rotors.at(2).Encode(a);
    a = rotors.at(1).Encode(a);
    a = rotors.at(0).Encode(a);
    a = reflector.Encode(a);
    a = rotors.at(0).EncodeBack(a);
    a = rotors.at(1).EncodeBack(a);
    a = rotors.at(2).EncodeBack(a);

    for (Plug & b : plugs)
    {
        std::string p {b.Get_Conn()};

        if (p.at(0) == a)
        {
            a = p.at(1);
            break;
        }
        if (p.at(1) == a)
        {
            a = p.at(0);
            break;
        }
    }

    return a;
}

std::string Interface::EncodeMessage(std::string const& message)
 {
    std::string c{};
    for (auto a : message)
    {
        c += Encode(a);
    }

    return c;
 }

void Interface::Rotate()
{
    if (rotors.at(2).Rotate())
    {
        if (rotors.at(1).Rotate())
        {
            rotors.at(0).Rotate();
        }
    }
}

void Interface::Menu()
{
    std::string input{};

    SetRotors();

    std::cout << "Welcome to the enigma machine!" << std::endl;
    while(true)
    {
        std::cout << "------------------------------" << std::endl;
        std::cout << "Current rotor positions: " << PrintPositions() << std::endl;
        std::cout << "Current plugs:           " << PrintPlugs() << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "Choose an option from the menu." << std::endl;
        std::cout << "1. Encode/Decode a message." << std::endl;
        std::cout << "2. Set rotor positions." << std::endl;
        std::cout << "3. Set plugs." << std::endl;
        std::cout << "4. Choose rotors." << std::endl;
        std::cout << "5. Exit" << std::endl;

        std::cout << "Choice: ";
        std::cin >> input;

        if (input == "1")
        {
            std::cout << "Write message to encode: ";
            std::cin >> input;
            std::string in;
            std::getline(std::cin, in, '\n');
            input += in;
            std::stringstream ss {input};

            in.clear();
            while (getline(ss, input, ' '))
            {
                in += ' ' + EncodeMessage(input);
            }
            std::cout << "Encoded message: " << in << std::endl << std::endl;
        }
        if (input == "2")
        {
            SetStartPos();
        }
        else if (input == "3")
        {
            SetPlugs();
        }
        else if (input == "4")
        {
            std::cout << "Choose 3 rotors to use" << std::endl;
            SetRotors();
            std::cout << "Rotors chosen: " << std::endl;
            for (auto const& c : rotors)
            {
                std::cout << c.Cipher() << std::endl;
            }
        }
        else if (input == "5")
        {
            break;
        }
    }
}

void Interface::Print() const
{
    for (auto const& a : rotors)
    {
        a.Print();
    }
}

std::string Interface::PrintPositions() const
{
    std::string positions{};
    for (auto a : rotors)
    {
        positions += a.Position();
    }

    return positions;
}

std::string Interface::PrintPlugs() const
{
    std::string p{};

    for (auto a : plugs)
    {
        p += a.Get_Conn();
        p += ' ';
    }

    return p;
}

void Interface::SetStartPos()
{
    int idx{};
    std::string text{};
    std::cout << "Write rotor start positions: " << std::endl;
    std::cin >> text;

    for (char c : text)
    {
        rotors.at(idx).SetPosition(c);
        ++idx;
    }
    
}

void Interface::SetPlugs()
{
    std::string pl{};
    std::string c{};

    std::cout << "Write plugs in AB format separated with blankspaces:" << std::endl;
    std::cin >> pl;
    std::getline(std::cin, c, '\n');
    pl += c;

    std::stringstream ss {pl};
    std::string p {};

    while(getline(ss, p, ' '))
    {
        plugs.push_back(Plug(p.at(0), p.at(1)));
    }
}

void Interface::SetRotors()
{
    rotors.clear();
    RotorTypes ro{};
    int i{};

    for (auto const& a : ro.rotor_Types)
    {
        ++i;
        std::cout << i << ". " << a.Cipher() << std::endl;
    }

    std::cout << "Left most rotor: ";
    std::cin >> i;
    rotors.push_back(ro.rotor_Types.at(i - 1));

    std::cout << "Middle rotor: ";
    std::cin >> i;
    rotors.push_back(ro.rotor_Types.at(i - 1));

    std::cout << "Right most rotor: ";
    std::cin >> i;
    rotors.push_back(ro.rotor_Types.at(i - 1));
}