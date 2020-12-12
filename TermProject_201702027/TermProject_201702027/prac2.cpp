#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <regex>
#include <locale>
#include <codecvt>
#include <algorithm> 
#include <tuple>

using namespace std;

class GlobalClass {
private:
    int Page;
    vector<string> file;
    static GlobalClass *s_instance;
    GlobalClass(int p = 0, vector<string> s_file = {}) {
        Page = p;
        file = s_file;
    }
   
public:
    tuple<int,bool> CurrentPrint(vector<string> s_file, int p) {
        int chkLine = 1;
        bool chkLast;
        int currentPage;
        
        for (int i = p;i < s_file.size();i++) {
            cout << right << setw(2) << chkLine << "| " << s_file[i] << '\n';
            
            chkLine += 1;
            if (i+1 == s_file.size()) {
                chkLast = true;
                currentPage = p;
            }
            else {
                chkLast = false;
                currentPage = p + 20;
            }
            if (chkLine == 21) {
                break;
            }
        }
         
        return tuple<int,bool>(currentPage,chkLast);
    }
    vector<string> SortFile(vector<string> s_file) {

        string field;
        string current;

        vector<string> sortfile = {};
        stringstream ss;
        std::copy(s_file.begin(), s_file.end(), ostream_iterator<string>(ss, " "));

        string input = ss.str();
        string delimiter = " ";
        string chk;
        string token;
        size_t pos = 0;

        while ((pos = input.find(delimiter)) != string::npos) {
            token = input.substr(0, pos);
            string tmp = token;
            current.append(tmp);

            if (current.size() > 75) {
                sortfile.push_back(chk);
                current = tmp + " ";
            }
            else {
                chk = current;
                current.append(" ");
            }
            input.erase(0, pos + delimiter.length());
        }
        return sortfile;    }

    static GlobalClass* instance()
    {
        if (!s_instance)
            s_instance = new GlobalClass;
        return s_instance;
    }


};

GlobalClass* GlobalClass::s_instance = NULL;

vector<string> fileOpen() {
    ifstream file;
    file.open("test.txt");
    vector < string > vecOfStr;
    string field;
    string current;
    string chk;
    if (file.is_open()) {
        while (getline(file, field, ' ')) {
            string tmp = field;
            current.append(tmp);

            if (current.size() > 75) {
                vecOfStr.push_back(chk);
                current = tmp + " ";
            }
            else  {
                chk = current;
                current.append(" ");

            }
        }
        if (current.size() <= 75) {
            current = current.erase(current.size() - 1, current.size());
            vecOfStr.push_back(current);
        }
    }
    else { cout << "Unable to open file" << endl; }

    return vecOfStr;
}
vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
    int n = sizeof(ss);

    int chk = 1;
    while (getline(ss, temp, delimiter)) {
        chk += 1;
        internal.push_back(temp);
    }

    return internal;

}
void saveFile(vector<string> file) {
    std::ofstream outfile("test.txt");
    std::string s;
    std::ostream_iterator<std::string> output_iterator(outfile, "\n");
    std::copy(file.begin(), file.end(), output_iterator);
}

