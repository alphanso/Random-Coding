#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstdio>

using namespace std;

class node
{
public:
	int length;
	node* right;
	node* left;
	string data;
	node(node* l, node* r, string d, int a)
	{
		right = r;
		left = l;
		data = d;
		length = a;
		//cout << d << " " << length << " " << a << endl;
	}

	node(node* l, node* r, string d)
	{
		right = r;
		left = l;
		data = d;
	}
	
	bool isLeaf()
	{
		if(left == NULL && right == NULL) return true;
		else return false;
	}
};

vector<node*> lst;
set<string> used;

bool isNull(node* X)
{
	return X==NULL;
}

bool equals(node* tree1, node* tree2)
{
	if(tree1 == NULL && tree2 == NULL) return true;
	if(tree1 == NULL || tree2 == NULL) return false;
	//cout << tree2->data << endl;
	//cout <<"Working till here\n" <<endl;
	//cout << tree1->data << endl;
	if(tree1->data != tree2->data) return false;
	return (equals(tree1->left, tree2->left) && equals(tree1->right, tree2->right));
}

string PrintTree(node* n){
	string ans = "";
	if(n == NULL) return "";
	else if(n->isLeaf()) return ans += n->data;
	
	ans += "(" + PrintTree(n->left) + "->" + PrintTree(n->right) + ")";
	//return ans;
	//cout << n->left->data <<" " <<n->right->data << endl;
	return ans;
}

string format(string s)
{
	string str="";
	for(int i=0; i<(int)s.size(); i++)
		{
			if(s[i] == '(') str += s[i];
			else if(s[i] == ')') str += s[i];
			else if(s[i] == '-');
			else if(s[i] == '>');
			else if('A' <= s[i] && s[i] <= 'Z') str += s[i];
			else if('a' <= s[i] && s[i] <= 'z') str += (char)(s[i] + ('A' - 'a'));
			else cerr << "Error: char not recognized " << s[i] << endl;
		}
	//cout << str << endl;
	return str;
}

node* constructTree(string str)
{
	//cout << "string->" << str << endl;
	node *left, *right, *ret;
	string s = "";
	if(str[0] == '(')
		{
			s = str.substr(1);
			//cout << s << endl;
			left = constructTree(s);
			//cout << 1 + (left->length) << endl;
			s = str.substr(1+left->length);
			//cout << s << endl;
			right = constructTree(s);
			//cout << left->length << " " << right->length << endl;
			node tree(left, right, "", left->length + right->length+2);
			ret = new node(tree);
		}
	else if(str[0] <= 'Z' && 'A' <= str[0])
		{
			s += str[0];
			node tree(NULL, NULL, s, 1);
			ret = new node(tree);
		}
	//cout << ret->data << endl;
	return ret;
}

node* falsetree;

bool search(node* tree)
{
	for(int i=0; i<(int)lst.size(); i++)
		if(equals(lst[i], tree)) return true;
	return false;
}

vector<node*> searchLeft(node* tree)
{
	vector<node*> ret;
	for(int i=0; i<(int)lst.size(); i++)
		if(equals(lst[i]->left, tree) && !search(lst[i]->right)) ret.push_back(lst[i]->right);
	return ret;
}

vector<node*> searchRight(node* tree)
{
	vector<node*> ret;
	for(int i=0; i<(int)lst.size(); i++)
		if(equals(lst[i]->right, tree)) ret.push_back(lst[i]->left);
	return ret;
}

void retList(node* tree)
{
	string s, tmp;
	if(tree == NULL) return;
	if(tree->isLeaf())
		{
			s = PrintTree(tree);
			tmp = "(" + s + "F)";
			if (search(falsetree))
				{
					lst.push_back(tree);
					return;
				}
			if(s == "F") return;
			node* t = constructTree(tmp);
			lst.push_back(t);
			return;
		}
	lst.push_back(tree->left);
	retList(tree->right);
	return;
}

