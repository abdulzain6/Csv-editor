#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct node_tree{
	int data;
	node_tree *left;
	node_tree *right;
};

class tree{
	public:
		node_tree *root;
		tree() : root(NULL) {}
		
		node_tree* insert_helper(node_tree *temp , int d)
		{
			if (temp == NULL)
			{
				temp = new node_tree;
				temp->data = d;
				temp->left = NULL;
				temp->right = NULL;
				if(root == NULL)
				{
					root = temp;
				}
			}
			else if(temp->data > d)
			{
				temp->left = insert_helper(temp->left , d);
			}
			else
			{
				temp->right = insert_helper(temp->right , d);
			}
			
			return temp;
		}
    void insert (int data){
      insert_helper(root, data);
    }
    int find_largest_helper (node_tree* temp){
      if (temp->right == NULL){
        return temp->data;
      }
      else{
        find_largest_helper(temp->right);
      }

    }
    int max(){
      return find_largest_helper(root);
    }
    int find_smallest_helper (node_tree* temp){
      if (temp->left == NULL){
        return temp->data;
      }
      else{
        find_smallest_helper(temp->left);
      }

    }
    int min(){
      return find_smallest_helper(root);
    }

};