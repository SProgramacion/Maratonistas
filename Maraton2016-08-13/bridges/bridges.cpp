//Ejercicio 1172 UVA
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <algorithm> 

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    
    for(int i = 0; i < cases; i++){
        int cityN, cityS, temp, tempk;
        bool entro;
        cin >> cityN;
        //Norte
        string citysNorte[cityN][3];
        for(int j = 0; j < cityN; j++){
            cin >> citysNorte[j][0] >> citysNorte[j][1] >> citysNorte[j][2];
        }

        //Sur
        cin >> cityS;
        string citysSur[cityS][3];
        for(int j = 0; j < cityS; j++){
            cin >> citysSur[j][0] >> citysSur[j][1] >> citysSur[j][2];
        }

        //Norte normal
        int puentes5 = 0, total5 = 0;
        int pl = -1;
        for(int j = 0; j < cityN; j++){
            for(int k = 0; k < cityS; k++){
                if(citysNorte[j][1] == citysSur[k][1] && k > pl){
                    pl = k;
                    puentes5++;
                    total5 += (atoi(citysNorte[j][2].c_str()) + atoi(citysSur[k][2].c_str()));
                    break;
                }
            }
        }
        //Norte reversa normal
        int puentes6 = 0, total6 = 0;
        pl = 10000001;
        for(int j = cityN-1; j >= 0; j--){
            for(int k = cityS-1; k >= 0; k--){
                if(citysNorte[j][1] == citysSur[k][1] && k < pl){ 
                    pl = k;
                    puentes6++;
                    total6 += (atoi(citysNorte[j][2].c_str()) + atoi(citysSur[k][2].c_str()));
                }
            }
        }

        //Norte datos 
        int puentes1 = 0, total1 = 0;
        pl = -1;
        entro = false;
        temp = -1, tempk = -1;
        for(int j = 0; j < cityN; j++){
            for(int k = 0; k < cityS; k++){
                if(citysNorte[j][1] == citysSur[k][1] && k > tempk){
                    entro = true;
                    if(atoi(citysSur[k][2].c_str()) > temp){
                        temp = atoi(citysSur[k][2].c_str());
                        tempk = k;
                    }
                    //break;
                }
            }
            if(entro){
                //cout << citysNorte[j][0] << ": " << citysNorte[j][1] << " == " << citysSur[tempk][0] << ": " << citysSur[tempk][1] << endl;
                pl = tempk;
                puentes1++;
                total1 += (atoi(citysNorte[j][2].c_str()) + atoi(citysSur[tempk][2].c_str()));
                entro = false;
            }
            temp = -1;
        }
        
        //cout << "===============" << endl;
        //Norte reversa
        int puentes2 = 0, total2 = 0;
        pl = 10000001;
        entro = false;
        temp = -1, tempk = 1000000;
        for(int j = cityN-1; j >= 0; j--){
            for(int k = cityS-1; k >= 0; k--){
                if(citysNorte[j][1] == citysSur[k][1] && k < tempk){ 
                    entro = true;
                    if(atoi(citysSur[k][2].c_str()) > temp){
                        temp = atoi(citysSur[k][2].c_str());
                        tempk = k;
                    }
                }
            }
            if(entro){
                pl = tempk;
                puentes2++;
                total2 += (atoi(citysNorte[j][2].c_str()) + atoi(citysSur[tempk][2].c_str()));
                entro = false;
            }
            temp = -1;
        }

        
        //Sur reversa
        int puentes3 = 0, total3 = 0;
        pl = 10000001;
        entro = false;
        temp = -1, tempk = 1000001;
        for(int j = cityS-1; j >= 0; j--){
            for(int k = cityN-1; k >= 0; k--){
                if(citysSur[j][1] == citysNorte[k][1] && k < tempk){ 
                    entro = true;
                    if(atoi(citysNorte[k][2].c_str()) > temp){
                        temp = atoi(citysNorte[k][2].c_str());
                        tempk = k;
                    }
                }
            }
            if(entro){
                
                pl = tempk;
                puentes3++;
                total3 += (atoi(citysSur[j][2].c_str()) + atoi(citysNorte[tempk][2].c_str()));
                entro = false;
            }
            temp = -1;
        }
        //cout << "===============" << endl;
        //Sur
        int puentes4 = 0, total4 = 0;
        pl = -1;
        entro = false;
        temp = -1, tempk = -1;
        for(int j = 0; j < cityS; j++){
            for(int k = 0; k < cityN; k++){
                if(citysSur[j][1] == citysNorte[k][1] && k > tempk){
                    entro = true;
                    if(atoi(citysNorte[k][2].c_str()) > temp){
                        temp = atoi(citysNorte[k][2].c_str());
                        tempk = k;
                    }
                }
            }
            if(entro){
                //cout << citysSur[j][0] << ": " << citysSur[j][1] << " == " << citysNorte[tempk][0] << ": " << citysNorte[tempk][1] << endl;
                pl = tempk;
                puentes4++;
                total4 += (atoi(citysSur[j][2].c_str()) + atoi(citysNorte[tempk][2].c_str()));
                entro = false;
            }
            temp = -1;          
        }
        //cout << "===============" << endl;

        //if(total1 >= total2 && total1 >= total3 && total1 >= total4 && total1 >= total5 && total1 >= total6){
            cout << total1 << " " << puentes1 << endl;
        //}else if(total2 >= total1 && total2 >= total3 && total2 >= total4 && total2 >= total5 && total2 >= total6){
            cout << total2 << " " << puentes2 << endl;
        //}else if(total3 >= total1 && total3 >= total2 && total3 >= total4 && total3 >= total5 && total3 >= total6){
            cout << total3 << " " << puentes3 << endl;
        //}else if(total4 >= total1 && total4 >= total2 && total4 >= total3 && total4 >= total5 && total4 >= total6){
            cout << total4 << " " << puentes4 << endl;
        //}else if(total5 >= total1 && total5 >= total2 && total5 >= total3 && total5 >= total4 && total5 >= total6){
            cout << total5 << " " << puentes5 << endl;
        //}else{
            cout << total6 << " " << puentes6 << endl;
        //}
            cout << "==================" << endl;
    }
}