// checks if tree is in the form of Axiom 1 : (A->(B->A))

bool A1(node* tree)
{
	if(tree == NULL) return false;
	if(tree->left == NULL) return false;
	if(tree->right == NULL) return false;
	if(tree->right->left == NULL || tree->right->right == NULL) return false;
	if(equals(tree->left, tree->right->right)) return true;
	else return false;
}

// checks if tree is in the form of Axiom 2 : ((A->(B->C))->((A->B)->(A->C)))

bool A2(node* tree)
{
	if(isNull(tree) || isNull(tree->left) || isNull(tree->right) || isNull(tree->left->right)) return false;
	if(isNull(tree->right->left) || isNull(tree->right->right)) return false;
	bool ret;
	ret = equals(tree->left->left,tree->right->left->left) and equals(tree->right->right->left,tree->left->left);
	ret = ret and equals(tree->left->right->left,tree->right->left->right);
	ret = ret and equals(tree->left->right->right,tree->right->right->right);
	return ret;
}

// checks if tree is in the form of Axiom 3 : (((A->F)->F)->A)

bool A3(node* tree)
{
	if(tree == NULL) return false;
	if(tree->left == NULL) return false;
	if(tree->right == NULL) return false;
	if(tree->left->left == NULL) return false;
	//cout << "working\n" << endl;
	if(!equals(tree->left->right, falsetree)) return false;
	if(equals(tree->left->left->right, falsetree) && equals(tree->left->left->left, tree->right)) return true;
	else return false;
}

// to prove the statement
//   A->B
//   look for B or A->F
//   look for A->(X->B) and A->X

// got the statement using Axiom 1

bool viaA1(node* stat)
{
	node* A = stat->left;
	node* B = stat->right;
	node AF(A, falsetree, "");
	node* r;
	r = new node(AF);
	return search(B) || search(r);
}

bool viaA2(node* stat)
{
	node* A = stat->left;
	node* B = stat->right;
	vector<node*> leftList = searchLeft(A);
	for(int i=0; i<(int)leftList.size(); i++)
		{
			node tmp(leftList[i], B, "");
			node fin(A, &tmp, "");
			node* r;
			r = new node(fin);
			if(search(r)) return true;
		}
	return false;
}

bool Prove(node* stat)
{
	string str = PrintTree(stat);
	cout << str << ":\n";
	used.insert(str);
	if(search(stat) || viaA1(stat) || viaA2(stat)) return true;
	
	if(A1(stat) || A2(stat) || A3(stat)) return true;
	
	//list of all statements that derive required statement
	
	vector<node*> derStatList = searchRight(stat);
	for(int i=0; i<(int)derStatList.size(); i++)
		{
			str = PrintTree(derStatList[i]);
			if(used.find(str) != used.end()) continue;
			if(Prove(derStatList[i])) return true;
		}
	return false;
}

// iterate

void PrintLst()
{
	string strLst="";
	for(int i=0; i<(int)lst.size(); i++)
		strLst += (PrintTree(lst[i])+" ");
	cout << strLst << endl;
}

vector<node*> extend(vector<node*> a, vector<node*> b)
{
	for(int i=0; i<(int)b.size(); i++)
		a.push_back(b[i]);
	return a;
}

bool MP()
{
	vector<node*> ls;
	for(int i=0; i<(int)lst.size(); i++)
		ls = extend(ls, searchLeft(lst[i]));
	lst = extend(lst, ls);
	if(ls.size()==0) return false;
	return true;
}

int main()
{
	falsetree = constructTree("F");
	string s;
	cin >> s;
	s = format(s);
	node* tr = constructTree(s);
	cout << PrintTree(tr) << " " << A1(tr) << " " << A2(tr) << " " << A3(tr) << endl;
	retList(tr);
	PrintLst();
	while(MP()) PrintLst();
	bool res = Prove(falsetree);
	if(res) cout << "Theorem is true" << endl;
	else cout << "Theorem is false" << endl;
	return 0;
}
