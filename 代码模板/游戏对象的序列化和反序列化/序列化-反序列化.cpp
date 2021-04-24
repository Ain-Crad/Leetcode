#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

enum Type{INT, STRING, BOOL, DOUBLE, ARRAY, MAP};

struct Info{
    Info(Type _t, string _type_name, string _type): t(_t), type_name(_type_name), type(_type){}
    Type t;
    string type_name;
    string type;
};

unsigned char getByte(int& cur, const string& encode){
    unsigned char v = 0;
    int t;
    if(isdigit(encode[cur])){
        t = encode[cur] - '0';
    }else{
        t = encode[cur] - 'a' + 10;
    }

    v = t;
    v <<= 4;

    if(isdigit(encode[cur + 1])){
        v |= encode[cur + 1] - '0';
    }else{
        v |= encode[cur + 1] - 'a' + 10;
    }

    cur += 2;

    return v;
}

void decodeInt(int& cur, const string& encode){
    unsigned int t;
    int v = 0;
    t = getByte(cur, encode);
    v |= (t << 24);
    t = getByte(cur, encode);
    v |= (t << 16);
    t = getByte(cur, encode);
    v |= (t << 8);
    t = getByte(cur, encode);
    v |= t;

    cout << v;
}

void decodeString(int& cur, const string& encode){

    unsigned int t;
    unsigned int len = 0;
    t = getByte(cur, encode);
    len |= (t << 24);
    t = getByte(cur, encode);
    len |= (t << 16);
    t = getByte(cur, encode);
    len |= (t << 8);
    t = getByte(cur, encode);
    len |= t;
    
    cout << "\"";
    for(unsigned int i = 0; i < len; ++i){
        cout << getByte(cur, encode);
    }
    cout << "\"";
}

void decodeBool(int& cur, const string& encode){
    unsigned char c = getByte(cur, encode);

    bool b = bool(c);
    if(b) cout << "true";
    else cout << "false";
}

void decodeDouble(int& cur, const string& encode){

    unsigned long long v = 0;
    unsigned long long t;
    t = getByte(cur, encode);
    v |= (t << 56);
    t = getByte(cur, encode);
    v |= (t << 48);
    t = getByte(cur, encode);
    v |= (t << 40);
    t = getByte(cur, encode);
    v |= (t << 32);
    t = getByte(cur, encode);
    v |= (t << 24);
    t = getByte(cur, encode);
    v |= (t << 16);
    t = getByte(cur, encode);
    v |= (t << 8);
    t = getByte(cur, encode);
    v |= t;

    double* res = reinterpret_cast<double*>(&v);

    cout << fixed << setprecision(2) << *res;
}

void decodeArray(int& cur, const string& encode, const string& inner_type){

    unsigned int t;
    unsigned int len = 0;
    t = getByte(cur, encode);
    len |= (t << 24);
    t = getByte(cur, encode);
    len |= (t << 16);
    t = getByte(cur, encode);
    len |= (t << 8);
    t = getByte(cur, encode);
    len |= t;

    cout << "[";
    for(unsigned int i = 0; i < len; ++i){
        if(i > 0) cout << ", ";
        switch(inner_type[0]){
            case 'i': decodeInt(cur, encode); break;
            case 's': decodeString(cur, encode); break;
            case 'b': decodeBool(cur, encode); break;
            case 'd': decodeDouble(cur, encode); break;
        }
    }
    cout << "]";
}

void decodeMap(int& cur, const string& encode, const string& inner_type){

    unsigned int t;
    unsigned int len = 0;
    t = getByte(cur, encode);
    len |= (t << 24);
    t = getByte(cur, encode);
    len |= (t << 16);
    t = getByte(cur, encode);
    len |= (t << 8);
    t = getByte(cur, encode);
    len |= t;

    cout << "{";
    for(unsigned int i = 0; i < len; ++i){
        if(i > 0) cout << ", ";
        decodeString(cur, encode);
        cout << ": ";
        switch(inner_type[0]){
            case 'i': decodeInt(cur, encode); break;
            case 's': decodeString(cur, encode); break;
            case 'b': decodeBool(cur, encode); break;
            case 'd': decodeDouble(cur, encode); break;
        }
    }
    cout << "}";
}

string getInnerTypeArray(string& type){
    int p = 0;
    while(p < type.size() && type[p] != '<') ++p;
    string inner_type = type.substr(p + 1);
    inner_type.pop_back();
    return inner_type;
}

string getInnerTypeMap(string& type){
    int p = 0;
    while(p < type.size() && type[p] != ',') ++p;
    string inner_type = type.substr(p + 1);
    inner_type.pop_back();
    return inner_type;
}

int main(){
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);
    string str;
    stringstream ss;
    vector<Info> df;    
    for(int i = 0; i < n; ++i){
        getline(cin, str);
        int p = 0;
        while(p < str.size() && str[p] != '#') ++p;
        if(p == 0) continue;
        str = str.substr(0, p);
        if(str[0] == ']') continue;

        ss.str(str);
        string type, type_name;
        ss >> type >> type_name;
        
        switch(type[0]){
            case 'i': df.push_back(Info(INT, type_name, "null")); break;
            case 's': df.push_back(Info(STRING, type_name, "null")); break;
            case 'b': df.push_back(Info(BOOL, type_name, "null")); break;
            case 'd': df.push_back(Info(DOUBLE, type_name, "null")); break;
            case 'a': df.push_back(Info(ARRAY, type_name, type)); break;
            case 'm': df.push_back(Info(MAP, type_name, type)); break;
        }
        
        ss.clear();
    }

    string encode;
    cin >> encode;
    int cur = 0;
    for(int i = 0; i < df.size(); ++i){
        cout << df[i].type_name << " = ";

        switch(df[i].t){
            case INT:{
                decodeInt(cur, encode);
                break;
            }
            case STRING:{
                decodeString(cur, encode);
                break;
            }
            case BOOL:{
                decodeBool(cur, encode);
                break;
            }
            case DOUBLE:{
                decodeDouble(cur, encode);
                break;
            }
            case ARRAY:{
                string inner_type = getInnerTypeArray(df[i].type);
                decodeArray(cur, encode, inner_type);
                break;
            }
            case MAP:{
                string inner_type = getInnerTypeMap(df[i].type);
                decodeMap(cur, encode, inner_type);
                break;
            }
        }

        cout << endl;
    }

    return 0;
}