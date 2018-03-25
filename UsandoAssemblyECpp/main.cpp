#include <iostream>

#ifdef __i386__
#define OS_LIN_X86
#endif

using namespace std;
extern "C"{
 int  madd(int x,int y);
 int  msub(int x,int y);
}

int main()
{
    int x = madd(1,2);
#ifdef OS_LIN_X86
    cout << "main 32" << endl;
#else
    cout << "main 64" << endl;
#endif

    int y = x+100;
return y;
}
