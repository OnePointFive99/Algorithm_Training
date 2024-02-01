#include <stdio.h>
#include<vector>
#include<cmath>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string check(string in)
{
    string ret;
    if (in == "01")ret = "A";
    if (in == "1000")ret = "B";
    if (in == "1010")ret = "C";
    if (in == "100")ret = "D";
    if (in == "0")ret = "E";
    if (in == "0010")ret = "F";
    if (in == "110")ret = "G";
    if (in == "0000")ret = "H";
    if (in == "00")ret = "I";
    if (in == "0111")ret = "J";
    if (in == "101")ret = "K";
    if (in == "0100")ret = "L";
    if (in == "11")ret = "M";
    if (in == "10")ret = "N";
    if (in == "111")ret = "O";
    if (in == "0110")ret = "P";
    if (in == "1101")ret = "Q";
    if (in == "010")ret = "R";
    if (in == "000")ret = "S";
    if (in == "1")ret = "T";
    if (in == "001")ret = "U";
    if (in == "0001")ret = "V";
    if (in == "011")ret = "W";
    if (in == "1001")ret = "X";
    if (in == "1011")ret = "Y";
    if (in == "1100")ret = "Z";
    if (in == "01111")ret = "1";
    if (in == "00111")ret = "2";
    if (in == "00011")ret = "3";
    if (in == "00001")ret = "4";
    if (in == "00000")ret = "5";
    if (in == "10000")ret = "6";
    if (in == "11000")ret = "7";
    if (in == "11100")ret = "8";
    if (in == "11110")ret = "9";
    if (in == "11111")ret = "0";
    if (in == "001100")ret = "?";
    if (in == "10010")ret = "/";
    if (in == "101101")ret = "()";
    if (in == "100001")ret = "-";
    if (in == "010101")ret = ".";
    return ret;
}

int main() {
    string n;
    cin >> n;//输入字符串
    string result = "";
    int j = 0;
    for (int i = 0; i <n.size(); i++)
    {
        if (n[i] == '.')
        {
            //cout << j<<' '<<i << endl;
            //cout << n.substr(j, i-j) << endl;
            string tmp = check(n.substr(j, i-j));
            //cout << tmp << endl;
            result = result + tmp;
            j = i + 1;
        }
        if (i == n.size() - 1)
        {
            string tmp = check(n.substr(j, i - j+1));
            //cout << n.substr(j, i - j+1) << endl;
            //cout << tmp << endl;
            result = result + tmp;
        }
    }
    cout << result << endl;
    return 0;
}