#include<iostream>
using namespace std;

int main() {
    char ch;
    while(1){
        cout<<"Press 1 for Calculate"<<endl;
        cout<<"Press 2 for end"<<endl;
        cout<<"Option : ";
        cin.get(ch);
        if(ch=='1'){
            double num1,num2;
            cout<<"Enter a Number 1 : ";
            cin>>num1;
            cout<<"Enter a Number 2 : ";
            cin>>num2;
            cin.ignore();
            while(1)
            {
            cout<<"Enter a operation (+,-,*,/) : ";
            cin.get(ch);
            if(ch=='+'){
                double result=num1+num2;
                cout<<"Result is "<<result<<endl;
                break;
            }
            else if(ch=='*'){
                double result=num1*num2;
                cout<<"Result is "<<result<<endl;
                break;
            }
            else if(ch=='-'){
                double result=num1-num2;
                cout<<"Result is "<<result<<endl;
            }
            else if(ch=='/'){
                if(num2>0)
                {
                double result=num1/num2;
                cout<<"Result is "<<result<<endl;
                }
                else
                    cout<<"Math Error"<<endl;
                break;
            }
            else
                cout<<"Wrong operation Entered "<<endl;
            }
            cin.ignore();
        }
        else if(ch=='2'){
            cout<<"Thanks for Using"<<endl;
            break;
        }
        else
        {
            cout<<"Input Invalid"<<endl;
        }
    }
    return 0;
}