#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <fstream>
using namespace std;

char race[30][35];
int carmx = 20; // midcolumn xaxix
int carmy = 14; // y
int count = 0;
int count2 = 0;
int racefx = 20; // firstcolumn xaxis
int racefy = 4;  // y axis

int racetx = 20; // thirscolumn xaxis
int racety = 23; // yaxis
void printroad();
void gotoxy(int x, int y);
void load_track();
void moveCarLeft();
void moveCarRight();
void moveCarUp();
void moveCarDown();

void emptymidcolumn();
void fillmidcolumn();


void fillfirstcolumn();
void emptyfirstcolumn();


void fillthirdcolumn();
void emptythirdcolumn();

void checkcount();

void enemysavemidc();
void enemysavetc();
void enemysavefirstc();

void updateValue();

void updatefirstvalue();
void updatelastvalue();
void updatedownValue();


void enemyemptytc();
void enemyemptyfirstc();
void enemyemptymidc();

void clearscreen();

void timetick(int rsult);
void timetickdot(int rsult2);

void emptydotinarray();
void dotinarray();
void dotinsecondarray();
void emptydotinsecondarray();

void dotinthirdarray();
void emptydotinthirdarray();
void secondcar();
void givelives();

void dotfirst();
void dotsecond();
void dotthird();

void set_cursor(bool visible);
void  livesavethirdcolumn();
void  liveemptythirdcolumn();
void liveemptyfirstcolumn();
void livesavefirstcolumn();
void liveemptysecondcolumn();
void livesavesecondcolumn();

void livesecondc();
void livefirstc();
void livethirdc();

void cartouch();
void cartouchh();
void cartouchhh();



int co = 5;
int ccheck = 0;
int midccheck = 0;
int  result3,carresult;
int checkcar = 0;
int live = 3;
 

int movemid = 3;
int movefirst = 3;
int Ethirdcolumn = 3;
int lifeonec = 0;  // livesfirst col
int lifesecondcol =0; // lives 2c olumn
int lifethirdcol =0;
int dotfirstx = 0;
int dotsecondx = 0;
int dotthirdx = 0;
int nexttime = 0;
int sccount ,sccountscol,sccounttcol=0;    // second car count for crash
int nextimemid = 0;
bool check = false;
bool checkmid = false;
bool checkfirst = false;
int firstcheck = 0;
int randcheck = 0;
int secondcarintrack =0;
int giveScore = 0;
int givelive = 0;

int score = 0;

bool firstcolumn = false;
bool secondcolumn = false;
bool thirdcolumn = false;
bool firstc,secondcolumnlive,thirdcolumnlive = false;  // used in lives 
int scarinfirstcol,scarinsecondcol ,scarinthirdcol= 3;  // second car move in first hurdle.
bool SEfirstcolumn,SEsecondcolumn,SEthirdcolumn = false;  // this will represent rand generate value of second car in same track

HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);


