# include "iGraphics.h"
#include<string>
#include<iostream>


int carMove_x,carMove_y,deviderChange_y=5,a,b,c,d,e,f,g,menu=-1,indexNumber=2,m=0,score=0,carpass=0,song=3,sound=1,gameLevel=0,zombieIndex=0,fuelCondition1,fuelCondition2,q=0;

double fuel=125.0,loading=0,Car_Health=100;

char str[18],User_name[18],s[18],saveScore[18],carPass[18];

bool music=true,gunmusic=false,levelCon=true;

char roadMove[13][25]= {"Images\\road\\21.bmp","Images\\road\\22.bmp","Images\\road\\23.bmp","Images\\road\\24.bmp","Images\\road\\25.bmp","Images\\road\\26.bmp","Images\\road\\27.bmp","Images\\road\\28.bmp","Images\\road\\29.bmp","Images\\road\\210.bmp","Images\\road\\211.bmp","Images\\road\\21.bmp","Images\\road\\210.bmp"};

char cars[9][25]= {"Images\\enemyCar\\1.bmp","Images\\enemyCar\\2.bmp","Images\\enemyCar\\3.bmp","Images\\enemyCar\\4.bmp","Images\\enemyCar\\5.bmp","Images\\enemyCar\\6.bmp","Images\\enemyCar\\7.bmp","Images\\enemyCar\\8.bmp","Images\\enemyCar\\9.bmp"};

char sideMove_left[25][25]= {"Images\\sidebg\\row-20.bmp","Images\\sidebg\\row-19.bmp","Images\\sidebg\\row-18.bmp","Images\\sidebg\\row-17.bmp","Images\\sidebg\\row-16.bmp","Images\\sidebg\\row-15.bmp","Images\\sidebg\\row-14.bmp","Images\\sidebg\\row-13.bmp","Images\\sidebg\\row-12.bmp","Images\\sidebg\\row-11.bmp","Images\\sidebg\\row-10.bmp","Images\\sidebg\\row-9.bmp","Images\\sidebg\\row-8.bmp"};

char sideMove_right[26][26]= {"Images\\sidebg\\row-20r.bmp","Images\\sidebg\\row-19r.bmp","Images\\sidebg\\row-18r.bmp","Images\\sidebg\\row-17r.bmp","Images\\sidebg\\row-16r.bmp","Images\\sidebg\\row-15r.bmp","Images\\sidebg\\row-14r.bmp","Images\\sidebg\\row-13r.bmp","Images\\sidebg\\row-12r.bmp","Images\\sidebg\\row-11r.bmp","Images\\sidebg\\row-10r.bmp","Images\\sidebg\\row-9r.bmp","Images\\sidebg\\row-8r.bmp"};

char roadMove2[25][25]={"Images\\road\\10.bmp","Images\\road\\9.bmp","Images\\road\\8.bmp","Images\\road\\7.bmp","Images\\road\\6.bmp","Images\\road\\5.bmp","Images\\road\\4.bmp","Images\\road\\3.bmp","Images\\road\\2.bmp","Images\\road\\1.bmp","Images\\road\\13.bmp","Images\\road\\12.bmp","Images\\road\\11.bmp"};

//ss
char zombie1[25][25]= {"Images\\zombie\\001.bmp","Images\\zombie\\002.bmp","Images\\zombie\\003.bmp","Images\\zombie\\004.bmp","Images\\zombie\\005.bmp","Images\\zombie\\006.bmp","Images\\zombie\\007.bmp","Images\\zombie\\008.bmp","Images\\zombie\\009.bmp","Images\\zombie\\010.bmp","Images\\zombie\\011.bmp","Images\\zombie\\012.bmp","Images\\zombie\\013.bmp","Images\\zombie\\014.bmp","Images\\zombie\\015.bmp"};

char zombie2[25][25]= {"Images\\zombie2\\001.bmp","Images\\zombie2\\002.bmp","Images\\zombie2\\003.bmp","Images\\zombie2\\004.bmp","Images\\zombie2\\005.bmp","Images\\zombie2\\006.bmp","Images\\zombie2\\007.bmp","Images\\zombie2\\008.bmp","Images\\zombie2\\009.bmp","Images\\zombie2\\010.bmp","Images\\zombie2\\011.bmp","Images\\zombie2\\012.bmp","Images\\zombie2\\013.bmp","Images\\zombie2\\014.bmp","Images\\zombie2\\015.bmp"};

char zombie3[25][25]= {"Images\\zombie3\\001.bmp","Images\\zombie3\\002.bmp","Images\\zombie3\\003.bmp","Images\\zombie3\\004.bmp","Images\\zombie3\\005.bmp","Images\\zombie3\\006.bmp","Images\\zombie3\\001.bmp","Images\\zombie3\\002.bmp","Images\\zombie3\\003.bmp","Images\\zombie3\\004.bmp","Images\\zombie3\\005.bmp","Images\\zombie3\\006.bmp","Images\\zombie3\\001.bmp","Images\\zombie3\\002.bmp","Images\\zombie3\\003.bmp"};

char zombie4[25][25]= {"Images\\zombie4\\001.bmp","Images\\zombie4\\002.bmp","Images\\zombie4\\003.bmp","Images\\zombie4\\004.bmp","Images\\zombie4\\010.bmp","Images\\zombie4\\011.bmp","Images\\zombie4\\012.bmp","Images\\zombie4\\013.bmp","Images\\zombie4\\014.bmp","Images\\zombie4\\015.bmp","Images\\zombie4\\016.bmp","Images\\zombie4\\017.bmp","Images\\zombie4\\018.bmp","Images\\zombie4\\019.bmp","Images\\zombie4\\020.bmp"};




char bulletimg[10][25]= {"Images\\others\\bullet.bmp","Images\\others\\bullet.bmp","Images\\others\\bullet.bmp","Images\\others\\bullet.bmp","Images\\others\\bullet.bmp","Images\\others\\bullet.bmp","Images\\others\\bullet.bmp","Images\\others\\bullet.bmp","Images\\others\\bullet.bmp","Images\\others\\bullet.bmp"};

char fuelTank[1][15]= {"fueltank.bmp"};

int flag[10]= {0};
char musicList[10][20]= {"Music\\1.wav","Music\\2.wav","Music\\4.wav","Music\\5.wav","Music\\3.wav"};
int f1=0;
int bulletCondition[10]= {0};

void front();
void menuList();
void newGame();
void settings();
void musicSettings();
void carSelection1();
void carSelection2();
void carSelection3();
void about();
void credit();
void highScore();
void instruction();
void pausetimer();
void resumetimer();
void level();
void gameOver();
void collisionCheck();
void Fuel();
void shoot();
void car_score();
void BackgroundMovement();
void setMove();
void change();
void zombieShow();
void zomcollision();
void zom_Collision_With_Car();
struct FileForSave
{
    char name[30];
    int score;
} pN[100];


