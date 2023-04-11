#ifndef PLUG_H
#define PLUG_H

#include <string>

class Plug
{
public:
    Plug();
    Plug(char a_conn, char b_conn);
    Plug(std::string const& connections);

    std::string Get_Conn() const;
private:
    char a;
    char b;
};

#endif // PLUG_H