main()
{

bool gameover = false;
bool win = false;
int result, result2;
  load_track();

    system("CLS");
    SetConsoleTextAttribute(hc, 0Xa);
    cout << R"(                                        __---~~~~--__                      __--~~~~---__
                                       `\---~~~~~~~~\\                    //~~~~~~~~---/'  
                                         \/~~~~~~~~~\||                  ||/~~~~~~~~~\/ 
                                                     `\\                //'
                                                       `\\            //'
                                                         ||          ||      
                                               ______--~~~~~~~~~~~~~~~~~~--______              
                                          ___ // _-~                        ~-_ \\ ___  
                                      `\__)\/~                              ~\/(__/'          
                                        _--`-___                            ___-'--_        
                                        /~     `\ ~~~~~~~~------------~~~~~~~~ /'     ~\        
                                     | `\   ______`\_      \------/      _/'______   /' |          
                                     |   `\_~-_____\ ~-________________-~ /_____-~_/'   |  
                                      `.     ~-__________________________________-~     .'       
                                       `.      [_______/------|~~|------\_______]      .'
                                       `\--___((____)(________\/________)(____))___--/'           
                                         |>>>>>>||                            ||<<<<<<|)";

    SetConsoleTextAttribute(hc, 0X07);
    int i = 0;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\tPlease wait Your game is loading...... " <<endl ;
    cout  <<endl;
    cout << "\t\t\t\t\t\t\t\tLoading ";
    char x = 177;

    for (i = 0; i < 50; i++)
    {
        SetConsoleTextAttribute(hc, 0Xa);
       if (x < 10)
    // {
            Sleep(200);
     //  } 
        cout << x;
        Sleep(100);
    }
    SetConsoleTextAttribute(hc, 0Xa);
    system("CLS");
    char choice = 'o';
    while(choice!='q' || choice !='Q'){
    cout << " ________________________________________________" << endl ;
    cout << "\n";
    cout << "        WELCOME 2D CAR RACING GAME                " << endl ;
    cout << " ________________________________________________" << endl;
    
    cout << " > Press [S] to start the game. " <<endl ;
    cout << " > Press [Q] for quit. " <<endl ;
    cout << " > Press [I] for instructions. "<<endl;
    cout << " > Enter choice ";
    
    cin >> choice;
    system("CLS");
    
    if (choice == 'S' || choice == 's')
    {
        gotoxy(2, 10);

        cout << R"( 
                         _____   ___  ______      ______  ___  _____ _____ _   _ _____        _____   ___  ___  ___ _____ 
                        /  __ \ / _ \ | ___ \     | ___ \/ _ \/  __ \_   _| \ | |  __ \      |  __ \ / _ \ |  \/  ||  ___|
                        | /  \// /_\ \| |_/ /     | |_/ / /_\ \ /  \/ | | |  \| | |  \/      | |  \// /_\ \| .  . || |__  
                      | |    |  _  ||    /  |    /|  _  | |     | | | . ` | | __  | | __     |  _  || |\/| ||  __|    __
                        | \__/\| | | || |\ \      | |\ \| | | | \__/\_| |_| |\  | |_\ \      | |_\ \| | | || |  | || |___ 
                        \____/\_| |_/\_| \_|     \_| \_\_| |_/\____/\___/\_| \_/\____/       \____/\_| |_/\_|  |_/\____/ 
                                                                                         
                                                                                         )";

        cout << "\n";
        cout << " *** CHOOSE DIFFICULTY LEVEL *** " << endl;
        cout << "\n";

        cout << " 1) PRESS 1 FOR PLAY NORMAL. " << endl;
        cout << " 2) PRESS 2 FOR PLAY HARD. " <<endl ;
        cout << " YOUR OPTION . ";
        int option;
        cin >> option;
     
        if (option == 1)
        {
         // set_cursor(false);
            system("CLS");
            gotoxy(50, 0);
            SetConsoleTextAttribute(hc, 0Xd);
            gotoxy(50, 0);
            cout << R"(
                                      _____           ___                                    
                                    / ___/__ _____  / _ \___ ________   ___ ____ ___ _  ___ 
                                   / /__/ _ `/ __/ / , _/ _ `/ __/ -_) / _ `/ _ `/  ' \/ -_)
                                   \___/\_,_/_/   /_/|_|\_,_/\__/\__/  \_, /\_,_/_/_/_/\__/ 
                                                                      /___/                 
)";
            printroad();

            gotoxy(45, 13);
            cout << " *** Press ESC to stop the game. *** ";

            SetConsoleTextAttribute(hc, 0X07);

            race[carmx][carmy] = ' ';
            race[carmx][carmy + 1] = '#';

            race[carmx + 1][carmy] = '#';
            race[carmx + 1][carmy + 1] = '#';
            race[carmx + 1][carmy + 2] = '#';

            race[carmx + 2][carmy] = ' ';
            race[carmx + 2][carmy + 1] = '#';

            race[carmx + 3][carmy] = '#';
            race[carmx + 3][carmy + 1] = '#';
            race[carmx + 3][carmy + 2] = '#';

            SetConsoleTextAttribute(hc, 0Xd);
            gotoxy(0,2);
            cout<<"#";

           SetConsoleTextAttribute(hc, 0X07);
            gotoxy(carmy, carmx);
            cout << " #";

            gotoxy(carmy, carmx + 1);
            cout << "###";

            gotoxy(carmy, carmx + 2);
            cout << " #";

            gotoxy(carmy, carmx + 3);
            cout << "###";

          
            while (true)
            {
                Sleep(200);
                SetConsoleTextAttribute(hc, 0Xc);
                gotoxy(50, 10);
                cout << " Remaining lives: " << live;

                
                SetConsoleTextAttribute(hc, 0Xb);
                gotoxy(50, 15);
                cout << " Your Score: " << score;
                SetConsoleTextAttribute(hc, 0X07);
                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveCarLeft(); // Function call to move car towards left
                }
                else if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveCarRight(); // Function call to move car towards right
                }
                else if (GetAsyncKeyState(VK_UP))
                {
                    moveCarUp(); // Function call to move car towards up
                }
                else if (GetAsyncKeyState(VK_DOWN))
                {
                    moveCarDown(); // Function call to move car towards down
                }
                else if (GetAsyncKeyState(VK_ESCAPE))
                {
                    break; // Stop the game
                }
                if (live == 0)
                {
                    gameover = true;
                    choice = 'p';
                    break;
                }
                if (score == 10)
                {
                    win = true;
                     choice = 'p';
                    break;
                }
                if (randcheck == 15)
                {
                    srand(time(0));
                    result = 1 + (rand() % 4);
                    randcheck = 0;
                }

                timetick(result);
                randcheck++;
               
                result = 0;
                if (giveScore == 50)
                {
                    srand(time(0));
                    result2 = 1 + (rand() % 4);
                    giveScore = 0;
                }

                timetickdot(result2);

                giveScore++;
              

                result2 = 0;

                if (givelive == 80)
                {
                    givelive = 0;
                    srand(time(0));
                    result3 = 1 + (rand() % 4);
                }
              
                givelives();
                  givelive++;
                result3 = 0;
            }

            if (gameover == true)
            {
                system("CLS");
                SetConsoleTextAttribute(hc, 0Xb);
                cout << R"(
__/\\\________/\\\________________________________________/\\\_______________________________________________________        
 _\///\\\____/\\\/________________________________________\/\\\_______________________________________________________       
  ___\///\\\/\\\/__________________________________________\/\\\_______________________________________________________      
   _____\///\\\/__________/\\\\\_____/\\\____/\\\___________\/\\\_________________/\\\\\_____/\\\\\\\\\\_____/\\\\\\\\__     
    _______\/\\\_________/\\\///\\\__\/\\\___\/\\\___________\/\\\_______________/\\\///\\\__\/\\\//////____/\\\/////\\\_    
     _______\/\\\________/\\\__\//\\\_\/\\\___\/\\\___________\/\\\______________/\\\__\//\\\_\/\\\\\\\\\\__/\\\\\\\\\\\__   
      _______\/\\\_______\//\\\__/\\\__\/\\\___\/\\\___________\/\\\_____________\//\\\__/\\\__\////////\\\_\//\\///////___  
       _______\/\\\________\///\\\\\/___\//\\\\\\\\\____________\/\\\\\\\\\\\\\\\__\///\\\\\/____/\\\\\\\\\\__\//\\\\\\\\\\_ 
        _______\///___________\/////______\/////////_____________\///////////////_____\/////_____\//////////____\//////////__
)";
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(hc, 0Xb);
                cout << R"( 
   ____      _      __  __  U _____ u       U  ___ u__     __ U _____ u   ____     
U /"___|uU  /"\  uU|' \/ '|u\| ___"|/        \/"_ \/\ \   /"/u\| ___"|/U |  _"\ u  
\| |  _ / \/ _ \/ \| |\/| |/ |  _|"          | | | | \ \ / //  |  _|"   \| |_) |/  
 | |_| |  / ___ \  | |  | |  | |___      .-,_| |_| | /\ V /_,-.| |___    |  _ <    
  \____| /_/   \_\ |_|  |_|  |_____|      \_)-\___/ U  \_/-(_/ |_____|   |_| \_\   
  _)(|_   \\    >><<,-,,-.   <<   >>           \\     //       <<   >>   //   \\_  
 (__)__) (__)  (__)(./  \.) (__) (__)         (__)   (__)     (__) (__) (__)  (__) 
  )";
                SetConsoleTextAttribute(hc, 0X07);
                if(choice == 'p'){
                    break;
                }
            }
            if (win == true)
            {
                system("CLS");
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(hc, 0Xa);
                cout << R"(
               __   __                                     _            
               \ \ / /   ___    _  _      o O O __ __ __  (_)    _ _    
                \ V /   / _ \  | +| |    o      \ V  V /  | |   | ' \   
                _|_|_   \___/   \_,_|   TS__[O]  \_/\_/  _|_|_  |_||_|  
              _| """ |_|"""""|_|"""""| {======|_|"""""|_|"""""|_|"""""| 
              "`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-' 
)";
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                //   clearscreen();
                if(choice == 'p'){
                    break;
                }
            }
        }

        //  ------------- FOR PLAY HARD
        else if (option == 2)
        {
            system("CLS");
            gotoxy(50, 0);
            SetConsoleTextAttribute(hc, 0Xd);
            gotoxy(50, 0);
            cout << R"(
                                      _____           ___                                    
                                    / ___/__ _____  / _ \___ ________   ___ ____ ___ _  ___ 
                                   / /__/ _ `/ __/ / , _/ _ `/ __/ -_) / _ `/ _ `/  ' \/ -_)
                                   \___/\_,_/_/   /_/|_|\_,_/\__/\__/  \_, /\_,_/_/_/_/\__/ 
                                                                      /___/                 
)";
            printroad();

            gotoxy(45, 13);
            cout << " *** Press ESC to stop the game. *** ";

            SetConsoleTextAttribute(hc, 0X07);

            race[carmx][carmy] = ' ';
            race[carmx][carmy + 1] = '#';

            race[carmx + 1][carmy] = '#';
            race[carmx + 1][carmy + 1] = '#';
            race[carmx + 1][carmy + 2] = '#';

            race[carmx + 2][carmy] = ' ';
            race[carmx + 2][carmy + 1] = '#';

            race[carmx + 3][carmy] = '#';
            race[carmx + 3][carmy + 1] = '#';
            race[carmx + 3][carmy + 2] = '#';

            gotoxy(0,2);
            cout<<"#";

            gotoxy(carmy, carmx);
            cout << " #";

            gotoxy(carmy, carmx + 1);
            cout << "###";

            gotoxy(carmy, carmx + 2);
            cout << " #" ;

            gotoxy(carmy, carmx + 3);
            cout << "###";

           
            while (true)
            {
                Sleep(200);
                SetConsoleTextAttribute(hc, 0Xc);
                gotoxy(50, 10);
                cout << " Remaining lives: " << live;

                
                SetConsoleTextAttribute(hc, 0Xb);
                gotoxy(50, 15);
                cout << " Your Score: " << score;
                SetConsoleTextAttribute(hc, 0X07);
                
                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveCarLeft(); // Function call to move Pacman towards left
                }
                else if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveCarRight(); // Function call to move Pacman towards right
                }
                else if (GetAsyncKeyState(VK_UP))
                {
                    moveCarUp(); // Function call to move Pacman towards up
                }
                else if (GetAsyncKeyState(VK_DOWN))
                {
                    moveCarDown(); // Function call to move Pacman towards down
                }
                else if (GetAsyncKeyState(VK_ESCAPE))
                {
                    break; // Stop the game
                }
                if (live == 0)
                {
                    gameover = true;
                     choice = 'p';
                    break;
                }
                if (score == 10)
                {
                    win = true;
                     choice = 'p';
                    break;
                }
               if (randcheck == 3)      // this will genrate car random position 
                {
                    srand(time(0));
                    result = 1 + (rand() % 4);
                    randcheck = 0;
                }

                timetick(result);
                randcheck++;
               
                result = 0; 
                
            
                if (giveScore == 50)
                {
                    srand(time(0));
                    result2 = 1 + (rand() % 4);
                    giveScore = 0;
                }

                timetickdot(result2);

                giveScore++;
              

                result2 = 0;

                if (givelive == 600)
                {
                    givelive = 0;
                    srand(time(0));
                    result3 = 1 + (rand() % 4);
                }
              
                givelives();
                  givelive++;
                result3 = 0;
            }

            if (gameover == true)
            {
                system("CLS");
                SetConsoleTextAttribute(hc, 0Xb);
                cout << R"(
__/\\\________/\\\________________________________________/\\\_______________________________________________________        
 _\///\\\____/\\\/________________________________________\/\\\_______________________________________________________       
  ___\///\\\/\\\/__________________________________________\/\\\_______________________________________________________      
   _____\///\\\/__________/\\\\\_____/\\\____/\\\___________\/\\\_________________/\\\\\_____/\\\\\\\\\\_____/\\\\\\\\__     
    _______\/\\\_________/\\\///\\\__\/\\\___\/\\\___________\/\\\_______________/\\\///\\\__\/\\\//////____/\\\/////\\\_    
     _______\/\\\________/\\\__\//\\\_\/\\\___\/\\\___________\/\\\______________/\\\__\//\\\_\/\\\\\\\\\\__/\\\\\\\\\\\__   
      _______\/\\\_______\//\\\__/\\\__\/\\\___\/\\\___________\/\\\_____________\//\\\__/\\\__\////////\\\_\//\\///////___  
       _______\/\\\________\///\\\\\/___\//\\\\\\\\\____________\/\\\\\\\\\\\\\\\__\///\\\\\/____/\\\\\\\\\\__\//\\\\\\\\\\_ 
        _______\///___________\/////______\/////////_____________\///////////////_____\/////_____\//////////____\//////////__
)";
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(hc, 0Xb);
                cout << R"( 
   ____      _      __  __  U _____ u       U  ___ u__     __ U _____ u   ____     
