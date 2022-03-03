#include <fstream>

#ifndef __CAESAR_H___
#define __CAESAR_H___


class Caesar
{
    public:
        void set_encfname(std::string);
        void set_dencfname(std::string);
        void set_enc_num(int);
        void dencryption();
        void encryption();
    private:
        char sym_enc(char);
        char sym_denc(char);
        std::string input {};
        std::string output {};
        int encrip {};
};

#endif