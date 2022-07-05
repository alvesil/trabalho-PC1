#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "menu.h"

#if def_WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


int main (){

menu_Principal();

return 0;

}