U /"___|uU  /"\  uU|' \/ '|u\| ___"|/        \/"_ \/\ \   /"/u\| ___"|/U |  _"\ u  
\| |  _ / \/ _ \/ \| |\/| |/ |  _|"          | | | | \ \ / //  |  _|"   \| |_) |/  
 | |_| |  / ___ \  | |  | |  | |___      .-,_| |_| | /\ V /_,-.| |___    |  _ <    
  \____| /_/   \_\ |_|  |_|  |_____|      \_)-\___/ U  \_/-(_/ |_____|   |_| \_\   
  _)(|_   \\    >><<,-,,-.   <<   >>           \\     //       <<   >>   //   \\_  
 (__)__) (__)  (__)(./  \.) (__) (__)         (__)   (__)     (__) (__) (__)  (__) 
  )";
                SetConsoleTextAttribute(hc, 0X07);
                if(choice == 'p'){
                    break;
                }
            }
            if (win == true)
            {
                system("CLS");
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(hc, 0Xa);
                cout << R"(
               __   __                                     _            
               \ \ / /   ___    _  _      o O O __ __ __  (_)    _ _    
                \ V /   / _ \  | +| |    o      \ V  V /  | |   | ' \   
                _|_|_   \___/   \_,_|   TS__[O]  \_/\_/  _|_|_  |_||_|  
              _| """ |_|"""""|_|"""""| {======|_|"""""|_|"""""|_|"""""| 
              "`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-' 
)";
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                //   clearscreen();
                if(choice == 'p'){
                    break;
                }
            }
        }
        else{
            cout <<" Invalid option entered."<<endl;
        }

        // ---------- END PLAY HARD
    }

    else if (choice == 'q' || choice == 'Q')
    {
        break;
    }
    else if (choice == 'i' || choice == 'I'){
        cout << " INSTRUCTIONS."<<endl;
        cout <<" --------------------"<<endl;
        cout <<" 1) Enemy died when coming cars hit the front car.."<<endl;
        cout <<" 2) You have 3 life.."<<endl;
        cout <<" 3) If enemy touch the car then one life will be decrease.."<<endl;
        cout <<" 4) After few minutes scores(@) (BLUE colour) fall down if you touch the (@) 1 score will be added.. "<<endl;
        cout <<" 4) After few minutes live($) (RED colour) fall down if you touch the ($) 1 live will be added.. "<<endl;
        cout << "5) if you take a 10 score you win.."<<endl;
        cout << "6) when live become zero game will be end..."<<endl;
        getch();
        system("CLS");
        
    }
    else{

        cout <<" Invalid option entered."<<endl;
    }
    }
}

void givelives()
{

    if (result3 == 1)
    {
        firstc = true;
    }
    if(result3 == 2){
        secondcolumnlive = true;
    }
    if(result3 == 3){
       thirdcolumnlive = true;
    }

    if (firstc == true)
    {
        gotoxy(4, lifeonec - 1);
        cout << " ";
        liveemptyfirstcolumn();

        SetConsoleTextAttribute(hc, 0Xc);
        gotoxy(4, lifeonec);
        cout << "$" ;
        livesavefirstcolumn();

        SetConsoleTextAttribute(hc, 0X07);

        if (race[lifeonec + 1][4] == '#')
        {
            live++;
            gotoxy(4, lifeonec);
            cout << " ";
            lifeonec = 3;
          liveemptyfirstcolumn();
            firstc = false;
        }

        lifeonec++;
        if (lifeonec == 24)
        {
            livefirstc();
        }
    }
    if(secondcolumnlive == true){
        gotoxy(14, lifesecondcol - 1);
        cout << " ";

        liveemptysecondcolumn();
        
        SetConsoleTextAttribute(hc, 0Xc);
        gotoxy(14, lifesecondcol);
        cout << "$" ;
        livesavesecondcolumn();

        SetConsoleTextAttribute(hc, 0X07);

        if (race[lifesecondcol + 1][14] == '#')
        {
            live++;
            gotoxy(14, lifesecondcol);
            cout << " ";
            lifesecondcol = 3;
          liveemptysecondcolumn();
            secondcolumnlive = false;
        }

        lifesecondcol++;
        if (lifesecondcol == 24)
        {
            livesecondc();
        }
    }

     if(thirdcolumnlive == true){
        gotoxy(24, lifethirdcol - 1);
        cout << " ";
          liveemptythirdcolumn();

        SetConsoleTextAttribute(hc, 0Xc);
        gotoxy(24, lifethirdcol);
        cout << "$" ;
         livesavethirdcolumn();
         
        SetConsoleTextAttribute(hc, 0X07);

        if (race[lifethirdcol + 1][24] == '#')
        {
            live++;
            gotoxy(24, lifethirdcol);
            cout << " ";
            lifethirdcol = 0;
           liveemptythirdcolumn();
            thirdcolumnlive = false;
        }

        lifethirdcol++;
        if (lifethirdcol == 24)
        {
            livethirdc();
            
        }
    }

    }
void livefirstc(){
          gotoxy(4, lifeonec - 1);
            cout << " ";
            lifeonec = 3;
             liveemptyfirstcolumn();
            firstc = false;
}
void livesecondc(){
             gotoxy(14, lifesecondcol - 1);
            cout << " ";
            liveemptysecondcolumn();
            lifesecondcol = 0;
          
            secondcolumnlive = false;
}
void livethirdc(){
            gotoxy(24, lifethirdcol - 1);
            cout << " ";
            lifethirdcol = 0;
            liveemptythirdcolumn();
            thirdcolumnlive = false;
}
//-----------------------
void liveemptyfirstcolumn(){
    race[lifeonec][4] = ' ';
}
void livesavefirstcolumn(){
     Sleep(10);
    race[lifeonec][4] = '$';
} // ------------------------
void liveemptysecondcolumn(){
    race[lifesecondcol][14] = ' ';
}
void livesavesecondcolumn(){
     Sleep(10);
    race[lifesecondcol][14] = '$';
}
//------------------------
void  liveemptythirdcolumn(){
   race[lifethirdcol][23] = ' ';
}
void  livesavethirdcolumn(){
     Sleep(10);
   race[lifethirdcol][23] = '$';
}