tuple<int,bool> findWord(vector<string> file, string fword) {
    int currentPage;
    bool isFind;

    for (int i = 0;i < file.size(); i++) {
        std::size_t found = file[i].find(fword);

        if (found != std::string::npos) {
            currentPage = i;
            isFind = true;
            break;
        }
        else {
            currentPage = 0;
            isFind = false;
        }
    }
    return tuple<int,bool>(currentPage,isFind);
}
tuple<vector<string>, bool> changeWord(vector<string> file, string ori, string want, int currentPage) {
    int chkLine = 1;
    bool isChange = false;
    int chk = 0;
    for (int i = 0;i < file.size(); i++) {
        std::size_t found = file[i].find(ori);

        if (found != std::string::npos) {
            file[i] = file[i].replace(found, ori.length(), want);
            
            chk += 1;
        }
    }
    if (chk != 0) {
        isChange = true;
    }
    return tuple<vector<string>, bool>(file, isChange);
}
tuple<vector<string>,bool> insertWord(vector<string> file, int col, int row, string iword, int currentPage) {
    int wantcol = currentPage + col - 1;

    stringstream tmp(file[wantcol]);
    string input = tmp.str();
    string delimiter = " ";
    int chk = 1;
    string token;
    size_t pos = 0;
    string current;
    bool isInsert;

    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        string tmp = token;

        if (chk == row) {
            current.append(tmp + " " + iword + " ");
            isInsert = true;
        }
        else {
            current.append(tmp + " ");
        }
        input.erase(0, pos + delimiter.length());
        chk += 1;
    }
    if (chk < row) {
        isInsert = false;
    }
    file[wantcol] = current;
    return tuple<vector<string>,bool>(file,isInsert);
}
tuple<vector<string>, bool> DeleteWord(vector<string> file, int col, int row, int currentPage) {
    int wantrow = currentPage + col - 1;

    stringstream tmp(file[wantrow]);
    string input = tmp.str();
    string delimiter = " ";
    int chk = 1;
    string token;
    size_t pos = 0;
    string current;
    bool isDelete = false;
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        string tmp = token;

        if (chk != row) {
            current.append(tmp + " ");
        }
        else if(chk == row) {
            isDelete = true;
        }
        input.erase(0, pos + delimiter.length());
        chk += 1;
    }
    file[wantrow] = current;
    return tuple<vector<string>, bool>(file, isDelete);
}

