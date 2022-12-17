#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h> 
#include <conio.h>
#include <time.h>

#define SIZE 6

using namespace std;

typedef struct Joueur
{
	char prenom[20];
	int point[10];
	int bonus = NULL;
	int coup1[10];
	int coup2[10];
}Joueur;

void affichageMenu()
{
	int continuer = 0;
	cout << "Bienvenue dans le jeu du bowling !!" << endl;
	cout << endl << "Vous pouvez entrer un nombre maximum de 6 joueurs !" << endl;
	cout << "Les regles sont tres simple : obtenir le score le plus haut. Pour cela, les strikes et les spares sont recommandes !!" << endl;

	do
	{
		cout << endl << "Tapez 1 pour continuer : ";
		cin >> continuer;
	} while (continuer != 1);
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

void saisie(Joueur * player, int * compteur)
{
	char prenom1[20];
	int saisieJoueur = 1;

	system("CLS");
	do
	{
		cout << "Entrez le nom du joueur " << *compteur + 1 << " : ";
		fgets(prenom1, 20, stdin);
		strcpy(player[*compteur].prenom, prenom1);
		if (*compteur != 5)
		{
			cout << "souhaitez vous ajouter un autre joueur ? (1 pour oui, 0 pour non) : ";
			cin >> saisieJoueur;
			int c = 0;
			while (c != '\n' && c != EOF)
			{
				c = getchar();
			}
		}
		*compteur = *compteur + 1;

	} while (saisieJoueur != 0 and *compteur != 6);


	//for (int i = 0; i < SIZE; i++)
	//{
	//	
	//	cout << "Entrez le nom du joueur " << i + 1 << " : ";
	//	cin >> prenom1;
	//	/*fgets(prenom1, 20, stdin);*/
	//	if (prenom1 == "test")
	//	{
	//		cout << "test1111";
	//		break;
	//	}/*
	//	strcpy(player[i].prenom, prenom1);
	//	cout << player[i].prenom;*/

	//}
}


void strike(Joueur * player)
{

}

void spare(Joueur * player)
{

}

void affichageScore(Joueur * player, int * compteur)
{

	for (int i = 0; i < *compteur; i++)
	{
		cout << "______________________________" << endl;
		cout << player[i].prenom;
		for (int j = 0; j < 10; j++)
		{
			cout << "|";
			cout << player[i].coup1[j];
			cout << player[i].coup2[j];
			cout << player[i].point[j];
		}
	}
}

void jeu(Joueur * player, int * compteur)
{
	char saisie;
	int nbMax = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < *compteur; j++)
		{
			srand(time(NULL));
			saisie = 'O';
			cout << endl << endl << "Joueur " << j + 1 << " c'est a ton tours" << endl;
			cout << "Appuie sur * pour lancer ta boule pour jouer le coup 1 :";
			do
			{
				saisie = _getch();
			} while (saisie = !'*');
			player[j].coup1[i] = rand() % 10;

			nbMax = 10 - player[j].coup1[i];

			cout << player[j].coup1[i];

			if (player[j].coup1[i] == 10)
			{
				player[j].bonus = 1;
			}
			else
			{
				srand(time(NULL));
				cout << endl << "Appuie sur * pour jouer le coup 2 :";
				do
				{
					saisie = _getch();
				} while (saisie = !'*');
				player[j].coup2[i] = rand() % nbMax+1;
				cout << player[j].coup2[i];
			}
		}
	}
}

int main(int argc, char ** argv)
{
	Joueur player[SIZE];
	int compteur = 0;
	affichageMenu();
	saisie(player, &compteur);
	affichageScore(player, &compteur);
	jeu(player, &compteur);
	cout << "points " << endl;
	cout << player[0].coup1[0];
	for (int i = 0; i < 10; i++)
	{
		cout << player[0].coup1[i] << endl;
	}

	return 0;
}