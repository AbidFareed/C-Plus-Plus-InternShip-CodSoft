#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;
int total_rows_in_hall;
int total_column_in_hall;
void display(char **arr){
    for(int i=0;i<total_rows_in_hall;i++){
        for(int j=0;j<total_column_in_hall;j++){
            cout<<i<<j<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"B = already Booked seats"<<endl;
    cout<<"A = Available seats"<<endl;
}
void savedata(char* filename,char**arr){
    ofstream fout(filename);
    fout<<total_rows_in_hall<<" "<<total_column_in_hall<<endl;
    for(int i=0;i<total_rows_in_hall;i++){
        for(int j=0;j<total_column_in_hall;j++){
            fout<<arr[i][j]<<" ";
        }
        fout<<endl;
    }
    fout.close();
}
void booking(char* filename){
    cin.ignore();
    ifstream fin(filename);
    if(!fin.is_open()){
        cout<<"File is not Open/Found"<<endl;
    }
    else{
        fin>>total_rows_in_hall;
        fin>>total_column_in_hall;
        char **hall=new char*[total_rows_in_hall];
        for(int i=0;i<total_rows_in_hall;i++){
            hall[i]=new char[total_column_in_hall];
            for(int j=0;j<total_column_in_hall;j++){
                fin>>hall[i][j];
            }
        }
        fin.close();
        char ch;
        double totalprice=0;
        while(1){
            cout<<"Press 1 for booking tickets"<<endl;
            cout<<"Press 2 for back"<<endl;
            cout<<"Option : ";
            cin.get(ch);
            if(ch=='1'){
                 display(hall);
                 int number=0;
                 cout<<"Enter a seat Number(like 11 12 but not 12A) : ";
                 cin>>number;
                 int row=number/10;
                 int col=number%10;
                 if (row >= 0 && row < total_rows_in_hall && col >= 0 && col < total_column_in_hall) {
                 if(hall[row][col]=='A'){
                     hall[row][col]='B';
                     totalprice+=1000;
                    cout<<"Booking Successfully"<<endl;
                 }
                 else
                 {
                     cout<<"Seat Alread Booked!! Sorry"<<endl;
                 }
                 }
                 else
                 {
                     cout << "Invalid Seat Number" << endl;
                 }
                 cin.ignore();
            }
            else if(ch=='2'){
                cout<<"Pay the bill within 10 mints"<<endl;
                cout<<"Your total bill is "<<totalprice<<endl;
                cout<<"Thanks For booking"<<endl;
                savedata(filename,hall);
                break;
            }
            else{
                cout<<"Wrong Input"<<endl;
                cin.ignore();
            }
        }
        if(hall!=nullptr){
        for (int i = 0; i < total_rows_in_hall; i++) {
        delete[] hall[i];
         }
    delete[] hall;
        }
    }
    
}
int main()
{
    cout<<"Welcome to Movie Ticket Booking System"<<endl;
    ifstream fin("movieslist.txt");
    if(!fin.is_open()){
        cout<<"Movies list is Missing"<<endl;
    }
    else{
        int size;
        fin>>size;
        fin.ignore();
        char **movieslist=new char*[size];
        int i=0;
        while(1){
        movieslist[i]=new char[100];
        if(fin.getline(movieslist[i],99,'\n'))
        {
            i++;
        }
        else
        break;
        }
        int ch;
        while(1){
            for(i=0;i<size;i++)
            {
            cout<<"Press "<<i+1<<" for "<<movieslist[i]<<" Movie"<<endl;
            }
            cout<<"Press "<<i+1<<" for end/exit "<<endl;
            cout<<"Option : ";
            cin>>ch;
            if(ch==i+1){
                cout<<"Thanks for using application"<<endl;
               return 0;
            }
            else if(ch<=i&&(ch-1)<size){
                char *filename=new char[100];
                strcpy(filename,movieslist[ch-1]);
                int len=strlen(movieslist[ch-1]);
                filename[len]='.';
                filename[len+1]='t';
                filename[len+2]='x';
                filename[len+3]='t';
                filename[len+4]='\0';
                booking(filename);
                delete[] filename;
            }
            else{
                cout<<"Invalid Input"<<endl;
            }
        }
        if(movieslist!=nullptr)
        {
            for (i = 0; i < size; i++) {
            delete[] movieslist[i];
        }
        delete[] movieslist;
        }
    }
    fin.close();
    return 0;
}
