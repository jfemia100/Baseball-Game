#include <iostream>
#include <cstdlib>
using namespace std;

// This function produces a random character, and compares it to your input. If it matches then it prints true and you get a hit.
bool HorM(char a){
    char p[3] = {'F', 'C', 'S'};
    char randomp = p[rand()%3];
    if(a == randomp) return true;
    else return false;
}

// This function prints out the position of your base runners
void print(int b){

    typedef char bases[5][6];

    bases b1 = {
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',char(47),' ',char(92),' '},
        {' ',' ',' ',' ',' ',char(219)},
        {' ',' ',char(92),' ',char(47),' '},
        {' ',' ',' ',' ',' ',' '}
    };

    bases b2 = {
        {' ',' ',' ',char(219),' ',' '},
        {' ',' ',char(47),' ',char(92),' '},
        {' ',' ',' ',' ',' ',char(219)},
        {' ',' ',char(92),' ',char(47),' '},
        {' ',' ',' ',' ',' ',' '}
    };

    bases b3 = {
        {' ',' ',' ',char(219),' ',' '},
        {' ',' ',char(47),' ',char(92),' '},
        {' ',char(219),' ',' ',' ',char(219)},
        {' ',' ',char(92),' ',char(47),' '},
        {' ',' ',' ',' ',' ',' '}
    };

    bases b4 = {
        {' ',' ',' ',char(219),' ',' '},
        {' ',' ',char(47),' ',char(92),' '},
        {' ',char(219),' ',' ',' ',char(219)},
        {' ',' ',char(92),' ',char(47),' '},
        {' ',' ',' ',char(219),' ',' '}
    };

    if(b == 1){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 6; j++){
                cout << b1[i][j];
            }
            cout << endl;
        }
        cout << endl;
    };

    if(b == 2){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 6; j++){
                cout << b2[i][j];
            }
            cout << endl;
        }
        cout << endl;
    };

    if(b == 3){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 6; j++){
                cout << b3[i][j];
            }
            cout << endl;
        }
        cout << endl;
    };

    if(b == 4){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 6; j++){
                cout << b4[i][j];
            }
            cout << endl;
        }
        cout << endl;
    };
}

//The main function runs through the entire game, and prints your score out at the end
int main(){
    int strikes = 0, hits = 0, runners = 0, runs = 0, outs = 0;
    string n[5];
    int h[5], r[5];
    int count = 0;
    string name;

    cout << "  *******      ***     ********  ********  *******      ***     *       *       " << endl;
    cout << "  *      *    *   *    *         *         *      *    *   *    *       *       " << endl;
    cout << "  *******     *****    ********  ********  *******     *****    *       *       " << endl;
    cout << "  *      *   *     *          *  *         *      *   *     *   *       *       " << endl;
    cout << "  *******   *       *  ********  ********  *******   *       *  ******  ******  " << endl;

    cout << "Rules of the game: " << endl;
    cout << "1. You have to score as many runs before you get three(3) outs." << endl;
    cout << "2. If you strike out, you lose the lead runner." << endl;
    cout << "Note: The game is case sensitive, so make sure your inputs are all capitalized." << endl;
    cout << endl;
    cout << "Have fun!" << endl;
    cout << endl;
    cout << endl;

    char ans;
    cout << "Would you like to start playing?(Y or N): ";
    cin >> ans;

    while(ans == 'Y'){
        cout << "Please enter a name to save your score under: ";
        cin >> name;
        cout << endl;
        while(outs < 3){
            cout << endl;
            cout << "New batter up!" << endl;
            while(strikes < 3){
                char p;
                cout << "Please select a pitch, Fastball(F), Curveball(C), or Slider(S)." << endl;
                cout << "Type in a letter that corresponds to that pitch: ";
                cin >> p;
                cout << endl;
                if (HorM(p)==true){
                    hits++;
                    strikes = 0;
                    runners++;
                    cout << "You got a hit!" << endl;
                    cout << "Runners: " << runners << endl;
                    print(runners);
                    if(runners == 4){
                            cout << "A runner scored!" << endl;
                            runners--;
                            runs++;
                    }
                    cout << endl;
                    cout << "New batter up!" << endl;
                }
                else {
                    strikes++;
                    cout << "Swing and a miss!"<< endl;
                    cout << "Strikes: " << strikes << endl;
                    if(strikes == 3){
                        cout << "You struck out!" << endl;
                        outs++;
                        cout << "Outs: " << outs << endl;
                        if(runners > 0){
                                runners--;
                                print(runners);
                                cout << "You lost a lead runner" << endl;
                        }
                    }
                }
            }
            strikes = 0;
            if(runners == 4){
                runners--;
                runs++;
            }
        }
       
        if(outs == 3){
            cout << endl;
            cout << "Game is over." << endl;
            cout << endl;
            cout << endl;
            cout << "Your stats for the game: "<< endl;
            cout << "Name    Hits    Runs" << endl;
            cout << name << "      " << hits << "      " << runs << endl;
            cout << endl;
            cout << endl;
            cout << "Would you like to play again, or end game? (Y or N): ";
            cin >> ans;
            if(ans == 'Y'){
                outs = 0;
                runs = 0;
                hits = 0;
                runners = 0;
                strikes = 0;
            }
        }
    }
    if(ans == 'N') return 0;
}
