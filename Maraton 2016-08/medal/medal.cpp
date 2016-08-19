#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int cases;
	cin >> cases;
	int medal[6];
	for(int i = 0; i < cases; i++){
		string res;
		int cu, cr;
		for(int j = 0; j < 6; j++){
			cin >> medal[j];
		}
		cu = medal[0] + medal[1] + medal[2];
		cr = medal[3] + medal[4] + medal[5];

		if(cu > cr){
			res = "count";
		}
		//Verificar color
		if(medal[0] > medal[3]){ //oro
			if(res == "count"){
				res = "both";
			}else{
				res = "color";
			}
		}else if(medal[0] == medal[3]){
			if(medal[1] > medal[4] && res != "both"){ //plata y bronce
				if(res == "count"){
					res = "both";
				}else{
					res = "color";
				}
			}else if(medal[1] == medal[4] && medal[2] > medal[5] && res != "both"){
				if(res == "count"){
					res = "both";
				}else{
					res = "color";
				}
			}else if(res != "count"){
				res = "none";	
			}
		}else{
			if(res != "count"){
				res = "none";	
			}
		}
		
		for(int j = 0; j < 6; j++){
			cout << medal[j] << " ";
		}
		
		if(i+1 != cases){
			cout << endl << res << endl;
		}else{
			cout << endl << res;
		}
	}
}

