/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: Lab8
 * Standard: C++0x
*/
#include <subaltern.h>
#include <senior_officers.h>
#include <big_brass.h>

int main()
{
    base rank0("Токарь", "Тимур", "Михайлович");
    subalter rank1("Тимур", "Токарь", "Михайлович");
    senior_officers rank2("Тимур", "Токарь", "Михайлович");
    big_brass rank3("Тимур", "Токарь", "Михайлович");

    base *ptr_base;

    ptr_base = &rank0;
    ptr_base->rank();

    ptr_base = &rank1;
    ptr_base->rank();

    ptr_base = &rank2;
    ptr_base->rank();

    ptr_base = &rank3;
    ptr_base->rank();

    return 0;
}

