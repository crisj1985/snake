#include <conio.h>
int main()
{
        _getch(0, FIONREAD, &bytesWaiting);
        return 0;
}