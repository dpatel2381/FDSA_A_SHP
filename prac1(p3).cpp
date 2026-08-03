#include<iostream>
#include<string>
using namespace std;

int main()
{
    cout<<"Enter your sentence:"<<endl;
    string sentence;

    string longest="",word="";
    getline(cin,sentence);

    for(int i=0;i<=sentence.length();i++)
    {
        if(sentence[i]==' '||sentence[i]=='\0')
        {  
            if(word.length()>longest.length())
            {
                longest=word;
            }
            word="";
        }
        else
        {
            word=word+sentence[i];
        }
    }
      

    cout<<"Longest word in sentence is: "<<longest<<endl;
    cout<<"The length of longest word is: "<<longest.length()<<endl;

}
