#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] > x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	ifstream txt1("score1.txt");
	ifstream txt2("score2.txt");
	ifstream txt3("score3.txt");
	ofstream dest("rank.txt");
    string text1,text2,text3;
	float a[60];
	int count = 0;
	while(getline(txt1,text1)){
        a[count]=atof(text1.c_str());
		count++;
	}
	while(getline(txt2,text2)){
        a[count]=atof(text2.c_str());
		count++;
	}
	while(getline(txt3,text3)){
        a[count]=atof(text3.c_str());
		count++;
	}
		sort(a,count);
		float b[20];
        count=1;
	for(int j=0;j<20;j++){
		b[j]=a[j];
		if(b[j-1]==b[j]){
			dest << b[j] << " = "<< count<<endl;
		}else{
			count=j+1;
            dest <<b[j]<< " = "<<j+1<<endl;
		}
	}
	return 0;
}

