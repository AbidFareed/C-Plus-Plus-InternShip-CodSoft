#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main()
{
    char*filename=new char[100];
    cout<<"Enter the File Name : ";
    cin.getline(filename,99);
    int flag=0;
    int length=0;
    for(int i=0;filename[i]!='\0';i++){
        if(filename[i]=='.'){
            flag=1;
        }
        length++;
    }
    if(flag==0){
        filename[length]='.';
        length++;
        filename[length]='t';
        length++;
        filename[length]='x';
        length++;
        filename[length]='t';
        length++;
        filename[length]='\0';
    }
    ifstream fin;
    fin.open(filename);
   
    if(!fin.is_open()){
        cout<<"File is Not Found"<<endl;
    }
    else{
        int wordcount=0;
        char*fetch=new char[1000];
        while(fin.getline(fetch,999,'\n')){
            for(int i=0;int(fetch[i])!=0;i++){
                if(fetch[i]==' '||int(fetch[i+1])==0){
                    wordcount++;
                }
            }
        }
       
        cout<<"Total Words in the Given File is "<<wordcount<<"."<<endl; 
    }
     fin.close();
    return 0;
}
