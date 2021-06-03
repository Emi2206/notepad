// notepad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
namespace fs= std::filesystem;

bool close = false;

void Logo()
{
    cout << endl << endl;
    cout << R"###(  _   _       _                       _ )###" << endl;
    cout << R"###( | \ | |     | |                     | |)###" << endl;
    cout << R"###( |  \| | ___ | |_ ___ _ __   __ _  __| |)###" << endl;
    cout << R"###( | . ` |/ _ \| __/ _ \ '_ \ / _` |/ _` |)###" << endl;
    cout << R"###( | |\  | (_) | ||  __/ |_) | (_| | (_| |)###" << endl;
    cout << R"###( |_| \_|\___/ \__\___| .__/ \__,_|\__,_|)###" << endl;
    cout << R"###(                     | |                )###" << endl;
    cout << R"###(                     |_|                )###" << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void Menu()
{
    cout << R"###(   _____                _            _____       _      _       )###" << endl;
    cout << R"###(  / ____|              | |          |  __ \     | |    | |      )###" << endl;
    cout << R"###( | |     _ __ ___  __ _| |_ ___     | |  | | ___| | ___| |_ ___ )###" << endl;
    cout << R"###( | |    | '__/ _ \/ _` | __/ _ \    | |  | |/ _ \ |/ _ \ __/ _ \)###" << endl;
    cout << R"###( | |____| | |  __/ (_| | ||  __/    | |__| |  __/ |  __/ ||  __/)###" << endl;
    cout << R"###(  \_____|_|  \___|\__,_|\__\___|    |_____/ \___|_|\___|\__\___|)###" << endl;
    cout << R"###(   ENTER 1 TO CREATE NEW FILE         ENTER 2 TO DELETE FILE     )###" << endl;
    cout << R"###(   _____ _                        __  __           _ _  __       )###" << endl;
    cout << R"###(  / ____| |                      |  \/  |         | (_)/ _|      )###" << endl;
    cout << R"###( | (___ | |__   _____      __    | \  / | ___   __| |_| |_ _   _ )###" << endl;
    cout << R"###(  \___ \| '_ \ / _ \ \ /\ / /    | |\/| |/ _ \ / _` | |  _| | | |)###" << endl;
    cout << R"###(  ____) | | | | (_) \ V  V /     | |  | | (_) | (_| | | | | |_| |)###" << endl;
    cout << R"###( |_____/|_| |_|\___/ \_/\_/      |_|  |_|\___/ \__,_|_|_|  \__, |)###" << endl;
    cout << R"###(                                                            __/ |)###" << endl;
    cout << R"###(                                                           |___/ )###" << endl;
    cout << R"###(   ENTER 3 TO SHOW ALL FILE         ENTER 4 TO MODIFY FILE       )###" << endl;
    cout << endl << "Enter 5 to Exit" << endl;
}

void Create()
{
    cout << R"###(   _____                _       )###" << endl;
    cout << R"###(  / ____|              | |      )###" << endl;
    cout << R"###( | |     _ __ ___  __ _| |_ ___ )###" << endl;
    cout << R"###( | |    | '__/ _ \/ _` | __/ _ \)###" << endl;
    cout << R"###( | |____| | |  __/ (_| | ||  __/)###" << endl;
    cout << R"###(  \_____|_|  \___|\__,_|\__\___|)###" << endl;
    cout << endl;
    cout << "Enter the name of the txt file : ";
    string filename;
    cin >> filename;

    ofstream outFile(filename + ".txt");
    outFile.close();

    cout << endl << filename + ".txt CREATED!!" << endl << endl;
    system("pause");
    system("cls");
}

void Delete()
{
    cout << R"###(  _____       _      _       )###" << endl;
    cout << R"###( |  __ \     | |    | |      )###" << endl;
    cout << R"###( | |  | | ___| | ___| |_ ___ )###" << endl;
    cout << R"###( | |  | |/ _ \ |/ _ \ __/ _ \)###" << endl;
    cout << R"###( | |__| |  __/ |  __/ ||  __/)###" << endl;
    cout << R"###( |_____/ \___|_|\___|\__\___|)###" << endl;
    string path = fs::current_path().string();
    int code = 1;

    for (const auto& file : fs::directory_iterator(path))
    {
        if (fs::path(file.path().string()).extension() == ".txt")
        {
            cout << code << " : " << fs::path(file.path().string()).filename() << endl;
            code++;
        }
    }

    cout << endl << "--END--" << endl << endl;

    cout << "Enter the file's code you want to DELETE : ";
    cin >> code;
    system("cls");
    int temp = 1;

    for (const auto& file : fs::directory_iterator(path))
    {
        if (fs::path(file.path().string()).extension() == ".txt")
        {
            if (code == temp)
            {
                remove(fs::path(file.path().string()).filename());
                cout << endl << fs::path(file.path().string()).filename() << " DELETED!!" << endl << endl;
                system("pause");
                system("cls");
                break;
            }
            temp++;
        }
    }
}

void Show()
{
    cout << R"###(   _____ _                    )###" << endl;
    cout << R"###(  / ____| |                   )###" << endl;
    cout << R"###( | (___ | |__   _____      __ )###" << endl;
    cout << R"###(  \___ \| '_ \ / _ \ \ /\ / / )###" << endl;
    cout << R"###(  ____) | | | | (_) \ V  V /  )###" << endl;
    cout << R"###( |_____/|_| |_|\___/ \_/\_/   )###" << endl;
    cout << endl;
    
    string path = fs::current_path().string();
    int code = 1;

    for (const auto& file : fs::directory_iterator(path))
    {
        if (fs::path(file.path().string()).extension()==".txt")
        {
            cout << code << " : " << fs::path(file.path().string()).filename() << endl;
            code++;
        } 
    }

    cout << endl << "--END--" << endl << endl;

    cout << "Enter the file's code you want to read : ";
    cin >> code;
    system("cls");
    int temp = 1;
   
    for (const auto& file : fs::directory_iterator(path))
    {
        if (fs::path(file.path().string()).extension() == ".txt")
        {
            if (code == temp)
            {
                ifstream inFile;
                string x;
                inFile.open(fs::path(file.path().string()));
                vector<string>data;

                if (!inFile) {
                    cerr << "Unable to open file";
                    exit(1);
                }
    
                while (getline(inFile, x))
                {
                    data.push_back(x);
                }

                inFile.close();
                system("cls");

                cout << endl << "     -----===-----" << endl << endl;
                for (auto& s : data)
                {
                    cout << s << endl;
                }
                cout << endl << "     -----===-----" << endl << endl;
             
                system("pause");
                system("cls");
                break;
            }
            temp++;
        }
    }
}

void Modify()
{
    cout << R"###(  __  __           _ _  __       )###" << endl;
    cout << R"###( |  \/  |         | (_)/ _|      )###" << endl;
    cout << R"###( | \  / | ___   __| |_| |_ _   _ )###" << endl;
    cout << R"###( | |\/| |/ _ \ / _` | |  _| | | |)###" << endl;
    cout << R"###( | |  | | (_) | (_| | | | | |_| |)###" << endl;
    cout << R"###( |_|  |_|\___/ \__,_|_|_|  \__, |)###" << endl;
    cout << R"###(                            __/ |)###" << endl;
    cout << R"###(                           |___/ )###" << endl;
    cout << endl;
    string path = fs::current_path().string();
    int code = 1;

    for (const auto& file : fs::directory_iterator(path))
    {
        if (fs::path(file.path().string()).extension() == ".txt")
        {
            cout << code << " : " << fs::path(file.path().string()).filename() << endl;
            code++;
        }
    }

    cout << endl << "--END--" << endl << endl;

    cout << "Enter the file's code you want to modify : ";
    cin >> code;
    system("cls");
    int temp = 1;

    for (const auto& file : fs::directory_iterator(path))
    {
        if (fs::path(file.path().string()).extension() == ".txt")
        {
            if (code == temp)//correct file
            {
                ifstream inFile;
                string x;
                inFile.open(fs::path(file.path().string()));
                vector<string>data;

                if (!inFile) {
                    cerr << "Unable to open file";
                    exit(1);
                }

                while (getline(inFile, x))
                {
                    data.push_back(x);
                }

                inFile.close();
                system("cls");

                cout << endl << "     -----===-----" << endl << endl;
                for (auto& s : data)
                {
                    cout << s << endl;
                }
                cout << endl << "     -----===-----" << endl << endl;

                cout << "Enter new data below this line" << endl << endl;
                string newData;
                getline(cin, newData);
                getline(cin, newData);
                
                ofstream myFile;
                myFile.open(fs::path(file.path().string()));       
                myFile << newData;
                cout << endl << "***Writing this to " << fs::path(file.path().string()).filename() << " successfully!***" << endl << endl;
                myFile.close();
                system("pause");
                system("cls"); 
            }
            temp++;
        }
    }
}

void Choice(int choice)
{
    switch (choice)
    {
    case 1:
        Create();
        break;
    case 2:
        Delete();
        break;
    case 3:
        Show();
        break;
    case 4:
        Modify();
        break;
    }
}

int main()
{
    Logo();
    int choice;
    while (!close)
    {
        Menu();
        cout << endl << "Choice : ";
        cin >> choice;
        if (choice == 5)
        {
            break;
        }
        system("cls");
        Choice(choice);
    }
    return 0;
}


