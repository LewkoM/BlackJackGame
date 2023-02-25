// POP 2020-12-08 projekt 1 Lewko Michal EIT 6 184511 Dev-C++ 5.11 TDM-GCC 4.9.2 64-bit Release

#include <iostream>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

int liczg(int wart[], int tabg[]) //podprogram liczy sumê w kartach gracza
{
	int suma=0;
	for(int i=0; i<52; i++) //petla przeszukuje tabele z kartami gracza i dodaje wartosci kart
	{
		for(int j=0; j<tabg[i]; j++)
		{
			suma=suma+wart[i];
		}
	}
	for(int i=0; i<4; i++) //petla zamienia wartosci asa z 11 na 1 gdy suma kart przekroczy 21
	{
		if(suma>21)
		{
			for(int j=0; j<tabg[i*13+12]; j++)
			{
				suma=suma-10;
				if(suma<=21)
				{
					break;
				}
			}
		}
	}
	return suma;
}

int liczg2(int wart[], int tabg2[]) //podprogram liczy sumê w kartach gracza2(2reka)-rozdzielenie
{
	int suma=0;
	for(int i=0; i<52; i++) //petla przeszukuje tabele z kartami gracza i dodaje wartosci kart
	{
		for(int j=0; j<tabg2[i]; j++)
		{
			suma=suma+wart[i];
		}
	}
	for(int i=0; i<4; i++) //petla zamienia wartosci asa z 11 na 1 gdy suma kart przekroczy 21
	{
		if(suma>21)
		{
			for(int j=0; j<tabg2[i*13+12]; j++)
			{
				suma=suma-10;
				if(suma<=21)
				{
					break;
				}
			}
		}
	}
	return suma;
}

int liczk(int wart[], int tabk[], int tab1[], int &nk) //podprogram liczy sumê w kartach krupiera oraz ewentualnie dobiera zgodnie z zasadami gry
{
	int suma=0;
	while(suma<17)
	{
		suma=0;
		for(int i=0; i<52; i++) //petla przeszukuje tabele z kartami krupiera i dodaje wartosci kart
		{
			for(int j=0; j<tabk[i]; j++)
			{
				suma=suma+wart[i];
			}
		}
		for(int i=0; i<4; i++) //petla zamienia wartosci asa z 11 na 1 gdy suma kart przekroczy 21
		{
			if(suma>21)
			{
				for(int j=0; j<tabk[i*13+12]; j++)
				{
					suma=suma-10;
					if(suma<=21)
					{
						break;
					}
				}
			}
		}
		if(suma<17) //petla ktora dobiera karty dla krupiera do momentu gdy bedzie mial sume kart rowna co najmniej 17
		{
			int x;
			for(int i=0; i<1; i++) //dobieranie 1 kart przez krupiera
			{
				x=rand() % 52;
				if(tab1[x]<3)
				{
					tabk[x]=(tabk[x]+1);
					tab1[x]=(tab1[x]+1);
					nk++;
				}
				else
				{
					i--;
				}
			}
		}
	}
		return suma;
}

void pokazkartyg(string tab[], int tabg[], int &ng) //podprogram wyswietlajacy karty gracza
{
	int y;
	for(int i=0; i<ng; i++)
	{cout<<"--------- ";} cout<<endl;
	
		for(int j=0; j<52; j++)
		{
			for(int z=0; z<tabg[j]; z++)
			{
				y=j;
				if(tab[y]=="10"){cout<<"|"<<tab[y]<<"     | ";}
				else{cout<<"|"<<tab[y]<<"      | ";}
			}
		}
	 cout<<endl;
	for(int i=0; i<ng; i++)
	{cout<<"|       | ";}
	cout<<endl;
	
		for(int j=0; j<52; j++)
		{
			for(int z=0; z<tabg[j]; z++)
			{
				y=j;
				cout<<"|   ";
				if(y<=12)// Kier 0-12
				{
					char kolor=3;
					cout<<kolor;
				}
				else if((y>12)&&(y<=25))// Karo 13-25
				{
					char kolor=4;
					cout<<kolor;
				}
				else if((y>25)&&(y<=38))// Pik 26-38
				{
					char kolor=5;
					cout<<kolor;
				}
				else if((y>38)&&(y<=52))// Trefl 39-52
				{
					char kolor=6;
					cout<<kolor;
				}
			cout<<"   | ";
			}
		}
	
	cout<<endl;
	for(int i=0; i<ng; i++)
	{cout<<"|       | ";}
	cout<<endl;
	
	
		for(int j=0; j<52; j++)
		{
			for(int z=0; z<tabg[j]; z++)
			{
				y=j;
				cout<<"|     "<<setw(2)<<tab[y]<<"| ";
			}
		}
		
	
	cout<<endl;
	for(int i=0; i<ng; i++)
	{cout<<"--------- ";}
	cout<<endl;
	
}

