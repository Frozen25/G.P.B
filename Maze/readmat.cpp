//readmat

#include <iostream>
#include <fstream> 
#include <string>

int main(){

	int H = 30;
	int V = 30;
	char data[V][H];
	// reading a text file

	using namespace std;


	string line;
	ifstream myfile ("m2.txt");
	if (myfile.is_open()){
		int n=0;
		while ( getline (myfile,line) ){
			for (int m=0; m < H ; ++m){
				//std::cout << sizeof(line) << std:: endl;
				data[n][m] = (line[m]);
				//cout << line << '\n';
				}
			++n;
			}
			myfile.close();
		}

	else cout << "Unable to open file"; 


	for (int i=0 ; i< V ; ++i){
		for (int j=0 ; j<H ; ++j){
			std::cout << data[i][j] << "";
		}
		std::cout << std::endl;
	}

	return 0;


}