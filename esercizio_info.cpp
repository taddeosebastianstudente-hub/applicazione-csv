#include <iostream>
#include <string>
using namespace std;
struct Info{
	string ClasseToponimo;
	string DescrizioneToponimo;
	string Numero;
	string Subalterno;
	string CAP;
	string SezioneISTAT;
	float Lat;
	float Lon;
	float Location;
	};

void CaricaDati(Info x[], string y){
	ifstream fileInput("testo.txt");
    string linea;
    if (fileInput.is_open()) {
        while (fileInput>>linea){
            cout<<linea<<'\n';
        }
        fileInput.close();
    } else {
        cout << "Impossibile aprire il file";
    }
	}
int main(int argc, char** argv) {
	
	return 0;
}    //prendere il file, prendere il contenuto e metterli qua