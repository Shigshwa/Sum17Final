Joe Chen

FaceMagazine
---------------

Description:

What if, you lived in a poor country where it is impossible for you to afford a smart phone or a computer, yet you wish to use the power of social networking to connect with your friends? I created this conceptual program to simulate a social network that would be able to function on a device as basic as a flip phone. FaceMagazine is not nearly as comprehensive or complex as an actual social network such as Facebook, but FaceMagazine can perform the most basic functions of a social network. 

A timeline is not available, but one can check another person's status by manually entering the person's name in. One can also check a person's profile, and read their statuses that they have posted overall. The application also has an image viewer, to view a person's images. The user can also manage their friends list as well.


Directions:

When the program is started, it will ask for a "username". Type "user" and press enter, and you will "log in".

The main menu is displayed, the menu options are self-explanatory, and some offer extended functionality.

Pressing 1 will allow you to check the latest post that a user has posted. If the user is not your friend, then you will not be able to see their status.

Pressing 2 will allow you to post a status. Enter anything, and it will be logged into your profile.

Pressing 3 will allow you to view a person's profile, and their posts. In addition, you can also use the image viewer to view a person's images.

Pressing 4 will allow you to manage your friends list.

Press 5 to log out. 


Dependencies:

This application uses the following dependencies

vector,
string,
iostream,
stdlib,
fstream,
time


System Requirements:

So long as you run the program with all of the files in the repository, then the program will run on any OS.

Run the program by compiling with "g++ -std=c++11 main.cpp FaceMagazine.cpp -o test"


Issues/Bugs:

This is a very simplified simulation of a command line social network. Because this application cannot connect to the internet, all of the users are fictitious, and their statuses are randomly selected from a text file of phrases.

In addition, due to the limitations of my programming knowledge, I can only implement the most basic of features that a social network has. If I could, I would attempt to implement a messaging functionality in the future.
