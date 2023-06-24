#include "Employe.h"

int main()
{
    Employe obj("PANKAJ", 100000);
    obj.setDetails();
    obj.displayEmployeInfo();

    Employe poj(obj);
    poj.setDetails();
    poj.displayEmployeInfo();

    Employe moj(std::move(obj));
    moj.setDetails();
    moj.displayEmployeInfo();

    Employe coj("DARSHAN", 200000);
    coj = moj;
    coj.setDetails();
    coj.displayEmployeInfo();

    Employe koj("VICKY", 300000);
    koj = std::move(coj);
    koj.setDetails();
    koj.displayEmployeInfo();
}