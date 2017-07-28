#define __USE_MINGW_ANSI_STDIO 0
#include "FaceMagazine.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;

//The constructor will build the graph of users from the text file.
FaceMagazine::FaceMagazine(string username)
{
    string finalusername=username+".txt";

    ifstream in(finalusername);
    string read;
    user* currentUser;
    user* targetUser;

    while (getline(in,read,',')){

        if (you==NULL){

            while (read!="end users"){

                addUser(read);
                currentUser=setUser(read);
                currentUser->imageHead=galleryCreator();

                if (read=="you"){

                    you=setUser(read);

                }

                getline(in,read,',');
            }
                getline(in,read,',');
        }

        currentUser=setUser(read);


        while (read!="end"){

            getline(in,read,',');

            if(read!="end"){

                targetUser=setUser(read);
                addConnection(currentUser,targetUser);

            }

        }

    }

}

FaceMagazine::~FaceMagazine()
{
    //dtor
}

//Getter function for the node that represents the user.
user* FaceMagazine::retrieveInfo(){

return you;
}

//Checks whether the specified user if your friend. Checks if the graph nodes are linked or not.
bool FaceMagazine::isFriends(user* checkUser){

    for (int i=0; i<checkUser->friends.size();i++){

        if (checkUser->friends[i]->name==you->name){

            return 1;

        }

    }

return 0;
}

//Displays the statuses stored in the node.
void FaceMagazine::displayStatuses(user* target){

    for (int i=0;i<target->statuses.size();i++){

        cout<<target->statuses[i]<<endl<<endl;

    }

}

//Stores the status into the node.
void FaceMagazine::addStatus(user* user, string in){

user->statuses.push_back(in);

}

//Returns the pointer to the specified node.
user* FaceMagazine::findUser(string name, bool &found){

    for (int i=0; i<users.size();i++){

        if (users[i]->name==name){

            found=1;
            return users[i];

        }

    }
found=0;
return NULL;
}

//An alternative function to the above function.
user* FaceMagazine::setUser(string name){

    for (int i=0; i<users.size();i++){

        if (users[i]->name==name){

            return users[i];

        }

    }
return NULL;
}

//Adds a node to the graph.
void FaceMagazine::addUser(string name){

    user *newUser=new user;
    newUser->name=name;

    newUser->imageHead=galleryCreator();

    users.push_back(newUser);

}

//Adds an edge between two nodes in the graph.
void FaceMagazine::addConnection(user* v1, user* v2){

    v1->friends.push_back(v2);
    v2->friends.push_back(v1);

}

//Simulates a posted status.
void FaceMagazine::postStatus(string status){

    cout<<"Status has been posted!"<<endl;

}

//Displays the main menu.
void FaceMagazine::displayMainMenu(){

    cout<<"-----------------"<<endl<<"~FaceMagazine~"<<endl;
    cout<<endl;

    cout<<"1. Check Status"<<endl<<"2. Post Status"<<endl<<"3. Look at Profile"<<endl<<"4. Logout"<<endl;


}

//returns a phrase from the statuses text file, based on the randomly generated number input.
string FaceMagazine::displayStatus(int in){

    fstream read("status.txt");
    string status;

    for (int i=0; i!=in; i++){

        getline(read,status);

    }

    read.close();

return status;
}

//Function that locates a user, and if found, displays the most recent status posted by the user.
void FaceMagazine::checkStatus(string inpName, string& resultingStatus){

    bool found=0;

    for (int i=0; i<users.size(); i++){

        if (users[i]->name==inpName){

            found=1;
            break;

        }

    }

    if (found==1){

        resultingStatus=displayStatus(rand()%50);

        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<inpName<<" posted: "<<resultingStatus<<endl;

    }

    else {

        cout<<"User not found."<<endl;

    }

}

//Function to initialize a unique linked list gallery for each user.
image* FaceMagazine::galleryCreator(){

    image *head=new image;
    image *temp;
    image *current=head;

    srand(time(NULL));

    for (int i=0;i<10;i++){

        if (current==head){

            head->imageName=to_string(rand()%30);
            head->prev=NULL;
            head->next=NULL;

            current=NULL;

        }

        else{

            current=head;

            while (current->next!=NULL){

                current=current->next;

            }

            temp= new image;

            temp->imageName=to_string(rand()%30);
            temp->prev=current;
            temp->next=NULL;
            current->next=temp;
            current=NULL;

        }


    }

return head;
}

//The function that runs through the linked list and displays the images in the list.
void FaceMagazine::imageViewer(user* user){

    image *current=user->imageHead;
    string currentImage=current->imageName+".txt";
    string imagePart;
    int option=0;

    ifstream pic("images/"+currentImage);

    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    while (getline(pic,imagePart)){

        cout<<imagePart<<endl;

    }

    cout<<"1. Previous Image"<<endl<<"2. Next Image"<<endl<<"3. Exit"<<endl;

    while (option!=3){

        cin>>option;
        cin.ignore();

        if (option==1){

            if (current->prev!=NULL){

                current=current->prev;

                currentImage=current->imageName+".txt";

                ifstream pic("images/"+currentImage);

                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

                while (getline(pic,imagePart)){

                    cout<<imagePart<<endl;

                }

                cout<<"1. Previous Image"<<endl<<"2. Next Image"<<endl<<"3. Exit"<<endl;

            }

            else{

                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout<<"End of Gallery"<<endl;
                cout<<"1. Previous Image"<<endl<<"2. Next Image"<<endl<<"3. Exit"<<endl;

            }

        }

        if (option==2){

            if (current->next!=NULL){

                current=current->next;

                currentImage=current->imageName+".txt";

                ifstream pic("images/"+currentImage);

                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

                while (getline(pic,imagePart)){

                    cout<<imagePart<<endl;

                }

                cout<<"1. Previous Image"<<endl<<"2. Next Image"<<endl<<"3. Exit"<<endl;

            }

            else{

                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout<<"End of Gallery"<<endl;
                cout<<"1. Previous Image"<<endl<<"2. Next Image"<<endl<<"3. Exit"<<endl;


            }

        }

    }

}
