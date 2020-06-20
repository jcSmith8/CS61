#include <iostream>
#include <vector>

using namespace std;

#define TABLE_SIZE 16

struct Student {
  string name;
  int score;
};

class Hashtable {
public:
  Hashtable() {};

  // (a) [2 points]
  // Hash function from string to int. Sum the ASCII values of all the
  // characters in the string, and return (Sum % TABLE_SIZE).
  int Hash(string s) {
    int total = 0;
    for(int i=0; s[i] != '\0'; i++){
      total += s[i];
    }
    return total%TABLE_SIZE;
  };

  // (b) [2 points]
  // Insert Student s into the Hashtable. First find the key using Hash of the
  // Student's name, and then insert it into the vector at that entry.
  void Insert(Student s) {
    int ind = Hash(s.name);
    data[ind].push_back(s);
  };

  // (c) [3 points]
  // Find Student with the given name. If found, return pointer to the Student.
  // If not found, return nullptr.
  Student* Find(string name) {
    Student* ptr;
    int ind = Hash(name);
    bool found = false;
    for(int i=0; i<(data[ind]).size();i++){
      if((data[ind])[i].name == name){
        ptr = &(data[ind])[i];
        found = true;
        break;
      }
    }
    if(found==false){
      ptr = nullptr;
    }
    return ptr;
  };

  // (d) [3 points]
  // Print all entries in the Hashtable. For each entry, print the key,
  // the number of Students stored at that entry, and all the Students
  // (name,score) in the entry.
  void Print(){
    for(int i=0; i<TABLE_SIZE; i++){
      vector<Student> curr = data[i];
      if(curr.size() <= 0){
        cout<< "Entry: "<<i<<" size: 0";
      } else {
        cout<< "Entry: "<<i<<" size: "<<data[i].size();
        for(int j=0; j<(curr.size()); j++){
          cout<<" "<<curr[j].name<<","<<curr[j].score;
        }
      }
      cout<<endl;
    }
  };

private:
  vector<Student> data[TABLE_SIZE];
};

int main() {

  string names[] = { "Alice", "Bob", "Carrie", "Diane", "Ethan", "Frank",
		     "George", "Henry", "Irene", "Joseph", "Kristy", "Liam",
		     "Monica", "Nancy" };

  Hashtable t;
  for (int i = 0; i < 14; i++) {
    Student s = { names[i], rand() % 100 };
    t.Insert(s);
  }
  t.Print();
  cout << endl;

  cout << "Give Diane 10 more points." << endl;
  Student* sptr = t.Find("Diane");
  if (sptr != nullptr) {
    sptr->score = sptr->score + 10;
  }
  t.Print();
  cout << endl;

  sptr = t.Find("Tom");
  if (sptr == nullptr) {
    cout << "Tom not found" << endl;
  } else {
    cout << "Tom found. Score is: " << sptr->score << endl;
  }

  return 0;
}

/*
Sample results:

Entry 0 size 1 Ethan,0
Entry 1 size 1 Diane,29
Entry 2 size 1 Frank,8
Entry 3 size 3 Bob,43 Irene,56 Liam,51
Entry 4 size 0
Entry 5 size 0
Entry 6 size 3 Carrie,62 Henry,56 Kristy,11
Entry 7 size 1 Monica,43
Entry 8 size 0
Entry 9 size 3 George,52 Joseph,19 Nancy,5
Entry 10 size 0
Entry 11 size 0
Entry 12 size 0
Entry 13 size 0
Entry 14 size 1 Alice,33
Entry 15 size 0

Give Diane 10 more points.
Entry 0 size 1 Ethan,0
Entry 1 size 1 Diane,39
Entry 2 size 1 Frank,8
Entry 3 size 3 Bob,43 Irene,56 Liam,51
Entry 4 size 0
Entry 5 size 0
Entry 6 size 3 Carrie,62 Henry,56 Kristy,11
Entry 7 size 1 Monica,43
Entry 8 size 0
Entry 9 size 3 George,52 Joseph,19 Nancy,5
Entry 10 size 0
Entry 11 size 0
Entry 12 size 0
Entry 13 size 0
Entry 14 size 1 Alice,33
Entry 15 size 0

Tom not found
*/
