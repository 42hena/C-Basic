#ifndef _NAMESP_H_
#define _NAMESP_H_
#include <iostream>

namespace BestComImp1
{
    void SimpleFunc(void);
}

namespace ProgComImp1
{
    void SimpleFunc(void);
}
void BestComImp1::SimpleFunc(void);
void ProgComImp1::SimpleFunc(void);
#endif