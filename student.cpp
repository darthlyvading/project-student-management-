#include<stdio.h>    
#include<iostream> 
#include<fstream> 
#include<string.h> 
  
using namespace std; 
  
int main(){ 
    
    char name[15];   
    int n = 0, optn = 0, count = 0; 
   
    string empty = "00";     
    string proctor = ""; 
    ifstream f("Student.txt");       
    string linec; 
    for (int i = 0; std::getline(f, linec); ++i){     
        count++;} 
      
    while(optn != 6){ 
    cout << "\nAvailable operations are : \n1. Add New Student\n2."
        << "Student Login\n3. Faculty Login\n4. Proctor Login\n5. Admin View\n"
        << "6. Exit\nEnter : "; 
    cin >> optn; 
  
    if(optn == 1){ 
    cout << "Enter the number of students: "; 
    cin >> n; 
      
    count = count + n; 
      
    for (int i = 0;i < n;i++){ 
        ofstream outfile; 
            outfile.open("Example.txt",ios::app); 
        cout << "Enter registration number: "; 
        cin >> name; 
        outfile << name << " "; 
          
        cout << "Enter your name: "; 
        cin >> name; 
        int len = strlen(name); 
          
        while (len < 15){ 
            name[len] = ' '; 
            len = len + 1; 
        } 
        outfile << name << " "; 
        outfile << empty << " "; 
        outfile << empty << " ";     
          
        cout << "Enter proctor ID: "; 
        cin >> proctor; 
          
        outfile << proctor << endl; 
    }} 
      
    else if (optn == 2){ 
        char regno[9]; 
        cout << "Enter  registration number: "; 
        cin >> regno; 
        ifstream infile; 
        int check = 0; 
        infile.open("Student.txt",ios::in); 
        while (infile >> name){ 
        if (strcmp(name,regno) == 0){ 
            cout << "\nRegistration Number: " << name << endl; 
            infile >> name; 
            cout << "Name: " << name << endl; 
              
            infile >> name; 
                cout << "IT1001 mark: " << name << endl; 
              
            infile>>name; 
            cout<<"IT1002 mark: "<<name<<endl; 
              
            infile>>name; 
            cout<<"Proctor ID: "<<name<<endl; 
              
            infile.close(); 
            check = 1;} 
        } 
          
        if (check == 0){ 
            cout<<"No such registration number found!"<<endl;}   
          
    } 
      
    else if (optn == 3){ 
        char subcode[7]; 
        cout << "Enter your subject code: "; 
        cin >> subcode; 
        string code1 = "IT1001", code2 = "IT1002",mark = ""; 
        ifstream infile; 
        int check = 0; 
          
        cout << "\nAvailable operations: \n1. Add data about marks\n"
                << "2. View data\nEnter option: "; 
        cin >> optn; 
          
        if (optn == 1){ 
            cout << "Warning! You would need to add mark"
                    << "details for all the students!" << endl; 
            for(int i = 0;i < count;i++){ 
                fstream file("Student.txt"); 
           if(strcmp(subcode,code1.c_str()) == 0){ 
                        file.seekp(26+37*i,std::ios_base::beg); 
                    cout << "Enter the mark of student#" << (i+1) << " : "; 
                cin >> mark; 
                file.write(mark.c_str(),2);} 
           if(strcmp(subcode,code2.c_str()) == 0){ 
                file.seekp(29+37*i,std::ios_base::beg); 
                cout << "Enter the mark of student#" << (i+1) << " : "; 
                cin >> mark; 
                file.write(mark.c_str(),2);} 
            } 
              
        } 
  
        else if(optn == 2){ 
        infile.open("Student.txt",ios::in); 
        if (strcmp(subcode,code1.c_str()) == 0){ 
            cout << "Registration number - Marks\n" << endl; 
            while(infile >> name){ 
            cout << name; 
            infile >> name; 
                infile >> name; 
            cout << " - " << name << endl; 
            infile >> name; 
            infile >> name; 
            check = 1; 
            } 
        } 
          
        infile.close(); 
        infile.open("Student.txt",ios::in);      
  
        if(strcmp(subcode,code2.c_str()) == 0){ 
            cout << "Registration number - Marks\n" << endl; 
                while(infile >> name){ 
            cout << name; 
            infile >> name; 
            infile >> name; 
            infile >> name; 
            cout << " - " << name << endl; 
            infile >> name; 
            check = 1; 
            } 
        }} 
          
        infile.close(); 
          
        if (check == 0){ 
            cout << "No such subject code found!" << endl; 
        } 
          
    } 
  
    else if (optn == 4){ 
        char procid[7]; 
        cout << "Enter your proctor ID: "; 
        cin >> procid; 
            int check = 1; 
        char temp1[100], temp2[100], temp3[100]; 
        char temp4[100], id[100]; 
        ifstream infile; 
        infile.open("Student.txt",ios::in); 
          
        while (infile >> temp1){ 
            infile >> temp2;             
        infile >> temp3; 
        infile >> temp4; 
        infile >> id; 
          
        if (strcmp(id,procid) == 0){             
            cout << "\nRegistration Number: " << temp1 << endl; 
            cout << "Name: " << temp2 << endl; 
            cout << "IT1001 Mark: " << temp3 << endl; 
            cout << "IT1002 Mark: " << temp4 << endl; 
            check = 1; 
        } 
        } 
          
        if (check == 0){ 
            cout << "No such proctor ID found" << endl; 
        }} 
       
  
    else if(optn == 5){ 
        char password[25]; 
        cout << "Enter the admin password: "; 
        cin >> password; 
  
        string admin_pass = "admin"; 
          
        if (strcmp(password,admin_pass.c_str()) == 0){ 
            cout << "Reg No.       \tName\tCSE1001\tCSE1002\tProctor ID" << endl; 
            ifstream infile; 
            infile.open("Student.txt",ios::in); 
            char data[20]; 
              
            while(infile >> name){ 
                cout << name << " "; 
                infile >> name; 
                cout << name << " "; 
                infile >> name; 
                cout << name << " "; 
                infile >> name; 
                cout << name << " "; 
                infile >> name; 
                cout << name << endl; 
            } 
        } 
    } 
}}
