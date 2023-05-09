#ifndef CIN_H
#define CIN_H
#include <iostream>
#include <string>
#include <fstream>

class Cin
{
private:
    /* data */
    bool m_fg = false; 

    std::ifstream f;
public:
    std::string get_cin();

    std::string cin_keyboard();
    std::string cin_file();

    Cin(std::string path,bool fg):m_fg(fg){ 
        if(path != "")
        {
            f.open(path,std::ios::in);
            if(!f.is_open())  
            std::cout<<"open "<<path<<" ERR"<<std::endl;
        }
    }

    ~Cin(){};
};


#endif