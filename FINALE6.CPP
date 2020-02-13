#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <process.h>
#include<fstream.h>

int wallcountA , wallcountB , movecountA , movecountB, linh , linv;

fstream x, y, z,a;
int code[2];

int flag=0, xh[100], yh[100], zh[100],xv[100],yv[100],zv[100];
int fh=0;
int fv=0;


void Enter();
void Intro();
void Menu();
void Board();
void Work();
void DisplayDetails();

void AboutGame()
{

	clrscr();
	textcolor(YELLOW);
	cout<<endl<<"\t\t\t\t";
	cputs("QUORIDOR");
	cout<<endl<<endl;
	textcolor(LIGHTBLUE);
	cout<<"\t";
	a.open("about.txt", ios::in);
	char li[50];
	while(!a.eof())
	{
	  a.getline(li, '.', 50);
	  cputs(li);

	}
	cout<<endl<<endl<<endl;
	cout<<"\t";
	textcolor(LIGHTRED);
	cputs("Press any key to return to the main menu");
	getch();
	a.close();

	Menu();

}

void Legend()
{
	moveto(500,60);
	setcolor(CYAN);
	outtext("LEGEND");
	moveto(470,70);
	outtext("M - move");
	moveto(470,90);
	outtext("LH - horizontal");
	moveto(475 , 100);
	outtext("wall");
	moveto(470,110);
	outtext("LV - vertical");
	moveto(475 , 120);
	outtext("wall");
}


void RULES()
{
		void Menu();
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
		setbkcolor(BLACK);
		setcolor(DARKGRAY);
		int i,j,x;
		x=0;
		for( i=0;i<10;i++)
		{
		 if(i==0||i==9)
		  setcolor(BLUE);
		 else
		   setcolor(DARKGRAY);

		 line(x,50,x,410);
		 x=x+40;
		}
		x=0;

		for( j=0;j<10;j++)
		{
		 if(j==0||j==9)
		   setcolor(BLUE);
		 else
		  setcolor(DARKGRAY);
		 line(0,50+x,360,50+x);
		 x=x+40;
		}
		setcolor(RED);
		circle(180,390,15);
		moveto(370 , 60);
		setcolor(CYAN);
		outtext("Player A's objective is to make ");
		moveto(370, 70);
		outtext("his coin reach the other end  ");
		moveto(370, 80);
		outtext("of the board");
		getch();
		moveto(370,100);
		outtext("A player can EITHER move his coin ");
		moveto(370,110);
		outtext("or draw a wall in his turn ");
		getch();
		setfillstyle(SOLID_FILL, LIGHTRED);
		bar(161,331,199,369);
		bar(121,371,159,409);
		bar(201,371,239,409);
		setcolor(CYAN);
		moveto(370,130);
		outtext("If he choses to move his coin");
		moveto(370,140);
		outtext("he can do it in the ADJACENT ");
		moveto(370,150);
		outtext("horizontal or vertical squares");
		getch();
		setfillstyle(SOLID_FILL, BLACK);
		bar(161,331,199,369);
		bar(121,371,159,409);
		bar(201,371,239,409);
		moveto(370, 170);
		outtext("If he choses to draw a wall in ");
		moveto(370,180);
		outtext("his turn he can select a horizontal ");
		moveto(370,190);
		outtext("or vertical wall ANYWHERE on ");
		moveto(370,200);
		outtext("the board. The wall will now act ");
		moveto(370,210);
		outtext("as a barrier to the coins of BOTH ");
		moveto(370,220);
		outtext("players");
		getch();
		setcolor(BLUE);
		line(160,370,240,370);
		setcolor(CYAN);
		moveto(370,240);
		outtext("Let us say there is a wall as ");
		moveto(370,250);
		outtext("shown .Thus player A can now move ");
		moveto(370,260);
		outtext("only in horizontal orientation as ");
		moveto(370,270);
		outtext("his path is blocked by the wall");
		getch();
		moveto(370,290);
		outtext("Press any key to go back to menu");
		getch();
		closegraph();
		Menu();


}

struct details
{
	int code;
	char name[20];
	int play;
	int won;
}s,s1;

struct identity
{
	int code;
}id;

