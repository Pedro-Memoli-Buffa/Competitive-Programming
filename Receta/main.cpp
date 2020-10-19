#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;


bool pertenece(string palabra, vector<string> palabras) {
	for (int i = 0; i < palabras.size(); i++) {
		if (palabra == palabras[i]) {
			return true;
		}
	}

	return false;
}


int receta(const vector<string>& heladera, const vector<string>& ingredientes, vector<string>& faltantes) {
	for (int i = 0; i < ingredientes.size(); i++) {
		if (!pertenece(ingredientes[i], heladera) and !pertenece(ingredientes[i], faltantes)) {
			faltantes.push_back(ingredientes[i]);
		}
	}

	return faltantes.size();
}



void evaluador() {
	ifstream fin;
	ofstream fout;

	fin.open("entrada.txt");
	fout.open("salida.txt");

	int cantH, cantR;
	vector<string> listaH, listaR;

	fin >> cantH >> cantR;

	for (int i = 0; i < cantH; i++) {
		string ingHeladera;
		fin >> ingHeladera;

		listaH.push_back(ingHeladera);
	}

	for (int i = 0; i < cantR; i++) {
		string ingReceta;
		fin >> ingReceta;

		listaR.push_back(ingReceta);
	}

	vector<string> faltantes;

	fout << receta(listaH, listaR, faltantes) << " " << endl;

	for (int i = 0; i < faltantes.size(); i++) {
		fout << faltantes[i] << " ";
	}
	
	fout.close();
	fin.close();
}



void main() {
	evaluador();
}