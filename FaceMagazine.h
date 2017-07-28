#define __USE_MINGW_ANSI_STDIO 0
#include <vector>
#include <string>

#ifndef FACEMAGAZINE_H
#define FACEMAGAZINE_H

struct image{

std::string imageName;

image* next;
image* prev;

};

struct user{

std::string name;
image* imageHead;
std::vector<user*> friends;
std::vector<std::string> statuses;


};

class FaceMagazine
{
    public:
        FaceMagazine(std::string);
        ~FaceMagazine();
        void displayMainMenu();
        void checkStatus(std:: string,std::string&);
        void addUser(std::string);
        void addConnection(user*,user*);
        void postStatus(std::string);
        void addFriend(user*);
        void observeProfile(user*);
        void imageViewer(user*);
        void addStatus(user*, std::string);
        void displayStatuses(user*);
        bool isFriends(user*);
        user* retrieveInfo();
        user* setUser(std::string);
        user* findUser(std::string,bool&);

    private:

        user* you=NULL;
        image head;
        std::vector<user*> users;
        std::string displayStatus(int);
        image* galleryCreator();



};

#endif // FACEMAGAZINE_H
