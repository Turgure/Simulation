#include <fstream>
#include <DxLib.h>
#include "FileStream.h"

ifstream FileStream::file;
string FileStream::str;
int FileStream::i;
int FileStream::j;
int FileStream::p;

void FileStream::load(string filename, vector<string>& data){
	file = ifstream(filename);
	if(file.fail()){
		printfDx("%s load error.", filename);
		return;
	}
	
	i = 0;
	while(getline(file, str)){
	    //コメント箇所は除く
	    if((p = str.find("//")) != str.npos) continue;
	    //コンマがあるかを探し、そこまでをvaluesに格納
	    for(j = 0; (p = str.find(",")) != str.npos; ++j){
	        data.push_back(str.substr(0, p));
	
	        //strの中身は", "の2文字を飛ばす
	        str = str.substr(p+2);
	    }
	    data.push_back(str);
	    ++i;
	}
}

void FileStream::load(string filename, vector<vector<string>>& data){
	file = ifstream(filename);
	if(file.fail()){
		printfDx("%s load error.", filename);
		return;
	}
	vector<string> inner;
	
	i = 0;
	while(getline(file, str)){
	    //コメント箇所は除く
	    if((p = str.find("//")) != str.npos) continue;
	    vector<string> inner;
	
	    //コンマがあるかを探し、そこまでをvaluesに格納
	    for(j = 0; (p = str.find(",")) != str.npos; ++j){
	        inner.push_back(str.substr(0, p));
	
	        //strの中身は", "の2文字を飛ばす
	        str = str.substr(p+2);
	    }
	    inner.push_back(str);
	    data.push_back(inner);
	    ++i;
	}
}