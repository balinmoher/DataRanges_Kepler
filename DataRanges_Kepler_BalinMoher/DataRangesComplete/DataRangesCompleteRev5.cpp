//=============== Data Range Manipulation Code ================//
// Revision number: 5.0                                        //
// Revised by, date: Balin Moher, October 1, 2019              //
// Verification Status: Functioning                            //
// Major changes: Removed debugging features                   //
//=============================================================//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Primary data structure
struct Range {
    int first, last;
    Range(int a, int b)
    {
        first = a;
        last = b;
    }
};

int temp_first, temp_last, input;
int p = 0, q = 0, t = 0, h = 0, i = 0, recheck = 0, add = 0, ind = 0, excl = 0;
int run = 1;
int del = 0;
//Vector, data structure stored here
vector<Range> RangeList;

void add_check(vector<Range> &RangeList, int &temp_first, int &temp_last, int &p, int &q, int &t, int &h, int &i, int &recheck, int &add, int &excl);
void del_check(vector<Range> &RangeList, int &temp_first, int &temp_last, int &p, int &q, int &t, int &h, int &i, int &recheck);
void get_check(vector<Range> &RangeList, int &temp_first, int &temp_last, int &p, int &q, int &t, int &h, int &i, int &recheck, int *pin);
int menu();

int main()
{
    
    menu(); //repeating menu function
    
}

int menu() {
    
    while (run == 1) {
        cout << "1: Add new Data Range\n2: Delete Data Range\n3: Get Data Range\n4: Exit\n(Enter 1, 2, 3 or 4)" << endl;
        cin >> input;
        if (input == 1){
            i = 0;
            for (int j = 0; j < 1; j++) {
                cout << "Please enter the start of the range" << endl;
                cin >> temp_first;
                cout << "Please enter the end of the range" << endl;
                cin >> temp_last;
                cout << ". . ." << endl;
                temp_last = temp_last - 1;
                if (temp_last - temp_first < 0) {
                    cout << "start must be less than end. please re-enter." << endl;
                j--;    
                }
            }
            if (ind != 0) {
                for (i; i < RangeList.size();) {
                    if (RangeList.empty()) {
                        break;
                    }
                    add_check(RangeList, temp_first, temp_last, p, q, t, h, i, recheck, add, excl);
                }
            }
    
            recheck = 0;
            i = 0;
            
            if (add == 1) {
                if (excl == 1) {
                RangeList.push_back(Range(temp_first, temp_last + 1));
                }
                else 
                RangeList.push_back(Range(temp_first, temp_last));
            }
            if (ind == 0) {
                RangeList.push_back(Range(temp_first, temp_last + 1));
                ind++;
            }
            if (del == 1) {
                RangeList.erase(RangeList.begin());
                del = 0;
            }
            cout << "Printing " << RangeList.size() << " Entries." << endl;
            for (int k = 0; k < RangeList.size() ; k++) {
                cout << "entry: " << k << endl;
                cout << RangeList.at(k).first << ' ' << RangeList.at(k).last << endl; 
            }
     
        }
        
        else if (input == 2){
            for (int j = 0; j < 1; j++) {
                cout << "Please enter the start of the range to delete" << endl;
                cin >> temp_first;
                cout << "Please enter the end of the range to delete" << endl;
                cin >> temp_last;
                cout << ". . ." << endl;
                temp_last = temp_last - 1;
                if (temp_last - temp_first < 0) {
                    cout << "start must be less than end. please re-enter." << endl;
                j--;    
                }
            }
            i = 0;
            for (i; i < RangeList.size();) {
                if (RangeList.empty()) {
                    break;
                }
                del_check(RangeList, temp_first, temp_last, p, q, t, h, i, recheck);
            }
            if (RangeList.empty()) {
                RangeList.push_back(Range(0,0));
                del = 1;
                cout << "Deleted entries. No entries in container." << endl;
            }
            
            recheck = 0;
            i = 0;
            if (del == 0) { 
                cout << "Printing " << RangeList.size() << " entries." << endl;
                for (int i = 0; i < RangeList.size() ; i++) {
                    cout << "entry: " << i << endl;
                    cout << RangeList.at(i).first << ' ' << RangeList.at(i).last << endl; 
                }
            }
        }
        
        else if (input == 3){
            i = 0;
            int pin[RangeList.size()];  //initialize array the size of the vector to store indication of range intersection (1 or 0);
            for (int k = 0; k < RangeList.size(); k++) {
                pin[k] = 0;
            }
            if (RangeList.empty()) {
                    cout << "No ranges to get." << endl;
            }
            else
            for (int j = 0; j < 1; j++) {
                cout << "Please enter the start of the range to get" << endl;
                cin >> temp_first;
                cout << "Please enter the end of the range to get" << endl;
                cin >> temp_last;
                cout << ". . ." << endl;
                temp_last = temp_last - 1;
                if (temp_last - temp_first < 0) {
                    cout << "start must be less than end. please re-enter." << endl;
                j--;    
                }
            }
            if (del == 1) {
                RangeList.erase(RangeList.begin());
                del = 0;
            }
            for (i; i < RangeList.size();) {
                if (RangeList.empty()) {
                    break;
                }
                get_check(RangeList, temp_first, temp_last, p, q, t, h, i, recheck, pin); 
            }
            
            recheck = 0;
            i = 0;
            
            int get = 0;
            for (int k = 0; k < RangeList.size() ; k++) { 
                if (pin[k-1] + pin[k] > 0 && get == 0) {
                    cout << "Intersections Found." << endl;
                    get = 1;
                }
                cout << "Container entry: " << k << endl;
                cout << "Intersection indicator (1 if intersection, 0 if not): " << pin[k] << endl;
            }
            
            if (get == 0) {
                cout << "No entries found." << endl; 
            }
            
            for (i = 0; i < RangeList.size() ; i++) {
                if (pin[i] == 1) {
                cout << "entry: " << i << endl;
                cout << RangeList.at(i).first << ' ' << RangeList.at(i).last << endl; 
                }
            }
        }
        
        else if (input == 4){
           run = 0; //quit program
        }
        if (run == 0) {
            cout << ". . .\nGoodbye" << endl;
            break;
        }
    }
}

