#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	//cout << pr;
	int n;
	long l=0;
	cin>>n;
	for(int i=0; i<n;i++){
		int in=0, c = 0;
		int hola = 0;
		while(cin>>in && in != 0){
			if(hola != 0){
				if(in>l){
					c += in-l;
				}
				//cout<<c<<" , "<<in<<" , "<<l <<endl;
			}
			l=in*2;
			++hola;
		}
		cout<<c<<endl;
	}
	
	//return 0;
}

