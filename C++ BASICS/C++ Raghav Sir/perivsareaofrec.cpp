#include<iostream>
using namespace std;
int main(){


int l,b;
cout<< " enter the length and breadth : \n ";
cin>>l;
cin>>b;
int area = l*b;
int peri = 2*(l+b);
if( area > peri )
{
    cout<<area;
    cout<< peri ;
   cout<< "area is more than peri"<<endl;

}
else 
{
     cout<<" area aint > than peri ";
}
}