int main() {
    GlobalClass* instance = GlobalClass::instance();
    vector < string > vecOffile = fileOpen();
    string tmp;
    bool chkLast = false;
    int currentPage = 0;
    tuple<int,bool> printResult = GlobalClass::instance()->CurrentPrint(vecOffile, currentPage);
    currentPage = get<0>(printResult);
    chkLast = get<1>(printResult);
    cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
    cout << "��ɾ �Է��ϼ���!" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    
    while (true) {
        string input;
        cout << "�Է�: "; cin >> input;
        cout << "-------------------------------------------------------------------------------\n" << endl;
        getline(cin, tmp);

        if (input.compare("n") == 0) {
            tuple<int, bool> printResult = GlobalClass::instance()->CurrentPrint(vecOffile, currentPage);
            currentPage = get<0>(printResult);
            chkLast = get<1>(printResult);
            if (chkLast) {
                cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                cout << "������ �������Դϴ�!" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;

            }
            else {
                cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                cout << "��ɾ �Է��ϼ���!" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;

            }
        }
        else if (input.compare("t") == 0) {
            saveFile(vecOffile);
            break;
        }
        else if (input.compare("p") == 0) {
            int previousPage = currentPage - 40;
            if (previousPage < 0) {
                tuple<int, bool> printResult = GlobalClass::instance()->CurrentPrint(vecOffile, 0);
                currentPage = get<0>(printResult);
                cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                cout << "ù��° �������Դϴ�!" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;

            }
            else {
                tuple<int, bool> printResult = GlobalClass::instance()->CurrentPrint(vecOffile, previousPage);
                currentPage = get<0>(printResult);
                cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                cout << "��ɾ �Է��ϼ���!" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
            }
        }
        else {
            input = input.erase(input.size() - 1, input.size());
            vector<string> temp = split(input, '(');
            string chkPara = temp[0];
            string chkCont = temp[1];
            vector<string> temp2 = split(chkCont, ',');

            if (chkPara.compare("i") == 0) {
                try {
                    int col = stoi(temp2[0]);
                    int row = stoi(temp2[1]);
                    string iword = temp2[2];
                    if (iword.size() > 75) {
                        tuple<int, bool> printResult = GlobalClass::instance()->CurrentPrint(vecOffile, currentPage - 20);
                        currentPage = get<0>(printResult);
                        cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                        cout << "�߰��Ϸ��� �ܾ��� ũ�Ⱑ 75����Ʈ �̻��Դϴ�! " << endl;
                        cout << "-------------------------------------------------------------------------------\n";

                    }
                    else {
                        bool isInsert;
                        tuple<vector<string>,bool> insertResult = insertWord(vecOffile, col, row, iword, currentPage - 20);
                        vecOffile = get<0>(insertResult);
                        isInsert = get<1>(insertResult);
                        vecOffile = GlobalClass::instance()->SortFile(vecOffile);
                        tuple<int, bool> printResult = GlobalClass::instance()->CurrentPrint(vecOffile, currentPage - 20);
                        currentPage = get<0>(printResult);
                        if (isInsert) {
                            cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                            cout << col << "��° ���� " << row << "��° �ܾ� �ڿ� " << iword << "��(��) �߰��Ǿ����ϴ�!" << endl;
                            cout << "-------------------------------------------------------------------------------\n";

                        }
                        else {
                            cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                            cout << col << "��° �ٿ� " << row << "��° �ܾ �������� �ʽ��ϴ�! " << endl;
                            cout << "-------------------------------------------------------------------------------\n";

                        }
                        
                    }
                }
                catch (...) {
                    cout << "��ɾ �ٽ� �Է����ּ���! " << endl;
                    cout << "-------------------------------------------------------------------------------\n";
                }
            }
            else if (chkPara.compare("d") == 0) {
                int col = stoi(temp2[0]);
                int row = stoi(temp2[1]);
                if (col > 20) {
                    tuple<int, bool> printResult = GlobalClass::instance()->CurrentPrint(vecOffile, currentPage - 20);
                    currentPage = get<0>(printResult);
                    cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                    cout << col << "���� �������� �ʽ��ϴ�! " << endl;
                    cout << "-------------------------------------------------------------------------------\n";

                }
                else {
                    bool isDelete;
                    tuple<vector<string>, bool> deleteResult = DeleteWord(vecOffile, col, row, currentPage - 20);
                    vecOffile = get<0>(deleteResult);
                    isDelete = get<1>(deleteResult);
                    vecOffile = GlobalClass::instance()->SortFile(vecOffile);
                    tuple<int, bool> printResult = GlobalClass::instance()->CurrentPrint(vecOffile, currentPage - 20);
                    currentPage = get<0>(printResult);
                    if (isDelete) {
                        cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                        cout << col << "��° ���� " << row << "��° �ܾ �����Ǿ����ϴ�!" << endl;
                        cout << "-------------------------------------------------------------------------------\n";
                    }
                    else {
                        cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                        cout << col << "��° ���� "<< row << "��° �ܾ ��ã�ҽ��ϴ�! " << endl;
                        cout << "-------------------------------------------------------------------------------\n";
                    }
                    
                }
            }
            else if (chkPara.compare("s") == 0) {
                bool isFind;
                string fword = chkCont;
                tuple<int,bool>findResult = findWord(vecOffile, fword);
                currentPage = get<0>(findResult);
                isFind = get<1>(findResult);
                tuple<int, bool> printResult = GlobalClass::instance()->CurrentPrint(vecOffile, currentPage);
                currentPage = get<0>(printResult);
                if (isFind) {
                    cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                    cout << fword << "��(��) ã�ҽ��ϴ�!" << endl;
                    cout << "-------------------------------------------------------------------------------\n";

                }
                else {
                    cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                    cout << fword << "��(��) ��ã�ҽ��ϴ�! ù�������� �̵��մϴ�." << endl;
                    cout << "-------------------------------------------------------------------------------\n";

                }
                
            }
            else if (chkPara.compare("c") == 0) {
                string ori = temp2[0];
                string want = temp2[1];
                bool isChange;
                tuple<vector<string>, bool> changeResult = changeWord(vecOffile, ori, want, currentPage);
                vecOffile = get<0>(changeResult);
                isChange = get<1>(changeResult);
                vecOffile = GlobalClass::instance()->SortFile(vecOffile);
                tuple<int, bool> printResult = GlobalClass::instance()->CurrentPrint(vecOffile, currentPage - 20);
                currentPage = get<0>(printResult);
                if (isChange) {
                    cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                    cout << ori << "�� " << want << "�� ����Ǿ����ϴ�!" << endl;
                    cout << "-------------------------------------------------------------------------------\n";

                }
                else {
                    cout << "-------------------------------------------------------------------------------\n" << "n:����������, p:����������, i:����, d:����, c:����, s:ã��, t:������ ���� \n" << "-------------------------------------------------------------------------------\n";
                    cout << ori << "��(��) ��ã�ҽ��ϴ�!" << endl;
                    cout << "-------------------------------------------------------------------------------\n";

                }
            }
            else {
                cout << "��ɾ �ٽ� �Է����ּ���!" << endl;
                cout << "-------------------------------------------------------------------------------\n";
            }
        }
    }
}