struct pass
{
    int p;

} enemyCarpass[10]= {0};
struct move
{
    int x_axis;
    int y_axis;
} roadMovement[13],roadMovement2[25],sideMovement[25],sideMovementRight[26],ec[9],bullet[10],fuel1,zom[12];

void enemyCar()
{
    //Road Left side enemy
    iShowBMP2(ec[0].x_axis,ec[0].y_axis,cars[0],0);
    iShowBMP2(ec[1].x_axis,ec[1].y_axis,cars[4],0);
    iShowBMP2(ec[2].x_axis,ec[2].y_axis,cars[5],0);

    //Road Middle side enemy
    iShowBMP2(ec[3].x_axis,ec[3].y_axis,cars[1],0);
    iShowBMP2(ec[4].x_axis,ec[4].y_axis,cars[2],0);
    iShowBMP2(ec[5].x_axis,ec[5].y_axis,cars[6],0);

    //Road  Right side enemy
    iShowBMP2(ec[6].x_axis,ec[6].y_axis,cars[3],0);
    iShowBMP2(ec[7].x_axis,ec[7].y_axis,cars[7],0);
    iShowBMP2(ec[8].x_axis,ec[8].y_axis,cars[8],0);
}
void roadDevider()
{
    iSetColor(255,255,255);
    iFilledRectangle(362.67,5-deviderChange_y,8,150);
    iFilledRectangle(531.34,5-deviderChange_y,8,150);
    iFilledRectangle(362.67,242.3-deviderChange_y,8,150);
    iFilledRectangle(531.34,242.3-deviderChange_y,8,150);
    iFilledRectangle(362.67,479.6-deviderChange_y,8,150);
    iFilledRectangle(531.34,479.6-deviderChange_y,8,150);
    iFilledRectangle(362.67,716.9-deviderChange_y,8,150);
    iFilledRectangle(531.34,716.9-deviderChange_y,8,150);
    iFilledRectangle(362.67,954.2-deviderChange_y,8,150);
    iFilledRectangle(531.34,954.2-deviderChange_y,8,150);
    iFilledRectangle(362.67,1191.5-deviderChange_y,8,150);
    iFilledRectangle(531.34,1191.5-deviderChange_y,8,150);
}

void bulletShow()
{
    for(int i=0; i<10; i++)
        if(bulletCondition[i]==i+1)
        {
            iShowBMP2(bullet[i].x_axis,bullet[i].y_axis,bulletimg[i],0);
            bullet[i].y_axis+=15;
        }
}
void shoot()
{

    if(bulletCondition[f1]==f1)
    {
        bullet[f1].x_axis=carMove_x+40;
        bullet[f1].y_axis=carMove_y+120;
        bulletCondition[f1]=f1+1;
        if(f1==9)
        {
            bulletCondition[0]=0;
            f1=0;
        }
        else
        {
            bulletCondition[f1+1]=f1+1;
            f1++;
        }

    }
}
void user_Name_Write_file()
{
    int i=0;
    strcpy(pN[i].name,str);
    pN[i].score=score;
    FILE *fp=fopen("Name1.txt","a");
    for(int i=0; i<1; i++)
    {
        fprintf(fp,"%s %d\n", pN[i].name, pN[i].score);
    }
    fclose(fp);
}

void file()
{

    int i=0,k=0;
    FILE *fp = fopen("Name1.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open file \n");
    }

    while (fscanf(fp,"%s %d",&pN[i].name,&pN[i].score) != EOF)
    {
        printf ("%s %d\n", pN[i].name,pN[i].score);
        i++;
        k++;
    }
    fclose(fp);
    strcpy(pN[i].name,str);
    pN[i].score=score;
    printf ("%s %d\n", pN[i].name,pN[i].score);

    FileForSave temp;


    for(int i=0; i<k; i++)
    {
        for(int j=i+1; j<k; j++)
        {
            if(pN[i].score<pN[j].score)
            {
                temp=pN[i];
                pN[i]=pN[j];
                pN[j]=temp;
            }
        }
    }


}
//score_Convert
char *itoa(int num, char *str)
{
    if (str == NULL)
    {
        return NULL;
    }
    sprintf(str, "%d", num);
    return str;
}
void GameState()
{
    if(menu!=7)
    {
        pausetimer();
    }
    if(menu==-1)
    {
        iShowBMP(0,0,"Images\\others\\Loading.bmp");
		iSetColor(255,255,255);
        iFilledRectangle(400,50,loading,20);
		iRectangle(400,50,120,20);
        if(loading<=120)
            loading+=0.5;
		
		iSetColor(255,0,0);
        iText(420,55,"Loading...",GLUT_BITMAP_HELVETICA_18);
       
        if(loading>120)
        {
            menu=0;
        }
    }
    if(menu==0)
    {
        front();

    }

    else if(menu==1)
	 {
		
	  menuList();
	 }
	 else if(menu==2)
	 {
     
	 newGame();

	 }
	 else if(menu==3)
	 {
	 settings();
	 }
	  else if(menu==4)
	 {
	 highScore();
	 }
	  else if(menu==5)
	 {
	instruction();
	 }
	  else if(menu==6)
	  {
	     credit();
	  }
	   else if(menu==12)
	  {
	    about();
	  }

	  else if(menu==8)
	  {
	  musicSettings();
	  
	  
	  }
	  else if(menu==9)
	  {
	  carSelection1();
	  
	  }
	   else if(menu==10)
	  {
	  carSelection2();
	  }
	   else if(menu==11)
	  {
	  carSelection3();
	  }
	  
    else if(menu==7)
    {
        level();
    }


}
void iDraw()
{

    iClear();

    GameState();
}



void iMouseMove(int mx, int my)
{


}



