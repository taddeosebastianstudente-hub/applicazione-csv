#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
struct Info {
    string ClasseToponimo;
    string DescrizioneToponimo;
    string Numero;
    string Subalterno;
    string CAP;
    string SezioneISTAT;
};
struct Indirizzo {
    float Lat;
    float Lon;
    string Location;
};
struct Record {
    Info info;
    Indirizzo ind;
};
void CaricaDati(Record database[],int &contatore){
	contatore=0; 
                ifstream fileIn("dati.txt");
                if (!fileIn.is_open()) {
                    cout<<"impossibile aprire il file"<<endl;
                } else {
                    while (contatore<1000 && 
                           fileIn>>database[contatore].info.ClasseToponimo 
                                  >>database[contatore].info.DescrizioneToponimo
                                  >>database[contatore].info.Numero
                                  >>database[contatore].info.Subalterno
                                  >>database[contatore].info.CAP
                                  >>database[contatore].info.SezioneISTAT
                                  >>database[contatore].ind.Lat
                                  >>database[contatore].ind.Lon
                                  >>database[contatore].ind.Location) {
                        contatore++;
                    }
                    fileIn.close();
                }
}
string visualizza(Record database[],int contatore){
	stringstream ss;
    for (int i=0;i<contatore;i++) {
    ss<<"record "<<i+1<<endl<<"classe toponimo: "<<database[i].info.ClasseToponimo<<endl<<"descrizione: "<<database[i].info.DescrizioneToponimo<<endl<<"numero: "<<database[i].info.Numero<<endl<<"subalterno: "<<database[i].info.Subalterno<<endl<<"CAP: "<<database[i].info.CAP<<endl<<"sezione ISTAT: "<<database[i].info.SezioneISTAT<<endl<<"latitudine: "<<database[i].ind.Lat<<endl<<"longitudine: "<<database[i].ind.Lon<<endl<<"location: "<<database[i].ind.Location<<endl;
	}
	    return ss.str();
    }
}
void filtraEordina(Record database[],int contatore,string ViaCercata,Record risultati[]){
	int contatoreR=0;
	for(int i=0;i<contatore;i++){
		if(database[i].info.DescrizioneToponimo==ViaCercata){
			risultati[contatoreR]=database[i];
			contatoreR++
	}
	}
	if(contatoreR==0){
		return 0;
	}
	for(int i=0;i<contatoreR-1;i++){
		for(int j=0;j<contatoreR-i-1;j++){
		   if(risultati[j].info.Numero>risultati[j+1].info.Numero){
		   	Record temp=risultati[j];
		   	risultati[j]=risultati[j+1];
		   	risultati[j+1]=temp;
	}
	}
	}
	return contatoreR;
	}
int main() {
    Record database[1000];
    int contatore=0;
    int scelta;
    do {
        cout<<"1-carica i primi 1000 record dal file"<<endl;
        cout<<"2-visualizza i dati in memoria"<<endl;
        cout<<"3-cerca via e mostra in ordine di numero crescente"<<endl;
        cout<<"0-esci dal programma"<<endl;
        cout<<"inserisci la tua scelta: ";
        cin>>scelta;
        switch (scelta) {
            case 1: {
             CaricaDati(database,contatore);
             break;
            }
            case 2: {
            	if(contatore==0){
            		cout<<"memoria vuota carica i dati con 1";
            	}
            	else{
            		string visualizzazione=visualizza(database,contatore);
            		cout<<visualizzazione;
            	}
                break;
            }
            case 3: {
                if (contatore==0) {
                    cout << "memoria vuota carica i dati con 1" << endl;
                } else {
                string viaCercata;
                cout<<"inserisci la via da cercare: ";
                cin<<ViaCercata;
                Record risultati[1000];
                int contatoreR=filtraEordina(database,contatore,viaCercata,risultati);
                if(contatoreR==0){
            		cout<<"nessun record trovato";
            	}
            	else{
            		cout<<"trovato "<<contatoreR<<" record per la via "<<viaCercata<<endl;
            		for(int i=0;i<contatoreR;i++){
            			cout<<"civico: "<<risultati[i].info.Numero;
            			cout<<"classe: "<<risultati[i].info.ClasseToponimo;
            			cout<<"CAP: "<<risultati[i].info.CAP;
            			cout<<"latitudine: "<<risultati[i].ind.Lat;
            			cout<<"longitudine: "<<risultati[i].ind.Lon;
            	}
            	}
            	}
                break;
            }
            case 0:
                cout << "uscita programma" << endl;
                break;
            default:
                cout<<"scelta non valida rifai"<<endl;
                break;
        }
    } while (scelta!=0);
    return 0;
}
