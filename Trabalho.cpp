#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;

// Definição de tipo
struct roms{
   string code;
   string title;
   string gender;
   string relYear;
   string developer;
   string qtdPlayer;
};
typedef struct roms tRoms;

// Assinatura das funções
int menu();
void cadastra(map <int, tRoms> &estoque);
void consulta(map <int, tRoms> estoque);
void excluiRom(map <int, tRoms> &estoque);
//void edit(map <int, tRoms> &estoque);
void print(map <int, tRoms> estoque);
void consultacode(map <int, tRoms> estoque);
void consultatitle(map <int, tRoms> estoque);


// Variáveis globais
int pk = 0;

int main(void){
    map <int, tRoms> estoque;
    
    int option;

	do{
		option = menu();
		
		switch(option){
			case 1: cadastra(estoque);
					break;
					
			case 2: consulta(estoque);
					break;
			
			case 3: consulta(estoque);
					break;
					
			case 4: excluiRom(estoque);
					break;
					
			case 5: print(estoque);
					break;
			
			case 6: exit(0);
					break;
			
			default: cout << endl << "Opcao invalida!\n" << endl;
			     	 cout << "Escolha uma Opcao: ";
					 cin >> option;
		}
		getch();
	}while(option != 3);

    return 0;
}

int menu() {
	system("cls");
	
	int option;
	
	cout << "\t\t\t\t\t *** biblioteca de ROMs de SNES ***" << endl;
	cout << endl;
	cout << "1 - Cadastro de ROMs" << endl;
	cout << "2 - Consulta de ROMs" << endl;
	cout << "3 - Editar ROM" << endl;
	cout << "4 - Excluir ROM" << endl;
	cout << "5 - Imprimir ROMs" << endl;
	cout << "6 - Finalizar" << endl;
	cout << endl;
	cout << "Escolha uma Opcao: ";
	cin >> option;
	
	return option;
	
}

void print(map <int, tRoms> estoque) {
	map <int, tRoms>::iterator mapIterator;
	string title;
	
	for(mapIterator = estoque.begin(); mapIterator != estoque.end(); mapIterator++) {
        	cout << endl;
            cout << "Codigo: " << mapIterator->second.code << endl;
            cout << "Titulo: " << mapIterator->second.title << endl;
            cout << "Genero: " << mapIterator->second.gender << endl;
 			cout << "Ano de Lancamento: " << mapIterator->second.relYear << endl;
 			cout << "Desenvolvedora da ROM: " << mapIterator->second.developer << endl;
            cout << "Quantidade de Jogadores: " << mapIterator->second.qtdPlayer << endl;
        cout << endl;
	
}
}

void cadastra(map<int, tRoms> &estoque) {	
	system("cls");
	cin.ignore();
	
	tRoms nova;
	
	cout << "\t\t\t\t\t *** CADASTRO DE ROMs ***" << endl;
	
	cout << "Digite o codigo da ROM: ";
    getline(cin, nova.code);
    
    cout << "Digite o titulo da ROM: ";
    getline(cin, nova.title);
    
    cout << "Digite o genero da ROM: ";
    getline(cin, nova.gender);
    
    cout << "Digite o ano de lancamento da ROM: ";
    getline(cin, nova.relYear);
    
     cout << "Digite o nome da desenvolvedora da ROM: ";
    getline(cin, nova.developer);
    
    cout << "Digite a quantidade de jogadores da ROM: ";
    cin >> nova.qtdPlayer;
    
    pk++;
    
    estoque[pk] = nova;
    
    cout << "Cadastro " << pk << " realizado com sucesso!" << endl;
    cout << "Aperte qualquer tecla para voltar ao menu!";
    
    return;
}


void excluiRom(map <int, tRoms> &estoque){
	int code;
	
	char opcao;
	
	if(estoque.size() != 0){
	cout << "Digite o codigo da ROM que deseja excluir: ";
    cin >> code;
    
	
	if(estoque.find(code) == estoque.end()) {
	cout << "ROM encontrada!" << endl;
    estoque.erase(code);
		cin.ignore();    
	    cout << "Deseja excluir? (S/N): " << endl;
	    cin >> opcao;
	    
	    
	    if(opcao == 'S' || opcao == 's') {
	    	estoque.erase(code);
	    	 cout << "ROM excluida com sucesso!" << endl;
	    	return;
		}
		return;
    
    }else {
       cout << "Codigo nao encontrada!" << endl;
	}
} else {
	 cout << "Nao existe ROM cadastrada!" << endl;
}
}


void consulta(map <int, tRoms> estoque) {
	system("cls");
	cin.ignore();
	
	int codePesquisa;
	
	do{
		cout << "\t\t\t\t\t *** CONSULTA DE ROMs ***" << endl;
		cout << endl;
		cout << "1 - Consultar pelo Codigo" << endl;
		cout << "2 - Consultar pelo Titulo" << endl;
		cout << endl;
		cout << "Escolha uma Opcao: ";
		cin >> codePesquisa;
	}while(codePesquisa < 1 || codePesquisa > 3);
	
	cin.ignore();
	
	switch(codePesquisa){
		case 1:	consultacode(estoque);
				break;
		case 2: consultatitle(estoque);
				break;
	}
	
	return;
}

void consultacode(map <int, tRoms> estoque) {	
	map <int, tRoms>::iterator mapIterator;
	string code;
	
	cout << "Digite o codigo: ";
    getline(cin, code);

	for(mapIterator = estoque.begin(); mapIterator != estoque.end(); mapIterator++) {
        if(mapIterator->second.code == code) {
        	cout << endl;
            cout << "Codigo: " << mapIterator->second.code << endl;
            cout << "Titulo: " << mapIterator->second.title << endl;
            cout << "Genero: " << mapIterator->second.gender << endl;
 			cout << "Ano de Lancamento: : " << mapIterator->second.relYear << endl;
 			cout << "Desenvolvedora da ROM: " << mapIterator->second.developer << endl;
            cout << "Quantidade de Jogadores: " << mapIterator->second.qtdPlayer << endl;
            break;                         
        }
    }
    
	return;
}

void consultatitle(map <int, tRoms> estoque) {	
	map <int, tRoms>::iterator mapIterator;
	string title;
	
	cout << "Digite o titulo: ";
    getline(cin, title);
	
	for(mapIterator = estoque.begin(); mapIterator != estoque.end(); mapIterator++) {
        if( (mapIterator->second.title).find(title) != -1) {
        	cout << endl;
            cout << "Codigo: " << mapIterator->second.code << endl;
            cout << "Titulo: " << mapIterator->second.title << endl;
            cout << "Genero: " << mapIterator->second.gender << endl;
 			cout << "Ano de Lancamento: : " << mapIterator->second.relYear << endl;
 			cout << "Desenvolvedora da ROM: " << mapIterator->second.developer << endl;
            cout << "Quantidade de Jogadores: " << mapIterator->second.qtdPlayer << endl;
        }
        cout << endl;
    }
    
	return;
}