void add_check(vector<Range> &RangeList, int &temp_first, int &temp_last, int &p, int &q, int &t, int &h, int &i, int &recheck, int &add, int &excl) {

        p = 0, q = 0, t = 0, h = 0, i;
        int start_bound, end_bound;


            cout << "Evaluating " << temp_first << "," << temp_last + 1 << " against " << RangeList.at(i).first  << "," << RangeList.at(i).last << " at position: " << i << endl;
            
            // New start in range, new end in range
            if (temp_first <= RangeList.at(i).last && temp_first >= RangeList.at(i).first && temp_last >= RangeList.at(i).first && temp_last < RangeList.at(i).last) {
                q=1; //start point intersection
                t=1; //end point interesection
                p=0; //new range within existing, merge
                h=0;

            }
            
            // New start in range, new end greater than range
            if (temp_first <= RangeList.at(i).last && temp_first >= RangeList.at(i).first && temp_last >= RangeList.at(i).last) {
                q=1; //start point in range
                t=0; //end point outside
                p=0; //merge
                h=0;

            }
            // New start less than range, new end within range
            if (temp_first < RangeList.at(i).first && temp_last >= RangeList.at(i).first && temp_last <= RangeList.at(i).last) {
                q=0; //start point less than range
                t=1; //end in range
                p=0; //merge
                h=0;

            }
            //New start less than range, new end greater than range
            if (temp_first < RangeList.at(i).first && temp_last > RangeList.at(i).last) {
                q=0; //start point less than range
                t=0; //end point greater than range
                p=1; //scan again
                h=1; //New range encompasses old

            }
            //New start and end less than range
            if (temp_first < RangeList.at(i).first && temp_last < RangeList.at(i).first) {
                q=0; //start point less than range
                t=0; //end point less than range
                p=1; //scan again
                h=0; //New range less than range. 
  
            }
            //New start and end greater than range
            if (temp_first > RangeList.at(i).last && temp_last > RangeList.at(i).last) {
                q=0; //No start point intersection
                t=0; //end point greater than range
                p=0; //scan again
                h=1; //new range greater than range. rescan
  
            }

        if (q == 1 && t == 1 && p == 0 && h == 0) {

            cout << "Already exists or within an existing range. Do not add new range." << endl;
            add = 0;
            recheck = 0;
            excl = 0;
            i++;
        }
    
        if (q == 1 && t == 0 && p == 0 && h == 0) {
            cout << "New start in range, new end greater than range. Found at " << i << ". Merging." << endl;

            start_bound = min(RangeList.at(i).first, temp_first);
            end_bound = temp_last;
            add = 1;
            RangeList.erase(RangeList.begin() + i);
            recheck = 1;
            i = 0;
            excl = 1;
        }
        
        else if (q == 0 && t == 1 && p == 0 && h == 0) {
            cout << "New start less than range, new end within range at " << i << ". Merging." << endl;
            
            start_bound = temp_first;
            end_bound = max(RangeList.at(i).last, temp_last);
            add = 1;
            RangeList.erase(RangeList.begin() + i);
            recheck = 1;
            i = 0;
            excl = 0;
        }
        
        if (q == 0 && t == 0 && p == 1 && h == 1) {
            cout << "New start less than range, new end greater than range at " << i << ". Merging. Re-Check for Intersection." << endl;
            
            start_bound = temp_first;
            end_bound = temp_last;
            add = 1;
            RangeList.erase(RangeList.begin() + i);
            recheck = 1;
            i = 0;
            excl = 1;
        }
        
        if (q == 0 && t == 0 && p == 1 && h == 0) {
            cout << "New start and end less than range at " << i << ". Re-Check for Intersection." << endl;
            
            start_bound = temp_first;
            end_bound = temp_last;
            add = 1;
            recheck = 1;
            i++;
            excl = 1;
        }
        
        if (q == 0 && t == 0 && p == 0 && h == 1) {
            cout << "New start and end greater than range at " << i << ". Re-Check for Intersection." << endl;
            
            start_bound = temp_first;
            end_bound = temp_last;
            add = 1;
            recheck = 1;
            i++;
            excl = 1;
        }
        
        if (q == 0 && t == 0 && p == 0 && h == 0) {
            cout << "No match found" << endl;
            add = 0;
            recheck = 0;
        }
        if (recheck == 1) {
            temp_first = start_bound;
            temp_last = end_bound;
        }
}

