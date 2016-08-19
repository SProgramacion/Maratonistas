#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int cases;
	cin >> cases;
	int arr[10];
	
	for(int i = 0; i < cases; i++){
		bool z = false, m = false, b = false;
		string res = "none";
		for(int j = 0; j < 10; j++){
			cin >> arr[j];
			if(arr[j] == 17 && !z){
				z = true;
				res = "zack";
			}
			if(arr[j] == 18 && !m){
				m = true;
				res = "mack";
			}
			if(m && z){
				res = "both";
			}
		}
		for(int j = 0; j < 10; j++){
			cout << arr[j] << " ";
		}
		if(i+1 != cases){
			cout << endl << res << endl;
		}else{
			cout << endl << res;
		}
	}
	return 0;
}

