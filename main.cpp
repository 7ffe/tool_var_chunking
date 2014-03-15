#include <iostream>
#include <string>
#include <vector>
#include "neverlost_util.h"

using namespace std;

/*
For your reference:
class NeverLostUtil {
public:
    
    static string readFileContent(const char* filename);
    static void writeFileContent(const char* filename, const string& content_str);


    // chunking
    static void chunkContent(const string& content_str, const bool var, const uint32_t chunksize, vector<string> &chunks);
};

*/

int main(int argc, char** argv) {

	string testdata_filename = "testdata.txt";
	string testdata_content = NeverLostUtil::readFileContent(testdata_filename.c_str());

	vector<string> chunks;

	NeverLostUtil::chunkContent(testdata_content, true, 1*1024, chunks);

	cout<<"chunk sizes: "<<endl;
	string cat_content = "";
	for (int i=0; i<chunks.size(); i++) {
		cout << (i==0?"":", ")<< chunks[i].size();
		cat_content += chunks[i];
	}
	cout<<endl;
	cout<<"chunk number: \t"<<chunks.size()<<endl;
	cout<<"total size: \t" << testdata_content.size()<<endl;
	cout<<"average size: \t " << 1.0 * testdata_content.size() / chunks.size() <<endl;

	if (testdata_content != cat_content) {
		cout<<"ERROR: restored data is not equal to original data."<<endl;
	}else {
		cout<<"Restored data is equal to original data."<<endl;
	}
	
	return 0;
}