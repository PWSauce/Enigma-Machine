#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor
{
public:
    Rotor(std::string out, char notch);
    Rotor(std::string out, char pos, char notch);

    bool Rotate();
    char Encode(char in);
    char EncodeBack(char in);
    char Position() const;
    void SetPosition(char pos);

    void Print() const;
    std::string Cipher() const;
private:
    std::string const out;
    char pos;
    char notch;
};

#endif // ROTOR_H