void iPassiveMouse(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        printf("x = %d, y= %d\n",mx,my);
        //new game
        if(menu==1 && mx>90 && mx<210 && my>550 && my<585 )
        {
            menu=2;
        }
		
      
		//settings
        if(menu==1 && mx>90 && mx<210 && my>490 && my<525)
        {
            menu=3;
        }
		//highscore
        if(menu==1 && mx>90 && mx<210 && my>430 && my<465)
        {
            menu=4;
        }
		//instruction
        if(menu==1 && mx>90 && mx<210 && my>370 && my<405)
        {
            menu=5;
        }
		//about
       if(menu==1 && mx>90 && mx<210 && my>310 && my<345)
        {
            menu=12;
        }
		//credit
        if(menu==1 && mx>90 && mx<210 && my>250 && my<285)
        {
            menu=6;
        }
		//exit
        if(menu==1 && mx>90 && mx<210 && my>190 && my<225)
        {
           exit(0);
        }
		//menu 2 back
       if(menu==2 && mx>75 && mx<180 && my>70 && my<100)
        {
            menu=1;
        }
		//menu 3 back
        if(menu==3 && mx>75 && mx<180 && my>70 && my<100)
        {
            menu=1;
        }
		//menu4 back
        if(menu==4 && mx>75 && mx<180 && my>70 && my<100)
        {
            menu=1;
        }
		//menu 5 back 
        if(menu==5 && mx>75 && mx<180 && my>70 && my<100)
        {
            menu=1;
        }
		//menu 6 back 
        if(menu==6 && mx>400 && mx<480 && my>40 && my<70)
        {
            menu=1;
        }
		//menu 12 back 
        if(menu==12 && mx>75 && mx<180 && my>70 && my<100)
        {
            menu=1;
        }

        if(menu==2 && mx>400 && mx<520 && my>120 && my<155 && str[0]!='\0')
        {
			score=0;
			carpass=0;
			gameLevel=0;
            menu=7;
        }
		//music back
		if(menu==8 && mx>75 && mx<180 && my>70 && my<100)
		{
		menu=1;
		}
		//music page
		if(menu==3 && mx>140 && mx<250 && my>445 && my<480)
		{
		menu=8;
		}
		//car button
		if(menu==3 && mx>140 && mx<250 && my>375 && my<410)
		{
		menu=9;
		}
		//lock in
		if( menu==9 && mx>385 && mx<495 && my>80 && my<80+35)
		{
		
		q=0;
		
		
		}
		if( menu==10 && mx>385 && mx<495 && my>80 && my<80+35)
		{
		
		q=1;
		
		
		}
		if( menu==11 && mx>385 && mx<495 && my>80 && my<80+35)
		{
		
		q=2;
		
		
		}
		
		//carselection back
		if(menu==9 && mx>75 && mx<180 && my>70 && my<100)
		{
		menu=1;
		}
		if(menu==10 && mx>75 && mx<180 && my>70 && my<100)
		{
		menu=1;
		}
		if(menu==11 && mx>75 && mx<180 && my>70 && my<100)
		{
		menu=1;
		}
		//carselection1 page rightArrow
		if( menu==9 && mx>835 && mx<850 && my>335 && my<375)
		{
		
		menu=10;
		
		}
		//carselection2 page RightArrow
		else if( menu==10 && mx>835 && mx<850 && my>335 && my<375)
		{
		
		menu=11;
		
		
		}
		//carselection2 page leftArrow
		if( menu==10 && mx>50 && mx<65 && my>335 && my<375)
		{
		
		menu=9;
		
		
		}
		//carselection3 page leftArrow
		if( menu==11 && mx>50 && mx<65 && my>335 && my<375)
		{
		
		menu=10;
			
		}
        //music no 1
        if(menu==8 &&  mx>290 && mx<440 && my>305 && my<330 && sound==1)
        {
            //musicList[0];
            song=0;

            PlaySound(musicList[song],NULL,SND_LOOP | SND_ASYNC);

        }
        //music no 2
        if(menu==8 && mx>290 && mx<640 && my>255 && my<280 && sound==1)
        {
            //musicList[1];
            song=1;
            PlaySound(musicList[song],NULL,SND_LOOP | SND_ASYNC);
        }
        //music no 3
        if(menu==8 && mx>290 && mx<450 && my>209 && my<230 && sound==1)
        {
            //musicList[2];
            song=2;
            PlaySound(musicList[song],NULL,SND_LOOP | SND_ASYNC);
        }
        //music no 4
        if(menu==8 && mx>290 && mx<430 && my>160 && my<180 && sound==1)
        {
            //musicList[3];
            song=3;
            PlaySound(musicList[song],NULL,SND_LOOP | SND_ASYNC);
        }
        //music no 5
        if(menu==8 && mx>290 && mx<460 && my>110 && my<130 && sound==1)
        {
            //musicList[4];
            song=4;
            PlaySound(musicList[song],NULL,SND_LOOP | SND_ASYNC);
        }

        if(menu==8 && mx>405 && mx<445 && my>500 && my<540)
        {

            {
                music=true;

                PlaySound(musicList[song],NULL,SND_LOOP | SND_ASYNC);


            }
            sound=1;
        }
        if(menu==8 && mx>465 && mx<505 && my>500 && my<540)
        {



            music=false;
            PlaySound(0,0,0);
            sound=0;
        }


    }


    if(gameLevel==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(sound==0)
        {
            PlaySound("Music\\gun.wav",NULL,SND_ASYNC);
        }
        shoot();

    }


}


void iKeyboard(unsigned char key)

{
	if(key=='w')
	{
	if(m==1){
			carMove_y+=0;
		}
			
	else if(m==0){
		if(carMove_y <= 595)
		carMove_y+=10;
		
	}
	
	}
	if(key=='a')
	{
	if(m==1){
			carMove_y+=0;
		}
			
	else if(m==0){
		if(carMove_x >= 170)
			carMove_x-=10;
	}
	}
	if(key=='s')
	{
	if(m==1){
			carMove_y+=0;
		}
			
	else if(m==0){
		if(carMove_y >= 50)
			carMove_y-=10;}
	}
	if(key=='d')
	{
	if(m==1){
			carMove_y+=0;
		}
			
	else if(m==0){
		if(carMove_x <= 605)
			carMove_x+=10;
	}
	}
    if(key=='\r' && menu==0)
    {
        menu=1;
    }
    if(key=='m' && menu!=2)
    {
        if(music)
        {

            music=false;
            PlaySound(0,0,0);
            sound=0;

        }
        else
        {
            music=true;

            PlaySound(musicList[song],NULL,SND_LOOP | SND_ASYNC);
            sound=1;


        }
    }
    if(menu==2 && indexNumber<18)
    {
        if(key!='\b')
        {
            if(key!='\r' && key!=' ' )
            {
                str[indexNumber]=key;

                indexNumber++;
                str[indexNumber]='\0';
            }
        }
        else
        {
            if(menu==2 && indexNumber<=0)

                indexNumber=0;

            else

                indexNumber--;
            str[indexNumber]='\0';
        }
    }

    if( menu==7 && key=='\r')
    {
        if(m==1)
        {
			gameLevel=0;
            menu=1;
            fuel=125.0;
            user_Name_Write_file();
            file();
            m=0;
            setMove();
            change();

        }

    }
}


