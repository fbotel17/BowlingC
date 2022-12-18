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
	int bonus = 0;
	int coup1[10];
	int coup2[10];
	char afficheCoup1[10];
	char afficheCoup2[10];
	int total[10];
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
	*compteur = 0;
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
		cout << endl << player[i].prenom;
		for (int j = 0; j < 10; j++)
		{
			cout << "|";
			if (player[i].coup1[j] != NULL)
			{
				if (player[j].bonus == 1)
				{
					cout << "X ";
				}
				cout << player[i].afficheCoup1[j] << " ";
			}
			else
			{
				cout << "   ";
			}
			if (player[i].coup2[j] != NULL)
			{
				cout << player[i].afficheCoup2[j] << "  ";

			}
			else
			{
				cout << "  ";
			}
			if (player[i].point[j] != NULL)
			{
				if (player[i].point[j] == 10)
				{
					cout << " ";
				}
				else
				{
					cout << player[i].total[j];
				}

			}
			else
			{
				cout << " ";
			}
		}
		cout << "| Points : " << player[i].total;
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
			player[j].coup1[i] = NULL;
			player[j].coup2[i] = NULL;
			player[j].point[i] = NULL;
			player[j].total[i] = NULL;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < *compteur; j++)
		{
			srand(time(NULL));
			saisie = 'O';
			system("CLS");
			affichageScore(player, compteur);
			cout << endl << endl << "Joueur " << j + 1 << " c'est a ton tours" << endl;
			cout << "Appuie sur * pour lancer ta boule pour jouer le coup 1 :" << endl;
			do
			{
				saisie = _getch();
			} while (saisie != '*');
			player[j].coup1[i] = rand() % 10 + 1;

			player[j].afficheCoup1[i] = player[j].coup1[i] + '0';
			if (player[j].bonus == 2 or player[j].bonus == 1)
			{
				player[j].coup1[i] = player[j].coup1[i] * 2;
			}
			nbMax = 10 - player[j].coup1[i];

			cout << player[j].afficheCoup1[i];

			if (player[j].coup1[i] == 10)
			{
				player[j].bonus = 1;
				player[j].coup2[i] = NULL;
				player[j].afficheCoup1[i] = 'X';
				cout << endl << "Strike !!!" << endl;
			}
			else
			{
				srand(time(NULL));
				affichageScore(player, compteur);
				cout << endl << endl << endl << "Appuie sur * pour jouer le coup 2 :";
				do
				{
					saisie = _getch();
				} while (saisie = !'*');
				player[j].coup2[i] = rand() % nbMax;

				player[j].afficheCoup2[i] = player[j].coup2[i] + '0';
				if (player[j].bonus == 1)
				{
					player[j].coup2[i] = player[j].coup2[i] * 2;
				}

				cout << player[j].coup2[i];
				if ((player[j].coup1[i] + player[j].coup2[i]) == 10)
				{
					player[j].bonus = 2;
					player[j].afficheCoup2[i] = '/';
					cout << endl << "Spare !!" << endl;
				}
			}

			player[j].point[i] = player[j].coup1[i] + player[j].coup2[i];
			if (i != 0)
			{
				player[j].total[i] = player[j].total[i - 1] + player[j].point[i];
			}
			else
			{
				player[j].total[i] = player[j].total[i] + player[j].point[i];
			}
				

			player[j].total[i] = player[j].total[i-1] + player[j].point[i];
			affichageScore(player, compteur);


			saisie = 'O';
			if (i != 9)
			{
				cout << endl << endl << endl << "Appuie sur * pour passer au joueur suivant :";
			}
			else
			{
				cout << endl << endl << endl << "Appuie sur * pour terminer la partie :";
			}
			do
			{
				saisie = _getch();
			} while (saisie != '*');

		}
	}
}

int main(int argc, char ** argv)
{
	Joueur player[SIZE];
	int compteur = 0;
	affichageMenu();
	saisie(player, &compteur);
	jeu(player, &compteur);
	affichageScore(player, &compteur);

	return 0;
}