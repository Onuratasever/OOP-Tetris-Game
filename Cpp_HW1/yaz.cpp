#include <iostream>
#include <vector>

using namespace std;

void kacdigit(string num)
{
    vector<char> digitArray;
    bool increase = false;
    int index = -1;
    bool negative = false;
    for(int k=num.size()-1; k>=0; k--)
    {
        if(num[k] != '-')
        {
            if(num[k] >= '5')
            {
            // increase = true;
                //cout << "pushttt: " << num[k] << endl;
                if( k != 0)
                    index = digitArray.size();
            }
                digitArray.push_back(num[k]);
        }
        else
            negative = true;
        
    }
    //cout << "index: " << index <<endl;
    int size = digitArray.size();
     if(size == 1)
    {
        if(negative)
            cout << "-";
        if(digitArray[size-1] >= '5')
            cout << 10;
        else
            cout << num;
        return;
    }
    if(index == -1)
    {  //cout << "gelsene aaqq\n";
        if(negative)
            cout << "-";
        cout << num;
        return ;
    }

   

    for(int i=0; i <= index; i++)
    {
       // if( i != size - 1)
            digitArray[i] = 0 + 48;
    }

    increase = true;
    int res = 0, i;
    bool onol = false;
    for(i= index+1; i<size; i++)
    {
        if(increase)
        {
            //cout << "geldi mi " << digitArray[i] << " geldi\n";
            digitArray[i] = digitArray[i] + 1;

            if(size - 1 == i)
            {
               // cout << "geldi mi\n" << digitArray[i] << " geldi\n";
                if(digitArray[i] >= '5')
                {
                   // cout << "i geldi: " << i << endl;
                    onol = true;
                }
            }

            increase = false;
        }
        if(digitArray[i] >= '5')
        {
            if(i != size -1)
                digitArray[i] = '0';
            increase = true;
        }
        
    }

    if(negative)
            cout << "-";
    for(i=size-1; i>=0; i--)
    {
        if(onol && i == size -1)
            cout << "10"  ;
        else
            cout << digitArray[i];
    }
}

int main()
{
    int numOf;
    cin >>numOf;

    for(int i=0; i<numOf; i++)
    {
        string number;
        cin >> number;
        kacdigit(number);
        if(i != numOf -1)
            cout <<"\n"; 
    }
    return 0;
}