void Enter()
{
	int che;
	clrscr();
	x.open("game8.dat", ios::out|ios::ate|ios::binary);
	for(int i=0; i<2; i++)
	{
		z.open("codes4.dat", ios::binary|ios::in);
		che=0;
		cout<<endl;
		cout<<"\n\nPLAYER"<<i+1;
		cout<<endl;
		cout<<"Enter your name: ";
		gets(s.name);
		cout<<endl<<"Enter your code:";
		cin>>s.code;

		code[i]=s.code;
		z.seekp(0,ios::beg);
		while(z.read((char*)&id, sizeof(id)))
		if(s.code==id.code)
			che++;
			z.close();

		if(che==0)
		{
			s.play=0;
			s.won=0;
			x.write((char*)&s, sizeof(s));
			z.open("codes4.dat", ios::binary|ios::out|ios::ate);
			id.code=s.code;
			z.write((char*)&id, sizeof(id));
			z.close();
		}

	}

	x.close();
}

void Intro()
{
	int m=0;
	y.open("game8.dat",ios::in|ios::binary);
	clrscr();
	textcolor(CYAN);
	cout<<"\t\t";
	cputs("OVERIEW");
	cout<<"\n\n\n\n";
	while(y.read((char*)&s, sizeof(s)) || m<2)
	{

	    if(s.code==code[m])
	    {
		if(m==0)
			textcolor(RED);
		else
			textcolor(GREEN);

		cputs("Player ");cout<<m+1<<":              ";
		puts ( s.name);
		cout<<"\n";
		cputs("Code:                  ");
		cout<<s.code;
		cout<<"\n";
		cputs("No.of matches played:  ");
		cout<<s.play;
		cout<<"\n";
		cputs("No. of matches won:    ");
		cout<<s.won;
		cout<<"\n\n\n";
		m++;
		y.seekp(0,ios::beg);

	    }
	}
	y.close();
	cout<<"\n\n\t\t";
	textcolor(CYAN);
	cputs("The game is ready to begin");
	cout<<"\n\t\t";
	cputs("Press any key to begin");
	getch();

}


void DisplayDetails()
{
	fstream f;
	clrscr();
	cout<<endl<<endl<<"\t\t\t\t";
	textcolor(CYAN);
	cputs("STATS");
	cout<<endl<<endl<<endl;
	f.open("game8.dat",ios::out|ios::ate|ios::in|ios::binary);
	f.seekp(0,ios::beg);
	int counter=0;
	while(f.read((char*)&s,sizeof(s)))
	{
		counter++;
		if(s.code==code[0])
		{
		      textcolor(BLUE);
		      cputs("\nPlayer Name");
		      cout<<"\t\t";
		      cputs("Number of moves");
		      cout<<"\t\t";
		      cputs("Number of walls");
		      cout<<"\n";
		      puts(s.name);
		      cout<<"\t\t\t";
		      cout<<movecountA;
		      cout<<"\t\t\t\t";
		      cout<<wallcountA;
		      cout<<"\n";
		      if(flag==1)
			      s.won++;
		     s.play++;
		    f.seekp((sizeof(s)*(counter-1)), ios::beg);
		    f.write((char*)&s, sizeof(s));

		    break;

		}
	  }

	  f.seekp(0,ios::beg);
	  int counter2=0;
	  while(f.read((char*)&s,sizeof(s)))
	   {

		counter2++;
		if(s.code==code[1])
		{
			cout<<"\n ";
			puts(s.name);
			cout<<"\t\t\t";
			cout<<movecountB;
			cout<<"\t\t\t\t";
			cout<<wallcountB;
			cout<<"\n";
			if(flag==2)
			   s.won++;
			s.play++;
			f.seekp((sizeof(s)*(counter2-1)), ios::beg);
			f.write((char*)&s, sizeof(s));

			break;

		}

	}
	f.close();
	getch();

}

void Menu()
{
	clrscr();
	int choice;
	void WORK();
	textcolor(CYAN);
	cout<<endl;
	cout<<"\t\t\t\t  ";
	cputs("MENU");
	cout<<endl<<endl;
	textcolor(MAGENTA);
	cout<<"\t";
	cputs("1.Play game");
	cout<<endl<<"\t";
	cputs("2.How to play");
	cout<<endl<<"\t";
	cputs("3.About the game");
	cout<<endl<<"\t";
	cputs("4.Exit");
	cout<<endl<<endl<<"\t";
	textcolor(YELLOW);
	cputs("Indicate your choice by entering the corresponding number");
	cout<<endl<<endl<<"\t";
	cin>>choice;

	if(choice==1)
	{

		flag=0;
		Enter();
		Intro();
		Board();
		Legend();
		WORK();
		getch();
		closegraph();
		DisplayDetails();
		Menu();
	 }

	else if(choice == 3)
		AboutGame();

	else if(choice==2)
	   RULES();

	else if(choice == 4)
	{
		textcolor(LIGHTRED);
		clrscr();
		cout<<endl<<endl<<endl<<endl<<endl<<"\t\t\t";
		cputs("The program will close down now");
		getch();
		exit(0);
	 }

}