void pokazkartyg2(string tab[], int tabg2[], int &ng2) //podprogram wyswietlajacy karty gracza2-rozdzielenie
{
	int y;
	for(int i=0; i<ng2; i++)
	{cout<<"--------- ";} cout<<endl;
	
		for(int j=0; j<52; j++)
		{
			for(int z=0; z<tabg2[j]; z++)
			{
				y=j;
				if(tab[y]=="10"){cout<<"|"<<tab[y]<<"     | ";}
				else{cout<<"|"<<tab[y]<<"      | ";}
			}
		}
	 cout<<endl;
	for(int i=0; i<ng2; i++)
	{cout<<"|       | ";}
	cout<<endl;
	
		for(int j=0; j<52; j++)
		{
			for(int z=0; z<tabg2[j]; z++)
			{
				y=j;
				cout<<"|   ";
				if(y<=12)// Kier 0-12
				{
					char kolor=3;
					cout<<kolor;
				}
				else if((y>12)&&(y<=25))// Karo 13-25
				{
					char kolor=4;
					cout<<kolor;
				}
				else if((y>25)&&(y<=38))// Pik 26-38
				{
					char kolor=5;
					cout<<kolor;
				}
				else if((y>38)&&(y<=52))// Trefl 39-52
				{
					char kolor=6;
					cout<<kolor;
				}
			cout<<"   | ";
			}
		}
	
	cout<<endl;
	for(int i=0; i<ng2; i++)
	{cout<<"|       | ";}
	cout<<endl;
	
	
		for(int j=0; j<52; j++)
		{
			for(int z=0; z<tabg2[j]; z++)
			{
				y=j;
				cout<<"|     "<<setw(2)<<tab[y]<<"| ";
			}
		}
		
	
	cout<<endl;
	for(int i=0; i<ng2; i++)
	{cout<<"--------- ";}
	cout<<endl;
	
}

void pokazkartyk(string tab[], int tabk[], int &nk) //podprogram wyswietlajacy karty krupiera
{
	int y;
	for(int i=0; i<nk; i++)
	{cout<<"--------- ";} cout<<endl;
	for(int i=0; i<1; i++)
	{
		for(int j=0; j<52; j++)
		{
			for(int z=0; z<tabk[j]; z++)
			{
				y=j;
				if(tab[y]=="10"){cout<<"|"<<tab[y]<<"     | ";}
				else{cout<<"|"<<tab[y]<<"      | ";}
			}
		}
	} cout<<endl;
	for(int i=0; i<nk; i++)
	{cout<<"|       | ";}
	cout<<endl;
	for(int i=0; i<1; i++)
	{
		for(int j=0; j<52; j++)
		{
			for(int z=0; z<tabk[j]; z++)
			{
				y=j;
				cout<<"|   ";
				if(y<=12)// Kier 0-12
				{
					char kolor=3;
					cout<<kolor;
				}
				else if((y>12)&&(y<=25))// Karo 13-25
				{
					char kolor=4;
					cout<<kolor;
				}
				else if((y>25)&&(y<=38))// Pik 26-38
				{
					char kolor=5;
					cout<<kolor;
				}
				else if((y>38)&&(y<=52))// Trefl 39-52
				{
					char kolor=6;
					cout<<kolor;
				}
			cout<<"   | ";
			}
		}
	}
	cout<<endl;
	for(int i=0; i<nk; i++)
	{cout<<"|       | ";}
	cout<<endl;
	for(int i=0; i<1; i++)
	{
		for(int j=0; j<52; j++)
		{
			for(int z=0; z<tabk[j]; z++)
			{
				y=j;
				cout<<"|     "<<setw(2)<<tab[y]<<"| ";
			}
		}
		
	}
	cout<<endl;
	for(int i=0; i<nk; i++)
	{cout<<"--------- ";}
	cout<<endl;
	
}

