#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    srand (time(NULL));
    

    //random_shuffle(&a[0],&a[9]);
    random_shuffle( &(a[0]) ,  &(random1[9]) );

    for (int i = 1 ; i < 10 ; ++i)
    	cout<<a[i] << " ";
    cout << endl;

}