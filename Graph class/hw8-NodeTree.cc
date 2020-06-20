//I understand that the final exam for this class is on December 4 and 6 in class.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node;

class Link {
public:
  Link(Node* n1, Node* n2) : node1(n1), node2(n2) {};
  Node* node1;
  Node* node2;
};

class Node {
public:
  Node(int n) : id(n) {};
  Node() : id(0) {};
  void MarkAllConnected(vector<int>& connected) {
    if (mark != 0) return;
    connected.push_back(id);
    mark = 1;
    for (Link* k : links) {
      if (k->node1 == this) {
	k->node2->MarkAllConnected(connected);
      } else {
        k->node1->MarkAllConnected(connected);
      }
    }
  };

  void PrintNodesAtDist(int d) {
    cout << "Nodes at distance " << d << endl;
    queue<Node*> q;
    mark = 0;
    q.push(this);
    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();
      if (curr->mark == d) {
	cout << curr->id << " ";
      } else if (curr->mark < d) {
	for (Link* k : curr->links) {
	  Node* other = k->node1;
	  if (other == curr) {
	    other = k->node2;
	  }
	  if (other->mark < 0) {
	    other->mark = curr->mark + 1;
	    q.push(other);
	  }
	}
      }
    }
    cout << endl;
  };

 bool isOdd(int n){
   if((n%2)==0){
     return false;
   } else {
     return true;
   }
 };

// Tests for an odd cycle within the graph
// Starting from P1, must have an odd # of links back to P1

  bool hasOddCycle(){
    queue<Node*> q;
    mark = 1;
    Node* first = this;
    q.push(this);
    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();
	    for (Link* k : curr->links) {
	        Node* next = k->node1;
	        if (next == curr) {
	           next = k->node2;
	        }
          if ((next == first) && (isOdd(curr->mark))){ //if we have an odd cycle return true
             return true;
          } else if (next->mark < 0) { //if next val hasnt been marked
	           next->mark = curr->mark + 1;
	           q.push(next);
	        }
	     }
    }
    return false;
  };

  int color; //0 and 1
  int id;
  int mark;
  vector<Link*> links;
};

#define NUM_NODES 32

class Graph {
public:
  Graph() {
    for (int i = 0; i < NUM_NODES; i++) {
      nodes[i].id = i;
    }
  };
  void AddLink(int n1, int n2) {
    Link* ptr = new Link(&(nodes[n1]), &(nodes[n2]));
    nodes[n1].links.push_back(ptr);
    nodes[n2].links.push_back(ptr);
  };

  void FindConnectedComponents() {
    for (int i = 0; i < NUM_NODES; i++) {
      nodes[i].mark = 0;
    }
    for (int i = 0; i < NUM_NODES; i++) {
      vector<int> connected;
      nodes[i].MarkAllConnected(connected);
      if (connected.size() > 1) {
	for (int i : connected) {
	  cout << i << " ";
	}
	cout << endl;
      }
    }
  };

  void PrintNodesAtDist(int d, int ind) {
    for (int i = 0; i < NUM_NODES; i++) {
      nodes[i].mark = -1;
    }
    nodes[ind].PrintNodesAtDist(d);
  };


  // Tests whether the tree is bipartite
  // No two "colors" can be touching within the tree

  bool TwoColorable(){
    for (int i = 0; i < NUM_NODES; i++) {
      nodes[i].mark = -1;
    }
    for( int i = 0; i < NUM_NODES; i++) {
      if(nodes[i].hasOddCycle()){
        return false;
      }
    }
    return true;
  };

  Node nodes[NUM_NODES];
};

int main() {
  Graph G;

  G.AddLink(1, 5);
  G.AddLink(5, 8);
  G.AddLink(2, 8);
  G.AddLink(1, 2);
  G.AddLink(8, 12);


  if (G.TwoColorable()) {
    cout << "Is Two Colorable" << endl;
  } else {
    cout << "Not Two Colorable" << endl;
  }

  Graph H;

  H.AddLink(13, 14);
  H.AddLink(14, 15);
  H.AddLink(16, 15);
  H.AddLink(16, 17);
  H.AddLink(13, 17);

  if (H.TwoColorable()) {
    cout << "Is Two Colorable" << endl;
  } else {
    cout << "Not Two Colorable" << endl;
  }

  return 0;
}

/*
Is Two Colorable
Not Two Colorable
*/
