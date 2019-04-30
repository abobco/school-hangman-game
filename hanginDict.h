#pragma once
#include <vector>
#include <string>
#include <fstream>

using namespace std;
#ifndef __HANGINDICT_H__
#define __HANGINDICT_H__

using namespace std;
class hanginDict
{
private:
	vector<string> sDictEASY;
	vector<string> sDictMED;
	vector<string> sDictHARD;
	ifstream iFile;

public:

	hanginDict();

	string selectWord(int difficulty);


};
#endif