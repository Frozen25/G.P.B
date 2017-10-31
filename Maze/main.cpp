#include <thread>
#include <iostream>
#include "interfaceFLTK/interfaz.h"


int interfaz(int* posX , int* posY)

int main()
{


    std::thread interfaceThread(interfaz,&server );
    interfaceThread.detach();


    return 0;
}

