#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include "FaceMagazine.h"

using namespace std;

int main()
{

//Ask for the username, which is simply a way to specify the text file.

    string username;

    cout<<"Welcome to FaceMagazine! Please log in by entering your username: ";

    getline(cin,username);

    while (username!="user"){

        cout<<"Invalid username. Please enter a username: ";
        getline(cin,username);

    }

    FaceMagazine mainProgram(username);

    cout<<endl<<"Welcome to FaceMagazine!"<<endl;

    int option=0;
    string name;
    bool found=0;

    while (option!=4){

        mainProgram.displayMainMenu();

        cin>>option;
        cin.ignore();

        if (option==1){

            cout<<"Please enter the user whom you wish to check: ";

            getline(cin,name);

            user* currentUser=mainProgram.findUser(name,found);

            if(found==1){

                if (mainProgram.isFriends(currentUser)){

                    string status;

                    mainProgram.checkStatus(name,status);

                    mainProgram.addStatus(currentUser,status);

                }

                else {

                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout<<currentUser->name<<" is not your friend! Unable to view statuses!"<<endl;

                }


            }

            else{

                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout<<"User not found."<<endl;

            }


        }

        if (option==2){

            cout<<"Enter Status: ";

            getline(cin,name);

            mainProgram.addStatus(mainProgram.retrieveInfo(),name);

            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout<<"Status Posted!"<<endl<<endl;

        }

        if (option==3){

            cout<<"Enter person's name: ";

            getline(cin,name);

            user* currentUser=mainProgram.findUser(name,found);

            if (found==1){

                while (option!=2){

                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout<<"Posts by "<<name<<":"<<endl<<"-----------------------"<<endl<<endl;
                    mainProgram.displayStatuses(currentUser);


                     cout<<"-----------"<<endl<<"Choose an option:"<<endl<<"1. View pictures"<<endl<<"2. Exit"<<endl;

                        cin>>option;
                        cin.ignore();

                        if (option==1){

                            mainProgram.imageViewer(currentUser);

                             cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

                        }
                }


            }

            else{

                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout<<"User not found."<<endl;

            }

             cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        }


    }

    cout<<endl<<"You have logged out!"<<endl;

    return 0;
}