void del_check(vector<Range> &RangeList, int &temp_first, int &temp_last, int &p, int &q, int &t, int &h, int &i, int &recheck) {

        p = 0, q = 0, t = 0, h = 0, i;
        int start_bound, end_bound;


            cout << "Evaluating " << temp_first << "," << temp_last + 1 << " against " << RangeList.at(i).first  << "," << RangeList.at(i).last << " at position: " << i << endl;
            
            // New start in range, new end in range
            if (temp_first <= RangeList.at(i).last && temp_first >= RangeList.at(i).first && temp_last >= RangeList.at(i).first && temp_last <= RangeList.at(i).last) {
                q=1; //start point intersection
                t=1; //end point interesection
                p=0; //new range within existing, merge
                h=0;

            }
            
            // New start in range, new end greater than range
            if (temp_first <= RangeList.at(i).last && temp_first >= RangeList.at(i).first && temp_last > RangeList.at(i).last) {
                q=1; //start point in range
                t=0; //end point outside
                p=0; //merge
                h=0;

            }
            // New start less than range, new end within range
            if (temp_first < RangeList.at(i).first && temp_last >= RangeList.at(i).first && temp_last <= RangeList.at(i).last) {
                q=0; //start point less than range
                t=1; //end in range
                p=0; //merge
                h=0;

            }
            //New start less than range, new end greater than range
            if (temp_first < RangeList.at(i).first && temp_last > RangeList.at(i).last) {
                q=0; //start point less than range
                t=0; //end point greater than range
                p=1; //scan again
                h=1; //New range encompasses old

            }
            //New start and end less than range
            if (temp_first < RangeList.at(i).first && temp_last < RangeList.at(i).first) {
                q=0; //start point less than range
                t=0; //end point less than range
                p=1; //scan again
                h=0; //New range less than range. 

            }
            //New start and end greater than range
            if (temp_first > RangeList.at(i).last && temp_last > RangeList.at(i).last) {
                q=0; //No start point intersection
                t=0; //end point greater than range
                p=0; //scan again
                h=1; //new range greater than range. rescan

            }
        
        if ( (q == 1 && t == 1 && p == 0 && h == 0) || (temp_first == RangeList.at(i).first && temp_last  == RangeList.at(i).last)) {

            cout << "Range to delete found within " << RangeList.at(i).first << "," << RangeList.at(i).last << " at " << i << "." << endl;
            if (temp_first == RangeList.at(i).first && temp_last == RangeList.at(i).last) {
                RangeList.erase(RangeList.begin() + i);
            }
            else if (temp_first == RangeList.at(i).first && temp_last < RangeList.at(i).last) {
                RangeList.push_back(Range(temp_last + 1, RangeList.at(i).last));  
                RangeList.erase(RangeList.begin() + i);
            }
            else if (temp_last == RangeList.at(i).last && temp_first > RangeList.at(i).first) {
                RangeList.push_back(Range(RangeList.at(i).first, temp_first - 1));  
                RangeList.erase(RangeList.begin() + i);
            }
            else if (temp_last < RangeList.at(i).last && temp_first > RangeList.at(i).first) {
                RangeList.push_back(Range(RangeList.at(i).first, temp_first - 1));  
                RangeList.push_back(Range(temp_last + 1, RangeList.at(i).last));
                RangeList.erase(RangeList.begin() + i);
            }

            i = RangeList.size();
        }
    
        if (q == 1 && t == 0 && p == 0 && h == 0) {
            cout << "Delete start in range, delete end greater than range. Found at " << i << "." << endl;
            if (RangeList.at(i).first < temp_first && RangeList.at(i).last != temp_first) {
            RangeList.push_back(Range(RangeList.at(i).first, temp_first));
            RangeList.erase(RangeList.begin() + i);
            start_bound = temp_first + 1;
            end_bound = temp_last;
            }
            else if (RangeList.at(i).last == temp_first) {
            RangeList.push_back(Range(RangeList.at(i).first, temp_first - 1));
            RangeList.erase(RangeList.begin() + i);
            start_bound = temp_first;
            end_bound = temp_last;
            }
            else {
            RangeList.erase(RangeList.begin() + i);
            start_bound = temp_first;
            end_bound = temp_last;
            }
            recheck = 1;
            i = 0;
    
        }
        
        else if (q == 0 && t == 1 && p == 0 && h == 0) {
            cout << "Delete start less than range, delete end within range at " << i << "." << endl;
            if (temp_last + 1 == RangeList.at(i).first) {
                cout << "end point exclusive. Nothing to delete." << endl;
            }
            else if (temp_last < RangeList.at(i).last && RangeList.at(i).first != temp_last && RangeList.at(i).last != temp_last + 1) {
            RangeList.push_back(Range(temp_last + 1, RangeList.at(i).last));
            RangeList.erase(RangeList.begin() + i);
            start_bound = temp_first;
            end_bound = temp_last - 1;
            }
            else if (RangeList.at(i).last == temp_last + 1) {
            RangeList.push_back(Range(temp_last + 1, RangeList.at(i).last));
            RangeList.erase(RangeList.begin() + i);
            start_bound = temp_first;
            end_bound = temp_last;
            }
            else if (RangeList.at(i).first == temp_last && RangeList.at(i).last != temp_last) {
            RangeList.push_back(Range(temp_last + 1, RangeList.at(i).last));
            RangeList.erase(RangeList.begin() + i);
            start_bound = temp_first;
            end_bound = temp_last;
            }
            else {
            RangeList.erase(RangeList.begin() + i);
            start_bound = temp_first;
            end_bound = temp_last;
            }

            recheck = 1;
            i = 0;
        }
        
        if (q == 0 && t == 0 && p == 1 && h == 1) {
            cout << "Delete start less than range, delete end greater than range at " << i << ". Deleting range." << endl;
            
            start_bound = temp_first;
            end_bound = temp_last;
            RangeList.erase(RangeList.begin() + i);
            recheck = 1;
            i = 0;
        }
        
        if (q == 0 && t == 0 && p == 1 && h == 0) {
            cout << "delete start and delete less than range at " << i << ". check next range." << endl;
            
            start_bound = temp_first;
            end_bound = temp_last;
            recheck = 1;
            i++;
        }
        
        if (q == 0 && t == 0 && p == 0 && h == 1) {
            cout << "Delete start and end greater than range at " << i << ". Check next range." << endl;
            
            start_bound = temp_first;
            end_bound = temp_last;
            recheck = 1;
            i++;
        }
        
        if (q == 0 && t == 0 && p == 0 && h == 0) {
            cout << "No match found" << endl;
            recheck = 0;
        }
        if (recheck == 1) {
            temp_first = start_bound;
            temp_last = end_bound;
        }
}