/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_LEFT)
    {
		if(menu==10)
			menu=9;
		else if(menu==11) 
			menu=10;
    }
    if(key == GLUT_KEY_RIGHT)
    {
		 if(menu==9)
			menu=10;
			 else if(menu==10)
				 menu=11;
    }
    if(key == GLUT_KEY_UP)
    {
        
    }
    if(key == GLUT_KEY_DOWN)
    {
       
    }

}
void front()
{

    iShowBMP(0,0,"Images\\others\\mainFront.bmp");
    iSetColor(160,160,160);
    iText(300,50,"Press ENTER to continue",GLUT_BITMAP_TIMES_ROMAN_24);

}
void menuList()
{
    iShowBMP(0,0,"menu.bmp");
    //newgame
    iSetColor(255,255,255);
    iFilledRectangle(85,545,130,45);
    iSetColor(0,0,0);
    iFilledRectangle(90,550,120,35);
    iSetColor(255,0,0);
    iText(95,558,"New Game",GLUT_BITMAP_TIMES_ROMAN_24);

    //settings
    iSetColor(255,255,255);
    iFilledRectangle(85,485,130,45);
    iSetColor(0,0,0);
    iFilledRectangle(90,490,120,35);
    iSetColor(255,0,0);
    iText(110,501,"Settings",GLUT_BITMAP_TIMES_ROMAN_24);
    //highscore
    iSetColor(255,255,255);
    iFilledRectangle(85,425,130,45);
    iSetColor(0,0,0);
    iFilledRectangle(90,430,120,35);
    iSetColor(255,0,0);
    iText(100,441,"Highscore",GLUT_BITMAP_TIMES_ROMAN_24);
    //instructions
    iSetColor(255,255,255);
    iFilledRectangle(85,365,130,45);
    iSetColor(0,0,0);
    iFilledRectangle(90,370,120,35);
    iSetColor(255,0,0);
    iText(91,381,"Instructions",GLUT_BITMAP_TIMES_ROMAN_24);
   //about
	iSetColor(255,255,255);
	iFilledRectangle(85,305,130,45);
	iSetColor(0,0,0);
	iFilledRectangle(90,310,120,35);
	iSetColor(255,0,0);
	iText(122,319,"About",GLUT_BITMAP_TIMES_ROMAN_24);
	//Credit
	iSetColor(255,255,255);
	iFilledRectangle(85,245,130,45);
	iSetColor(0,0,0);
	iFilledRectangle(90,250,120,35);
	iSetColor(255,0,0);
	iText(122,259,"Credit",GLUT_BITMAP_TIMES_ROMAN_24);
	//quit
	iSetColor(255,255,255);
	iFilledRectangle(85,185,130,45);
	iSetColor(0,0,0);
	iFilledRectangle(90,190,120,35);
	iSetColor(255,0,0);
	iText(127,200,"Quit",GLUT_BITMAP_TIMES_ROMAN_24);


}
void newGame()
{
    iShowBMP(0,0,"Images\\others\\name1.bmp");
    iSetColor(255,255,255);
    iRectangle(335,410,240,35);

    iSetColor(255,0,0);
    iText(340,465,"ENTER YOUR NAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,0,0);
    iText(347,421,str,GLUT_BITMAP_TIMES_ROMAN_24);


    iSetColor(255,255,255);
    iFilledRectangle(395,115,130,45);
    iSetColor(0,0,0);
    iFilledRectangle(400,120,120,35);
    iSetColor(255,0,0);
    iText(405,128,"Start Game",GLUT_BITMAP_TIMES_ROMAN_24);
    //back

    iSetColor(255,255,255);
    iFilledRectangle(100,70,80,30);
    double xa[]= {75,100,100};
    double ya[]= {85,60,110};

    iFilledPolygon( xa,ya,3 );
    iSetColor(255,0,0);
    iText(113,77,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
}
void settings()
{

    iShowBMP(0,0,"settings1.bmp");
    iSetColor(255,255,255);
    iFilledRectangle(100,70,80,30);
    double xa[]= {75,100,100};
    double ya[]= {85,60,110};

    iFilledPolygon( xa,ya,3 );
    iSetColor(255,0,0);
    iText(113,77,"Back",GLUT_BITMAP_TIMES_ROMAN_24);

    iText(140,530,"SETTINGS",GLUT_BITMAP_HELVETICA_18);
    iSetColor(255,255,255);
    iFilledRectangle(135,440,120,45);
    iSetColor(0,0,0);
    iFilledRectangle(140,445,110,35);
    iSetColor(255,0,0);
    iText(165,455,"Music",GLUT_BITMAP_TIMES_ROMAN_24);
	//car button

	iSetColor(255,255,255);
	iFilledRectangle(135,370,120,45);
	iSetColor(0,0,0);
	iFilledRectangle(140,375,110,35);
	iSetColor(255,0,0);
	iText(170,385,"Cars",GLUT_BITMAP_TIMES_ROMAN_24);
}
void musicSettings()
{

    iShowBMP(0,0,"music1.bmp");
    //music on /off
    iSetColor(255,255,255);
    iRectangle(405,500,40,40);

    iText(415,480,"ON",GLUT_BITMAP_8_BY_13);
    if(sound==1)
    {

        iSetColor(255,0,0);
        iFilledCircle(425,520,19);

    }
    iSetColor(255,255,255);
    iRectangle(465,500,40,40);

    iText(473,480,"OFF",GLUT_BITMAP_8_BY_13);
    if(sound==0)
    {
        iSetColor(255,0,0);
        iFilledCircle(485,520,19);
    }
    iSetColor(255,255,255);
    iFilledRectangle(100,70,80,30);
    double xa[]= {75,100,100};
    double ya[]= {85,60,110};

    iFilledPolygon( xa,ya,3 );
    iSetColor(255,0,0);
    iText(113,77,"Back",GLUT_BITMAP_TIMES_ROMAN_24);

    //music headline
    iText(420,590,"Music",GLUT_BITMAP_TIMES_ROMAN_24);
    iFilledRectangle(412,580,80,2);
  
    iText(400,380,"Music List",GLUT_BITMAP_TIMES_ROMAN_24);
    iFilledRectangle(398,370,110,2);
    iText(295,310,"1.Tokyo Drift",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(295,260,"2.Styles of Beyond-Nine Thou",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(295,210,"3.Till I Collapse",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(295,160,"4.In The End",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(295,110,"5.See You Again",GLUT_BITMAP_TIMES_ROMAN_24);


}
void carSelection1()
{
	 iShowBMP(0,0,"Images\\userCar\\carSelection1.bmp");

     iSetColor(255,255,255);
	 iFilledRectangle(380,75,120,45);
     if(q==0)
    {	
	iSetColor(0,255,0);
    }
	iFilledRectangle(385,80,110,35);
	iSetColor(255,0,0);
	iText(402,90,"Lock In",GLUT_BITMAP_TIMES_ROMAN_24);
	//back
	iSetColor(255,255,255);
	iFilledRectangle(100,70,80,30);
	double xa[]={75,100,100};
	double ya[]={85,60,110};
	iFilledPolygon( xa,ya,3 );
	iSetColor(255,0,0);
	iText(113,77,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,0,0);
	double xb[]={835,850,835};
	double yb[]={375,355,335};
    iFilledPolygon( xb,yb,3 );  
	  }
void carSelection2()
{
	 iShowBMP(0,0,"Images\\userCar\\carSelection2.bmp");
	 iSetColor(255,255,255);
	 iFilledRectangle(380,75,120,45);
     if(q==1)
	{
	  iSetColor(0,255,0);
	}
	 iFilledRectangle(385,80,110,35);
	 iSetColor(255,0,0);
	 iText(402,90,"Lock In",GLUT_BITMAP_TIMES_ROMAN_24);
		
		//back
		iSetColor(255,255,255);
		iFilledRectangle(100,70,80,30);
		double xa[]={75,100,100};
		double ya[]={85,60,110};

		iFilledPolygon( xa,ya,3 );
		iSetColor(255,0,0);
		iText(113,77,"Back",GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255,0,0);
		double xb[]={835,850,835};
		double yb[]={375,355,335};

		iFilledPolygon( xb,yb,3 );
		
		double xc[]={50,65,65};
		double yc[]={355,375,335};

		iFilledPolygon( xc,yc,3 );
}

void carSelection3()
{
	 iShowBMP(0,0,"Images\\userCar\\carSelection3.bmp");

		  iSetColor(255,255,255);
		iFilledRectangle(380,75,120,45);
		
		  if(q==2) 
		{
		iSetColor(0,255,0);
		}
	

		iFilledRectangle(385,80,110,35);
		iSetColor(255,0,0);
		iText(402,90,"Lock In",GLUT_BITMAP_TIMES_ROMAN_24);
		
		//back

		iSetColor(255,255,255);
		iFilledRectangle(100,70,80,30);
		double xa[]={75,100,100};
		double ya[]={85,60,110};

		iFilledPolygon( xa,ya,3 );
		iSetColor(255,0,0);
		iText(113,77,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,0,0);
		
		
		double xc[]={50,65,65};
		double yc[]={355,375,335};

		iFilledPolygon( xc,yc,3 );
}

void highScore()
{
    iShowBMP(0,0,"Images\\others\\highscore.bmp");
    iSetColor(255,255,255);
    iFilledRectangle(100,70,80,30);
    double xa[]= {75,100,100};
    double ya[]= {85,60,110};

    iFilledPolygon( xa,ya,3 );
    iSetColor(255,0,0);
    iText(113,77,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,255,255);
    iFilledRectangle(290,619,80,30);
    iSetColor(0,0,0);
    iFilledRectangle(294,622,72,25);
    iSetColor(255,0,0);
    iText(306,628,"Name",GLUT_BITMAP_HELVETICA_18);
    iSetColor(255,255,255);
    iFilledRectangle(475,619,80,30);
    iSetColor(0,0,0);
    iFilledRectangle(479,622,72,25);
    iSetColor(255,0,0);
    iText(491,628,"Score",GLUT_BITMAP_HELVETICA_18);
    iSetColor(255,255,255);
    //score_work
    int x=300,y=600;
    for(int i=0; i<5; i++)
    {
        itoa(pN[i].score,saveScore);
        iText(x, y,pN[i].name,GLUT_BITMAP_HELVETICA_18);
        iText(x+200, y,saveScore,GLUT_BITMAP_HELVETICA_18);
        y-=50;
    }
}
void instruction()
{
    iShowBMP(0,0,"Images\\others\\instruction1.bmp");
    iSetColor(255,255,255);
    iFilledRectangle(100,70,80,30);
    double xa[]= {75,100,100};
    double ya[]= {85,60,110};

    iFilledPolygon( xa,ya,3 );
    iSetColor(255,0,0);
    iText(113,77,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
}
void about()
{
	iShowBMP(0,0,"Images\\others\\about.bmp");
	 iSetColor(255,255,255);
		iFilledRectangle(100,70,80,30);
		double xa[]={75,100,100};
		double ya[]={85,60,110};

		iFilledPolygon( xa,ya,3 );
		iSetColor(255,0,0);
		iText(113,77,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
}


void credit()
{
	iShowBMP(0,0,"Images\\others\\credit.bmp");
	 iSetColor(255,255,255);
		iFilledRectangle(400,40,80,30);
		iSetColor(255,0,0);
		iText(413,47,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
}
void pausetimer()
{
    iPauseTimer(a);
    iPauseTimer(b);
    iPauseTimer(c);
    iPauseTimer(e);
    iPauseTimer(f);

}
void resumetimer()
{
    iResumeTimer(a);
    iResumeTimer(b);
    iResumeTimer(c);
    iResumeTimer(e);
    iResumeTimer(f);


}
void levelchange()
{
	levelCon=false;
	if(carMove_y<=710)
		carMove_y+=3;
	else
	{	
		
		gameLevel=1;
		iPauseTimer(g);
		PlaySound(musicList[song],NULL,SND_LOOP | SND_ASYNC);
	}
}
void level()
{
	    if(gameLevel == 0)
        {
            if(m==0)
            {
                resumetimer();

            }
            else
            {
               pausetimer();
            }

            BackgroundMovement();
            roadDevider();
			enemyCar();
			if(score==29){
				gunmusic=true;
				PlaySound("Music\\zom.wav",NULL,SND_ASYNC);
			
			}
			if(score>=30)
			{
				pausetimer();
				iShowBMP2(250,250, "Images\\others\\levelChangingPic.bmp",0);
				iResumeTimer(g);
				levelchange();
				
			}
            
             if(q==0)
		  {
			  iShowBMP2(carMove_x, carMove_y, "Images\\userCar\\userCar1.bmp",255);
		  }
		  else if(q==1)
		  {
		   iShowBMP2(carMove_x, carMove_y, "Images\\userCar\\userCar2.bmp",0);
		  }
		  else if(q==2)
			   {
		   iShowBMP2(carMove_x, carMove_y, "Images\\userCar\\userCar3.bmp",0);
		  }
            //Fuel();
            iSetColor(96,96,96);
            iFilledRectangle(0,0,900,60);
            Fuel();
            collisionCheck();
            car_score();

            if(menu==7 && m==1 && levelCon)
            {
                iShowBMP2(370,350, "Images\\others\\GameOver1.bmp",0);
				pausetimer();

            }

			
		}

        else if(gameLevel == 1)
        {
			if(!levelCon){
				setMove();
				resumetimer();
				fuel=125;
				levelCon=true;


			}
			
			
			if(carMove_y>=710)
				carMove_y=60;
             
			  BackgroundMovement();
            roadDevider();
			enemyCar();
			
            
             if(q==0)
		  {
			  iShowBMP2(carMove_x, carMove_y, "Images\\userCar\\userCar1.bmp",255);
		  }
		  else if(q==1)
		  {
		   iShowBMP2(carMove_x, carMove_y, "Images\\userCar\\userCar2.bmp",0);
		  }
		  else if(q==2)
			   {
		   iShowBMP2(carMove_x, carMove_y, "Images\\userCar\\userCar3.bmp",0);
		  }
			
            
           
			collisionCheck();
			zombieShow();
			zomcollision();
			zom_Collision_With_Car();
            bulletShow();

			iSetColor(96,96,96);
            iFilledRectangle(0,0,900,60);
			Fuel();
			car_score();

			if(menu==7 && m==1)
            {
                iShowBMP2(370,350, "Images\\others\\GameOver1.bmp",0);
				pausetimer();
				
            }
        }
}
void setMove()
{
    carMove_x=425;
    carMove_y=35;

    int var=0;

    for(int i=0; i<13; i++)
    {
		
        roadMovement[i].x_axis=200;
        sideMovement[i].x_axis=0;
        sideMovementRight[i].x_axis=700;
        roadMovement[i].y_axis=var;
        sideMovement[i].y_axis=var;
        sideMovementRight[i].y_axis=var;
        
        roadMovement2[i].x_axis=0;
        roadMovement2[i].y_axis=var;
		var+=62;
    }
    ec[0].x_axis=230;
    ec[0].y_axis=280;
    ec[1].x_axis=230;
    ec[1].y_axis=460;
    ec[2].x_axis=230;
    ec[2].y_axis=640;

    ec[3].x_axis=380;
    ec[3].y_axis=1060;
    ec[4].x_axis=380;
    ec[4].y_axis=1630;
    ec[5].x_axis=380;
    ec[5].y_axis=1990;

    ec[6].x_axis=540;
    ec[6].y_axis=570;
    ec[7].x_axis=540;
    ec[7].y_axis=780;
    ec[8].x_axis=540;
    ec[8].y_axis=1260;
}

void change()
{
    if(deviderChange_y>=710)
        deviderChange_y=0;
    else
        deviderChange_y+=8;
    for(int i=0; i<13; i++)
    {
		if(gameLevel==0){
        roadMovement[i].y_axis-=8;
        sideMovement[i].y_axis-=8;
        sideMovementRight[i].y_axis-=8;
        if(roadMovement[i].y_axis<=-70)
        {
            roadMovement[i].y_axis=710;
            sideMovement[i].y_axis=710;
            sideMovementRight[i].y_axis=710;
        }
		}
		else
		{
        roadMovement2[i].y_axis-=8;
		if(roadMovement2[i].y_axis<=-70)
            roadMovement2[i].y_axis=710;
		}
    }

    if(fuel>0)
    {
        fuel-=0.25;
        if(fuel==0)
        {
            gameOver();
        }
    }
	 if(fuel==100||fuel==60||fuel==25||fuel==80){
		fuel1.x_axis=200+rand()%500;
		fuel1.y_axis=200+rand()%300;
		fuelCondition1=0;
	}


}

void Fuel()
{
    iSetColor(0,255,0);
    iText(32,50,"Fuel:",GLUT_BITMAP_HELVETICA_12);
    if(fuel<=50)
        iSetColor(255,0,0);
    iFilledRectangle(32,36,fuel,8);
    iRectangle(32,36,125,8);
    //carHealth
    iSetColor(0,255,0);
    iText(32,10,"Car Health:",GLUT_BITMAP_HELVETICA_12);
    iSetColor(0,255,0);
    if(Car_Health>0)
    {
        iFilledRectangle(32,20,Car_Health,8);
    }
    iRectangle(32,20,100,8);

    if(Car_Health==0)
    {
        gameOver();
    }
	if((fuel<=100&&fuel>80||fuel<=60&&fuel>=40||fuel<25&&fuel>=10)&&fuelCondition1==0){
		iShowBMP2(fuel1.x_axis,fuel1.y_axis,"fueltank.bmp",0);
		fuelCondition2=0;
	}
	else
		fuelCondition2=1;
	


}
void fuelCollision()
{
	if((carMove_x+81 > fuel1.x_axis+25 && fuel1.x_axis+75 > carMove_x+42) && (fuel1.y_axis+14<carMove_y+93 && fuel1.y_axis+182>carMove_y+35)&&fuelCondition2==0)
    {
		
                fuel+=40;
		if(fuel>125)
			fuel=125;
		fuelCondition1=1;

    }

}

void zombieInitialize()							//Zombie axis initialization code
{
    int zv= 0;
    if(zom[11].y_axis<=40)
    {
        for(int i=0; i<12; i++)
        {
            zom[i].x_axis= (200+rand()%400);
            zom[i].y_axis= 710+zv;
            zv+=(125+rand()%76);
           
        }
    }
    else
        for(int i=0; i<12; i++)
        {
            zom[i].y_axis-=10;
        }
    zombieIndex++;
    if(zombieIndex>14)
        zombieIndex=0;
   
}

void zombieShow()
{
    for(int i=0; i<12; i++) 														//Zombie showing code
    {

        if(i==0 || i==7 || i==8)
            iShowBMP2(zom[i].x_axis,zom[i].y_axis,zombie1[zombieIndex],0);
        else if(i==1 || i== 6 || i==10)
            iShowBMP2(zom[i].x_axis,zom[i].y_axis,zombie2[zombieIndex],0);
        else if(i==2 || i==5 || i==9)
            iShowBMP2(zom[i].x_axis,zom[i].y_axis,zombie3[zombieIndex],0);
        else if(i==3 || i== 4 || i== 11)
            iShowBMP2(zom[i].x_axis,zom[i].y_axis,zombie4[zombieIndex],0);
    }
}

void zom_Collision_With_Car()
{
    //ZOM : 0

    if((carMove_x+81 > zom[0].x_axis+18 && zom[0].x_axis+59 > carMove_x+42 ) &&(zom[0].y_axis+10<carMove_y+93 && zom[0].y_axis+62 > carMove_y+35))
    {
        Car_Health-=0.5;
    }
    //ZOM : 1
    if((carMove_x+81 > zom[1].x_axis+10 && zom[1].x_axis+59 > carMove_x+42 ) &&(zom[1].y_axis+10<carMove_y+93 && zom[1].y_axis+60 > carMove_y+35  ))
    {
        Car_Health=Car_Health-0.5;
    }
    //ZOM : 2
    if((carMove_x+81 > zom[2].x_axis+12 && zom[2].x_axis+75 > carMove_x+42 ) &&(zom[2].y_axis+5<carMove_y+93 && zom[2].y_axis+62 > carMove_y+35 ))
    {
        Car_Health=Car_Health-0.5;
    }
    //ZOM : 3
    if((carMove_x+81 > zom[3].x_axis+60 && zom[3].x_axis+90 > carMove_x+42 ) &&(zom[3].y_axis+55<carMove_y+93 && zom[3].y_axis+110 >carMove_y+35  ))
    {
        Car_Health=Car_Health-0.5;
    }
    //ZOM : 4
    if((carMove_x+81 > zom[4].x_axis+60 && zom[4].x_axis+90 > carMove_x+42 ) &&(zom[4].y_axis+55<carMove_y+93 && zom[4].y_axis+110 > carMove_y+35  ))
    {
        Car_Health=Car_Health-0.5;
    }

    //ZOM : 5
    if((carMove_x+81 > zom[5].x_axis+12 && zom[5].x_axis+75 > carMove_x+42 ) &&(zom[5].y_axis+5<carMove_y+93 && zom[5].y_axis+62 > carMove_y+35  ))
    {
        Car_Health=Car_Health-0.5;
    }

    //ZOM : 6
    if((carMove_x+81 > zom[6].x_axis+10 && zom[6].x_axis+59 > carMove_x+42 ) &&(zom[6].y_axis+10<carMove_y+93 && zom[6].y_axis+60 >carMove_y+35  ))
    {
        Car_Health=Car_Health-0.5;
    }
    //ZOM : 7
    if((carMove_x+81 > zom[7].x_axis+18 && zom[7].x_axis+59 > carMove_x+42 ) &&(zom[7].y_axis+10<carMove_y+93 && zom[7].y_axis+62 > carMove_y+35  ))
    {
        Car_Health=Car_Health-0.5;

    }
    //ZOM : 8
    if((carMove_x+81 > zom[8].x_axis+18 && zom[8].x_axis+59 > carMove_x+42 ) &&(zom[8].y_axis+10<carMove_y+93 && zom[8].y_axis+62 > carMove_y+35  ))
    {
        Car_Health=Car_Health-0.5;

    }
    //ZOM : 9
    if((carMove_x+81 > zom[9].x_axis+12 && zom[9].x_axis+75 > carMove_x+42 ) &&(zom[9].y_axis+5<carMove_y+93 && zom[9].y_axis+62 > carMove_y+35  ))
    {
        Car_Health=Car_Health-0.5;
    }

    //ZOM : 10
    if((carMove_x+81 > zom[10].x_axis+10 && zom[10].x_axis+59 > carMove_x+42 ) &&(zom[10].y_axis+10<carMove_y+93 && zom[10].y_axis+60 >carMove_y+35  ))
    {

        Car_Health=Car_Health-0.5;

    }
    //ZOM : 11
    if((carMove_x+81  > zom[11].x_axis+60 && zom[11].x_axis+90 > carMove_x+42 ) &&(zom[11].y_axis+55<carMove_y+93 && zom[11].y_axis+110 > carMove_y+35  ))
    {
        Car_Health=Car_Health-0.5;
    }

}


void zomcollision()
{

    for(int i=0; i<12; i++)
    {
        if(i==0||i==7||i==8)
        {
            for(int j=0; j<10; j++)
            {

                if((bullet[j].x_axis+28 > zom[i].x_axis+18 && zom[i].x_axis+59 > bullet[j].x_axis+20 ) &&(zom[i].y_axis+10<bullet[j].y_axis+6 && zom[i].y_axis+62 > bullet[j].y_axis+35  ))
                {
                    if(bulletCondition[j]==j+1)
                    {
                        bulletCondition[j]=j-1;

                        bullet[j].x_axis=carMove_x+40;
                        bullet[j].y_axis=carMove_y+120;

                        zom[i].y_axis=0;
						score++;
                    }


                }
            }
        }

        else if(i==1||i==6||i==10)
        {
            for(int j=0; j<10; j++)
            {
                if((bullet[j].x_axis+28 > zom[i].x_axis+10 && zom[i].x_axis+59 > bullet[j].x_axis+20 ) &&(zom[i].y_axis+10<bullet[j].y_axis+6 && zom[i].y_axis+60 > bullet[j].y_axis+35  ))
                {
                    if(bulletCondition[j]==j+1)
                    {
                        bulletCondition[j]=j-1;

                        bullet[j].x_axis=carMove_x+40;
                        bullet[j].y_axis=carMove_y+120;

                        zom[i].y_axis=0;
						score++;
                    }
                }
            }
        }
        else if(i==2||i==5||i==9)
        {
            for(int j=0; j<10; j++)
            {
                if((bullet[j].x_axis+28 > zom[i].x_axis+12 && zom[i].x_axis+75 > bullet[j].x_axis+20 ) &&(zom[i].y_axis+5<bullet[j].y_axis+6 && zom[i].y_axis+62 > bullet[j].y_axis+35  ))
                {
                    if(bulletCondition[j]==j+1)
                    {
                        bulletCondition[j]=j-1;

                        bullet[j].x_axis=carMove_x+40;
                        bullet[j].y_axis=carMove_y+120;

                        zom[i].y_axis=0;
						score++;
                    }
                    
                }
            }
        }
        else if(i==3||i==4||i==11)
        {
            for(int j=0; j<10; j++)
            {
                if((bullet[j].x_axis+28 > zom[i].x_axis+60 && zom[i].x_axis+90 > bullet[j].x_axis+20 ) &&(zom[i].y_axis+55<bullet[j].y_axis+6 && zom[i].y_axis+110 > bullet[j].y_axis+35  ))
                {
                    if(bulletCondition[j]==j+1)
                    {


                        bullet[j].x_axis=carMove_x+40;
                        bullet[j].y_axis=carMove_y+120;
                        bulletCondition[j]=j-1;
						zom[i].y_axis=0;
						score++;
                    }
                }
            }

        }


    }

}


void enemyMoveInLeftRoad()
{
    int local_y_axis=990,zero_Axis=430,p=0,var1=140,var2=180;
    for(int i=0; i<3; i++)
    {
        if(ec[i].y_axis>=50&&ec[i].y_axis<=59&& p==0)
        {
            score++;
            carpass++;
            p=1;

        }
        if(ec[i].y_axis<=-zero_Axis)
        {
            ec[i].y_axis=local_y_axis+rand()%10;
            ec[i].x_axis+=rand()%60;
            if(ec[i].x_axis>=290)
            {
                ec[i].x_axis=200;
                p=0;
                if(i==0)
                {
                    local_y_axis+=var1;
                    zero_Axis-=var1;

                }
                if(i==1)
                {

                    local_y_axis+=var2;
                    zero_Axis-=var2;
                }
            }
        }
        else
            ec[i].y_axis -=10;

    }

}

void enemyMoveInMiddleRoad()
{
    int local_y_axis=1060,zero_Axis=1060,var1=570,var2=360;
    int p=0;
    for(int i=3; i<6; i++)
    {
        if(ec[i].y_axis>=50&&ec[i].y_axis<=59&& p==0)
        {
            score++;
            carpass++;
            p=1;
        }
        if(ec[i].y_axis<=-zero_Axis)
        {
            ec[i].y_axis=local_y_axis+rand()%10;
            ec[i].x_axis+=rand()%60;
            if(ec[i].x_axis>=400)
                ec[i].x_axis=370;
            p=0;
            if(i==3)
            {
                local_y_axis+=var1;
                zero_Axis-=var1;
            }
            if(i==4)
            {
                local_y_axis+=var2;
                zero_Axis-=var2;
            }
        }
        else
        {
            ec[i].y_axis -=10;
        }
    }
}

void enemyMoveInRightRoad()
{
    int local_y_axis=570,zero_Axis=850,p=0,var1=210,var2=480;
    for(int i=6; i<9; i++)
    {
        if(ec[i].y_axis>=50&&ec[i].y_axis<=59&& p==0)
        {
            score++;
            carpass++;
            p=1;

        }
        if(ec[i].y_axis<=-zero_Axis)
        {
            ec[i].y_axis=local_y_axis+rand()%10;
            ec[i].x_axis+=rand()%60;
            if(ec[i].x_axis>=560)
                ec[i].x_axis=520;
            p=0;
            if(i==6)
            {
                local_y_axis+=var1;
                zero_Axis-=var1;

            }
            if(i==7)
            {

                local_y_axis+=var2;
                zero_Axis-=var2;
            }
        }
        else
        {
            ec[i].y_axis -=10;
        }
    }

}
void gameOver()
{
    iPauseTimer(a);
    iPauseTimer(b);
    iPauseTimer(c);
    iPauseTimer(e);
    iPauseTimer(f);
    m=1;
}
void collisionCheck()
{
	//First Row
	if((carMove_x+81 > ec[0].x_axis+38 && ec[0].x_axis+71 > carMove_x+42) && (ec[0].y_axis+22<carMove_y+93 && ec[0].y_axis+115>carMove_y+35))
	{
		gameOver();
	}
	if((carMove_x+81 > ec[4].x_axis+56 && ec[4].x_axis+79 > carMove_x+42) && (ec[4].y_axis+12<carMove_y+93 && ec[4].y_axis+107>carMove_y+35))
	{
		gameOver();
	}
	if((carMove_x+81 > ec[5].x_axis+52 && ec[5].x_axis+88 > carMove_x+42) && (ec[5].y_axis+11<carMove_y+111 && ec[5].y_axis+107>carMove_y+11))
	{
		gameOver();
	}

	//Second Row
	if((carMove_x+81 > ec[1].x_axis+47 && ec[1].x_axis+85 > carMove_x+42) && (ec[1].y_axis+11<carMove_y+93 && ec[1].y_axis+107>carMove_y+35))
	{
		gameOver();
	}

	if((carMove_x+81 > ec[2].x_axis+42 && ec[2].x_axis+81 > carMove_x+42) && (ec[2].y_axis+19<carMove_y+100 && ec[2].y_axis+100>carMove_y+35))
	{
		gameOver();
	}
	if((carMove_x+81 > ec[6].x_axis+32 && ec[6].x_axis+70 > carMove_x+42) && (ec[6].y_axis+9<carMove_y+111 && ec[6].y_axis+93>carMove_y+35))
	{
		gameOver();
	}

	//Third Row
	if((carMove_x+81 > ec[3].x_axis+44 && ec[3].x_axis+78 > carMove_x+42) && (ec[3].y_axis+9<carMove_y+93 && ec[3].y_axis+95>carMove_y+35))
	{
		gameOver();
	}
	if((carMove_x+81 > ec[7].x_axis+25 && ec[7].x_axis+55 > carMove_x+42) && (ec[7].y_axis+27<carMove_y+93 && ec[7].y_axis+109>carMove_y+35))
	{
		gameOver();
	}
	if((carMove_x+81 > ec[8].x_axis+25 && ec[8].x_axis+75 > carMove_x+42) && (ec[8].y_axis+14<carMove_y+93 && ec[8].y_axis+182>carMove_y+35))
	{
		gameOver();
	}
	fuelCollision();
}


void BackgroundMovement()
{
    for(int i=0; i<13; i++)
    {
		if(gameLevel==0){
        iShowBMP(roadMovement[i].x_axis,roadMovement[i].y_axis,roadMove[i]);
        iShowBMP(sideMovement[i].x_axis,sideMovement[i].y_axis,sideMove_left[i]);
        iShowBMP(sideMovementRight[i].x_axis,sideMovementRight[i].y_axis,sideMove_right[i]);
		}
		else
		{
        iShowBMP(roadMovement2[i].x_axis,roadMovement2[i].y_axis,roadMove2[i]);

		}

    }
}
void car_score()
{


    if(m==0)
    {

        itoa(score,s);
        iSetColor(243,153,19);
        iText(654,48,s,GLUT_BITMAP_9_BY_15);
        iText(200,48,"Name:",GLUT_BITMAP_9_BY_15);
        iText(242,48,str,GLUT_BITMAP_9_BY_15);
        iText(600,48,"Score:",GLUT_BITMAP_9_BY_15);
    }
    else
    {
        itoa(score,s);
        iSetColor(255,255,255);
        iText(450,360,s,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(390,360,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(200,48,"Name:",GLUT_BITMAP_9_BY_15);
        iText(242,48,str,GLUT_BITMAP_9_BY_15);
    }

}

int main()
{
    file();
    if(music)
    {
        PlaySound(musicList[song],NULL,SND_LOOP | SND_ASYNC);
    }

    setMove();
    a=iSetTimer(20,change);
    b=iSetTimer(15,enemyMoveInLeftRoad);
    c=iSetTimer(20,enemyMoveInMiddleRoad);
    e=iSetTimer(15,enemyMoveInRightRoad);
    f=iSetTimer(150,zombieInitialize);
	g=iSetTimer(15,levelchange);
	iPauseTimer(g);
    indexNumber=strlen(str);

    iInitialize(900, 710, "City Driver");
    iStart();
    return 0;
}
