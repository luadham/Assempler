//
// Created by adham
//

#ifndef SYSPROJECT_FORMATONE_H
#define SYSPROJECT_FORMATONE_H
#include <bits/stdc++.h>
#include "IFormat.h"

using namespace std;
class FormatOne : public IFormat{
public:
    FormatOne();
    string generateObjCode(string obCode) {
        return obCode;
    }

};


#endif
