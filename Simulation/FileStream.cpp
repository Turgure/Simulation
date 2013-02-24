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
	    //�R�����g�ӏ��͏���
	    if((p = str.find("//")) != str.npos) continue;
	    //�R���}�����邩��T���A�����܂ł�values�Ɋi�[
	    for(j = 0; (p = str.find(",")) != str.npos; ++j){
	        data.push_back(str.substr(0, p));
	
	        //str�̒��g��", "��2�������΂�
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
	    //�R�����g�ӏ��͏���
	    if((p = str.find("//")) != str.npos) continue;
	    vector<string> inner;
	
	    //�R���}�����邩��T���A�����܂ł�values�Ɋi�[
	    for(j = 0; (p = str.find(",")) != str.npos; ++j){
	        inner.push_back(str.substr(0, p));
	
	        //str�̒��g��", "��2�������΂�
	        str = str.substr(p+2);
	    }
	    inner.push_back(str);
	    data.push_back(inner);
	    ++i;
	}
}