//v3.0 será feita em Visual C++!!!

#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <windows.h> // biblioteca para alterar a cor do texto no console

using namespace std;

double calcularMedia(double p1, double p2, double t1, double t2 = 0)
{
    double media = (p1 + p2 + t1) / 3;
    return media;
}

void resetarCor(HANDLE hConsole)
{
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void corVerm(HANDLE hConsole)
{
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED); 
}

void corVerd(HANDLE hConsole)
{
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    cout << "v2.0 (c)Raziel, 2022\nPortado por Lucas Raziel 2023 para C++\n\n";
	double media, p1, p2, t1, t2 = 0;

    while (true) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		resetarCor(hConsole);
        cout << "Escolha a disciplina:\n";
        cout << "1 - Economia e Finanças (Frederico)\n";
        cout << "2 - Sociedade e Tecnologia (Marcelo)\n";
        cout << "3 - Estruturas de Dados (Fernanda)\n";
        cout << "4 - Engenharia de Software II (Simone)\n";
        cout << "5 - Interação Humano Computador (Fábio)\n";
        cout << "6 - Estatística Aplicada (Sávio)\n";
        cout << "0 - Sair\n";
		cout << endl;
		cout << "escolha> ";

        int opcao;
        cin >> opcao;

        if (opcao == 0) {
            break;
        }

        cout << "Digite as notas:\n";
		cout << endl;
        cout << "P1: ";
        cin >> p1;
        cout << "P2: ";
        cin >> p2;
        cout << "T1: ";
        cin >> t1;

		if (opcao == 6) {
			media = (7 * p1 + 7 * p2 + 6 * t1) / 20;
			goto FIM;
        }
		
		media = calcularMedia(p1, p2, t1);
		
	FIM:
        cout << cout.precision(2);
        cout << "\nSua média é de: " << media << endl;

        if (media < 6) {
			corVerm(hConsole);
            cout << "\nREPROVADO!\n\n";
        } else {
			corVerd(hConsole);
            cout << "\nAPROVADO!\n\n";
        }
    }

	cout << endl;

    cout << "Obrigado por utilizar este programa!\n";
    system("PAUSE");

    return 0;
}