void get_check(vector<Range> &RangeList, int &temp_first, int &temp_last, int &p, int &q, int &t, int &h, int &i, int &recheck, int *pin) {

        p = 0, q = 0, t = 0, h = 0, i;
        int start_bound, end_bound;
        pin[RangeList.size()];


            cout << "Evaluating " << temp_first << "," << temp_last + 1<< " against " << RangeList.at(i).first  << "," << RangeList.at(i).last << " at position: " << i << endl;
            
            // New start in range, new end in range
            if (temp_first <= RangeList.at(i).last && temp_first >= RangeList.at(i).first && temp_last >= RangeList.at(i).first && temp_last <= RangeList.at(i).last) {
                q=1; //start point intersection
                t=1; //end point interesection
                p=0; //new range within existing, merge
                h=0;

            }
            
            // New start in range, new end greater than range
            if (temp_first <= RangeList.at(i).last && temp_first >= RangeList.at(i).first && temp_last > RangeList.at(i).last) {
                q=1; //start point in range
                t=0; //end point outside
                p=0; //merge
                h=0;
   
            }
            // New start less than range, new end within range
            if (temp_first < RangeList.at(i).first && temp_last >= RangeList.at(i).first && temp_last <= RangeList.at(i).last) {
                q=0; //start point less than range
                t=1; //end in range
                p=0; //merge
                h=0;
  
            }
            //New start less than range, new end greater than range
            if (temp_first < RangeList.at(i).first && temp_last > RangeList.at(i).last) {
                q=0; //start point less than range
                t=0; //end point greater than range
                p=1; //scan again
                h=1; //New range encompasses old
     
            }
            //New start and end less than range
            if (temp_first < RangeList.at(i).first && temp_last < RangeList.at(i).first) {
                q=0; //start point less than range
                t=0; //end point less than range
                p=1; //scan again
                h=0; //New range less than range. 
                
            }
            //New start and end greater than range
            if (temp_first > RangeList.at(i).last && temp_last > RangeList.at(i).last) {
                q=0; //No start point intersection
                t=0; //end point greater than range
                p=0; //scan again
                h=1; //new range greater than range. rescan

            }
        
        if ( (q == 1 && t == 1 && p == 0 && h == 0) || (temp_first == RangeList.at(i).first && temp_last  == RangeList.at(i).last)) {

            cout << "Range to get found within " << RangeList.at(i).first << "," << RangeList.at(i).last << " at " << i << "." << endl;
  
            pin[i] = 1;
            start_bound = temp_first;
            end_bound = temp_last;
            i = RangeList.size();
        }
    
        if (q == 1 && t == 0 && p == 0 && h == 0) {
            cout << "Get start in range, get end greater than range. Found at " << i << ". Recording location." << endl;
            
            pin[i] = 1;
            start_bound = temp_first;
            end_bound = temp_last;
            recheck = 1;
            i++;
    
        }
        
        else if (q == 0 && t == 1 && p == 0 && h == 0) {
            cout << "get start less than range, get end within range at " << i << "." << endl;
            if (temp_last == RangeList.at(i).first && temp_last == RangeList.at(i).last) {
                cout << "end point exclusive. Nothing to get." << endl;
            }
            else if (temp_last < RangeList.at(i).last && RangeList.at(i).first != temp_last && RangeList.at(i).last != temp_last + 1) {
              pin[i] = 1;
            }
            else if (RangeList.at(i).last == temp_last + 1) {
            pin[i] = 1;
            }
            else if (RangeList.at(i).first == temp_last) {
              pin[i] = 1;
            }
            else if (RangeList.at(i).last == temp_last) {
              pin[i] = 1;
            }
            start_bound = temp_first;
            end_bound = temp_last;
            recheck = 1;
            i++;
        }
        
        if (q == 0 && t == 0 && p == 1 && h == 1) {
            cout << "Get start less than range, get end greater than range at " << i << ". Deleting range." << endl;
            
            start_bound = temp_first;
            end_bound = temp_last;
            pin[i] = 1;
            recheck = 1;
            i++;
        }
        
        if (q == 0 && t == 0 && p == 1 && h == 0) {
            cout << "get start and get end less than range at " << i << ". check next range." << endl;
            pin[i] = 0;
            start_bound = temp_first;
            end_bound = temp_last;
            recheck = 1;
            i++;
        }
        
        if (q == 0 && t == 0 && p == 0 && h == 1) {
            cout << "Get start and get end greater than range at " << i << ". Check next range." << endl;
            pin[i] = 0;
            start_bound = temp_first;
            end_bound = temp_last;
            recheck = 1;
            i++;
        }
        
        if (q == 0 && t == 0 && p == 0 && h == 0) {
            cout << "No match found" << endl;
            add = 0;
            recheck = 0;
        }
        if (recheck == 1) {
            temp_first = start_bound;
            temp_last = end_bound;
        }
}