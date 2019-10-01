#include <iostream>
#include <vector>

using namespace std;



struct Range {
    int first, last;
    Range(int a, int b)
    {
        first = a;
        last = b;
    }
};


int input, run = 1;

int ind = 0;
int i;
vector<Range> RangeList;

int menu();

int main()
{


    
    menu();

    

}

int menu() {
   while (run == 1) {
   cout << "1: Add new Data Range\n2: Delete Data Range\n3: Get Data Range\n4: Exit\n(Enter 1, 2, 3 or 4)" << endl;
   cin >> input;
   if (input == 1){
    int present = 0;   
    int temp_first, temp_last;
    
    cout << "Please enter the start of the range" << endl;
    cin >> temp_first;
    cout << "Please enter the end of the range" << endl;
    cin >> temp_last;
    cout << ". . ." << endl;

    if (ind == 0) {
    RangeList.push_back(Range(temp_first, temp_last));
    }
    
    
    if (ind != 0) {
        int y = RangeList.size();
        int i;
        int p = 0;
        for (i = 0; i < RangeList.size() ; i++) {
            cout << "Checking for " << temp_first << " and " << temp_last << " in " << RangeList.size() << " places." << endl;
            
            if ((RangeList.at(i).first == temp_first) && (RangeList.at(i).last == temp_last)) {
            cout << "found match at " << i << endl;
            p = 1;
            break;
            }
        }

        if (p == 0) {
            cout << "No match found" << endl;
            RangeList.push_back(Range(temp_first, temp_last));
        }
        
        // for (int i = 0; i < RangeList.size() ; i++) {
           
        //     if (RangeList.at(i).first == temp_first && RangeList.at(i).last != temp_last) {
        //       int diff =  RangeList.at(i).last - temp_last;
              
        //       if (diff > 0){
        //         RangeList.at(i).last = temp_last; 
        //         break;
        //       }
        //     }
        //     if (RangeList.at(i).first != temp_first && RangeList.at(i).last == temp_last) {
        //       int diff =  RangeList.at(i).first - temp_first;
              
        //       if (diff > 0){
        //         RangeList.at(i).first = temp_first;  
        //         break;
        //       }
        //     }
        //     cout << i << endl;

        // }
    }
    
    for (int i = 0; i < RangeList.size() ; i++) 
    cout << RangeList.at(i).first << ' ' <<RangeList.at(i).last << endl; 

    ind++;   

    
    
    
    
    
    
    
    
   }
   else if (input == 2){

   }
   else if (input == 3){

   }
   else if (input == 4){
      run = 0;
   }
   if (run == 0) {
   cout << ". . .\nGoodbye" << endl;
   break;
   }
}
}