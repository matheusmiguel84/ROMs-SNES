#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct roms
{
	string code;
	string title;
	string gender;
	string relYear;
	string developer;
	string qtdPlayer;
};
typedef struct roms tRoms;

int menu();
void cadastra(map<int, tRoms> &roms);
void consulta(map<int, tRoms> roms);
void excluiRom(map<int, tRoms> &roms);
void edit(map<int, tRoms> &roms);
void print(map<int, tRoms> roms);
void consultaCode(map<int, tRoms> roms);
void consultaTitle(map<int, tRoms> roms);

int code = 0;

int main(void)
{
	map<int, tRoms> roms;

	int option;

	do
	{
		option = menu();

		switch (option)
		{
		case 1:
			cadastra(roms);
			break;

		case 2:
			consulta(roms);
			break;

		case 3:
			edit(roms);
			break;

		case 4:
			excluiRom(roms);
			break;

		case 5:
			print(roms);
			break;

		case 6:
			exit(0);
			break;

		default:
			cout << endl
				 << "Opcao invalida!\n"
				 << endl;
			cout << "Escolha uma Opcao: ";
			cin >> option;
		}
		getch();
	} while (option != 7);

	return 0;
}

int menu()
{
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

void print(map<int, tRoms> roms)
{
	system("cls");
	map<int, tRoms>::iterator mapIterator;
	cout << "\t\t\t\t\t *** IMPRESSAO DE ROMs ***" << endl;
	string title;
	if (roms.size() != 0)
	{
		for (mapIterator = roms.begin(); mapIterator != roms.end(); mapIterator++)
		{
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
	else
	{
		cout << "Nao existe ROM cadastrada!" << endl;
		cout << "Aperte qualquer tecla para voltar ao menu!";
	}
}

void cadastra(map<int, tRoms> &roms)
{
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

	code++;

	roms[code] = nova;
	cout << "Cadastro " << code << " realizado com sucesso!" << endl;
	cout << "Aperte qualquer tecla para voltar ao menu!";

	return;
}

void edit(map<int, tRoms> &roms)
{
	system("cls");
	cout << "\t\t\t\t\t *** EDICAO DE ROMs ***" << endl;
	int code;

	char opcao;

	if (roms.size() != 0)
	{
		cout << "Digite o codigo do cadastro da ROM que deseja editar: ";
		cin >> code;

		if (roms.find(code) == roms.end())
		{
			cout << "Codigo nao encontrado!" << endl;
		}
		else
		{
			cout << "ROM encontrada!" << endl;
			cin.ignore();
			cout << "Deseja editar? (S/N): " << endl;
			cin >> opcao;

			if (opcao == 'S' || opcao == 's')
			{
				cin.ignore();
				cout << "Digite o novo titulo da ROM:" << endl;
				getline(cin, roms[code].title);
				cout << "Digite o novo genero da ROM: " << endl;
				getline(cin, roms[code].gender);
				cout << "Digite o novo ano de lancamento da ROM: " << endl;
				getline(cin, roms[code].relYear);
				cout << "Digite o novo desenvolvedora da ROM: " << endl;
				getline(cin, roms[code].developer);
				cout << "Digite a nova quantidade de jogadores da ROM: " << endl;
				cin >> roms[code].qtdPlayer;
				cout << "ROM " << code << " editada com sucesso!" << endl;
				cout << "Aperte qualquer tecla para voltar ao menu!";
			}
			return;
		}
	}
	else
	{
		cout << "Nao existe ROM cadastrada!" << endl;
		cout << "Aperte qualquer tecla para voltar ao menu!";
	}
}

void excluiRom(map<int, tRoms> &roms)
{
	system("cls");
	cout << "\t\t\t\t\t *** EXCLUIR ROM ***" << endl;
	int code;

	char opcao;

	if (roms.size() != 0)
	{
		cout << "Digite o codigo do cadastro da ROM que deseja excluir: ";
		cin >> code;

		if (roms.find(code) == roms.end())
		{
			cout << "Codigo nao encontrado!" << endl;
		}
		else
		{
			cout << "ROM encontrada!" << endl;
			cin.ignore();
			cout << "Deseja excluir? (S/N): " << endl;
			cin >> opcao;

			if (opcao == 'S' || opcao == 's')
			{
				roms.erase(code);
				cout << "ROM excluida com sucesso!" << endl;
				cout << "Aperte qualquer tecla para voltar ao menu!";
				return;
			}
			return;
		}
	}
	else
	{
		cout << "Nao existe ROM cadastrada!" << endl;
		cout << "Aperte qualquer tecla para voltar ao menu!";
	}
}

void consulta(map<int, tRoms> roms)
{
	system("cls");
	cout << "\t\t\t\t\t *** CONSULTA DE ROMs ***" << endl;
	cin.ignore();

	int codePesquisa;

	if (roms.size() != 0)
	{
		do
		{
			cout << endl;
			cout << "1 - Consultar pelo Codigo" << endl;
			cout << "2 - Consultar pelo Titulo" << endl;
			cout << endl;
			cout << "Escolha uma Opcao: ";
			cin >> codePesquisa;
		} while (codePesquisa < 1 || codePesquisa > 3);

		cin.ignore();

		switch (codePesquisa)
		{
		case 1:
			consultaCode(roms);
			break;
		case 2:
			consultaTitle(roms);
			break;
		}
	}
	else
	{
		cout << "Nao existe ROM cadastrada!" << endl;
		cout << "Aperte qualquer tecla para voltar ao menu!";
	}
	return;
}

void consultaCode(map<int, tRoms> roms)
{
	map<int, tRoms>::iterator mapIterator;
	string code;

	cout << "Digite o codigo: ";
	getline(cin, code);

	for (mapIterator = roms.begin(); mapIterator != roms.end(); mapIterator++)
	{
		if (mapIterator->second.code == code)
		{
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

void consultaTitle(map<int, tRoms> roms)
{
	map<int, tRoms>::iterator mapIterator;
	string title;

	cout << "Digite o titulo: ";
	getline(cin, title);

	for (mapIterator = roms.begin(); mapIterator != roms.end(); mapIterator++)
	{
		if ((mapIterator->second.title).find(title) != -1)
		{
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
