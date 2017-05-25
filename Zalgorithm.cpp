#include <iostream>
#include <string>
using namespace std;
int z[1000];

// function to create Z array

void CalcZarr(string s){
    int n = s.length();
    int l,r,k;

    //initially the z box having left and right 
    //index as zero
    l = r = 0;

    for(int i = 1; i < n; i++){ 

        //checking if i > right if it dosent that 
        //means we have already calculated the substring prefix
        // and we can copy 

        if(i>r){

            l = r = i;
            while( r<n && s[r-l] == s[r]){
                r++;
            }
            z[i] = r-l;
            r--;
        }else{

            k = i-l;
            //checking if z touches the right box
            if(z[k]<r-i+1)
                z[i] = z[k];

            // if does then calculate in normal way
            //else copy
            else{
                l = i;
                while(r<n && s[r-l] == s[r]){
                    r++;
                }
                z[i] = r-l;
                r--;
            }
        }
    }
}

int main()
{
    string text = "your text string";
    string pattern = "pattern you wanna search";
    string concate = pattern + '$' + text;
    CalcZarr(concate);

    for(int i=1;i<n;i++)cout<<z[i]<<endl;
    
    return 0;
}