void Board()
{
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
		setbkcolor(BLACK);
		setcolor(DARKGRAY);
		int i,j,x;
		x=0;

		for( i=0;i<10;i++)
		{
			if(i==0||i==9)
				setcolor(BLUE);
			else
				setcolor(DARKGRAY);

			line(100+x,50,100+x,410);
			x=x+40;
		}
		x=0;

		for( j=0;j<10;j++)
		{
			if(j==0||j==9)
				setcolor(BLUE);
			else
				setcolor(DARKGRAY);
			line(100,50+x,460,50+x);
			x=x+40;
		}
		setcolor(DARKGRAY);
		moveto(75,70);
		outtext("A");
		moveto(75,110);
		outtext("B");
		moveto(75,150);
		outtext("C");
		moveto(75,190);
		outtext("D");
		moveto(75,230);
		outtext("E");
		moveto(75,270);
		outtext("F");
		moveto(75,310);
		outtext("G");
		moveto(75,350);
		outtext("H");
		moveto(75,390);
		outtext("I");
		moveto(120,35);
		outtext("1");
		moveto(160,35);
		outtext("2");
		moveto(200,35);
		outtext("3");
		moveto(240,35);
		outtext("4");
		moveto(280,35);
		outtext("5");
		moveto(320,35);
		outtext("6");
		moveto(360,35);
		outtext("7");
		moveto(400,35);
		outtext("8");
		moveto(440,35);
		outtext("9");
		setcolor(RED);
		circle(280,70,15);
		setcolor(GREEN);
		circle(280,390,15);
}

int i=0;
int a1 , a2;
char b1 , b2;

int condition ( int c, char r, int a , char b)
{

	int X(int );
	int Y (char );
	int i=0;
	int j=0;
	int wo=0;

	if ( c>9|| c<1)
		wo++;
	else if( r>'I'||r<'A')
		wo++;

	if(c>(a+1)||c<(a-1))
		wo++;
	if(r>(b+1)||r<(b-1))
		wo++;
	if( c!=a && r!=b)
		wo++;

	if(::i%2==0)
	{
		if ( c==a2 && r==b2)
			wo++;
	}
	else
		if( c==a1 && r==b1 )
			wo++;

	if ( c==a)
	{
		for ( i=0;i<linh;i++)
		{
			if( (yh[i]>Y(r) && yh[i]<Y(b))||(yh[i]<Y(r) && yh[i]>Y(b)) )
				if(a==xh[i] || a==zh[i])
					wo++;

		}
	}
	else if ( r==b)
		for(j=0;j<linv;j++)
		{
			if(( xv[j]>X(c) && xv[j]<X(a))||(xv[j]<X(c) && xv[j]>X(a)) )
				if( b== yv[j] ||  b==zv[j] )
					wo++;

		}

	if(wo==0)
		return(1);
	else
		return (0);

}

int draw( int a , char b)
{
	int k[4];int fla=0;

	k[0] = condition ( a , ++b , a , b);
	k[1] = condition ( a , --b, a, b);
	k[2]= condition ( ++a , b, a ,b );
	k[3] = condition ( --a, b, a , b);
	for ( int i =0 ; i<4; i ++)
	{
		if ( k[i]==1)
			fla++;
	}

	if ( fla==0)
		return (1);
	else
		return(0);
}


void W(int i )
{
	int X(int);
	int Y(char );
	static int m,n;
	if(fh==0)
		m=0;
	if(fv==0)
		n=0;
	char chv;
	cin>>chv;
	if(chv=='H')
	{
		char r; int c1,c2;
		cin>>r>>c1>>c2;
		setcolor(BLUE);
		line ( (X(c1)-20) , (Y(r)+20) , X(c2) + 20 , Y(r)+20 );
		yh[m]=Y(r)+20; xh[m]= c1 ; zh[m] = c2;
		m++;fh++;linh++;
	}
	else if(chv=='V')
	{
		char r1,r2; int c;
		cin>>c>>r1>>r2;
		setcolor(BLUE);
		line( X(c)+20 , Y(r1) -20 , X(c)+20 , Y(r2) +20);
		xv[n]=X(c)+20; yv[n]=r1 ; zv[n] = r2;
		n++;
		fv++;
		linv++;
	}
	setcolor(BLACK);
	if(i%2==0)
	{
		moveto(280,430);
		outtext("Player 1");
	}
	else
	{
		moveto(280,20);
		outtext("Player 2");
	}
}