void timetickdot( int rsult2)
{

    if (rsult2 == 1)
    {
        firstcolumn = true;
    }
    if (rsult2 == 2)
    {
        secondcolumn = true;
    }
    if (rsult2 == 3)
    {
        thirdcolumn = true;
    }

    if (firstcolumn == true)
    {

        gotoxy(4, dotfirstx - 1);
        cout << " ";
        emptydotinarray();

        gotoxy(4, dotfirstx);
        SetConsoleTextAttribute(hc, 0Xb);
        cout << "@";
        SetConsoleTextAttribute(hc, 0X07);

        dotinarray();

        if (race[dotfirstx + 1][5] == '#')
        {
            score++;
            gotoxy(4, dotfirstx);
            cout << " ";
            dotfirstx = 3;
            firstcolumn = false;
          emptydotinarray();
        }

        dotfirstx++;
        if (dotfirstx == 24)
        {
            dotfirst();
            
        }
    }
    if (secondcolumn == true)
    {

        gotoxy(14, dotsecondx - 1);
        cout << " ";
        emptydotinsecondarray();

        SetConsoleTextAttribute(hc, 0Xb);
        gotoxy(14, dotsecondx);
        cout << "@";
        SetConsoleTextAttribute(hc, 0X07);
        dotinsecondarray();

        if (race[dotsecondx + 1][14] == '#')
        {
            score++;
            gotoxy(14, dotsecondx);
            cout << " ";
            dotsecondx = 3;
            secondcolumn = false;
            emptydotinsecondarray();
            
        }

        dotsecondx++;
        if (dotsecondx == 24)
        {
            dotsecond();
            
        }
    }

    if (thirdcolumn == true)
    {

        gotoxy(23, dotthirdx - 1);
        cout << " ";
        emptydotinthirdarray();

        SetConsoleTextAttribute(hc, 0Xb);
        gotoxy(23, dotthirdx);
        cout << "@";
        SetConsoleTextAttribute(hc, 0X07);
        dotinthirdarray();

        if (race[dotthirdx + 1][23] == '#')
        {
            score++;
            gotoxy(23, dotthirdx);
            cout << " ";
            dotthirdx = 3;
            thirdcolumn = false;
            emptydotinthirdarray();
        }

        dotthirdx++;
        if (dotthirdx == 24)
        {
             dotthird();
            gotoxy(23, dotthirdx - 1);
            cout << " ";
            dotthirdx = 3;
            emptydotinthirdarray();
            thirdcolumn = false;
        }
    }
}
void dotthird(){
           gotoxy(23, dotthirdx - 1);
            cout << " ";
           
            dotthirdx = 3;
            emptydotinthirdarray();
            thirdcolumn = false;
}
void dotfirst(){
         gotoxy(4, dotfirstx - 1);
            cout << " ";
            dotfirstx = 3;
         emptydotinarray();

            firstcolumn = false;
}
void dotsecond(){
         gotoxy(14, dotsecondx - 1);
            cout << " ";
            dotsecondx = 3;
           // cout << "FFF";
            emptydotinsecondarray();
            
            secondcolumn = false;
} 
void dotinarray()
{
   Sleep(10);
    race[dotfirstx][5] = '@';
}
void dotinthirdarray()
{
  Sleep(10);
    race[dotthirdx][23] = '@';
}
void dotinsecondarray()
{    Sleep(10);
    race[dotsecondx][14] = '@';
}
void emptydotinarray()
{

    race[dotfirstx][5] = ' ';
}
void emptydotinsecondarray()
{
    race[dotsecondx][14] = ' ';
}
void emptydotinthirdarray()
{
    race[dotthirdx][23] = ' ';
}
void printroad()
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 34; j++)
        {
            gotoxy(j, i);
            cout << race[i][j];
        }
        cout << endl;
    }
}
void moveCarUp()
{
    if (carmx != 0 && racefx != 0 && racetx != 0)
    {
        if (race[carmx][carmy + 1] == '#')
        {
            
            gotoxy(carmy, carmx);
            cout << "  ";

            gotoxy(carmy, carmx + 1);
            cout << "   ";

            gotoxy(carmy, carmx + 2);
            cout << "  " ;

            gotoxy(carmy, carmx + 3);
            cout << "   " ;

            //------------               xaxis 18
            gotoxy(carmy, carmx - 1); // 17
            cout << " #" ;

            gotoxy(carmy, carmx); // 18
            cout << "###";

            gotoxy(carmy, carmx + 1); // 19
            cout << " #";

            gotoxy(carmy, carmx + 2); // 20
            cout << "###";

            emptymidcolumn();
            updateValue();

            fillmidcolumn();
        }
        else if (race[racefx + 1][racefy] == '#')
        {
            gotoxy(racefy, racefx);
            cout << "  " ;

            gotoxy(racefy, racefx + 1);
            cout << "   " ;

            gotoxy(racefy, racefx + 2);
            cout << "  " ;

            gotoxy(racefy, racefx + 3);
            cout << "   " ;
            //----                     //18
            gotoxy(racefy, racefx - 1);
            cout << " #"; // incerement 1

            gotoxy(racefy, racefx);
            cout << "###";

            gotoxy(racefy, racefx + 1);
            cout << " #";

            gotoxy(racefy, racefx + 2);
            cout << "###";

            emptyfirstcolumn();
            updateValue();

            fillfirstcolumn();
        }
        else if (race[racetx][racety + 1] = '#')
        {
            gotoxy(racety, racetx); // first value of racety and k;   racety or racetx akhri block
            cout << "  ";
            gotoxy(racety, racetx + 1);
            cout << "   ";
            gotoxy(racety, racetx + 2);
            cout << "  " ;
            gotoxy(racety, racetx + 3);
            cout << "   " ;

            //-----------    18
            gotoxy(racety, racetx - 1); //
            cout << " #";
            gotoxy(racety, racetx);
            cout << "###";
            gotoxy(racety, racetx + 1);
            cout << " #";
            gotoxy(racety, racetx + 2);
            cout << "###";

            emptythirdcolumn();
            updateValue();
            fillthirdcolumn();
        }
    }
}
void moveCarDown()
{
    if (race[23][14] != '#')
    {
        if (race[carmx][carmy + 1] == '#')
        {
            gotoxy(carmy, carmx);
            cout << "  " ;

            gotoxy(carmy, carmx + 1);
            cout << "   " ;

            gotoxy(carmy, carmx + 2);
            cout << "  " ;

            gotoxy(carmy, carmx + 3);
            cout << "   " ;

            //----       //18
            gotoxy(carmy, carmx + 1); // 17
            cout << " #" ;

            gotoxy(carmy, carmx + 2); // 18
            cout << "###";

            gotoxy(carmy, carmx + 3); // 19
            cout << " #";

            gotoxy(carmy, carmx + 4); // 20
            cout << "###";

            emptymidcolumn();
            updatedownValue();

            fillmidcolumn();
        }

        else if (race[racefx + 1][racefy] == '#')
        {
            if (race[23][4] != '#')
            {
                gotoxy(racefy, racefx);
                cout << "  " ;

                gotoxy(racefy, racefx + 1);
                cout << "   " ;

                gotoxy(racefy, racefx + 2);
                cout << "  " ;

                gotoxy(racefy, racefx + 3);
                cout << "   " ;
                //----                     //18
                gotoxy(racefy, racefx + 1);
                cout << " #"; // incerement 1

                gotoxy(racefy, racefx + 2);
                cout << "###";

                gotoxy(racefy, racefx + 3);
                cout << " #";

                gotoxy(racefy, racefx + 4);
                cout << "###";

                emptyfirstcolumn();
                updatedownValue();

                fillfirstcolumn();
            }
        }
        else if (race[racetx][racety + 1] = '#')
        {
            if (race[23][23] != '#')
            {
                gotoxy(racety, racetx); // first value of racety and k;   racety or racetx akhri block
                cout << "  " ;
                gotoxy(racety, racetx + 1);
                cout << "   " ;
                gotoxy(racety, racetx + 2);
                cout << "  " ;
                gotoxy(racety, racetx + 3);
                cout << "   " ;

                //-----------    18
                gotoxy(racety, racetx + 1); //
                cout << " #" ;
                gotoxy(racety, racetx + 2);
                cout << "###" ;
                gotoxy(racety, racetx + 3);
                cout << " #" ;
                gotoxy(racety, racetx + 4);
                cout << "###" ;

                emptythirdcolumn();
                updatedownValue();
                fillthirdcolumn();
            }
        }
    }
}
void updateValue()
{
    carmx--;
    racefx--;
    racetx--;
}
void updatedownValue()
{
    carmx++;
    racefx++;
    racetx++;
}

