//
// Created by cao on 19-7-2.
//

#ifndef STRLIB_H
#define STRLIB_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>

namespace std
{
    class Error : public std::exception
    {

        std::string _M_msg;

    public:
        explicit

        Error(const std:: string& __arg):_M_msg(__arg){};

        const char* what() const noexcept
        {
            return _M_msg.c_str();
        };

    };

    extern inline void lstrip_(std::string &s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
        }));
    }

    extern inline void rstrip_(std::string &s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch){
            return !std::isspace(ch);}
            ).base(), s.end()
            );
    }

    extern inline void strip_(std::string &s)
    {
        lstrip_(s);
        rstrip_(s);
    }

    extern inline std::string lstrip(std::string s)
    {
        lstrip_(s);
        return s;
    }

    extern inline std::string rstrip(std::string s)
    {
        rstrip_(s);
        return s;
    }

    extern inline std::string strip(std::string s)
    {
        strip_(s);
        return s;
    }

    extern inline std::string replace(std::string s ,const std::string &org, const std::string &dest)
    {
        int  cur1=s.find(org);
        int  cur2=org.size();
        if (cur1 == -1)
        {
            ostringstream err_out;
            err_out << "can't find \"" << org <<  "\" in \"" << s << "\" " << std::endl;
            throw Error(err_out.str());
            return nullptr;
        }
        s.erase(cur1,cur2);
        s.insert(cur1,dest);
        return s;
    }

    extern inline std::vector<std::string> split(const std::string &s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    template<class ... str>
    std::string join(str... strlist)
    {
        int size= sizeof...(str);
        if(size < 1)
        {   ostringstream err_out;
            err_out << "no param" << std::endl;
            throw Error(err_out.str());
            return nullptr;
        }
        std::initializer_list<std::string> T={strlist...};
        std::string reslut;
        for(auto &t:T)reslut=reslut+"/"+t;
        reslut.erase(0,1);
        return reslut;
    }
}
#endif //STRLIB_H
