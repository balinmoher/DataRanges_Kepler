#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;



struct Range {
    int first, last, start_bound, end_bound, temp_first, temp_last;
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

void check(vector<Range> &RangeList, int temp_first, int temp_last);
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

        int temp_first, last_input, temp_last;
    
        cout << "Please enter the start of the range" << endl;
        cin >> temp_first;
        cout << "Please enter the end of the range" << endl;
        cin >> last_input;
        cout << ". . ." << endl;
        temp_last = last_input-1;
       
        cout << "First Range? (0 if yes): " << ind << endl;
        
    
        if (ind != 0) {
/////
        check(RangeList, temp_first, temp_last);

        }
        // if (p == 1) {
        //     for (int i = 0; i < RangeList.size() ; i++) {
        //       //1.check if solution for each case works (except outside ones)
        //       //2. Figure out how to sort for new ranges
        //       // scan through, if its lower than start store somewhere, if its
        //     }
        // }
        
  
    
        if (ind == 0) {
            RangeList.push_back(Range(temp_first, temp_last));
            ind++;
        }
    
    for (int i = 0; i < RangeList.size() ; i++) {
    cout << RangeList.at(i).first << ' ' << RangeList.at(i).last << endl; 
    }
  

    


    
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

void check(vector<Range> &RangeList, int temp_first, int temp_last) {
        int i;
        int p = 0, q = 0, t = 0, h = 0;
        int m1, m2;
        
        for (int i = 0; i < RangeList.size() ; i++) {   
            
            // New start in range, new end in range
            if (temp_first <= RangeList.at(i).last && temp_first >= RangeList.at(i).first && temp_last >= RangeList.at(i).first && temp_last <= RangeList.at(i).last) {
                q=1; //start point intersection
                t=1; //end point interesection
                p=0; //new range within existing, merge
                break;
            }
            // New start in range, new end greater than range
            if (temp_first <= RangeList.at(i).last && temp_first >= RangeList.at(i).first && temp_last > RangeList.at(i).last) {
                q=1; //start point in range
                t=0; //end point outside
                p=0; //merge
                m1 = i; //remember position of match
                break;
            }
            // New start less than range, new end within range
            if (temp_first < RangeList.at(i).first && temp_last >= RangeList.at(i).first && temp_last <= RangeList.at(i).last) {
                q=0; //start point less than range
                t=1; //end in range
                p=0; //merge
                m1 = i; //remember position of match
                break;
            }
            //New start less than range, new end greater than range
            if (temp_first < RangeList.at(i).first && temp_last > RangeList.at(i).last) {
                q=0; //start point less than range
                t=0; //end point greater than range
                p=1; //scan again
                h=1; //New range encompasses old
                m1 = i; //remember position of match
                break;
            }
            //New start and end less than range
            if (temp_first < RangeList.at(i).first && temp_last < RangeList.at(i).first) {
                q=0; //start point less than range
                t=0; //end point less than range
                p=1; //scan again
                h=0; //New range less than range. 
                m1 = i; //remember position of match
                break;
            }
            //New start and end greater than range
            if (temp_first > RangeList.at(i).last && temp_last > RangeList.at(i).last) {
                q=0; //No start point intersection
                t=0; //end point greater than range
                p=0; //scan again
                h=1; //new range greater than range. rescan
                m1 = i; //remember position of match
                break;
            }
        }
        
        cout << "Indicators (q, t, p):" << q << " " << t << " " << p << endl;   
        int start_bound;
        int end_bound;
        
        if ( q == 1 && t == 1 && p == 0) {
        cout << "Already exists or within an existing range. No action." << endl;
        }
    
        else if (q == 1 && t == 0 && p == 0) {
            cout << "New start in range, new end greater than range. Found at " << m1 << ". Merging." << endl;

            int start_bound = min(RangeList.at(m1).first, temp_first);

            RangeList.push_back(Range(start_bound, temp_last));
            RangeList.erase(RangeList.begin() + m1);
        }
        
        else if (q == 0 && t == 1 && p == 0) {
            cout << "New start less than range, new end within range at " << m1 << ". Merging." << endl;

            int end_bound = max(RangeList.at(m1).last, temp_last);

            RangeList.push_back(Range(temp_first, end_bound));
            RangeList.erase(RangeList.begin() + m1);
        }
        
        else if (q == 0 && t == 0 && p == 1 && h == 1) {
            cout << "New start less than range, new end greater than range at " << m1 << ". Merging. Re-Check for Intersection." << endl;
            
            int start_bound = temp_first;
            int end_bound = temp_last;
            
            RangeList.push_back(Range(start_bound, end_bound));
            RangeList.erase(RangeList.begin() + m1);
        }
        
        else if (q == 0 && t == 0 && p == 1 && h == 0) {
            cout << "New start and end less than range at " << m1 << ". Re-Check for Intersection." << endl;
            
            int start_bound = temp_first;
            int end_bound = temp_last;
            
            RangeList.push_back(Range(start_bound, end_bound));
        }
        
        else if (q == 0 && t == 0 && p == 0 && h == 1) {
            cout << "New start and end greater than range at " << m1 << ". Re-Check for Intersection." << endl;
            
            int start_bound = temp_first;
            int end_bound = temp_last;
            
            RangeList.push_back(Range(start_bound, end_bound));
        }
        
        
        else if (q == 0 && t == 0 && p == 0) {
            cout << "No match found" << endl;
            RangeList.push_back(Range(temp_first, temp_last));
        }
    
}