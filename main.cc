#include "interface.h"
#include "rotor.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string encode(string message, Interface m)
{
    return m.EncodeMessage(message);
}

void menu()
{
    std::vector<Rotor> r {Rotor{"EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A'}, 
                          Rotor{"AJDKSIRUXBLHWTMCQGZNPYFVOE", 'A'}, 
                          Rotor{"BDFHJLCPRTXVZNYEIWGAKMUSQO", 'A'}};

    Rotor refl {"YRUHQSLDPXNGOKMIEBFZCWVJAT", 'A'};

    char input{};
    std::string message{};
    Interface m{r, refl};

    while(true)
    {
        cout << "Choose a menu option" << endl;
        cout << "----------------------" << endl;
        cout << "Current rotor positions: " << m.PrintPositions() << endl;
        cout << "Current plugs: " << m.PrintPlugs() << endl;
        cout << "------------------------------" << endl;
        cout << "1. Set rotor positions" << endl;
        cout << "2. Set plugs" << endl;
        cout << "3. Encode message" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> input;

        if (input == '1')
        {
            m.SetStartPos();
        }
        if (input == '2')
        {
            m.SetPlugs();
        }
        if (input == '3')
        {
            cout << "Write message to encode: ";
            cin >> message;
            message = encode(message, m);
            cout << "Encoded message: " << message << endl;
        }
        if (input == '4')
        {
            break;
        }
    }
}

int main()
{
    std::vector<Rotor> rotor_Types {Rotor{"EKMFLGDQVZNTOWYHXUSPAIBRCJ"}, 
                                    Rotor{"AJDKSIRUXBLHWTMCQGZNPYFVOE"}, 
                                    Rotor{"BDFHJLCPRTXVZNYEIWGAKMUSQO"},
                                    Rotor{"ESOVPZJAYQUIRHXLNFTGKDCMWB"}, 
                                    Rotor{"VZBRGITYUPSDNHLXAWMJQOFECK"}, 
                                    Rotor{"JPGVOUMFYQBENHZRDKASXLICTW"},
                                    Rotor{"NZJHGRCXMYSWBOUFAIVLPEKQDT"}, 
                                    Rotor{"FKQHTLXOCBJSPDZRAMEWNIUYGV"}};
                                    
    Interface m {};
    m.Menu();

    return 0;
}