void moveCarLeft()
{
    if (count2 == 1)
    {
        Sleep(03);
           if(race[carmx][carmy] == '*'){
            live--;
            score--;
            cartouchh();
        } 
         else if ( race[carmx+1][carmy] == '*'){
            live--;
            score--;
           // cartouchh();
            gotoxy(14, movemid - 1);
                cout << "   " ;

                gotoxy(14, movemid - 2);
                cout << "  " ;

                gotoxy(14, movemid - 3);
                cout << "   " ;

                gotoxy(14, movemid - 4);
                cout << "  " ;

                enemyemptymidc();
                midccheck = 0;
                nextimemid = 0;
                movemid = 3;
                score++;
                checkmid = false;
        } 
       else if (race[carmx+2][carmy] == '*'){
             live--;
            score--;
           // cartouchh();
           gotoxy(14, movemid - 1);
                cout << "   " ;

                gotoxy(14, movemid - 2);
                cout << "  " ;

                gotoxy(14, movemid - 3);
                cout << "   " ;

                gotoxy(14, movemid - 4);
                cout << "  " ;

                enemyemptymidc();
                midccheck = 0;
                nextimemid = 0;
                movemid = 3;
                score++;
                checkmid = false;
        }
        else if (race[carmx+3][carmy] == '*'){
             live--;
            score--;
          //  cartouchh();
            gotoxy(14, movemid - 1);
                cout << "   " ;

                gotoxy(14, movemid - 2);
                cout << "  " ;

                gotoxy(14, movemid - 3);
                cout << "   " ;

                gotoxy(14, movemid - 4);
                cout << "  " ;

                enemyemptymidc();
                midccheck = 0;
                nextimemid = 0;
                movemid = 3;
                score++;
                checkmid = false;
        }
      /*  if(race[carmx][carmy] == '*' || race[carmx+1][carmy] == '*' ||race[carmx+2][carmy] == '*' || race[carmx+3][carmy] == '*'  || race[carmx+4][carmy] == '*' ){
            live--;
            score--;
            cartouchh();
        } */
       
/*    if(race[carmx][13] == '@' || race[carmx+1][13] == '@' ||race[carmx+2][13] == '@'|| race[carmx+4][13] == '@'||race[carmx][14] == '@' || race[carmx+1][14] == '@' ||race[carmx+2][14] == '@'|| race[carmx+3][14] == '@' || race[carmx+4][14] == '@' ||race[carmx][15] == '@' || race[carmx+1][15] == '@' ||race[carmx+2][15] == '@'|| race[carmx+3][15] == '@'|| race[carmx][16] == '@' || race[carmx+1][16] == '@' ||race[carmx+2][16] == '@'|| race[carmx+4][16] == '@'||race[carmx][17] == '@' || race[carmx+1][17] == '@' ||race[carmx+2][17] == '@'|| race[carmx+4][17] == '@'){
            score ++;
            dotsecond();
        } */

          if(race[carmx][13] == '@'){
              score ++;
            dotsecond();
        }

        else if (race[carmx+1][13] == '@'){
          score ++;
            dotsecond();
        }
        else if (race[carmx+2][13] == '@'){
             score ++;
            dotsecond();
        }
        else if (race[carmx+3][13] == '@'){
             score ++;
            dotsecond();
        }
        else if (race[carmx][14] == '@'){
          score ++;
            dotsecond();

        }else if (race[carmx+1][14] == '@'){
            score ++;
            dotsecond();
        }
        else if (race[carmx+2][14] == '@'){
              score ++;
            dotsecond();
        }
        else if (race[carmx+3][14] == '@'){
               score ++;
            dotsecond();
        }
        else if (race[carmx][15] == '@'){
          score ++;
            dotsecond();
        }
        else if (race[carmx+1][15] == '@'){
            score ++;
            dotsecond();
        }
        else if (race[carmx+2][15] == '@'){
             score ++;
            dotsecond();
        }
        else if (race[carmx+3][15] == '@'){
          score ++;
            dotsecond();
        }
        /*else if (race[carmx][16] == '@'){
             score++;
           dotsecond();
        }
        }else if (race[carmx+1][16] == '@'){
             score++;
           dotsecond();
        }
        else if (race[carmx+2][16] == '@'){
              score++;
           dotsecond();
        }
        else if (race[carmx+3][16] == '@'){
              score++;
           dotsecond();
        } */
         
      /*  if(race[carmx][13] == '$' || race[carmx+1][13] == '$' ||race[carmx+2][13] == '$'|| race[carmx+4][13] == '$'||race[carmx][14] == '$' || race[carmx+1][14] == '$' ||race[carmx+2][14] == '$'|| race[carmx+3][14] == '$' || race[carmx+4][14] == '$' ||race[carmx][15] == '$' || race[carmx+1][15] == '$' ||race[carmx+2][15] == '$'|| race[carmx+3][15] == '$'|| race[carmx][16] == '$' || race[carmx+1][16] == '$' ||race[carmx+2][16] == '$'|| race[carmx+4][16] == '$'||race[carmx][17] == '$' || race[carmx+1][17] == '$' ||race[carmx+2][17] == '$'|| race[carmx+4][17] == '$'){
            live ++;
            livesecondc();
        } */

        if(race[carmx][13] == '$'){
             live ++;
            livesecondc();
        }

        else if (race[carmx+1][13] == '$'){
          live ++;
            livesecondc();
        }
        else if (race[carmx+2][13] == '$'){
            live ++;
            livesecondc();
        }
        else if (race[carmx+3][13] == '$'){
             live ++;
            livesecondc();
        }
        else if (race[carmx][14] == '$'){
        live ++;
            livesecondc();

        }else if (race[carmx+1][14] == '$'){
            live ++;
            livesecondc();
        }
        else if (race[carmx+2][14] == '$'){
              live ++;
            livesecondc();
        }
        else if (race[carmx+3][14] == '$'){
             live ++;
            livesecondc();
        }
        else if (race[carmx][15] == '$'){
           live ++;
            livesecondc();
        }
        else if (race[carmx+1][15] == '$'){
           live ++;
            livesecondc();
        }
        else if (race[carmx+2][15] == '$'){
             live ++;
            livesecondc();
        }
        else if (race[carmx+3][15] == '$'){
          live ++;
            livesecondc();
        }
        
        gotoxy(racety, racetx); // first value of racety and k;   racety or racetx akhri block
        cout << "  " ;
        gotoxy(racety, racetx + 1);
        cout << "   " ;
        gotoxy(racety, racetx + 2);
        cout << "  " ;
        gotoxy(racety, racetx + 3);
        cout << "   " ;
        count2 = 0;

        gotoxy(carmy, carmx);
        cout << " #" ;

        gotoxy(carmy, carmx + 1);
        cout << "###" ;

        gotoxy(carmy, carmx + 2);
        cout << " #";

        gotoxy(carmy, carmx + 3);
        cout << "###";

        emptythirdcolumn();
        fillmidcolumn();
    }
    else if (carmy != 0)
    {
         Sleep(03);
           if(race[racefx][racefy] == '*'){
            live--;
            score--;
            cartouch();
        } 
       else if ( race[racefx+1][racefy] == '*'){
            live--;
            score--;
          //  cartouch();
          gotoxy(4, movefirst - 1);
                cout << "   " ;

                gotoxy(4, movefirst - 2);
                cout << "  " ;

                gotoxy(4, movefirst - 3);
                cout << "   " ;

                gotoxy(4, movefirst - 4);
                cout << "  " ;

                enemyemptyfirstc();
                movefirst = 3;
                firstcheck = 0;
                score++;
                checkfirst = false;
        }
        else if (race[racefx+2][racefy] == '*'){
             live--;
            score--;
          //  cartouch();
          gotoxy(4, movefirst - 1);
                cout << "   " ;

                gotoxy(4, movefirst - 2);
                cout << "  " ;

                gotoxy(4, movefirst - 3);
                cout << "   " ;

                gotoxy(4, movefirst - 4);
                cout << "  " ;

                enemyemptyfirstc();
                movefirst = 3;
                firstcheck = 0;
                score++;
                checkfirst = false;
        } 
        else if (race[racefx+3][racefy] == '*'){
             live--;
            score--;
          //  cartouch();
             gotoxy(4, movefirst - 1);
                cout << "   " ;

                gotoxy(4, movefirst - 2);
                cout << "  " ;

                gotoxy(4, movefirst - 3);
                cout << "   " ;

                gotoxy(4, movefirst - 4);
                cout << "  " ;

                enemyemptyfirstc();
                movefirst = 3;
                firstcheck = 0;
                score++;
                checkfirst = false;
        } 
       /* if(race[racefx][racefy] == '*' || race[racefx+1][racefy] == '*' ||race[racefx+2][racefy] == '*'|| race[racefx+3][racefy] == '*'){
            live--;
            score--;
            cartouch();
        } */
       /* if(race[carmx][4] == '@' || race[carmx+1][4] == '@' ||race[carmx+2][4] == '@'|| race[carmx+3][4] == '@' ||race[carmx][3] == '@' || race[carmx+1][3] == '@' ||race[carmx+2][3] == '@'|| race[carmx+3][3] == '@'||race[carmx][2] == '@' || race[carmx+1][2] == '@' ||race[carmx+2][2] == '@'|| race[carmx+3][2] == '@' || race[carmx][5] == '@' || race[carmx+1][5] == '@' ||race[carmx+2][5] == '@'|| race[carmx+3][5] == '@'){
            score ++; 
            dotfirst();
        } */

        if(race[carmx][3] == '@'){
              score ++;
            dotsecond();
        }

        else if (race[carmx+1][3] == '@'){
          score ++;
            dotsecond();
        }
        else if (race[carmx+2][3] == '@'){
             score ++;
            dotsecond();
        }
        else if (race[carmx+3][3] == '@'){
             score ++;
            dotsecond();
        }
        else if (race[carmx][4] == '@'){
          score ++;
            dotsecond();

        }else if (race[carmx+1][4] == '@'){
            score ++;
            dotsecond();
        }
        else if (race[carmx+2][4] == '@'){
              score ++;
            dotsecond();
        }
        else if (race[carmx+3][4] == '@'){
               score ++;
            dotsecond();
        }
        else if (race[carmx][5] == '@'){
          score ++;
            dotsecond();
        }
        else if (race[carmx+1][5] == '@'){
            score ++;
            dotsecond();
        }
        else if (race[carmx+2][5] == '@'){
             score ++;
            dotsecond();
        }
        else if (race[carmx+3][5] == '@'){
          score ++;
            dotsecond();
        }

       /*  if(race[carmx][4] == '$' || race[carmx+1][4] == '$' ||race[carmx+2][4] == '$'|| race[carmx+3][4] == '$' ||race[carmx][3] == '$' || race[carmx+1][3] == '$' ||race[carmx+2][3] == '$'|| race[carmx+3][3] == '$'||race[carmx][2] == '$' || race[carmx+1][2] == '$' ||race[carmx+2][2] == '$'|| race[carmx+3][2] == '$' || race[carmx][5] == '$' || race[carmx+1][5] == '$' ||race[carmx+2][5] == '$'|| race[carmx+3][5] == '$'){
            live ++; 
            livefirstc();
        } */
          
           if(race[carmx][3] == '$'){
            live ++; 
            livefirstc();
        }

        else if (race[carmx+1][3] == '$'){
          live ++; 
            livefirstc();
        }
        else if (race[carmx+2][3] == '$'){
            live ++; 
            livefirstc();
        }
        else if (race[carmx+3][3] == '$'){
            live ++; 
            livefirstc();
        }
        else if (race[carmx][4] == '$'){
          live ++; 
            livefirstc();

        }
        else if (race[carmx+1][4] == '$'){
            score ++;
            dotsecond();
        }
        else if (race[carmx+2][4] == '$'){
             live ++; 
            livefirstc();
        }
        else if (race[carmx+3][4] == '$'){
              live ++; 
            livefirstc();
        }
        else if (race[carmx][5] == '$'){
          live ++; 
            livefirstc();
        }
        else if (race[carmx+1][5] == '$'){
           live ++; 
            livefirstc();
        }
        else if (race[carmx+2][5] == '$'){
            live ++; 
            livefirstc();
        }
        else if (race[carmx+3][5] == '$'){
                 live ++; 
            livefirstc();
        }


       // if()
        gotoxy(carmy, carmx);
        cout << "  ";

        gotoxy(carmy, carmx + 1);
        cout << "   " ;

        gotoxy(carmy, carmx + 2);
        cout << "  " ;

        gotoxy(carmy, carmx + 3);
        cout << "   " ;

        gotoxy(racefy, racefx);
        cout << " #" ;

        gotoxy(racefy, racefx + 1);
        cout << "###";

        gotoxy(racefy, racefx + 2);
        cout << " #" ;

        gotoxy(racefy, racefx + 3);
        cout << "###" ;
        checkcount();
        // cout<<count;
        // getch();
        emptymidcolumn();
        fillfirstcolumn();
    }
}
void moveCarRight()
{

    if (count == 2)
    {
         Sleep(03);
            if(race[carmx][carmy] == '*'){
            live--;
            score--;
           // cartouchh();
           gotoxy(14, movemid - 1);
                cout << "   " ;

                gotoxy(14, movemid - 2);
                cout << "  " ;

                gotoxy(14, movemid - 3);
                cout << "   " ;

                gotoxy(14, movemid - 4);
                cout << "  " ;

                enemyemptymidc();
                midccheck = 0;
                nextimemid = 0;
                movemid = 3;
                score++;
                checkmid = false;

        } 
      else if ( race[carmx+1][carmy] == '*'){
            live--;
            score--;
          //  cartouchh();
          gotoxy(14, movemid - 1);
                cout << "   " ;

                gotoxy(14, movemid - 2);
                cout << "  " ;

                gotoxy(14, movemid - 3);
                cout << "   " ;

                gotoxy(14, movemid - 4);
                cout << "  " ;

                enemyemptymidc();
                midccheck = 0;
                nextimemid = 0;
                movemid = 3;
                score++;
                checkmid = false;

        }
       else if (race[carmx+2][carmy] == '*'){
             live--;
            score--;
           // cartouchh();
           gotoxy(14, movemid - 1);
                cout << "   " ;

                gotoxy(14, movemid - 2);
                cout << "  " ;

                gotoxy(14, movemid - 3);
                cout << "   " ;

                gotoxy(14, movemid - 4);
                cout << "  " ;

                enemyemptymidc();
                midccheck = 0;
                nextimemid = 0;
                movemid = 3;
                score++;
                checkmid = false;

        }  
        else if (race[carmx+3][carmy] == '*'){
             live--;
             score--;
           // cartouchh();
              gotoxy(14, movemid - 1);
                cout << "   " ;

                gotoxy(14, movemid - 2);
                cout << "  " ;

                gotoxy(14, movemid - 3);
                cout << "   " ;

                gotoxy(14, movemid - 4);
                cout << "  " ;

                enemyemptymidc();
                midccheck = 0;
                nextimemid = 0;
                movemid = 3;
                score++;
                checkmid = false;

        } 
        
       /*  if(race[carmx][carmy] == '*' || race[carmx+1][carmy] == '*' ||race[carmx+2][carmy] == '*' || race[carmx+3][carmy] == '*' || race[carmx+4][carmy] == '*' ){
            live--;
            score--;
            cartouchh();
        } */
     /*   if(race[carmx][13] == '@' || race[carmx+1][13] == '@' ||race[carmx+2][13] == '@'|| race[carmx+4][13] == '@'||race[carmx][14] == '@' || race[carmx+1][14] == '@' ||race[carmx+2][14] == '@'|| race[carmx+3][14] == '@' || race[carmx+4][14] == '@' ||race[carmx][15] == '@' || race[carmx+1][15] == '@' ||race[carmx+2][15] == '@'|| race[carmx+3][15] == '@'|| race[carmx][16] == '@' || race[carmx+1][16] == '@' ||race[carmx+2][16] == '@'|| race[carmx+4][16] == '@'||race[carmx][17] == '@' || race[carmx+1][17] == '@' ||race[carmx+2][17] == '@'|| race[carmx+4][17] == '@'){
            score++;
           dotsecond();
        } */
        if(race[carmx][13] == '@'){
              score++;
           dotsecond();
        }

        else if (race[carmx+1][13] == '@'){
              score++;
           dotsecond();
        }
        else if (race[carmx+2][13] == '@'){
             score++;
           dotsecond();
        }
        else if (race[carmx+3][13] == '@'){
             score++;
           dotsecond();
        }
        else if (race[carmx][14] == '@'){
            score++;
           dotsecond();
        }
        else if (race[carmx+1][14] == '@'){
              score++;
           dotsecond();
        }
        else if (race[carmx+2][14] == '@'){
             score++;
           dotsecond();
        }
        else if (race[carmx+3][14] == '@'){
              score++;
           dotsecond();
        }
        else if (race[carmx][15] == '@'){
            score++;
           dotsecond();
        }
        else if (race[carmx+1][15] == '@'){
             score++;
           dotsecond();
        }
        else if (race[carmx+2][15] == '@'){
             score++;
           dotsecond();
        }
        else if (race[carmx+3][15] == '@'){
             score++;
           dotsecond();
        }
        else if (race[carmx][16] == '@'){
             score++;
           dotsecond();
        }
        
        else if (race[carmx+1][16] == '@'){
             score++;
           dotsecond();
        }
        else if (race[carmx+2][16] == '@'){
              score++;
           dotsecond();
        }
        else if (race[carmx+3][16] == '@'){
              score++;
           dotsecond();
        }
     /*   if(race[carmx][13] == '$' || race[carmx+1][13] == '$' ||race[carmx+2][13] == '$'|| race[carmx+4][13] == '$'||race[carmx][14] == '$' || race[carmx+1][14] == '$' ||race[carmx+2][14] == '$'|| race[carmx+3][14] == '$' || race[carmx+4][14] == '$' ||race[carmx][15] == '$' || race[carmx+1][15] == '$' ||race[carmx+2][15] == '$'|| race[carmx+3][15] == '$'|| race[carmx][16] == '$' || race[carmx+1][16] == '$' ||race[carmx+2][16] == '$'|| race[carmx+4][16] == '$'||race[carmx][17] == '$' || race[carmx+1][17] == '$' ||race[carmx+2][17] == '$'|| race[carmx+4][17] == '$'){
            score++;
           livesecondc();
        } */
        if(race[carmx][13] == '$'){
             score++;
           livesecondc();
        }

         else if(race[carmx+1][13] == '$'){
             score++;
           livesecondc();
        }
         else if(race[carmx+2][13] == '$'){
              score++;
           livesecondc();
        }
         else if(race[carmx+3][13] == '$'){
             score++;
           livesecondc();
        }
         else if(race[carmx][14] == '$'){
              score++;
           livesecondc();
        } else if(race[carmx+1][14] == '$'){
            score++;
           livesecondc();
        } else if(race[carmx+2][14] == '$'){
              score++;
           livesecondc();
        } else if(race[carmx+3][14] == '$'){
             score++;
           livesecondc();
        }
         else if(race[carmx][15] == '$'){
            score++;
           livesecondc();
        } 
        else if(race[carmx+1][15] == '$'){
            score++;
           livesecondc();
        }
         else if(race[carmx+2][15] == '$'){
             score++;
           livesecondc();
        } 
        else if(race[carmx+3][15] == '$'){
             score++;
           livesecondc();
        }
         else if(race[carmx][16] == '$'){
             score++;
           livesecondc();
        } 
        else if(race[carmx+1][16] == '$'){
          
             score++;
           livesecondc();
        } 
        else if(race[carmx+2][16] == '$'){
             score++;
           livesecondc();
        } 
        else if(race[carmx+3][16] == '$'){
             score++;
           livesecondc();
        }


        gotoxy(racefy, racefx);
        cout << "  " ;

        gotoxy(racefy, racefx + 1);
        cout << "   " ;

        gotoxy(racefy, racefx + 2);
        cout << "  " ;

        gotoxy(racefy, racefx + 3);
        cout << "   " ;
        count = 0;

        gotoxy(carmy, carmx);
        cout << " #" ;

        gotoxy(carmy, carmx + 1);
        cout << "###" ;

        gotoxy(carmy, carmx + 2);
        cout << " #" ;

        gotoxy(carmy, carmx + 3);
        cout << "###" ;

        emptyfirstcolumn();
        fillmidcolumn();
    }
    else if (carmy != 30)
    { // empty center
    
     Sleep(03);
     
      if(race[racetx][racety] == '*'){
            live--;
            score--;
           // cout <<"hid"<<racetx<<"y "<<racety;
            cartouchhh(); 
        }
        else if ( race[racetx+1][racety] == '*'){
            live--;
            score--;
           cartouchhh();
        }
        else if (race[racetx+2][racety] == '*'){
             live--;
            score--;
           cartouchhh();
        }
       else if (race[racetx+3][racety] == '*'){
             live--;
            score--;
            cartouchhh();
        }  
       /*if(race[racetx][racety] == '*' || race[racetx+1][racety] == '*' ||race[racetx+2][racety] == '*' || race[racetx+3][racety] == '*'  ){
            live--;
            score--;
            cartouchhh(); 
        }*/

      /*  if(race[carmx][25] == '@' || race[carmx+1][25] == '@' ||race[carmx+2][25] == '@'|| race[carmx+3][25] == '@'||race[carmx][22] == '@' || race[carmx+1][22] == '@' ||race[carmx+2][22] == '@'|| race[carmx+3][22] == '@'||race[carmx][23] == '@' || race[carmx+1][23] == '@' ||race[carmx+2][23] == '@'|| race[carmx+3][23] == '@' ||race[carmx][24] == '@' || race[carmx+1][24] == '@' ||race[carmx+2][3] == '@'|| race[carmx+3][24] == '@'){
            score ++;
            
            dotthird();
        } */
        if(race[carmx][22] == '@'){
             score ++;
            
            dotthird();
        }
        else if (race[carmx+1][22] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx+2][22] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx+3][22] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx][23] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx+1][23] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx+2][23] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx+3][23] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx][24] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx+1][24] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx+2][24] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx+3][24] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx][25] == '@'){
            score ++;
            
            dotthird();
        }
        
        else if (race[carmx+1][25] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx+2][25] == '@'){
            score ++;
            
            dotthird();
        }
        else if (race[carmx+3][25] == '@'){
            score ++;
            
            dotthird();
        }

       /* if(race[carmx][25] == '$' || race[carmx+1][25] == '$' ||race[carmx+2][25] == '$'|| race[carmx+3][25] == '$'||race[carmx][22] == '$' || race[carmx+1][22] == '$' ||race[carmx+2][22] == '$'|| race[carmx+3][22] == '$'||race[carmx][23] == '$' || race[carmx+1][23] == '$' ||race[carmx+2][23] == '$'|| race[carmx+3][23] == '$' ||race[carmx][24] == '$' || race[carmx+1][24] == '$' ||race[carmx+2][3] == '$'|| race[carmx+3][24] == '$'){
            live ++;
            
            livethirdc();
        } */
        if(race[carmx][22] == '$'){
            live ++;
            
            livethirdc();
        }
        else if(race[carmx+1][22] == '$'){
             live ++;
            
            livethirdc();
        }
         else if(race[carmx+2][22] == '$'){
             live ++;
            
            livethirdc();
        }
         else if(race[carmx+3][22] == '$'){
             live ++;
            
            livethirdc();
        }
         else if(race[carmx][23] == '$'){
             live ++;
            
            livethirdc();
        }
         else if(race[carmx+1][23] == '$'){
             live ++;
            
            livethirdc();
        }
         else if(race[carmx+2][23] == '$'){
             live ++;
            
            livethirdc();
        } 
        else if(race[carmx+3][23] == '$'){
             live ++;
            
            livethirdc();
        }
         else if(race[carmx][24] == '$'){
             live ++;
            
            livethirdc();
        } 
        else if(race[carmx+1][24] == '$'){
             live ++;
            
            livethirdc();
        }
         else if(race[carmx+2][24] == '$'){
             live ++;
            
            livethirdc();
        }
         else if(race[carmx+3][24] == '$'){
             live ++;
            
            livethirdc();
        }
         else if(race[carmx][25] == '$'){
             live ++;
            
            livethirdc();
        } 
        else if(race[carmx+1][25] == '$'){
             live ++;
            
            livethirdc();
        } 
        else if(race[carmx+2][25] == '$'){
             live ++;
            
            livethirdc();
        } 
        else if(race[carmx+3][25] == '$'){
             live ++;
            
            livethirdc();
        }

        gotoxy(carmy, carmx);
        cout << "  " ;

        gotoxy(carmy, carmx + 1);
        cout << "   " ;

        gotoxy(carmy, carmx + 2);
        cout << "  " ;

        gotoxy(carmy, carmx + 3);
        cout << "   " ;

        gotoxy(racety, racetx); // first value of racety and k;   racety or racetx akhri block
        cout << " #" ;
        gotoxy(racety, racetx + 1);
        cout << "###" ;
        gotoxy(racety, racetx + 2);
        cout << " #" ;
        gotoxy(racety, racetx + 3);
        cout << "###" ;
        count2 = 1;

        emptymidcolumn();
        fillthirdcolumn();
    }
}
void load_track(){
    string line;
    fstream f;
    f.open("track.txt",ios::in);
    for(int i=0;i<24; i++){
        getline(f,line);
     
        for(int y=0; y<32;y++){
        
            race[i][y] = line[y];
            cout << race[i][y];
        }
    }
}
void timetick(int rsult)
{
   int forlivemid = 1;
   int forlivefirst = 1;
   int forlive =1;

    if (rsult == 1)
    {
        check = true;
    }
    if (rsult == 2)
    {
        checkmid = true;
    }
    if (rsult == 3)
    {
        checkfirst = true;
    }


   
    if (check == true)
    {
        if(race[0][24]!= '#'){
            
        if (nexttime != 21 && ccheck != 21)
        {
            gotoxy(23, Ethirdcolumn - 1); // 19
            cout << "   " ;

            gotoxy(23, Ethirdcolumn - 2);
            cout << "  " ;

            gotoxy(23, Ethirdcolumn - 3);
            cout << "   " ;

            gotoxy(23, Ethirdcolumn - 4);
            cout << "  " ;

            enemyemptytc();

            gotoxy(23, Ethirdcolumn); // 18
            cout << "***" ;

            gotoxy(23, Ethirdcolumn - 1); // 17
            cout << " *" ;

            gotoxy(23, Ethirdcolumn - 2); // 16
            cout << "***" ;

            gotoxy(23, Ethirdcolumn - 3); // 15
            cout << " *" ;
            enemysavetc();
            //    Sleep(300);

            if (forlive == 1)
            {
                if (race[Ethirdcolumn][23 + 1] == '*')
                {
                    if (race[Ethirdcolumn + 1][23 + 1] == '#')
                    {
                        live--;
                        forlive = 1;
                        gotoxy(23, Ethirdcolumn);
                        cout << "   " ;

                        gotoxy(23, Ethirdcolumn - 1);
                        cout << "  " ;

                        gotoxy(23, Ethirdcolumn - 2);
                        cout << "   " ;

                        gotoxy(23, Ethirdcolumn - 3);
                        cout << "  " ;
                        //------

                        enemyemptytc();

                        ccheck = 0;
                        nexttime = 0;
                        Ethirdcolumn = 3;
                        check = false;
                    }
                }
            }

            Ethirdcolumn++;
            ccheck++;
            nexttime++;
        
            if (ccheck == 21)
            {
                  //  cartouchhh();
                gotoxy(23, Ethirdcolumn - 1);
                cout << "   " ;

                gotoxy(23, Ethirdcolumn - 2);
                cout << "  " ;

                gotoxy(23, Ethirdcolumn - 3);
                cout << "   " ;

                gotoxy(23, Ethirdcolumn - 4);
                cout << "  " ;

                 enemyemptytc();
                Ethirdcolumn = 3;
                ccheck = 0;
                nexttime = 0;
                score++;
                check = false;
                
                
            }
        }
    }
    }
    if (checkmid == true)
    {
        if(race[0][15]!= '#'){
        if (nextimemid != 21 && midccheck != 21)
        {  
            gotoxy(14, movemid - 1);
            cout << "   " ;

            gotoxy(14, movemid - 2);
            cout << "  " ;

            gotoxy(14, movemid - 3);
            cout << "   " ;

            gotoxy(14, movemid - 4);
            cout << "  " ;

            enemyemptymidc();

            //---
            gotoxy(14, movemid);
            cout << "***" ;

            gotoxy(14, movemid - 1);
            cout << " *" ;

            gotoxy(14, movemid - 2);
            cout << "***" ;

            gotoxy(14, movemid - 3);
            cout << " *" ;
            //--
            gotoxy(14, movemid);
            cout << "***" ;

            gotoxy(14, movemid - 1);
            cout << " *" ;

            gotoxy(14, movemid - 2);
            cout << "***" ;

            gotoxy(14, movemid - 3);
            cout << " *" ;
            enemysavemidc(); // save in to array..
                             //   Sleep(400);

            // for check the car is crash or not..
            if (forlivemid == 1)
            {
                if (race[movemid][14 + 1] == '*')
                {
                    if (race[movemid + 1][14 + 1] == '#')
                    {
                        live--;
                        forlivemid = 1;
                        gotoxy(14, movemid);
                        cout << "   " ;

                        gotoxy(14, movemid - 1);
                        cout << "  " ;

                        gotoxy(14, movemid - 2);
                        cout << "   " ;

                        gotoxy(14, movemid - 3);
                        cout << "  " ;
                        enemyemptymidc();
                        midccheck = 0;
                        nextimemid = 0;
                        movemid = 3;
                        checkmid = false;
                    }
                }
            }

            movemid++;
            midccheck++;
            nextimemid++;

            if (midccheck == 21)
            {

                //cartouchh();
                  gotoxy(14, movemid - 1);
                cout << "   " ;

                gotoxy(14, movemid - 2);
                cout << "  " ;

                gotoxy(14, movemid - 3);
                cout << "   " ;

                gotoxy(14, movemid - 4);
                cout << "  " ;

                enemyemptymidc();
                midccheck = 0;
                nextimemid = 0;
                movemid = 3;
                score++;
                checkmid = false;
            }
        }
    }
    }
    //   ----------------- FIRST COLUMN CAR
    if (checkfirst == true)

    {  if(race[0][5]!= '#'){
        if (firstcheck != 21)
        {
            gotoxy(4, movefirst - 1);
            cout << "   " ;

            gotoxy(4, movefirst - 2);
            cout << "  " ;

            gotoxy(4, movefirst - 3);
            cout << "   " ;

            gotoxy(4, movefirst - 4);
            cout << "  " ;

            enemyemptyfirstc();
            //---------------
            gotoxy(4, movefirst);
            cout << "***" ;

            gotoxy(4, movefirst - 1);
            cout << " *" ;

            gotoxy(4, movefirst - 2);
            cout << "***" ;

            gotoxy(4, movefirst - 3);
            cout << " *" ;
            enemysavefirstc(); // save in to array..
                               //    Sleep(400);

            // for check the car is crash or not..
            if (forlivefirst == 1)
            {
                if (race[movefirst][4 + 1] == '*')
                {
                    if (race[movefirst + 1][4 + 1] == '#')
                    {
                        live--;
                        forlivefirst = 1;
                        gotoxy(4, movefirst);
                        cout << "   " ;

                        gotoxy(4, movefirst - 1);
                        cout << "  " ;

                        gotoxy(4, movefirst - 2);
                        cout << "   " ;

                        gotoxy(4, movefirst - 3);
                        cout << "  " ;
                        enemyemptyfirstc();

                        firstcheck = 0;
                        movefirst = 3;
                        checkmid = false;
                    }
                }
            }

            movefirst++;
            firstcheck++;

            if (firstcheck == 21)
            {
               // cartouch();
                gotoxy(4, movefirst - 1);
                cout << "   " ;

                gotoxy(4, movefirst - 2);
                cout << "  " ;

                gotoxy(4, movefirst - 3);
                cout << "   " ;

                gotoxy(4, movefirst - 4);
                cout << "  " ;

                enemyemptyfirstc();
                
                movefirst = 3;
                firstcheck = 0;
                score++;
                checkfirst = false;
                
            }
        }
    }
    }
}
// 3rd column
void cartouchhh(){
              gotoxy(23, Ethirdcolumn - 1);
                cout << "   " ;

                gotoxy(23, Ethirdcolumn - 2);
                cout << "  " ;

                gotoxy(23, Ethirdcolumn - 3);
                cout << "   " ;

                gotoxy(23, Ethirdcolumn - 4);
                cout << "  " ;

                enemyemptytc();
                Ethirdcolumn = 3;
                ccheck = 0;
                nexttime = 0;
                score++;
                check = false;
}  //2nd column
void cartouchh(){
             
            
              gotoxy(14, movemid - 1);
                cout << "   " ;

                gotoxy(14, movemid - 2);
                cout << "  " ;

                gotoxy(14, movemid - 3);
                cout << "   " ;

                gotoxy(14, movemid - 4);
                cout << "  " ;

                enemyemptymidc();
                midccheck = 0;
                nextimemid = 0;
                movemid = 3;
                score++;
                checkmid = false;
}
void cartouch(){
               gotoxy(4, movefirst - 1);
                cout << "   " ;

                gotoxy(4, movefirst - 2);
                cout << "  " ;

                gotoxy(4, movefirst - 3);
                cout << "   " ;

                gotoxy(4, movefirst - 4);
                cout << "  " ;

                enemyemptyfirstc();
                movefirst = 3;
                firstcheck = 0;
                score++;
                checkfirst = false;
} 
void enemysavetc()
{
   // cout <<Ethirdcolumn;
    //getch();
    Sleep(20);
    race[Ethirdcolumn][23] = '*';
    race[Ethirdcolumn][23 + 1] = '*';
    race[Ethirdcolumn][23 + 2] = '*';

    race[Ethirdcolumn - 1][23] = ' ';
    race[Ethirdcolumn - 1][23 + 1] = '*';

    race[Ethirdcolumn - 2][23] = '*';
    race[Ethirdcolumn - 2][23 + 1] = '*';
    race[Ethirdcolumn - 2][23 + 2] = '*';

    race[Ethirdcolumn - 3][23] = ' ';
    race[Ethirdcolumn - 3][23 + 1] = '*';
}
void enemysavemidc()
{
   // cout << movemid;
 Sleep(20);
    race[movemid][14] = '*';
    race[movemid][14 + 1] = '*';
    race[movemid][14 + 2] = '*';

    race[movemid - 1][14] = ' ';
    race[movemid - 1][14 + 1] = '*';

    race[movemid - 2][14] = '*';
    race[movemid - 2][14 + 1] = '*';
    race[movemid - 2][14 + 2] = '*';

    race[movemid - 3][14] = ' ';
    race[movemid - 3][14 + 1] = '*';
}
void enemysavefirstc()
{     // cout << movefirst ;
       Sleep(20);
    race[movefirst][4] = '*';
    race[movefirst][4 + 1] = '*';
    race[movefirst][4 + 2] = '*';

    race[movefirst - 1][4] = ' ';
    race[movefirst - 1][4 + 1] = '*';

    race[movefirst - 2][4] = '*';
    race[movefirst - 2][4 + 1] = '*';
    race[movefirst - 2][4 + 2] = '*';

    race[movefirst - 3][4] = ' ';
    race[movefirst - 3][4 + 1] = '*';
}
void enemyemptytc()
{ 
    race[Ethirdcolumn][23] == ' ';
    race[Ethirdcolumn][23 + 1] == ' ';
    race[Ethirdcolumn][23 + 2] == ' ';

    race[Ethirdcolumn - 1][23] == ' ';
    race[Ethirdcolumn - 1][23 + 1] == ' ';

    race[Ethirdcolumn - 2][23] == ' ';
    race[Ethirdcolumn - 2][23 + 1] == ' ';
    race[Ethirdcolumn - 2][23 + 2] == ' ';

    race[Ethirdcolumn - 3][23] == ' ';
    race[Ethirdcolumn - 3][23 + 1] == ' ';
}
void enemyemptymidc()
{
    race[movemid][14] == ' ';
    race[movemid][14 + 1] == ' ';
    race[movemid][14 + 2] == ' ';

    race[movemid - 1][14] == ' ';
    race[movemid - 1][14 + 1] == ' ';

    race[movemid - 2][14] == ' ';
    race[movemid - 2][14 + 1] == ' ';
    race[movemid - 2][14 + 2] == ' ';

    race[movemid - 3][14] == ' ';
    race[movemid - 3][14 + 1] == ' ';
}
void enemyemptyfirstc()
{
    race[movefirst][4] == ' ';
    race[movefirst][4 + 1] == ' ';
    race[movefirst][4 + 2] == ' ';

    race[movefirst - 1][4] == ' ';
    race[movefirst - 1][4 + 1] == ' ';

    race[movefirst - 2][4] == ' ';
    race[movefirst - 2][4 + 1] == ' ';
    race[movefirst - 2][4 + 2] == ' ';

    race[movefirst - 3][4] == ' ';
    race[movefirst - 3][4 + 1] == ' ';
}
void emptymidcolumn()
{
    race[carmx][carmy] = ' ';
    race[carmx][carmy + 1] = ' ';

    race[carmx + 1][carmy] = ' ';
    race[carmx + 1][carmy + 1] = ' ';
    race[carmx + 1][carmy + 2] = ' ';

    race[carmx + 2][carmy] = ' ';
    race[carmx + 2][carmy + 1] = ' ';

    race[carmx + 3][carmy] = ' ';
    race[carmx + 3][carmy + 1] = ' ';
    race[carmx + 3][carmy + 2] = ' ';
}
void fillfirstcolumn()
{
    race[racefx][racefy] = ' ';
    race[racefx][racefy + 1] = '#';

    race[racefx + 1][racefy] = '#';
    race[racefx + 1][racefy + 1] = '#';
    race[racefx + 1][racefy + 2] = '#';

    race[racefx + 2][racefy] = ' ';
    race[racefx + 2][racefy + 1] = '#';

    race[racefx + 3][racefy] = '#';
    race[racefx + 3][racefy + 1] = '#';
    race[racefx + 3][racefy + 2] = '#';
}
void fillthirdcolumn()
{
    race[racetx][racety] = ' ';
    race[racetx][racety + 1] = '#';

    race[racetx + 1][racety] = '#';
    race[racetx + 1][racety + 1] = '#';
    race[racetx + 1][racety + 2] = '#';

    race[racetx + 2][racety] = ' ';
    race[racetx + 2][racety + 1] = '#';

    race[racetx + 3][racety] = '#';
    race[racetx + 3][racety + 1] = '#';
    race[racetx + 3][racety + 2] = '#';
}
void emptythirdcolumn()
{
    race[racetx][racety] = ' ';
    race[racetx][racety + 1] = ' ';

    race[racetx + 1][racety] = ' ';
    race[racetx + 1][racety + 1] = ' ';
    race[racetx + 1][racety + 2] = ' ';

    race[racetx + 2][racety] = ' ';
    race[racetx + 2][racety + 1] = ' ';

    race[racetx + 3][racety] = ' ';
    race[racetx + 3][racety + 1] = ' ';
    race[racetx + 3][racety + 2] = ' ';
}
void emptyfirstcolumn()
{
    race[racefx][racefy] = ' ';
    race[racefx][racefy + 1] = ' ';

    race[racefx + 1][racefy] = ' ';
    race[racefx + 1][racefy + 1] = ' ';
    race[racefx + 1][racefy + 2] = ' ';

    race[racefx + 2][racefy] = ' ';
    race[racefx + 2][racefy + 1] = ' ';

    race[racefx + 3][racefy] = ' ';
    race[racefx + 3][racefy + 1] = ' ';
    race[racefx + 3][racefy + 2] = ' ';
}
void fillmidcolumn()
{
    race[carmx][carmy] = ' ';
    race[carmx][carmy + 1] = '#';

    race[carmx + 1][carmy] = '#';
    race[carmx + 1][carmy + 1] = '#';
    race[carmx + 1][carmy + 2] = '#';

    race[carmx + 2][carmy] = ' ';
    race[carmx + 2][carmy + 1] = '#';

    race[carmx + 3][carmy] = '#';
    race[carmx + 3][carmy + 1] = '#';
    race[carmx + 3][carmy + 2] = '#';
}
void checkcount()
{
    count = 2;
    // cout<<count;
}
void gotoxy(int x, int y)
{
    COORD coordinates; // coordinates is declared as COORD
    coordinates.X = x; // defining x-axis
    coordinates.Y = y; // defining  y-axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}