/*
1
20
C0 O1 895719
C1 O1 179175
C2 O1 88868
C3 O3 5176
C4 O4 702273
C5 O0 465446
C6 O3 722584
C7 O0 171922
C8 O2 512828
C9 O3 632707
C10 O2 131700
C11 O1 960334
C12 O2 174383
C13 O3 175098
C14 O4 483562
C15 O2 413176
C16 O4 573464
C17 O0 798166
C18 O1 565284
C19 O0 775679
4
C20 O3 758045
C21 O0 806725
C22 O1 906014
C23 O0 701794

//////////////
1
10
C10 O2 131700
C11 O1 960334
C12 O2 174383
C13 O3 175098
C14 O4 483562
C15 O2 413176
C16 O4 573464
C17 O0 798166
C18 O1 565284
C19 O0 775679
4
C20 O3 758045
C21 O0 806725
C22 O1 906014
C23 O0 701794
/////////////
1
5
C1 OS2 200
C2 Mac 250
C3 Linux 50
C4 OS2 100
C5 Mac 100
7
C1 Mac 100
C2 Linux 250
C3 Mac 75
C4 OS2 5
C5 Vista 160
C6 Mac 170
C7 OS2 30

*/

/*

        string citysNorteCopy[cityN][3]; //copia del norte
        for (int j = 0; j < cityN; ++j)
        {
            citysNorteCopy[j][0] = citysNorte[j][0];
            citysNorteCopy[j][1] = citysNorte[j][1];
            citysNorteCopy[j][2] = citysNorte[j][2];
        }

//Organizar mayor a menor
        for(int h = 0; h < cityN - 1; h++){
            for(int j = h + 1; j < cityN; j++){
                if(atoi(citysNorte[h][2].c_str()) < atoi(citysNorte[j][2].c_str())){
                    for(int k = 0; k < 3; k++)
                    {
                        swap(citysNorte[h][k], citysNorte[j][k]);
                    }   
                }
            }
        }
        //Agregar indices anteriores
        for (int j = 0; j < cityN; ++j)
        {
            for (int k = 0; k < cityN; ++k)
            {
                if(citysNorte[j][0] == citysNorteCopy[k][0] && citysNorte[j][1] == citysNorteCopy[k][1] && citysNorte[j][2] == citysNorteCopy[k][2]){
                    stringstream x;
                    x << k;
                    citysNorte[j][3] = x.str();
                    break;
                }
            }
        }*/
