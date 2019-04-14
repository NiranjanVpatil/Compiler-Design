#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isKeyword(char buffer[]){
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    int i, flag = 0;
    
    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    
    return flag;
}

int main ()
{
  char ch, buffer[15];
  char arithmetic_operators[] = {"+-*/%="}; 
  char parenthesis[] = {"(){}"}; 
  char separators[] = {",;"};
  int i,j=0;

  ifstream myfile ("addition.txt");
  if (myfile.is_open())
  {
    while (!myfile.eof() )
    {
     ch  = myfile.get();
     for(i = 0;i < 6; i++)
     {
       if(ch == arithmetic_operators[i]) 
        {
             cout <<ch<<"is Operator"<<'\n';       
        } 
        
        
     }
     for(int i = 0; i<3; i++)
     {
       if(ch == separators[i])
        {
            cout <<ch<<"is Seperator"<<'\n'; 
        }
     }
     
     for(int i = 0; i<5; i++)
     {
       if(ch == parenthesis[i])
        {
            cout <<ch<<"is parenthesis"<<'\n'; 
        }
     }
     
   
    
     
     if(isalnum(ch)){
               buffer[j++] = ch;
           }
           else if((ch == ' ' || ch == '\n' || ch ==',' || ch == ';'|| ch == '(' || ch == ')'  || ch == '{' || ch =='}') && (j != 0))
                 {
                   buffer[j] = '\0';
                   j = 0;
                                      
                   if(isKeyword(buffer) == 1)
                       cout<<buffer<<" is keyword\n";
                   else
                       cout<<buffer<<" is identifier\n";
                  }
     
     
     
    }
  
  }

  else 
  {
      cout << "Unable to open file"; 
  }
  


  return 0;
    
}
