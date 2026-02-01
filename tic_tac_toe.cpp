#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void grid(char *g);
void player_move(char *g,char human);
void computer_move(char *g,char comp);
bool winner(char *g,char human, char comp);
bool tie(char *g);

int main()
{
    
    char choice;
    char g[9]={' ',' ', ' ', ' ', ' ',' ', ' ', ' ', ' '};
    char human='X';
    char comp='O';
    bool running=true;
    int result;
    grid(g);
    do{
    while(running){
        player_move(g,human);
        grid(g);
        cout << '\n';

        if(winner(g,human,comp)){
            running=false;
            break;
        }
        else if(tie(g)){
            running=false;
            break;
        }

        computer_move(g,comp);
        grid(g);
    }
    cout << '\n';
    cout << "Wanna play again?(y/n): ";
    cin >> choice;
    }while(choice == 'y' || choice == 'Y');
    cout << "THANKS FOR PLAYING ^_^" << '\n';
    system("pause");
    return 0;
}

 void grid(char *g)
 {
    cout << "  "<< ' ' << "  " << "|" << "  "<< ' ' << "  " << "|" << "  "<< ' ' << "  " << '\n';
    cout << "  "<< g[0] << "  " << "|" << "  "<< g[1] << "  " << "|" << "  "<< g[2] << "  " << '\n';
    cout << "__"<< "_" << "__" << "|" << "__"<< "_" << "__" << "|" << "__"<< "_" << "__" << '\n';
    cout << "  "<< ' ' << "  " << "|" << "  "<< ' ' << "  " << "|" << "  "<< ' ' << "  " << '\n';
    cout << "  "<< g[3] << "  " << "|" << "  "<< g[4] << "  " << "|" << "  "<< g[5] << "  " << '\n';
    cout << "__"<< "_" << "__" << "|" << "__"<< "_" << "__" << "|" << "__"<< "_" << "__" << '\n';
    cout << "  "<< ' ' << "  " << "|" << "  "<< ' ' << "  " << "|" << "  "<< ' ' << "  " << '\n';
    cout << "  "<< g[6] << "  " << "|" << "  "<< g[7] << "  " << "|" << "  "<< g[8] << "  " << '\n';
    cout << "  "<< ' ' << "  " << "|" << "  "<< ' ' << "  " << "|" << "  "<< ' ' << "  " << '\n';
 }

void player_move(char *g,char human)
{
    int pos;
    do{
        cout << "Enter a slot to put marker(1-9): ";
        cin >> pos;
        pos--;
        if(g[pos]==' '){
            g[pos]=human;
            break;
        }
    }while(!pos > 0 || !pos <8);
}

void computer_move(char *g,char comp)
{
    int pos;
    srand(time(0));
    while(true){
        pos=rand()%9;
        if(g[pos]==' '){
            g[pos]=comp;
            break;
        }
    }
}

bool winner(char *g,char human, char comp)
{
    if((g[0]!=' ') && (g[0]==g[1] && g[1]==g[2])){
        g[0]==human? cout << "YOU WIN !!" : cout << "YOU LOSE..";
    }
    else if((g[3]!=' ') && (g[3]==g[4] && g[4]==g[5])){
        g[3]==human? cout << "YOU WIN !!" : cout << "YOU LOSE..";
    }
    else if((g[6]!=' ') && (g[6]==g[7] && g[7]==g[8])){
        g[6]==human? cout << "YOU WIN !!" : cout << "YOU LOSE..";
    }
    else if((g[0]!=' ') && (g[0]==g[3] && g[3]==g[6])){
        g[0]==human? cout << "YOU WIN !!" : cout << "YOU LOSE..";
    }
    else if((g[1]!=' ') && (g[1]==g[4] && g[4]==g[7])){
        g[1]==human? cout << "YOU WIN !!" : cout << "YOU LOSE..";
    }
    else if((g[2]!=' ') && (g[2]==g[5] && g[5]==g[8])){
        g[2]==human? cout << "YOU WIN !!" : cout << "YOU LOSE..";
    }
    else if((g[0]!=' ') && (g[0]==g[4] && g[4]==g[8])){
        g[0]==human? cout << "YOU WIN !!" : cout << "YOU LOSE..";
    }
    else if((g[2]!=' ') && (g[2]==g[4] && g[4]==g[6])){
        g[2]==human? cout << "YOU WIN !!" : cout << "YOU LOSE..";
    }
    else{
        return false;
    }
    return true;
}

bool tie(char *g)
{
    for(int i=0;i<9;i++){
        if(g[i]==' '){
            return false;
        }
    }
    cout << "IT'S A TIE!!..";
    return true;
}