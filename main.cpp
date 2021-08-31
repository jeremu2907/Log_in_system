#include <iostream>
#include <vector>
#include "functions.h"


using namespace std;


vector <string> Username;
vector <string> Password;
vector <string> Name;

void Create_Account();
void Log_In();
void User_info(string username, int key);

int main(){
    while(true){
        cout << "\n\n1 for log in, 2 for creating new account \n\n";
        int SelectType;
        do{
            cin >> SelectType;
            if(SelectType == 1)
                Log_In();
            else if(SelectType == 2)
                Create_Account();
            else{
                cout << "\n\nInvalid input, try again" << "\n\n";
                SelectType = 0;
            }
        }
        while(SelectType == 0);
    }

}

void Create_Account(){
    //user input
    string user_name;
    string pass_word;
    string name;
    cout << "\n\nCreate username: ";
    cin >> user_name;
    cout << "\n\nCreate password: ";
    cin >> pass_word;
    cout << "\n\nEnter name: ";
    cin >> name;

    //account validation
    if(Account_Validation( &user_name, Username) == true){;
        //Saving to memory
        Username.push_back(user_name);
        Name.push_back(name);
    }
    else{
        cout << "\n\nUsername taken, try another one";
        do{
            cout << "\n\nCreate username: ";
            cin >> user_name;
        }
        while(Account_Validation(&user_name, Username) == false);
        Username.push_back(user_name);
    }

    //password validation
    if(Password_Validation( &pass_word) == true){
        //Saving to memory
        Password.push_back(pass_word);
    }
    else{
        do{
            cout << "\n\nPassword does not meet standard";
            cout << "\n\nCreate password: ";
            cin >> pass_word;
        }
        while(Password_Validation(&pass_word) == false);
        Password.push_back(pass_word);
    }

    cout << "\n\nWelcome " << name << ", your account has been created successfully!";
    
}

void Log_In(){
    string username, password;
    int key;
    do{
        cout << "\n\nPlease enter username: ";
        cin >> username;

        if(Account_Validation( &username, Username) == true){  //true means that account is not stored
            cout << "\n\nThat username is not found, please try again.";
        }
        else{
            key = Search_key( &username, Username );
        }
    }
    while(Account_Validation( &username, Username) == true);


    do{
        cout << "\n\nPlease enter password: ";
        cin >> password;
        // truefalse = (password != Password[key])? 0:1;
        if(password != Password[key]){
            cout << "Password is incorrect";
        }
        else{
            cout << "You logged in successfully";
        }
    }
    while(password != Password[key]);
    
    User_info(username, key);
}

void User_info(string username, int key){
    int input;
    do{
        cout << "\n\nWelcome " << Name[key] << " this is your personal account, what would you like to do?";
        cout << "\n[1] change name" << "\n[2] change username" << "\n[3] change password" << "\n[4] log out\n" << endl;
        cin >> input;
        switch(input){
            case 1:
                cout << "\n\nWhat would you like to change your name into? ";
                cin >> Name[key];
                cout << "\n\nConfirmed, you have changed your name to " << Name[key];
                break;

            case 2:{
                string temp_user_name;
                cout << "\n\nWhat would you like to change your username into? ";
                do{
                    cin >> temp_user_name;
                    if(Account_Validation(&temp_user_name, Username) == false)
                        cout <<"\n\nThis username has been taken, try another one: \n";
                }
                while(Account_Validation(&temp_user_name, Username) == false);
                Username[key] = temp_user_name;
                cout << "\n\nConfirmed, you have changed your username to " << Username[key];
                break;
            }

            case 3:
                string temp_password_first;
                string temp_password_second;
                cout << "\n\nWhat would you like to change your password into? ";
                do{
                    cin >> temp_password_first;
                    if(Password_Validation(&temp_password_first) == false)
                        cout << "\n\nPassword does not meet the requirement, try again: \n";
                }
                while(Password_Validation(&temp_password_first) == false);
                cout << "\n\nRe-enter your password: ";
                do{
                    cin >> temp_password_second;
                    if(temp_password_second != temp_password_first)
                        cout << "\n\nPasswords do not match";
                }
                while(temp_password_second != temp_password_first);
                Password[key] = temp_password_first;
                cout << "\n\nConfirmed, you have changed your name to " << Password[key];
                break;
        }
    }
    while(input==1 || input==2 || input==3);
    cout << "\n\nYou are logged out.";
}