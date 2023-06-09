#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor
{
public:
    Rotor(std::string out);
    Rotor(std::string out, char pos);

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
};

#endif // ROTOR_H