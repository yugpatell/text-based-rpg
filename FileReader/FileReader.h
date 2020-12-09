#ifndef __FILE_READER__
#define __FILE_READER__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FileReader{
  public:
    vector<string> rarities;
    FileReader(){};
    FileReader(string fileName){
      string word;
      ifstream file(fileName);
      if (file.is_open()){
        while (file >> word){
          rarities.push_back(word);
          file.get(); //gets the newline Character
        }
        file.close();
      } else {
        cout << "Unable to open file" << endl;
       }
    }
    int size() const {
        return rarities.size();
    }

};

#endif //__FILE_READER__
