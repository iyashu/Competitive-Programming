#include<iostream>
using namespace std;
int main()
{
    while(1)
    {
        float x,y,z;
        cin>>x>>y;
        if(x==-1&&y==-1)break;
        else if(x<=y) {z=x;x=y;y=z;}
        z=x/(y+1);
        if(z-int(z)==0) z=z;
        else z=z+1;
         cout<<int(z)<<endl;
    }
    return 0;
}
