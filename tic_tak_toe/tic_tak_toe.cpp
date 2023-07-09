#include<iostream>
using namespace std;
//3 function in total
// 1 function:  it will ask fro users to enter theri names we willl display the board


class ttt{
    char block[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int row,col;
    string player1 = " ";
    string  player2 = " ";
    char token = 'x';
    bool tie;
    public:
        ttt(){
            cout<<"\t\tWELCOME TO THE GAME OF TIC TAK TOE"<<endl;
            cout<<" \t\twe have two players in this game:"<<endl;
            cout<<"\tenter the name of first player: "<<endl;
            cout<<"\t"<<"";cin>>player1;
            cout<<"\tenter the name of second player "<<endl;
            cout<<"\t"<<"";cin>>player2;
            cout<<"\tso we have " <<player1<<" V/S "<<player2<<endl<<"\tlets se who wins this game!"<<endl;
        }
        void board(){
            cout<<"\t   The TIC TAK TOE BOARD"<<endl;
            cout<<"\t\t"<<" " <<block[0][0]<<"  |"<<" "<<block[0][1]<<"  |"<<" "<<block[0][2]<<endl;
            cout<<"\t\t"<<"_ _ "<<" _ _ "<<" _ _ "<<endl;
            cout<<"\t\t"<<" " <<block[1][0]<<"  |"<<" "<<block[1][1]<<"  |"<<" "<<block[1][2]<<endl;
            cout<<"\t\t"<<"_ _ "<<" _ _ "<<" _ _ "<<endl;
            cout<<"\t\t"<<" " <<block[2][0]<<"  |"<<" "<<block[2][1]<<"  |"<<" "<<block[2][2]<<endl;
            cout<<"\t\t"<<"_ _"<<" _ _ "<<" _ _ "<<endl;
        }
    void initalise();
    bool conditions();
    void result();
};
void ttt::initalise(){
    int digit;
    if(token=='x'){
        cout<<player1<<" turns: "<<endl;
        cout<<"enter your block:"<<" ";
        cin>>digit;
    }
    if(token=='0'){
        cout<<player2<<" turns: "<<endl;
        cout<<"enter your block:"<<" ";
        cin>>digit;
    }
    //now we're checking the conditions and intialising the values of rows and col accordingt o the digits .
    if(digit == 1){
        row=0;
        col=0;
    }
    else if(digit == 2){
        row=0;
        col=1;
    }
    else if(digit == 3){
        row=0;
        col=2;
    }
    else if(digit == 4){
        row=1;
        col=0;
    }
    else if(digit == 5){
        row=1;
        col=1;
    }
    else if(digit == 6){
        row=1;
        col=2;
    }
    else if(digit == 7){
        row=2;
        col=0;
    }
    else if(digit == 8){
        row=2;
        col=1;
    }
    else if(digit == 9){
        row=2;
        col=2;
    }
    else{
        cout<<"Invalid input"<<endl<<"Please enter number between (1-9)"<<endl;
        return;
    }
    //checking for unused space
    if(token == 'x' && block[row][col]!='x' && block[row][col]!='0'){
        block[row][col] = 'x';
        token = '0';
    }
    else if(token == '0' && block[row][col]!='x' && block[row][col]!='0'){
        block[row][col] = '0';
        token = 'x';
    }
    else{
        cout<<"there is no empty space"<<endl;
        initalise();
    }
}
bool ttt::conditions() {
    // Checking for a winning condition
    for (int i = 0; i < 3; i++) {
        if ((block[i][0] == block[i][1] && block[i][1] == block[i][2]) ||
            (block[0][i] == block[1][i] && block[1][i] == block[2][i])) {
            return true;
        }
    }

    if ((block[0][0] == block[1][1] && block[1][1] == block[2][2]) ||
        (block[0][2] == block[1][1] && block[1][1] == block[2][0])) {
        return true;
    }

    // Checking for empty spaces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (block[i][j] != 'x' && block[i][j] != '0') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

void ttt::result(){
    if(token == 'x' && tie == false){
        cout<<player2<<" Wins!";
        cout<<"Congractulations "<<player2<<endl;
        cout<<" ";
        cout<<"better luck next time "<<player1;
    }
    else if(token == '0' && tie == false){
        cout<<player1<<" Wins!";
        cout<<"Congractulations "<<player1<<endl;
        cout<<" ";
        cout<<"better luck next time "<<player2;
    }
    else{
        cout<<"Wah! what a match! it's a TIE!"<<endl;
    }
}
int main()
{
    ttt obj;
    while(!obj.conditions()){
        obj.board();
        obj.initalise();
        obj.conditions();
    }
    obj.board();
    obj.result();
    return 0;
}