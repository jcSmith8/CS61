#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node;

class Link {
public:
  int distance;
  Node* node1;
  Node* node2;
  Link(int d, Node* n1, Node* n2) : distance(d), node1(n1), node2(n2) {};
};

class Node {
private:
  string city;
  // (a) [8 points] Change links from vector<Link*> to
  // unordered_map<string, Link*>, a map from the name of the other city to
  // Link*.
  // Then change the implementation of AddLink and PrintConnectedCities
  // accordingly.
  // Basically uncomment the following line and comment the line after.
  // unordered_map<string, Link*> links;
  vector<Link*> links;
public:
  Node() : city("") {};
  Node(string str) : city(str) {};
  string GetCity() { return city; };

  // (a) Change this to AddLink(const string& other_city_name, Link* link).
  // Make sure you change the calls to this function in Graph::AddLink.
  void AddLink(Link* link) {
    links.push_back(link);
  };

  // (a) Change this.
  void PrintConnectedCities() {
    for (int i = 0; i < links.size(); i++) {
      if (links[i]->node1 == this) {
	cout << links[i]->node2->city << endl;
      } else {
        cout << links[i]->node1->city << endl;
      }
    }
  };
};

class Graph {
public:
  unordered_map<string, Node> nodes;

  Graph() {
    vector<string> city_names =
      { "San Francisco", "Seattle", "Portland", "Los Angeles", "San Diego",
	"Salt Lake City", "Phoenix", "Denver", "St. Louis", "New Orleans",
	"Houston", "San Antonio", "Dallas", "Austin", "Minneapolis", "Chicago",
	"Las Vegas", "Tucson", "Kansas City", "Nashville", "Charlotte", 
	"Indianapolis", "New York", "Washington", "Philadelphia", "Boston",
	"Miami", "Fort Lauderdale", "Orlando", "Atlanta", "Charleston",
	"Richmond", "Raleigh" };
    for (int i = 0; i < city_names.size(); i++) {
      nodes[city_names[i]] = (Node(city_names[i]));
    }
  };

  void AddLink(string c1, string c2, int d) {
    unordered_map<string, Node>::iterator it1 = nodes.find(c1);
    unordered_map<string, Node>::iterator it2 = nodes.find(c2);
    if ((it1 == nodes.end()) || (it2 == nodes.end())) return;
    Link* link = new Link(d, &((*it1).second), &((*it2).second));
    // (a) Change the calls to Node::AddLink.
    (*it1).second.AddLink(link);
    (*it2).second.AddLink(link);
  };

  // (b) [8 points] Write a RemoveLink function that will remove the link
  // between the two named cities, if such a link exists.
  // Make sure you remove them from both nodes.
  // Make sure you free the space on the memory heap so that
  // there is no memory leak.
  // You may write helper functions in the Node class as you need.
  // Implement it assuming that you have done Question (a).
  void RemoveLink(string c1, string c2);

  // (c) [4 points] Write a destructor for the Graph class, to free
  // all the dynamically allocated memory for all the links.
  // You may write helper functions in the Node class as you need.

  

  void PrintConnectedCities(string city) {
    unordered_map<string, Node>::iterator it = nodes.find(city);
    if (it != nodes.end()) {
      (*it).second.PrintConnectedCities();
    }
  };
};

int main() {
  Graph g;

  g.AddLink("San Diego", "Chicago", 3000);
  g.AddLink("Chicago", "Washington", 500);

  g.PrintConnectedCities("Chicago");

  return 0;
}

