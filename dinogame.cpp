/*
||Jai Ganeshaaye Namah||
*/

// This code is just for the purpose of reading. If copied, this comment must not be removed, else god won't forgive you. My github profile - https://github.com/PunVas
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

int gBegin = 0;
string layer0 = "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
string layer1 = "\xDB                                                                                                                             \xDB";
string layer2 = "\xDB                                                                                                                             \xDB";
string layer3 = "\xDB                                                                                                                             \xDB";
string layer4 = "\xDB                                                                                                                             \xDB";
string layer5 = "\xDB                                                                                                                             \xDB";
string layer6 = "\xDB                                                                                                                             \xDB";
string layer7 = "\xDB                                                                                                                             \xDB";
string layer8 = "\xDB                                                                                                                             \xDB";
string layer9 = "\xDB                                                                                                                             \xDB";
string layer10 = "\xDB                                                                                                                             \xDB";
string layer11 = "\xDB                                                                                                                             \xDB";
string layer12 = "\xDB                                                                                                                             \xDB";
string layer13 = "\xDB                                                                                                                             \xDB";
string layer14 = "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
string layer15 = "";
string gameFrame[] = {layer0, layer1, layer2, layer3, layer4, layer5, layer6, layer7, layer8, layer9, layer10, layer11, layer12, layer13, layer14, layer15};
int currentScore = 0;
int highestScore = 0;

void readHighestScore() {
    ifstream file("HIScore.txt");
    if (file.is_open()) {
        file >> highestScore;
        file.close();
    }
}

void saveHighestScore() {
    ofstream file("HIScore.txt");
    if (file.is_open()) {
        file << highestScore-2;
        file.close();
    }
}

void updateScore(int score) {
    currentScore = score;
    if (currentScore > highestScore) {
        highestScore = currentScore;
        saveHighestScore();
    }
}

string scoreWallah() {
    return "Score: " + to_string(currentScore) + " | Highest Score: " + to_string(highestScore);
}

int rukaavaten(int ikka) {
    static int rukaavat = 124;
    if (rukaavat != -1) {
        if (!(ikka == 13 && rukaavat == 10)) {
            gameFrame[13][rukaavat] = '\xDB';
            gameFrame[13][rukaavat + 1] = ' ';
            gameFrame[15] = scoreWallah();
            rukaavat--;
            return 1;
        } else {
            gBegin = true;
            return 0;
        }
    } else {
        rukaavat = 124;
    }
}

void clickKeDauraan1(int x) {
    rukaavaten(x);
    gameFrame[x][10] = ' ';
    gameFrame[x - 1][10] = '#';
    gameFrame[15] = scoreWallah();
    system("cls");
    for (int i = 0; i < 16; i++) {
        cout << gameFrame[i] << endl;
    }
    Sleep(10);
}

void clickKeDauraan2(int x) {
    rukaavaten(x);
    gameFrame[x - 1][10] = ' ';
    gameFrame[x][10] = '#';
    gameFrame[15] = scoreWallah();
    system("cls");
    for (int i = 0; i < 16; i++) {
        cout << gameFrame[i] << endl;
    }
    Sleep(10);
}

int main() {
    readHighestScore();
    currentScore = 0;
    gameFrame[13][10] = '#';

    while (!gBegin) {
        
        int yDino = 13;
        rukaavaten(yDino);
        system("cls");
        for (int i = 0; i < 16; i++) {
            cout << gameFrame[i] << endl;
        }
        if (_kbhit()) {
            char in = _getch();
            fflush(stdin);
            if (in == ' ') {
                for (int ipv = 13; ipv > 7; ipv--) {
                    if (rukaavaten(yDino) == 0) {
                        break;
                    }
                    currentScore++;
                    clickKeDauraan1(ipv);
                    yDino = ipv;
                }
                for (int ipv2 = 8; ipv2 < 14; ipv2++) {
                    if (rukaavaten(yDino) == 0) {
                        break;
                    }
                    currentScore++;
                    clickKeDauraan2(ipv2);
                    yDino = ipv2;
                }
                if (rukaavaten(yDino) == 0) {
                    break;
                }
                while (_kbhit()) {
                    _getch();
                }
            }
            if (rukaavaten(yDino) == 0) {
                break;
            }
        }
        
        currentScore++;
        updateScore(currentScore);
    }
    return 0;
}
