#ifndef __FILE_READER__
#define __FILE_READER__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FileReader{
  private:
    vector<string> rarities;
  public:
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

};

#endif //__FILE_READER__

//while (file >> word){
//  rarities.push(word);
//}
