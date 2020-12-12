//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cstdio>
//#include <iomanip>
//#include <stdio.h>
//#include <vector>
//#include <sstream>
//#include <regex>
//#include <locale>
//#include <codecvt>
//#include <algorithm> 
//
//using namespace std;
//
//vector<string> fileOpen() {
//    ifstream file;
//    file.open("test.txt");
//    vector < string > vecOfStr;
//    char buf[75];
//    string field;
//    string current;
//    string chk;
//    if (file.is_open()) {
//        while (getline(file, field, ' ')) {
//            string tmp = field;
//            current.append(tmp);
//
//            if (current.size() > 75) {
//                chk.erase(chk.length(), 1);
//                vecOfStr.push_back(chk);
//                current = tmp+" ";
//            }
//            else {
//                chk = current;
//                current.append(" ");
//                
//            }
//        }
//    }
//    else { cout << "Unable to open file" << endl; }
//    
//    return vecOfStr;
//}
//vector<string> split(string str, char delimiter) {
//    vector<string> internal;
//    stringstream ss(str);
//    string temp;
//    int n = sizeof(ss);
//
//    int chk = 1;
//    while (getline(ss, temp, delimiter)) {
//        chk += 1;
//        internal.push_back(temp);
//    }
//    
//    return internal;
//
//}
//int CurrentPrint(vector<string> file, int currentPage) {
//    int chkLine = 1;
//    int chk = currentPage ;
//    for (int i = chk;i < file.size();i++) {
//        cout << right << setw(2) << chkLine << "| " << file[i] << '\n';
//
//        chkLine += 1;
//        if (i + 1 == file.size()) {
//            
//        }
//        if (chkLine == 21) {
//            break;
//        }
//
//    }
//    return currentPage+20;
//}
//int NextPrint(vector<string> file, int currentPage) {
//    int chkLine = 1;
//    bool chkLast = false;
//    for (int i = currentPage;i < file.size();i++) {
//        cout << right << setw(2) << chkLine << "| " << file[i] << '\n';
//
//        chkLine += 1;
//        if (i + 1 == file.size()) {
//             chkLast = true;
//        }
//        if (chkLine == 21) {
//            break;
//        }
//        
//    }
//    cout << "-------------------------------------------------------------------------------\n" << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후 종료 \n" << "-------------------------------------------------------------------------------\n";
//    if (chkLast) {
//        cout << "마지막 페이지입니다! " << endl;
//    }
//    else {
//        cout << "명령어를 입력하세요!" << endl;
//    }
//   
//    cout << "-------------------------------------------------------------------------------" << endl;
//    return currentPage+20;
//}
//int PreviousPrint(vector<string> file, int currentPage) {
//    int chkLine = 1;
//    int chk = currentPage - 40;
//
//    if (chk < 0) {
//        for (int i = 0;i < 20;i++) {
//            cout << right << setw(2) << chkLine << "| " << file[i] << '\n';
//
//            chkLine += 1;
//            if (chkLine == 21) {
//                break;
//            }
//        }
//        cout << "-------------------------------------------------------------------------------\n" << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후 종료 \n" << "-------------------------------------------------------------------------------\n";
//        cout << "첫번째 페이지 입니다!" << endl;
//        cout << "-------------------------------------------------------------------------------\n";
//
//        return currentPage;
//    }
//    else {
//        for (int i = chk;i < file.size();i++) {
//            cout << right << setw(2) << chkLine << "| " << file[i] << '\n';
//
//            chkLine += 1;
//            if (chkLine == 21) {
//                break;
//            }
//         }
//        cout << "-------------------------------------------------------------------------------\n" << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후 종료 \n" << "-------------------------------------------------------------------------------\n";
//        cout << "명령어를 입력하세요!" << endl;
//        cout << "-------------------------------------------------------------------------------" << endl;
//        return chk+20;
//    }
//    
//}
//void saveFile(vector<string> file) {
//    std::ofstream outfile("test2.txt");
//    std::string s;
//    std::ostream_iterator<std::string> output_iterator(outfile, "\n");
//    std::copy(file.begin(), file.end(), output_iterator);
//}
//vector<string> SortFile(vector<string> file) {
//   
//    string field;
//    string current;
//    
//    vector<string> sortfile = {};
//    stringstream ss;
//    std::copy(file.begin(), file.end(), ostream_iterator<string>(ss, " "));
//    
//    string input = ss.str();
//    string delimiter = " ";
//    string chk;
//    string token;
//    size_t pos = 0;
//   
//    while ((pos = input.find(delimiter)) != string::npos) {
//        token = input.substr(0, pos);
//        string tmp = token;
//        current.append(tmp);
//
//        if (current.size() > 75) {
//            sortfile.push_back(chk);
//            current = tmp+" ";
//            //current.append(" ");
//        }
//        else {
//            chk = current;
//            current.append(" ");
//        }
//        input.erase(0, pos + delimiter.length());
//    }
//    return sortfile;
//}
//int findWord(vector<string> file, string fword) {
//    int currentPage;
//    for (int i = 0;i < file.size(); i++) {
//        std::size_t found = file[i].find(fword);
//
//        if (found != std::string::npos) {
//            currentPage = i;
//        }
//    }
//    return currentPage;
//}
//vector<string> changeWord(vector<string> file,string ori, string want,int currentPage ) {
//    int chkLine = 1;
//  
//    for (int i = 0;i < file.size();  i++) {
//        std::size_t found = file[i].find(ori);
//      
//        if (found != std::string::npos) {
//            file[i] = file[i].replace(found, ori.length(), want);
//        }
//    }
//    return file;
//}
//vector<string> insertWord(vector<string> file, int col, int row,string iword,int currentPage) {
//    int wantrow = currentPage + col - 1;
//   
//    stringstream tmp(file[wantrow]);
//    string input = tmp.str();
//    string delimiter = " ";
//    int chk=1;
//    string token;
//    size_t pos = 0;
//    string current;
//
//    while ((pos = input.find(delimiter)) != string::npos) {
//        token = input.substr(0, pos);
//        string tmp = token;
//        
//        if (chk == row) {
//            current.append(tmp + " " + iword + " ");
//        }
//        else {
//            current.append(tmp+" ");
//        }
//        input.erase(0, pos + delimiter.length());
//        chk += 1;
//    }
//    file[wantrow] = current;
//    return file;
//}
//vector<string> DeleteWord(vector<string> file, int col, int row,int currentPage) {
//    int wantrow = currentPage + col - 1;
//   
//    stringstream tmp(file[wantrow]);
//    string input = tmp.str();
//    string delimiter = " ";
//    int chk=1;
//    string token;
//    size_t pos = 0;
//    string current;
//
//    while ((pos = input.find(delimiter)) != string::npos) {
//        token = input.substr(0, pos);
//        string tmp = token;
//        
//        if(chk != row) {
//            current.append(tmp+" ");
//        }
//        input.erase(0, pos + delimiter.length());
//        chk += 1;
//    }
//    file[wantrow] = current;
//    return file;
//}
//int main() {
//    
//    vector < string > vecOffile = fileOpen();
//    string tmp;
//    int currentPage = 0;
//    currentPage = NextPrint(vecOffile, currentPage);
//    
//    while (true) {
//        string input;
//        cout << "입력: "; cin >> input;
//        cout << "-------------------------------------------------------------------------------\n" << endl;
//      
//        getline(cin, tmp);
//        //string input = tmp;
//       
//        if (input.compare("n") == 0) {
//            string fck;
//            currentPage = NextPrint(vecOffile, currentPage);
//         /*   cout << "input: n" << endl;*/
//        }
//         else if (input.compare("t")==0) {
//            //cout << "input: t" << endl;
//            saveFile(vecOffile);
//            break;
//         }
//         else if (input.compare("p")==0) {
//            currentPage = PreviousPrint(vecOffile, currentPage);
//            //cout << "input: p" << endl;
//         }
//        else {
//            
//            input = input.erase(input.size() - 1,input.size());
//            vector<string> temp = split(input, '(');
//            string chkPara = temp[0];
//            string chkCont = temp[1];
//            vector<string> temp2 = split(chkCont, ',');
//
//            //char chk = strtok(input, "(,");
//        
//            if (chkPara.compare("i")==0) {
//                int col = stoi(temp2[0]);
//                int row = stoi(temp2[1]);
//                string iword = temp2[2];
//                if (iword.size() > 75) {
//                    currentPage = CurrentPrint(vecOffile, currentPage - 20);
//                    cout << "-------------------------------------------------------------------------------\n" << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후 종료 \n" << "-------------------------------------------------------------------------------\n";
//                    cout << "추가하려는 단어의 크기가 75바이트 이상입니다! " << endl;
//                    cout << "-------------------------------------------------------------------------------\n";
//
//                }
//                else {
//                    vecOffile = insertWord(vecOffile, col, row, iword, currentPage - 20);
//                    vecOffile = SortFile(vecOffile);
//                    currentPage = CurrentPrint(vecOffile, currentPage - 20);
//                    cout << "-------------------------------------------------------------------------------\n" << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후 종료 \n" << "-------------------------------------------------------------------------------\n";
//                    cout << col << "번째 줄의 " << row << "번째 단어 뒤에" << iword << "이(가) 추가되었습니다!" << endl;
//                    cout << "-------------------------------------------------------------------------------\n";
//
//                }
//               
//                //cout << "input: i" << endl;
//            }
//            else if (chkPara.compare("d")==0) {
//                int col = stoi(temp2[0]);
//                int row = stoi(temp2[1]);
//                if (col > 20) {
//                    currentPage = CurrentPrint(vecOffile, currentPage - 20);
//                    cout << "-------------------------------------------------------------------------------\n" << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후 종료 \n" << "-------------------------------------------------------------------------------\n";
//                    cout << col << "줄은 존재하지 않습니다! " << endl;
//                    cout << "-------------------------------------------------------------------------------\n";
//
//                }
//                else {
//                    vecOffile = DeleteWord(vecOffile, col, row, currentPage - 20);
//                    vecOffile = SortFile(vecOffile);
//                    currentPage = CurrentPrint(vecOffile, currentPage - 20);
//                    cout << "-------------------------------------------------------------------------------\n" << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후 종료 \n" << "-------------------------------------------------------------------------------\n";
//                    cout << col << "번째 줄의 " << row << "번째 단어가 삭제되었습니다!" << endl;
//                    cout << "-------------------------------------------------------------------------------\n";
//
//                }
//               
//                //cout << "input: d" << endl;
//            }
//            else if (chkPara.compare("s")==0) {
//                string fword = chkCont;
//                currentPage = findWord(vecOffile, fword);
//                currentPage = CurrentPrint(vecOffile, currentPage);
//                cout << "-------------------------------------------------------------------------------\n" << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후 종료 \n" << "-------------------------------------------------------------------------------\n";
//                cout << fword << "을(를) 찾았습니다!" << endl;
//                cout << "-------------------------------------------------------------------------------\n";
//
//                //cout << "input: s" << endl;
//            }
//            else if (chkPara.compare("c")==0) {
//                string ori = temp2[0];
//                string want = temp2[1];
//                vecOffile = changeWord(vecOffile, ori, want,currentPage);
//                vecOffile=SortFile(vecOffile);
//                currentPage = CurrentPrint(vecOffile, currentPage-20);
//                cout << "-------------------------------------------------------------------------------\n" << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후 종료 \n" << "-------------------------------------------------------------------------------\n";
//                cout << ori<<"가 "<<want<<"로 변경되었습니다!" << endl;
//                cout << "-------------------------------------------------------------------------------\n" << endl;
//  
//                //cout << "input: c" << endl;
//            }
//            else {
//                cout << "명령어를 다시 입력해주세요!" << endl;
//            }
//
//
//        }
//
//    }
//
//
//
//}