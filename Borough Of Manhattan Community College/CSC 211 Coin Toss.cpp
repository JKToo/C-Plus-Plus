#include <iostream>
#include <ctime>
using namespace std;

class Coin
{
private:
    string sideup;
    
public:
    Coin() {
        srand(time(NULL));
        int random = rand() % 2 + 1;
        if (random == 1) sideup = "heads";
        else sideup = "tails";
    }

    void toss()
    {
        srand(time(NULL));
        int random = rand() % 2 + 1;
        if (random == 1) sideup = "heads";
        else sideup = "tails";
    }

    string getSideup()
    {
        return sideup;
    }

};

int main()
{
    Coin flip;
    string input;
    int heads = 0;
    int tails = 0;


    for (int i = 0; i < 21; i++)
    {
        cout << "Initial start: " << flip.getSideup() << endl;
        cout << "Heads or tails? ";
        cin >> input;
        if (input == "heads")
        {
            cout << "You chose " << input << endl;
            heads++;
        }
        else if (input == "tails") 
        {
            cout << "You chose " << input << endl;
            tails++;
        }
        //cout << "AI chose: " << flip.getSideup() << endl;
        flip.toss();
        cout << "It landed on " << flip.getSideup() << endl;
        if (flip.getSideup() == input) cout << "You win!" << endl << endl;
        else cout << "You lose" << endl << endl;

    }

    cout << "heads count: " << heads << endl;
    cout << "tails count: " << tails;
}