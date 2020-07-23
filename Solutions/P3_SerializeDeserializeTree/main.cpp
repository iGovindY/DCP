#include <iostream>

using namespace std;

// Tree Node
class Node
{
public:
    string val;
    Node * left;
    Node * right;
    Node(string val, Node * left = nullptr, Node * right = nullptr);
};

Node::Node(string val, Node * left, Node * right)
{
    this->val = val;
    this->left = left;
    this->right = right;
}

/** Serialize() to serialize a tree with root Node into string */
string serialize(Node * root)
{
    string a;
    if(!root)
    {
        a += "|";
        return a;
    }
    a += root->val;
    a += "|";
    a += serialize(root->left);
    a += serialize(root->right);
    return a;
}
/** Deserialize() to deserialize arg string and return Tree with Node */
Node * deserialize(string &str)
{
    auto pos = str.find("|");
    string curStr = str.substr(0,pos);
    str = str.substr(pos+1);
    if(curStr == "")
    {
        return nullptr;
    }
    Node * newNode = new Node(curStr);
    newNode->left = deserialize(str);
    newNode->right = deserialize(str);
    return newNode;
}
// Utility function to print tree in xml format
void printTree(Node * root, int depth = 0)
{
    int a =0;
    while(a++<depth)
    {
        cout<< "  ";
    }
    if(!root)
    {
        cout<< "</NULL>"<<endl;;
        return;
    }
    cout<< "<"<< root->val << ">" <<endl;
    printTree(root->left,depth+1);
    printTree(root->right,depth+1);
    a = 0;
    while(a++<depth)
    {
        cout<< "  ";
    }
    cout<< "</"<< root->val << ">" <<endl;
}

// Driver function
int main()
{
    Node l("left.left");
    Node a("left",&l);
    Node b("right");
    Node n("root",&a,&b);
    //Node n("c");
    cout<<"Input Tree"<< endl;
    printTree(&n);
    cout<< endl;
    string s = serialize(&n);
    string s1 =s;
    cout << "Serialized: ["<<s << "]" << endl;
    Node * root = deserialize(s);
    cout<<" Tree after deserialization"<< endl;
    printTree(root);
    cout<< endl;
    string s2 = serialize(root);
    cout << "Deserialized Tree serialized again: ["<<s2 << "]" << endl;
    if(s1 != s2)
    {
        cout<< "->>>failed!!";
        return 1;
    }
    cout<< "->>>success!!";
    return 0;
}
