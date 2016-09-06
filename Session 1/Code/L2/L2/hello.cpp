#include<iostream>

using namespace std;

int main()
{
    int i=0;

    loop :
           cout<<i<<" ";
           i++;
           if(i<10)
            goto loop;

}
