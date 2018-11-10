#include <iostream>
#include <algorithm>

using namespace std;

struct par{
    int pos[2];
    par(int x, int y){
        pos[0] = x;
        pos[1] = y;
    }
};



int main()
{

	//cout << int(11/2) << endl;
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    srand (time(NULL));

    std::vector <par> Meteors;
    Meteors.push_back(par(1,2));
    Meteors.push_back(par(3,4));

    for (par i : Meteors){
        cout << i.pos[0] << " " << i.pos[1] <<endl;
    }
    
    //cout << "This " << " is a " << "single C++ statement";
    //random_shuffle(&a[0],&a[9]);
    //random_shuffle( &(a[0]) ,  &(a[9]) );
    double x = 33.4434;
    int i;
	cout << "Please enter an integer value: ";
	cin >> i;
	cout << "The value you entered is " << i;
	cout << " and its double is " << i*2 << ".    "<< (int) x << " \n";
	
    


    for (int i = 1 ; i < 10 ; ++i)
    	cout<<a[i] << " ";
    cout << endl;

}