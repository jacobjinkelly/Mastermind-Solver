#include <iostream>
#include <vector>

using namespace std;

int checkPlace=0,checkColour=0;
int guess[4];
int check[4];

void check();
void getNextGuess();

int main()
{
    guess[0]=0,guess[1]=0,guess[2]=1,guess[3]=1; //initial guess
    int possibilities[6][6][6][6]; //boolean matrix
    for (int h=0;h<6;h++)
        for (int i=0;i<6;i++)
            for (int j=0;j<6;j++)
                for (int k=0;k<6;k++) possibilities[h][i][j][k]=1;

    int feedbackPlace=0,feedbackColour=0;
    while (feedbackPlace!=4) //while guess doesn't get all four pegs in correct place
    {
        for (int i=0;i<4;i++) cout<<guess[i]<<" "; //print out guess
        //get feedback on guess
        cin>>feedbackPlace; //how many pegs were the correct colour and the correct place
        cin>>feedbackColour; //how many pegs were the correct colour
        //eliminate all possibilities that don't give the same response if it were the code
        for (int h=0;h<6;h++)
            for (int i=0;i<6;i++)
                for (int j=0;j<6;j++)
                    for (int k=0;k<6;k++)
                    {
                        check[0]=h;
                        check[1]=i;
                        check[2]=j;
                        check[3]=k;
                        check();
                        if ((checkColour!=feedbackColour)||(checkPlace!=feedbackPlace)) possibilities[h][i][j][k]=0;
                    }
        getNextGuess();
    }
    return (0);
}

void check()
{
    checkPlace=0,checkColour=0;
    for (int i=0;i<4;i++)
    {
        if (guess[i]==check[i]) checkPlace++;
        for (int j=0;j<4;j++)
            if (check[i]==guess[j])
            {
                checkColour++;
                break;
            }
    }
}

void getNextGuess()
{
    for (int h=0;h<6;h++)
        for (int i=0;i<6;i++)
            for (int j=0;j<6;j++)
                for (int k=0;k<6;k++)
                    if (possibilities[h][i][j][k])
                    {
                        guess[0]=h;
                        guess[1]=i;
                        guess[2]=j;
                        guess[3]=k;
                        return;
                    }
}

