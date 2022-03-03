#include "caesar.h"
#include <iostream>
#include <fstream>
#include <cstring>

char Caesar::sym_enc(char sym)
{
    if (sym >= 'A' && sym <= 'Z' )
    {
        if(sym + (encrip % 26) >= 'A' && sym + (encrip % 26) <= 'Z' )
        {
            return sym + (encrip % 26);    
        }
        else if(sym + (encrip % 26) < 'A')
        {
            return sym+(encrip % 26) + 26;   
        }
        else
        {
            return sym+(encrip % 26) - 26;
        }
        
    }
    if (sym >= 'a' && sym <= 'z' )
    {
        if(sym + (encrip % 26) >= 'a' && sym + (encrip % 26) <= 'z' )
        {
            return sym + (encrip % 26);    
        }
        else if(sym + (encrip % 26) < 'a')
        {
            return sym+(encrip % 26) + 26;   
        }
        else
        {
            return sym+(encrip % 26) - 26;
        }
        
    }
    
    return sym;
}

char Caesar::sym_denc(char sym)
{
    if (sym >= 'A' && sym <= 'Z' )
    {
        if(sym - (encrip % 26) >= 'A' && sym - (encrip % 26) <= 'Z' )
        {
            return sym - (encrip % 26);    
        }
        else if(sym - (encrip % 26) < 'A')
        {
            return sym - (encrip % 26) + 26;   
        }
        else
        {
            return sym + (encrip % 26) - 26;
        }
        
    }
    if (sym >= 'a' && sym <= 'z' )
    {
        if(sym - (encrip % 26) >= 'a' && sym - (encrip % 26) <= 'z' )
        {
            return sym - (encrip % 26);    
        }
        else if(sym - (encrip % 26) < 'a')
        {
            return sym - (encrip % 26) + 26;   
        }
        else
        {
            return sym - (encrip % 26) -  26;
        }
        
    }
    
    return sym;
}

void Caesar::set_encfname(std::string filename) 
{
    input = filename;
}

void Caesar::set_dencfname(std::string filename)
{
    output = filename;
}

void Caesar::set_enc_num(int num) 
{
    encrip = num;
}

void Caesar::encryption()
{
    std::ofstream fout;
    std::ifstream fin;

    fin.open(input);
    if(!fin.is_open())
    {
        std::cout << "Encryption File is not exist" << std::endl;
        return;
    }

    fout.open(output);

    while(!fin.eof())
    {
        std::string tmp_input;
        std::string tmp_output;
        getline(fin, tmp_input);
        for(int i = 0; i < tmp_input.size(); ++i)
        { 
            tmp_output[i] = Caesar::sym_enc(tmp_input[i]);
            fout << tmp_output[i];
        }
        fout << "\n";
    }
}

void Caesar::dencryption()
{
    std::ofstream fout;
    std::ifstream fin;
    fin.open(output);
    if(!fin.is_open())
    {
        std::cout << "Dencryption File is not exist" << std::endl;
        return;
    }

    fout.open(input);

    while(!fin.eof())
    {
        std::string tmp_input;
        std::string tmp_output;
        getline(fin, tmp_input);
        for(int i = 0; i < tmp_input.size(); ++i)
        { 
            tmp_output[i] = Caesar::sym_denc(tmp_input[i]);
            fout << tmp_output[i];
        }
        fout << "\n";
    }
}

int main()
{
    Caesar some;
    some.set_encfname("input.txt");
    some.set_dencfname("output.txt");
    some.set_enc_num(3);
    some.dencryption();

    return 0;
}