void tasowanie(int tab1[], int tabg[], int tabk[]) //podprogram tasujacy karty po zakonczonej grze
{
	for(int i=0; i<52; i++)
	{
		tab1[i]=0;
		tabg[i]=0;
		tabk[i]=0;
	}
}

void rozgrywka(int &nk, int &ng, int &money) //podprogram symulujacy jedna rozgrywke
{
	int sumak=0, sumag=0;
	string tab[52] = {
	"2","3","4","5","6","7","8","9","10","J","Q","K","A", 
	"2","3","4","5","6","7","8","9","10","J","Q","K","A",
	"2","3","4","5","6","7","8","9","10","J","Q","K","A",
	"2","3","4","5","6","7","8","9","10","J","Q","K","A"}; //tablica kart i ich symboli
	int wart[52] = {2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11}; //tablica wartosci danych kart
	int tab1[52] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //tablica pomocnicza
	int tabg[52] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //tablica pomocnicza do zapisu kart gracza
	int tabk[52] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //tablica pomocnicza do zapisu kart krupiera
	int graa=1;
	int stawka=1, war=1;
	cout<<"Podaj stawke: ";
	while(war==1) //podawanie stawki o jaka gracz chce grac
	{
		cin>>stawka;
		if(stawka>money)
		{
			cout<<"Nie masz wystarczajaco duzo zetonow!"<<endl;
		}
		else
		{
		
			war=0;
		}
	}
	int x;
	for(int i=0; i<2; i++) //poczatkowe losowanie kart krupiera
	{
		x=rand() % 52;
		if(tab1[x]<3)
		{
			tabk[x]=(tabk[x]+1);
			tab1[x]=(tab1[x]+1);
		}
		else
		{
			i--;
		}
	}
	tabg[0]=1;
	tab1[0]=1;
	tabg[13]=1;
	tab1[13]=1;
	cout<<"Twoje karty:"<<endl;
	pokazkartyg(tab, tabg, ng); //wywolanie funkcji pokazywania kart gracza
	cout<<endl<<"Suma twoich kart: "<<liczg(wart, tabg);
	cout<<endl<<endl<<"Karty krupiera:"<<endl;
	cout<<"--------- "<<endl;
	for(int j=0; j<52; j++) //pokazanie tylko 1 z kart krupiera
	{
		int czy=0;
		for(int z=0; z<tabk[j]; z++)
		{
			if(tab[j]=="10"){cout<<"|"<<tab[j]<<"     | ";}
			else{cout<<"|"<<tab[j]<<"      | ";}
			czy=1;
			break;
		}
		if(czy==1){break;}
	}
	cout<<endl<<"|       | "<<endl;
	for(int j=0; j<52; j++)
	{
		int czy=0;
		for(int z=0; z<tabk[j]; z++)
		{
			cout<<"|   ";
			if(j<=12)// Kier 0-12
			{
				char kolor=3;
				cout<<kolor;
				czy=1;
				break;
			}
			else if((j>12)&&(j<=25))// Karo 13-25
			{
				char kolor=4;
				cout<<kolor;
				czy=1;
				break;
			}
			else if((j>25)&&(j<=38))// Pik 26-38
			{
				char kolor=5;
				cout<<kolor;
				czy=1;
				break;
			}
			else if((j>38)&&(j<=52))// Trefl 39-52
			{
				char kolor=6;
				cout<<kolor;
				czy=1;
				break;
			}
		}
		if(czy==1){cout<<"   | ";break;}
	}	
	cout<<endl<<"|       | "<<endl;
	for(int j=0; j<52; j++)
	{
		int czy=0;
		for(int z=0; z<tabk[j]; z++)
		{
			cout<<"|     "<<setw(2)<<tab[j]<<"| ";
			czy=1;
			break;
		}
		if(czy==1){break;}
	}
	cout<<endl<<"--------- "<<endl;
	cout<<"Druga karta krupiera nieznana!"<<endl<<endl;	
	bool przegrana=0;
	
	while((graa>0) && (przegrana==0)) //menu z mozliwymi akcjami dla gracza
	{
		cout<<"*Mozliwe akcje:*"<<endl<<"1.Dobierz karte"<<endl<<"2.Nie dobieraj"<<endl<<"3.Podwoj stawke"<<endl<<"4.Rozdziel karty"<<endl<<"5.Zakoncz gre"<<endl;
		cin>>graa;
		switch(graa)
		{
			case 5: //zakonczenie petli i koniec rozgrywki
				{
					money=money-stawka;
					graa=0;
					ng=2;
					nk=2;
					break;
				}
			case 1: //dobieranie 1 karty przez gracza
				{
					for(int i=0; i<1; i++)
					{
						int x=(rand() %52);
						if(tab1[x]<3)
						{
							tabg[x]=tabg[x]+1;
							tab1[x]=tab1[x]+1;
						}
						else
						{
							i--;
						}
					}
						ng++;
						cout<<"Twoje karty:"<<endl;
						pokazkartyg(tab, tabg, ng);
						int sumakart=liczg(wart, tabg);
						cout<<endl<<"Suma twoich kart: "<<sumakart<<endl;
						if(sumakart>21)
						{
							cout<<"Przegrales, za duza suma kart!"<<endl<<endl;
							money=money-stawka;
							przegrana=1;
							ng=2;
						}
					break;
				}
			case 2: //gracz pasuje, pokazywane sa karty krupiera, wygrywa najwieksza wartosc kart nie przekraczajaca 21
				{
					cout<<"Nie dobrales kart."<<endl;
					int gracz, krupier;
					gracz=liczg(wart, tabg);
					krupier=liczk(wart, tabk, tab1, nk);
					cout<<"Twoje karty:"<<endl;
					pokazkartyg(tab, tabg, ng);
					cout<<"Suma twoich kart: "<<gracz<<endl;
					cout<<"Karty krupiera:"<<endl;
					pokazkartyk(tab, tabk, nk);
					cout<<"Suma kart krupiera: "<<krupier<<endl<<endl;
					if(krupier<=21)
					{
						if(gracz>krupier)
						{
							cout<<"Wygrales!"<<endl;
							money=money+2*stawka;
						}
						else if(gracz==krupier)
						{
							cout<<"Remis!"<<endl;
							money=money+stawka;
						}
						else
						{
							cout<<"Przegrales!"<<endl;
							money=money-stawka;
						}
					}
					else
					{
						cout<<"Wygrales!"<<endl;
						money=money+2*stawka;
					}
					cout<<endl;
					przegrana=1;
					nk=2; ng=2;
					break;
				}
			case 3: //podwojenie stawki przy doborze tylko 1 karty przez gracza
				{	
				
					if(ng==2)
					{
						stawka=stawka*2;
						int x=(rand() %52);
						for(int i=0; i<1; i++)
						{
							if(tab1[x]<3)
								{
									tabg[x]=tabg[x]+1;
									tab1[x]=tab1[x]+1;
									ng++;
								}
							else
								{
									i--;
								}
						}
					}
					else 
					{cout<<"Mozesz podwoic stawke majac tylko dwie karty, nie wiecej!"<<endl;break;}
				
					cout<<"Twoje karty:"<<endl;
						pokazkartyg(tab, tabg, ng);
						int sumakart=liczg(wart, tabg);
						cout<<endl<<"Suma twoich kart: "<<sumakart<<endl;
						if(sumakart>21)
						{
							cout<<"Przegrales, za duza suma kart!"<<endl<<endl;
							money=money-stawka;
							przegrana=1;
							ng=2;
							nk=2;
							break;
						}
					int gracz, krupier;
					gracz=liczg(wart, tabg);
					krupier=liczk(wart, tabk, tab1, nk);	
					cout<<"Karty krupiera:"<<endl;
					pokazkartyk(tab, tabk, nk);
					cout<<endl<<"Suma kart krupiera: "<<krupier<<endl;
					if(krupier<=21)
					{
						if(gracz>krupier)
						{
							cout<<endl<<"Wygrales!"<<endl;
							money=money+stawka;
						}
						else if(gracz==krupier)
						{
							cout<<endl<<"Remis!"<<endl;
						}
						else
						{
							cout<<endl<<"Przegrales!"<<endl;
							money=money-stawka;
						}
					}
					else
					{
						cout<<"Wygrales!"<<endl;
						money=money+2*stawka;
					}
					cout<<endl;
					przegrana=1;
					nk=2; ng=2;
					break;			
				}
			case 4: //gdy gracz posiada dwie takie same karty to moze je rozdzielic i dobierac na dwie rece
				{
					if(ng==2)
					{
					
						int tabg2[52] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
						int ng2=0;
						bool dwie=0;
						for(int i=0;i<13;i++)
						{
							if((tabg[i] + tabg[i+13] + tabg[i+26] + tabg[i+39]) == 2)
							{
								dwie=1;
							}
							
						}
						if(dwie==1)
						{
								int j=0;
							for(int i=0;i<13;i++)
							{
								if((tabg[i] + tabg[i+13] + tabg[i+26] + tabg[i+39]) == 2)
								{
									dwie=1;
									ng--;
									ng2++;
								}
								for(j; j<1; j++)
								{
									for(int k=0; k<52; k++)
									{
										if(tabg[k]>=1)
										{
											tabg[k]-=1;
											tabg2[k]=1;
											j=1;
											break;
										}
									}
								}
								
							}
							
							stawka=stawka*2;
							// akcje a kartami na jedna reke 
							bool pierwsza=0;
							bool porazka1=0;
							while((graa>0) && (przegrana==0)) //menu z mozliwymi akcjami dla gracza
							{
								
								if(pierwsza==0)
								{
								
									cout<<"*Mozliwe akcje na pierwsza reke:*"<<endl;
									cout<<"1.Dobierz karte"<<endl<<"2.Nie dobieraj"<<endl<<"3.Zakoncz gre"<<endl;
									cin>>graa;
									switch(graa)
									{
										case 3: //zakonczenie petli i koniec rozgrywki
											{
												money=money-stawka;
												graa=0;
												ng=2;
												nk=2;
												break;
											}
										case 1: //dobieranie 1 karty na pierwsza reke
											{
												
													for(int i=0; i<1; i++)
													{
														int x=(rand() %52);
														if(tab1[x]<3)
														{
															tabg[x]=tabg[x]+1;
															tab1[x]=tab1[x]+1;
														}
														else
														{
															i--;
														}
													}
														ng++;
														cout<<"Twoje karty na pierwszej rece:"<<endl<<endl;;
														pokazkartyg(tab, tabg, ng);
														int sumakart=liczg(wart, tabg);
														cout<<endl<<"Suma twoich kart na pierwszej rece: "<<sumakart<<endl;
														if(sumakart>21)
														{
															cout<<"Przegrales na pierwszej rece, za duza suma kart! Zaczynasz gre na drugiej rece!"<<endl<<endl;
															stawka=(stawka/2);
															money=money-stawka;
															porazka1=1;
															pierwsza=1;	
														}
											
																
											break;
											}
										case 2: 
											{
												cout<<"Nie dobrales kart. Zaczynasz grac na drugiej rece!"<<endl;
												pierwsza=1;
												break;
											}
									}
								}
								else if(pierwsza==1)// akcje na druga reke
								{
									cout<<"*Mozliwe akcje na druga reke:*"<<endl;
									cout<<"1.Dobierz karte"<<endl<<"2.Nie dobieraj"<<endl<<"3.Zakoncz gre"<<endl;
									cin>>graa;
									switch(graa)
									{
										case 3: //zakonczenie petli i koniec rozgrywki
											{
												money=money-stawka;
												graa=0;
												ng=2;
												nk=2;
												break;
											}
										case 1: //dobieranie 1 karty na druga reke
											{
												
													for(int i=0; i<1; i++)
													{
														int x=(rand() %52);
														if(tab1[x]<3)
														{
															tabg2[x]=tabg2[x]+1;
															tab1[x]=tab1[x]+1;
														}
														else
														{
															i--;
														}
													}
														ng2++;
														cout<<"Twoje karty na drugiej rece:"<<endl<<endl;
														pokazkartyg2(tab, tabg2, ng2);
														int sumakart=liczg2(wart, tabg2);
														cout<<endl<<"Suma twoich kart na drugiej rece: "<<sumakart<<endl;
														if(sumakart>21 && porazka1==1)
														{
															cout<<"Przegrales na pierwszej i drugiej rece! Przegrywasz gre!"<<endl<<endl;
															money=money-stawka;
															przegrana=1;
															ng=2;
															ng2=0;
															
															break;	
														}
														else if(sumakart>21 && porazka1==0)
														{
															cout<<"Za duza suma kart. Przegrales na drugiej rece!"<<endl;
															int gracz, gracz2, krupier;
															gracz=liczg(wart, tabg);
															gracz2=liczg2(wart, tabg2);
															krupier=liczk(wart, tabk, tab1, nk);
															cout<<"Twoje karty na pierwszej rece:"<<endl;
															pokazkartyg(tab, tabg, ng);
															cout<<"Suma twoich kart na pierwszej rece: "<<gracz<<endl;
															cout<<"Twoje karty na drugiej rece:"<<endl;
															pokazkartyg2(tab, tabg2, ng2);
															cout<<"Suma twoich kart na drugiej rece: "<<gracz2<<endl;
															cout<<"Karty krupiera:"<<endl;
															pokazkartyk(tab, tabk, nk);
															cout<<"Suma kart krupiera: "<<krupier<<endl<<endl;
															if(krupier<=21)
															{
																if((gracz>=krupier && gracz <=21) && (gracz2>=krupier && gracz2 <=21))
																{
																	cout<<"Wygrales na dwoch rekach. Otrzymujesz poczatkowa stawke pomnozona przez 4!"<<endl;
																	money=money+2*stawka;
																}
																else if(((gracz2>=krupier && gracz2 <=21) && porazka1==1) || ((gracz>=krupier && gracz <=21) && (gracz2>=21 && gracz2<krupier) ))
																{
																	cout<<"Wygrales na jednej rece. Nic nie zyskujesz i nic nie tracisz"<<endl;
																	
																}
																else if(gracz==krupier || gracz2==krupier)
																{
																	cout<<"Remis! Nic nie zyskujesz i nic nie tracisz"<<endl;
																	
																}
																else
																{
																	cout<<"Przegrales!"<<endl;
																	money=money-stawka;
																}
															}
															else if(krupier>21 && gracz<=21 && gracz2>21)
															{
																cout<<"Wygrales na jednej rece!"<<endl;
																
															}
															else if(krupier>21 && gracz2<=21 && gracz>21)
															{
																cout<<"Wygrales na jednej rece!"<<endl;
																
															}
															else
															{
																cout<<"Wygrywasz!"<<endl;
																money=money + (2*stawka);
															}
															cout<<endl;
															przegrana=1;
															nk=2; ng=2;
															break;
													}					
											break;
											}
										case 2: //gracz pasuje na drugiej rece, pokazywane sa karty krupiera i suma kart gracza na pierwszej i drugiej rece, wygrywa najwieksza wartosc kart nie przekraczajaca 21
											{
												cout<<"Nie dobrales kart."<<endl;
												int gracz, gracz2, krupier;
												gracz=liczg(wart, tabg);
												gracz2=liczg2(wart, tabg2);
												krupier=liczk(wart, tabk, tab1, nk);
												cout<<"Twoje karty na pierwszej rece:"<<endl;
												pokazkartyg(tab, tabg, ng);
												cout<<"Suma twoich kart na pierwszej rece: "<<gracz<<endl;
												cout<<"Twoje karty na drugiej rece:"<<endl;
												pokazkartyg2(tab, tabg2, ng2);
												cout<<"Suma twoich kart na drugiej rece: "<<gracz2<<endl;
												cout<<"Karty krupiera:"<<endl;
												pokazkartyk(tab, tabk, nk);
												cout<<"Suma kart krupiera: "<<krupier<<endl<<endl;
												if(krupier<=21)
												{
													if((gracz>=krupier && gracz <=21) && (gracz2>=krupier && gracz2 <=21))
													{
														cout<<"Wygrales na dwoch rekach. Otrzymujesz poczatkowa stawke pomnozona przez 4!"<<endl;
														money=money+2*stawka;
													}
													else if(((gracz2>=krupier && gracz2 <=21) && porazka1==1) || ((gracz>=krupier && gracz <=21) && (gracz2>=21 && gracz2<krupier) ))
													{
														cout<<"Wygrales na jednej rece. Nic nie zyskujesz i nic nie tracisz"<<endl;
														
													}
													else if(gracz==krupier || gracz2==krupier)
													{
														cout<<"Remis! Nic nie zyskujesz i nic nie tracisz"<<endl;
														
													}
													else
													{
														cout<<"Przegrales!"<<endl;
														money=money-stawka;
													}
												}
												else if(krupier>21 && gracz<=21 && gracz2>21)
												{
													cout<<"Wygrales na jednej rece!"<<endl;
													
												}
												else if(krupier>21 && gracz2<=21 && gracz>21)
												{
													cout<<"Wygrales na jednej rece!"<<endl;
													
												}
												else
												{
													cout<<"Wygrywasz!"<<endl;
													money=money + (2*stawka);
												}
												cout<<endl;
												przegrana=1;
												nk=2; ng=2;
												break;
										}
									}
									
								}
							}
							for(int i=0; i<52; i++)//usuwanie kart na drugiej rece
							{
								tabg2[i]=0;
							}	
						}
						else
						{cout<<"Nie posiadasz dwoch takich samych kart!"<<endl<<endl;}
				}
				
					else
					{cout<<"Liczba twoich wszystkich kart jest wieksza niz 2!"<<endl<<endl;} 
				break;	
				}
		}		
	}
	tasowanie(tab1, tabg, tabk);	
}

int main()
{
	srand (time(NULL));
	int menu=0;
	int money=100; //ilosc zetonow gracza
	int ng=2; //liczba kart gracza
	int nk=2; //liczba kart krupiera
	int gra=1;
	
	while((gra==1)&&(money>0)) //menu decyzji dla gracza
	{
		cout<<"Menu:"<<endl<<"1.Zacznij gre"<<endl<<"2.Sprawdz stan konta"<<endl<<"3.Zakoncz gre"<<endl;
		cin>>menu;
		cout<<endl;
		switch(menu)
		{
			case 1:
				{
					rozgrywka(nk, ng, money);break; 
				};
			case 2:
				{
					cout<<"Posiadasz: "<<money*10<<"zl"<<endl<<endl; break;
				}
			case 3:
				{
					gra=0;
					break;
				}
			default: 
				{
					cout<<"Wprowadz odpowiednia akcje!"<<endl;break;
				}
		}
	}
	
	cout<<"Koniec gry, zostalo ci: "<<money*10<<"zl";
	
}
