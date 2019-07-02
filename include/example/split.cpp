//
// Created by cao on 19-7-2.
//

#include "strlib.h"
#include <fstream>
int main()
{
    std::string dataset="/data/DataSet/all_hk";
    std::string imgPath=std::join(dataset,"JPEGImages");
    std::string annPath=std::join(dataset,"Annotations");
    std::string trainTxt=std::join(dataset,"ImageSets","Main","train.txt");
    std::string valTxt=std::join(dataset,"ImageSets","Main","val.txt");
    std::vector<std::string> trainLine;
    std::vector<std::string> valLine;
    std::fstream f;
    f.open(trainTxt);
    if (f.is_open())
    {
        std::string temp;
        while (std::getline(f,temp))
        {
            trainLine.push_back(std::join(imgPath,std::strip(temp)+".jpg"));
        }
    }
    f.close();
    f.open(valTxt);
    if (f.is_open())
    {
        std::string temp;
        while (std::getline(f,temp))
        {
            valLine.push_back(std::join(imgPath,std::strip(temp)+".jpg"));
        }
    }

    return 0;

}