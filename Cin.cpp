
#include "Cin.h"

std::string Cin::get_cin()
{
    if(m_fg)
        return cin_keyboard();
    std::string t= cin_file();
    std::cout<<t<<std::endl;
    return t;
}

std::string Cin::cin_keyboard()
{
    char s;
    std::string p;
    while(1)
    {
        s = std::cin.get();
        if(s == '\n')
        {
            return p;
        }
        p+=s;
    }
    return p;

}
std::string Cin::cin_file()
{
    std::string ret_s;
    if(!f.eof())
    {
        getline(f,ret_s);
        return ret_s;
    }
    f.close();
    exit(0);
    return "0";
}

