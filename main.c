#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Modulos\metodos.h"
#include "Modulos\menu.h"
#include "Modulos\diciplina.h"


#if def_WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void menu_Principal();

int main (){

menu_Principal();

return 0;

}
