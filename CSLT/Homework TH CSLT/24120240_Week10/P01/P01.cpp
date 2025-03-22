// #include <iostream>  
// #include <fstream>  

// struct Node {
//     int key;
//     Node* next;
// };

// void addLast(Node*& head, Node*& tail, int x) {
//     Node* newNode = new Node;
//     newNode->key = x;
//     newNode->next = nullptr;

//     if (head == nullptr) {
//         head = tail = newNode;
//     }
//     else {
//         tail->next = newNode;
//         tail = newNode;
//     }
// }

// void removeAllX(Node*& head, Node*& tail, int x) {
//     Node* current = head;
//     Node* prev = nullptr;

//     while (current != nullptr) {
//         if (current->key == x) {
//             Node* nodeToDelete = current;
//             if (current == head) {
//                 // Removing the head node  
//                 head = head->next;
//                 current = head;
//                 if (head == nullptr) {
//                     // List is now empty  
//                     tail = nullptr;
//                 }
//             }
//             else {
//                 // Removing node in the middle or end  
//                 prev->next = current->next;
//                 if (current == tail) {
//                     // Updating tail if we deleted the last node  
//                     tail = prev;
//                 }
//                 current = current->next;
//             }
//             delete nodeToDelete;
//         }
//         else {
//             // Move to the next node  
//             prev = current;
//             current = current->next;
//         }
//     }
// }

// // Prints the linked list  
// void printList(Node* head) {
//     Node* current = head;
//     while (current != nullptr) {
//         std::cout << current->key << " ";
//         current = current->next;
//     }
//     std::cout << "\n";
// }

// // Deletes all nodes in the linked list and frees memory  
// void cleanUp(Node*& head) {
//     Node* current = head;
//     while (current != nullptr) {
//         Node* nodeToDelete = current;
//         current = current->next;
//         delete nodeToDelete;
//     }
//     head = nullptr;
// }

// int main() {
//     int x;
//     Node* head = nullptr;
//     Node* tail = nullptr;

//     std::ifstream fileInput("input.txt");
//     if (!fileInput.is_open()) {
//         std::cout << "Can't open file input.txt\n";
//         return 0;
//     }

//     while (true) {
//         fileInput >> x;
//         addLast(head, tail, x);
//         if (x == 0) break;
//     } 
//     int removeValue;
//     fileInput >> removeValue;
//     fileInput.close();
//     printList(head);
//     removeAllX(head, tail, removeValue);

//     std::cout << "Removed " << removeValue << " linked list: ";
//     printList(head);
//     std::ofstream fileOutput("output.txt");
//     if (fileOutput.is_open()) {
//         Node* current = head;
//         while (current != nullptr) {
//             fileOutput << current->key << " ";
//             current = current->next;
//         }
//         fileOutput.close();
//     }
//     else {
//         std::cout << "Can't open file output.txt\n";
//     }

//     // Clean up the linked list to free memory  
//     cleanUp(head);

//     return 0;
// }







//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//struct Node{
//       int val;
//       Node* child;
//};
//
//signed main(){
//       Node* head = nullptr;
//       Node* tail = nullptr;
//       ifstream inFile("input.txt");
//       while (1){
//              int x;
//              inFile >> x;
//              if (!x) break;
//              if (head == nullptr){
//                  head = new Node;
//                  head->val = x;
//                  head->child = nullptr;
//                  tail = head;
//              }
//              else{
//                  Node* tmp = new Node;
//                  tmp->val = x;
//                  tmp->child = nullptr;
//                  tail->child = tmp;
//              }
//       }
//
//       inFile.close();
//
//       cout << "Please enter number x: ";
//       int x;
//       cin >> x;
//       while (head != nullptr && head->val == x){
//              Node* tmp = head;
//              head = head->child;
//              delete tmp;
//       }
//       Node* cur = head;
//       while (cur != nullptr){
//              if (cur->val){
//                  
//              }
//       }
//       
//       ofstream outFile("output.txt");
//       for (;head != nullptr; head = head->child){
//            cout << head->val << " ? ";
//            outFile << head->val << " ";
//       }
//       outFile.close();
//}

#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* child;
	Node* par;
};

int sz(Node*& head, Node*& tail) {
	int cnt = 0;
	Node* tmp = head;
	while (tmp != nullptr) {
		++cnt;
		tmp = tmp->child;
	}
	return cnt;
}

void outList(Node*& head, Node*& tail) {
	cout << "Linked list:\n";
	for (Node* tmp = head; tmp != nullptr; tmp = tmp->child) {
		cout << tmp->val << " ";
	 }
	cout << "\n";
}

void addLast(Node* &head, Node* &tail, int val) {
    // first node
	if (head == nullptr) {
		head = new Node;
		head->val = val;
		head->child = nullptr;
		head->par = nullptr;
		tail = head;
		return;
	}
	tail->child = new Node;
	tail->child->par = tail;
	tail = tail->child;
	tail->val = val;
	tail->child = nullptr;
}

void addFirst(Node*& head, Node*& tail, int val) {
	Node* tmp = new Node;
	tmp->val = val;
	tmp->par = nullptr;
	tmp->child = head;
	if (head != nullptr) head->par = tmp;
	head = tmp;
	if (tail == nullptr) {
		tail = head;
	}
}

void removeX(Node*& head, Node*& tail, int X) {
	Node* head2 = nullptr;
	Node* tail2 = nullptr;
	for (Node* tmp = head; tmp != nullptr; tmp = tmp->child) {
		if (tmp->val != X) {
			addLast(head2, tail2, tmp->val);
		}
	}
	// free the memory
	while (head != nullptr) {
		Node* tmp = head;
		head = head->child;
		delete tmp;
	}
	head = head2;
	tail = tail2;
}

bool isCycle(Node* head) {
	if (!head || !head->child) return false;

	Node* slow = head;
	Node* fast = head;

	while (fast && fast->child){
		slow = slow->child;
		fast = fast->child->child;
		if (slow == fast) return true;
	}
	return false;
}

signed main() {
	Node* head = nullptr;
	Node* tail = nullptr;
    // head, tail lan luot la thang dau tien va cuoi cung "co' value"
	for (int i = 1; i <= 8; i += 2) {
		addLast(head, tail, i);
	}
	for (int i = 9; i <= 15; i += 2) {
		addFirst(head, tail, i);
	}
    
	int x;
	cout << "Nhap x de xoa: ";
	cin >> x;

	removeX(head, tail, x);
	outList(head, tail);

	while (head != nullptr) {
		Node* tmp = head;
		head = head->child;
		delete tmp;
	}

}