#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> eliminar(vector<int> arr, vector<int> restas){
	int repetido = 0;
	vector<int> newRestas, newArr;
	for (int i = 0; i < arr.size(); ++i)
	{
		if((i+1) <= restas.size() && restas[i] != restas[i+1]){
			newArr.push_back(arr[i]);
			newRestas.push_back(restas[i]);
		}else{
			if(restas[i] == restas[i+1]){
				repetido = restas[i];
			}
		}
	}

	//cout << "REPETIDO: " << repetido << endl;
	vector<int> finish;
	for (int i = 0; i < newRestas.size(); ++i)
	{
		if(newRestas[i] != repetido){
			finish.push_back(newArr[i]);
		}
	}
	sort(finish.begin(), finish.end());
	return finish;
}

int main() {
	int cases;
	cin >> cases;

	for (int i = 0; i < cases; ++i)
	{
		int music;
		cin >> music;
		int musics[music][2];
		for (int j = 0; j < music; ++j)
		{
			cin >> musics[j][0];
			musics[j][1] = musics[j][0] - (j+1);
		}

		vector<int> ordenado, restas;
		int mayor = 100002;
		for (int j = 0; j < music; ++j)
		{
			if(musics[j][1] > 0){
				ordenado.push_back(musics[j][0]);
				restas.push_back(musics[j][1]);
			}
		}
		//cout << "SALIDA" << endl;
		sort(ordenado.begin(), ordenado.end());
		sort(restas.begin(), restas.end());
		vector<int> final = eliminar(ordenado, restas);

		cout << final.size() << endl;
		if(final.size() > 0){
			for (int j = 0; j < final.size(); ++j)
			{
				cout << final[j] << endl;
			}
		}
		
	}
}