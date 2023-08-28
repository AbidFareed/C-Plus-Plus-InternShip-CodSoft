#include<iostream>
using namespace std;
char* regrowch(char* ptr, int input, int& size)
{
    char* temp = new char[size + 1];
    int i=0;
    for (i = 0; i < size-1; i++)
        temp[i] = ptr[i];
    temp[i++] = input;
    temp[i++] = '\0';
    size=i;
    delete[] ptr;
    ptr = nullptr;
    return temp;
}
char* input(){
    int size=0;
    char*arr=new char[1];
    char ch;
    while(1){
        cin.get(ch);
        if(ch=='\n'||ch=='\0'||int(ch)==10)
            break;
        else
        arr=regrowch(arr,ch,size);
    }
    return arr;
}
void delete_two_d_array(char**arr,int size){
    for(int i=0;i<size;i++){
        delete[]arr[i];
        arr[i]=nullptr;
    }
    delete arr;
}
void display(int max_grade){
            if(max_grade==4){
                cout<<"A";
            }
            else if(max_grade==3){
                cout<<"B";
            }
            else if(max_grade==2){
                cout<<"C";
            }
            else if(max_grade==1){
                cout<<"D";
            }
            else if(max_grade==0){
                cout<<"F";
            }
}
int main() {
    cout<<"Welcome to Student Grading System"<<endl;
    int size_of_class=0;
    char ch;
    int max_grade=4,min_grade=0,average_grade;//A=4,B=3,C=2,D=1,F=0
    while(1){
        cout<<"Press 1 for Calculate Average,Maximum,Minimum Grades"<<endl;
        cout<<"Press 2 for end"<<endl;
        cout<<"Option : ";
        cin.get(ch);
        if(ch=='1'){
            cout<<"Enter the Size of Class : ";
            cin>>size_of_class;
            char**name=new char*[size_of_class];
            char *grades=new char[size_of_class];
            for(int i=0;i<size_of_class;i++){
                 cin.ignore();
                cout<<"Enter a "<<i+1<<"st Student Name : ";
                name[i]=input();
                cout<<"Enter a "<<i+1<<"st Student Grade(Aa,Bb,Cc,Dd,Ff but Not A+) : ";
                cin.get(grades[i]);
            }
            for(int i=0;i<size_of_class;i++){
                //max_grade
                if((grades[i]=='A'||grades[i]=='a')&&max_grade<4){
                    max_grade=4;
                }
                else if((grades[i]=='B'||grades[i]=='b')&&max_grade<3){
                    max_grade=3;
                  
                }
                else if((grades[i]=='C'||grades[i]=='c')&&max_grade<2){
                    max_grade=2;
               
                }
                else if((grades[i]=='D'||grades[i]=='d')&&max_grade<1){
                    max_grade=1;
              
                }
                else if((grades[i]=='F'||grades[i]=='f')&&max_grade<0){
                    max_grade=0;
                  
                }
                //min_grade
                if((grades[i]=='F'||grades[i]=='f')&&min_grade>0){
                    min_grade=0;
                }
                else if((grades[i]=='D'||grades[i]=='d')&&min_grade>1){
                    min_grade=1;
                }
                else if((grades[i]=='C'||grades[i]=='c')&&min_grade>2){
                    min_grade=2;
                }
                else if((grades[i]=='B'||grades[i]=='b')&&min_grade>3){
                    min_grade=3;
                }
                else if((grades[i]=='A'||grades[i]=='a')&&min_grade>4){
                    min_grade=4;
                }
                
                //Average
                if(grades[i]=='A'||grades[i]=='a'){
                average_grade+=4;
                 }
                else if(grades[i]=='B'||grades[i]=='b'){
               average_grade+=3;
                }
                else if(grades[i]=='C'||grades[i]=='c'){
                 average_grade+=2;
                }
                else if(grades[i]=='D'||grades[i]=='d'){
                 average_grade+=1;
                }
                else if(grades[i]=='F'||grades[i]=='f'){
                 average_grade+=0;
                } 
            }
            average_grade=average_grade/size_of_class;
            cout<<"Maximum Grade is ";display(max_grade);cout<<" In the Class"<<endl;
            cout<<"Minimum Grade is ";display(min_grade);cout<<" In the Class"<<endl;
            cout<<"Average Grade is ";display(average_grade);cout<<" In the Class"<<endl;
            delete[]grades;
            delete_two_d_array(name,size_of_class);
            cin.ignore();
        }
        else if(ch=='2'){
            cout<<"Thanks For Using this app"<<endl;
            break;
        }
        else
        cout<<"Wrong Input Entered"<<endl;
    }
    return 0;
}