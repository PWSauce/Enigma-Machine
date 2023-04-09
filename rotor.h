#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor
{
public:
    Rotor(std::string out);

    bool Rotate();
    char Encode(char in);
    char EncodeBack(char in);
    char Position() const;

    void Print() const;
private:
    std::string out;
    char startPos;
};

#endif // ROTOR_H