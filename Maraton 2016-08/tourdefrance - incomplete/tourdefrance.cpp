#include <iostream>
using namespace std;

int cityUltima = 0;
int cityNow = 0;

int ida(int matriz[][3], int rutas){
	int cityActual = 0, cityPrevius= 0, totalTemp=0, total = 0, distance = 100002;
	bool cityNext = false;
	for (int j = 0; j < rutas; ++j)
	{
		if(matriz[j][0] != cityPrevius){
			distance = 100002;
			cityPrevius = matriz[j][0];
			total += totalTemp;
			totalTemp = 0;
			cityNext = true;
		}

		if((cityPrevius == matriz[j][0] && cityNext == false) || cityActual == matriz[j][0]){
			cityNext = false;
			if(matriz[j][2] < distance){
				//cout << "POS: " << (j+1) << endl;
				totalTemp = matriz[j][2];
				cityPrevius = matriz[j][0];
				cityActual = matriz[j][1];
				distance = matriz[j][2];
				cityUltima = j;
				cityNow = matriz[j][1];
			}
		}	
	}

	total += totalTemp; //Suma el ultimo que no repite el ciclo
	return total;
}

int vuelta(int matriz[][3], int rutas, int city){
	int cityActual = cityNow, cityPrevius = (city-1), totalTemp = 0, total = 0, distance = 100002;
	bool cityNext = false;
	int firstTemp = 0;
	for(int j = cityUltima-1; j >= 0; j--){
		if(matriz[j][0] != cityPrevius){
			distance = 100002;
			cityPrevius = matriz[j][0];
			total += totalTemp;
			totalTemp = 0;
			cityNext = true;
			//Guardar temporales
			firstTemp = 0;
		}

		if(matriz[j][0] == 0){
			total += totalTemp;
			return total;
		}else{
			if((cityPrevius == matriz[j][0] && cityNext == false) || cityActual == matriz[j][0]){
				cityNext = false;
				if(matriz[j][2] < distance){
					//cout << "POS: " << (j) << endl;
					totalTemp = matriz[j][2];
					cityPrevius = matriz[j][0];
					cityActual = matriz[j][1];
					distance = matriz[j][2];	
					firstTemp = matriz[j][0];
				}
			}	
		}
		
	}
	total += totalTemp; //Suma el ultimo que no repite el ciclo
	return total;
}



int main() {
	int cases;
	cin >> cases;

	for (int i = 0; i < cases; ++i)
	{
		int ciudades, rutas;
		cin >> ciudades >> rutas; 

		int matriz[rutas][3];
		for (int j = 0; j < rutas; ++j)
		{
			cin >> matriz[j][0] >> matriz[j][1] >> matriz[j][2];
		}

		int total = ida(matriz, rutas) + vuelta(matriz, rutas, ciudades);
		cout << total << endl;
	}
}