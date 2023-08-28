#include<iostream>
using namespace std;

int main() {
    char * Name=new char[100];
    cout<<"Enter Your Name : ";
    cin.getline(Name,99);
    char ch;
    int score=0;
    while(1)
    {
        cout<<"Press 1 For new Game"<<endl;
        cout<<"Press 2 for End"<<endl;
        cout<<"Option : ";
        cin.get(ch);
        if(ch=='1')
        {
            int range = 100;
            int num=rand()%range;
            int input=0;
            while(1)
            {
            cout<<"Guess Number : ";
            cin>>input;
            if(input==num){
                cout<<"Your guess is right! You earn 10 points"<<endl;
                score+=10;
                break;
            }
            else if(input>num){
                cout<<"Your guess is to high"<<endl;
            }
            else if(input<num)
            {
                cout<<"Your guess is to Low"<<endl;
            }
            }
            cin.ignore();
        }
        else if(ch=='2')
        {
           cout<<Name<<" your Total Score is "<<score<<endl;
           break;
        }
        else
        {
            cout<<"Enter Wrong Input!!"<<endl;
        }
    }

    return 0;
}