void WORK()
{

	 linh=0;  linv=0;
	int coinA=0;
	int coinB=1;
	 wallcountA =0;  wallcountB=0;  movecountA=0;
	 movecountB=0;
	void W(int );
	i=0;
	char ch;
	void PA( int);
	void PB( int);
	while(flag==0)
	{
		if(::i%2==0)
		{
			setcolor(GREEN);
			moveto(280 ,430);
			outtext("Player 1");
			cin>>ch;
			if(ch=='M')
			{
				PA(coinA);
				coinA++;
				movecountA++;
			}
			else if (ch=='L')
			{
				wallcountA++;
				W(::i);
			}
			else if(ch  == 'Q' || ch == 'q')
			 exit(0);
		}

		else
		{
			setcolor(RED);
			moveto(280,20);
			outtext("Player 2");
			cin>>ch;
			if(ch=='M' || ch=='m')
			{
				movecountB++;
				PB(coinB);
				coinB++;
			}
			else if( ch=='L' || ch=='l')
			{
				wallcountB++;
				W(::i);
			}
			else if(ch  == 'Q' || ch == 'q')
			 exit(0);
		}
		i++;

	}
	if(flag==1)
	{
		setcolor(GREEN);
		moveto(280,430);
		outtext("PLAYER 1 WINS");

	}
	else if (flag==2)
	{
		setcolor(RED);
		moveto(280,20);
		outtext("PLAYER 2 WINS");

	}
	else if (flag==3)
	{
	  setcolor(CYAN);
	  moveto(300, 230);
	  outtext("DRAW MATCH");
	}

}

int X(int col)
{
	int k;
	for(int i=1;i<=9;i++)
	{
		if(i==col)
		{
			k=col;
		}
	}
	return(80+(40*k));
}

int Y(char row)
{
	char c='A';
	int k;

	for(int i=0;i<10;i++,c++)
	if(row==c)
		k=i;
	return(70 +(40*k));
}

void PA(  int coin)
{
	static int a; static int b;
	if(coin==0)
	{
		a=5;
		b='I';
	}

	char r; int c,check;

	int d = draw ( a, b );

	if ( d==1)
	{
		flag=3;
		WORK();
	}
	else
	{
		TryA:
			cin>>c>>r;
			a1=c;
			b1=r;
			setcolor(BLACK);
			moveto(250,435);
			outtext("Incorrect Move-Try again");
			int condition ( int , char, int , char);
			check=condition(c,r, a, b);
			if(check==1)
			{
				setcolor(BLACK);
				circle( X(a) , Y(b) , 15);
				setcolor(GREEN);
				circle( X(c), Y(r) , 15);
				setcolor(BLACK);
				moveto(280,430);
				outtext("Player 1");
			}
			else
			{
				setcolor(WHITE);
				moveto(250,435);
				outtext("Incorrect move-Try again");
				goto TryA;
			}
			if(r=='A')
				flag=1;
			a=c;
			b=r;
	}
}

void PB( int coin)
{
	static int a; static int b;
	if(coin==1)
	{
		a=5;
		b='A';
	}
	char r;
	int c, check;
	int d=draw(a,b);
	if(d==1)
	{
		flag=3;
		WORK();
	}
	else
	{
		TryB:
		cin>>c>>r;
		a2=c;
		b2=r;
		setcolor(BLACK);
		moveto(250,15);
		outtext("Incorrect move-Try again");
		int condition ( int , char, int , char);
		check=condition(c,r, a , b);
		if(check==1)
		{
			setcolor(BLACK);
			circle(X(a), Y(b), 15);
			setcolor(RED);
			circle(X(c), Y(r), 15);

			setcolor(BLACK);
			moveto(280,20);
			outtext("Player 2");
		 }
		else
		{
			setcolor(WHITE);
			moveto(250,15);
			outtext("Incorrect move-Try again");
			goto TryB;
		}
		if ( r=='I')
			flag=2;
		a=c;
		b=r;
	}
}

void main()
{
	clrscr();
	int Check(char[] , char[] );
	char pass[8];int i=0;
	char password[8]="quoridor";
	clrscr();
	cout<<"Password:\t";
	while( i<8)
	{
	 pass[i]=getch();
	 cout<<"*";
	 i++;
	}

       if(Check(pass,password)==0)
       {
		cout<<"\nAccess granted";
		getch();
		Menu();

       }
       else
		cout<<"Access denied";
}

Check(char a[],char b[])
{
	int i,k=0;
	for (i=0;i<8;i++)
	{
		if(a[i]!=b[i])
		k++;
	}
	if(k==0)
		return(0);
	else
		return(1);
}

