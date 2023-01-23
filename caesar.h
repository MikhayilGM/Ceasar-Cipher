#ifndef __CAESAR_H___
#define __CAESAR_H___

#include <fstream>

class Caesar
{
    private:
        void dencryption();
        void encryption();
        char sym_enc(char);
        char sym_denc(char);
    public:
        void set_encfname(std::string);
        void set_dencfname(std::string);
        void set_enc_num(int);
    
    private:

        std::string input {};
        std::string output {};
        int encrip {};
};

#endif
