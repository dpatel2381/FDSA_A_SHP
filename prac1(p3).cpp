#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string sentence;
    cout<<"Enter a sentence: ";
    getline(cin, sentence);

    string longestWord="", currentWord="";
    int maxLength = 0;

    for(size_t i=0;i<=sentence.size();i++) 
    {
        char c=(i<sentence.size())?sentence[i]:' ';
        if(isalpha(c)) 
        {
            currentWord+=c;
        } 
        else 
        {
            if(!currentWord.empty()) 
            {
                if((int)currentWord.size()>maxLength) 
                {
                    maxLength=currentWord.size();
                    longestWord=currentWord;
                }
                currentWord.clear();
            }
        }
    }

    cout<<"Longest word: "<<longestWord<<endl;
    cout<<"Size: "<<maxLength<<endl;
    return 0;
}
