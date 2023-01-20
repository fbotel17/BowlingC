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
	int bonus[10];
	int coup1[10];
	int coup2[10];
	int strikeBonus[10];
	char afficheCoup1[10];
	char afficheCoup2[10];
	int total[10];
	int coupSup = NULL;
	char afficheCoupSup = NULL;
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

void saisie(Joueur* player, int* compteur)
{
	char prenom1[20];
	int saisieJoueur = 1;
	*compteur = 0;
	system("CLS");
	do
	{
		cout << "Entrez le nom du joueur " << *compteur + 1 << " : ";
		fgets(prenom1, 20, stdin);
		for (int i = 0; i < 20; i++)
		{
			if (prenom1[i] == '\0')
			{
				prenom1[i - 1] = NULL;
			}
		}
		strcpy(player[*compteur].prenom, prenom1);
		if (*compteur != 5)
		{
			cout << "souhaitez vous ajouter un autre joueur ? (1 pour oui, 0 pour non) : ";
			do
			{
				if (saisieJoueur != 0 and saisieJoueur != 1)
				{
					cout << endl << "Entre 0 et 1 (1 pour oui, 0 pour non) : " << endl;
				}

				cin >> saisieJoueur;
			} while (saisieJoueur != 0 and saisieJoueur != 1);
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
	//	cout << "Entrez le nnom du joueur " << i + 1 << " : ";
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



void affichageScoreFinal(Joueur* player, int* compteur)
{

	for (int i = 0; i < *compteur; i++)
	{
		if (i != 0)
		{
			cout << endl << endl << player[i].prenom << endl;
		}
		else
		{
			cout << player[i].prenom << endl;
		}
		for (int j = 0; j < 10; j++)
		{
			cout << "|";
			if (player[i].afficheCoup1[j] != NULL)
			{

				cout << player[i].afficheCoup1[j] << " ";
			}
			/*else if (player[i].coup1[j] == 0)
			{
				cout << "~ ";
			}*/
			else
			{
				cout << "   ";
			}
			if (player[i].afficheCoup2[j] != NULL)
			{
				cout << player[i].afficheCoup2[j] << "  ";

			}/*
			else if (player[i].coup1[j] == 0)
			{
				cout << "~ ";
			}*/
			else
			{
				cout << "  ";
			}
			if (j == 9)
			{
				if (player[i].coupSup != NULL)
				{
					cout << player[i].coupSup << "  ";
				}
			}
			if (player[i].point[j] != NULL)
			{
				if (player[i].point[j] == 10)
				{
					cout << "  ";
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
			if (j == 9)
			{
				cout << " | Score : " << player[i].total[j];

			}

		}

	}


}

void affichageScore(Joueur* player, int* compteur)
{

	for (int i = 0; i < *compteur; i++)
	{
		if (i != 0)
		{
			cout << endl << endl << player[i].prenom << endl;
		}
		else
		{
			cout << player[i].prenom << endl;
		}
		for (int j = 0; j < 10; j++)
		{
			cout << "|";
			if (player[i].afficheCoup1 != NULL)
			{

				cout << player[i].afficheCoup1[j] << " ";
			}
			/*else if (player[i].coup1[j] == 0)
			{
				cout << "~ ";
			}*/
			else
			{
				cout << "   ";
			}
			if (player[i].afficheCoup1 != NULL)
			{
				cout << player[i].afficheCoup2[j] << "  ";

			}/*
			else if (player[i].coup1[j] == 0)
			{
				cout << "~ ";
			}*/
			else
			{
				cout << "  ";
			}
			if (j == 9)
			{
				if (player[i].coupSup != NULL)
				{
					cout << player[i].coupSup << "  ";
				}
			}
			if (player[i].point[j] != NULL)
			{
				if (player[i].point[j] == 10)
				{
					cout << "  ";
				}
				else
				{
					cout << player[i].total[j];
				}

			}
			else
			{
				cout << "   ";
			}

		}
		cout << "|";

	}


}

void jeu(Joueur* player, int* compteur)
{
	int partie;

	do
	{
		system("CLS");
		affichageMenu();
		saisie(player, compteur);
		char saisie;
		int nbMax = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < *compteur; j++)
			{
				player[j].coup1[i] = NULL;
				player[j].coup2[i] = NULL;
				player[j].afficheCoup1[i] = NULL;
				player[j].afficheCoup2[i] = NULL;
				player[j].point[i] = NULL;
				player[j].strikeBonus[i] = NULL;
				player[j].bonus[i] = 0;
				player[j].coupSup = 0;
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
				cout << endl << endl << "Joueur " << j + 1 << " ( " << player[j].prenom << " ) c'est a ton tours" << endl;
				cout << "Appuie sur * pour lancer ta boule pour jouer le coup 1 :";

				//coup1
				do
				{
					saisie = _getch();
				} while (saisie != '*');

				//nombre aléatoire entre 0 et 10
				player[j].coup1[i] = rand() % 11;

				//affiche coup tiré
				cout << player[j].coup1[i] << endl << endl;

				//nbmax = reste de quille
				nbMax = 10 - player[j].coup1[i] + 1;

				if (player[j].coup1[i] == 0)
				{
					player[j].afficheCoup1[i] = '-';
				}
				else
				{
					//conversion du coup1 int en afficheCoup1 en char pour l'affichage
					player[j].afficheCoup1[i] = player[j].coup1[i] + '0';
				}

				

				//si le coup d'avant était un strike ou un spare alors le coup1 est doublé

				/*if (player[j].bonus[i - 1] == 2 or player[j].bonus[i - 1] == 1)
				{
					player[j].coup1[i] = player[j].coup1[i] * 2;
				}*/


				//si strike
				if (player[j].coup1[i] == 10)
				{
					player[j].bonus[i] = 1;
					player[j].coup2[i] = NULL;
					player[j].afficheCoup1[i] = 'X';
					cout << endl << "Strike !!!" << endl << endl;
					/*if ((player[j].bonus[i - 1] == 2 or player[j].bonus[i - 1] == 1))
					{
						player[j].coup1[i] = player[j].coup1[i] * 2;
					}*/
					if (player[j].bonus[i - 1] == 1)
					{
						player[j].strikeBonus[i] = 2;
						if (player[j].strikeBonus[i - 1] == 2)
						{
							player[j].strikeBonus[i] = 3;
						}
						if (player[j].strikeBonus[i - 1] == 3)
						{
							player[j].strikeBonus[i] = 3;
						}
					}
					if (i == 9)
					{
						player[j].coup2[i] = rand() % 11;
						if (player[j].coup2[i] == 10)
						{
							player[j].afficheCoup2[i] = 'X';
							player[j].coupSup = rand() % 11;
							if (player[j].coupSup == 10)
							{
								player[j].afficheCoupSup = 'X';

							}
							else
							{
								player[j].afficheCoupSup = player[j].coupSup + '0';

							}

						}
						else
						{
							player[j].afficheCoup2[i] = player[j].coup2[i] + '0';
							nbMax = 10 - player[j].coup2[i] + 1;
							player[j].coupSup = rand() % nbMax;
							if (player[j].coup2[i] + player[j].coupSup == 10)
							{
								player[j].afficheCoupSup = '/';
							}
							else
							{
								player[j].afficheCoupSup = player[j].coupSup + '0';
							}

						}

						/*
						if (player[j].coupSup == 10)
						{
							player[j].afficheCoupSup = 'X';

						}
						else
						{
							player[j].afficheCoupSup = player[j].coupSup + '0';
						}
						*/

					}

				}
				//si premier coup n'est pas trike
				else
				{
					srand(time(NULL));
					affichageScore(player, compteur);
					cout << endl << endl << endl << "Appuie sur * pour jouer le coup 2 :";
					do
					{
						saisie = _getch();
					} while (saisie = !'*');

					//nombre aléatoire entre 0 et le reste de quille
					player[j].coup2[i] = rand() % nbMax;


					if (player[j].coup2[i] == 0)
					{
						player[j].afficheCoup2[i] = '-';
					}
					else
					{
						//conversion du coup1 int en afficheCoup1 en char pour l'affichage
						player[j].afficheCoup2[i] = player[j].coup2[i] + '0';
					}
					//conversion du coup2 int en afficheCoup2 en char pour l'affichage
					

					cout << player[j].coup2[i] << endl << endl;






					//si spare
					//si la valeur des deux coups fait 10 alors c'est un spare
					//on attribu 2 au bonus pour le joueur, correspondant au spare
					if ((player[j].coup1[i] + player[j].coup2[i]) == 10)
					{
						player[j].bonus[i] = 2;

						//si le coup d'avant était un strike alors le coup2 est doublé
						/*if (player[j].bonus[i - 1] == 1)
						{
							player[j].coup2[i] = player[j].coup2[i] * 2;
						}*/

						player[j].afficheCoup2[i] = '/';
						cout << endl << "Spare !!" << endl << endl;
						if (i == 9)
						{
							cout << endl << endl << endl << "Coup supplémentaire ! Appuie sur * pour jouer :";
							do
							{
								saisie = _getch();
							} while (saisie = !'*');
							player[j].coupSup = rand() % 11;
						}
					}

				}



				/*if (player[j].strikeBonus[i - 1] == 3)
				{
					player[j].total[i - 1] = player[j].total[i - 1] - 30;
					player[j].total[i - 1] = player[j].total[i - 1] + 30;
				}*/
				/*else
				{*/
				//if (player[j].strikeBonus[i - 1] == 2)
				//{
				//	/*player[j].point[i-1] = 20;*/
				//	/*if (player[j].coup1[i] != 10) 
				//	{
				//		player[j].coup1[i] = player[j].coup1[i] * 2;
				//	}*/
				//	
				//	player[j].total[i - 1] = player[j].total[i - 1] + 20;

				//}
			//}


			/*if (player[j].strikeBonus[i - 1] == 2)
			{
				player[j].coup1[i] = player[j].coup1[i] * 2;
			}

			if (player[j].strikeBonus[i - 1] == 3)
			{
				player[j].coup1[i] = player[j].coup1[i] * 2;
			}*/







			//si le coup d'avant était un spare ou strike alors le coup 1 est doublé
				if (player[j].bonus[i - 1] == 2 or player[j].bonus[i - 1] == 1)
				{

					if (player[j].strikeBonus[i - 1] == 2)
					{
						/*player[j].point[i-1] = 20;*/
						/*if (player[j].coup1[i] != 10)
						{
							player[j].coup1[i] = player[j].coup1[i] * 2;
						}*/

						player[j].coup1[i] = player[j].coup1[i] * 3;

					}
					else if (player[j].strikeBonus[i - 1] == 3)
					{
						player[j].coup1[i] = player[j].coup1[i] * 3;
					}
					else
					{
						player[j].coup1[i] = player[j].coup1[i] * 2;
					}
				}


				//si le coup d'avant était un strike alors le coup 2 est doublé
				if (player[j].bonus[i - 1] == 1)
				{
					player[j].coup2[i] = player[j].coup2[i] * 2;


					/*if (player[j].bonus[i - 2] == 1 and player[j].bonus[i - 3] == 1 )
					{
						player[j].coup1[i] = player[j].coup1[i] * 2;
						player[j].coup1[i - 3] = player[j].coup1[i - 3] + 10;

					}

					else
					{
						if (player[j].bonus[i - 2] == 1)
						{
							player[j].coup1[i] = player[j].coup1[i] * 2;

						}
						if (player[j].bonus[i - 3] == 1 and player[j].bonus[i - 2] == 1)
						{
							player[j].coup1[i - 3] = player[j].coup1[i - 3] - 10;

						}
					}*/

				}



				//calcul le total des points du coup
				player[j].point[i] = player[j].coup1[i] + player[j].coup2[i] + player[j].coupSup;

				//aditionne au total de la partie le total d'avant + le nombre de point actuel si on n'est pas au premier coup
				if (i != 0)
				{
					player[j].total[i] = player[j].total[i - 1] + player[j].point[i];

				}
				//si c'est le premier coup alors on attribue au total le nombre de point du premier coup
				else
				{
					player[j].total[i] = player[j].point[i];

				}
				affichageScore(player, compteur);


				saisie = 'O';
				if (i != 9)
				{
					cout << endl << endl << endl << "Appuie sur * pour passer au joueur suivant :";
				}
				/*else
				{
					system("CLS");
					affichageScore(player, compteur);
					cout << endl << endl << endl << "Appuie sur * pour terminer la partie :";
				}
				do
				{
					saisie = _getch();
				} while (saisie != '*');*/
				if (i != 9)
				{
					system("CLS");
					cout << endl << endl << endl << "Appuie sur * pour passer au joueur suivant :";

				}
			}
		}

		system("CLS");
		affichageScoreFinal(player, compteur);
		cout << endl << endl << endl << "Appuie sur 1 pour terminer la partie :";
		do
		{
			saisie = _getch();
		} while (saisie != '1');
		system("CLS");
		partie = 1;
		cout << "souhaitez vous relancer une partie ? (1 pour oui, 0 pour non) : ";
		cin >> partie;
		int c = 0;
		while (c != '\n' && c != EOF)
		{
			c = getchar();
		}
	} while (partie != 0);
}

int main(int argc, char** argv)
{
	Joueur player[SIZE];
	int compteur = 0;
	jeu(player, &compteur);

	return 0;
}