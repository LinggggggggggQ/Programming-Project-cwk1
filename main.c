#include <stdio.h>
#include "interface.h"


#ifdef PARAM_SUP
char* _BOOK_DATA_PATH = NULL;
char* _USER_INFO_PATH = NULL;
char* _USER_BOOK_PATH = NULL;
#endif

int main(int argc, char const *argv[])
{
#ifdef PARAM_SUP
    if (argc == 4) {
        _BOOK_DATA_PATH = argv[1];
        _USER_INFO_PATH = argv[2];
        _USER_BOOK_PATH = argv[3];
    }  else {
        printf("Invalid parameters.\n");
        return -1;
    }
#endif
    run_interface();//调用interface中的run_interface函数，展示用户选择界面
    return 0;
}
