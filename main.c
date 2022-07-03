#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "modules/structs.h"
#include "modules/metodos.h"
#include "modules/menus.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int main (){

    menu_Principal();
    return 0;

}