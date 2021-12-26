#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

template<typename A , typename B>
class node_dict{
    public:
    A key;
    B value;
    node_dict<A,B>* next = NULL;
    node_dict<A,B>* previous = NULL;
};

template<typename A , typename B>
class dictionary{
  public:
    node_dict<A,B>* head;
    node_dict<A,B>* tail;
    int size = 0;

    dictionary(){
        head = NULL;
        tail = NULL;
    }
    
    void insert (A key , B value){
        size++;
        node_dict<A,B>* temp = new node_dict<A,B>;
        temp->key = key;
        temp->value = value;

        if (head==NULL){
            head = temp;
            tail = temp;
        }
        else{
            temp->previous = tail;
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
        }
    }

    void display(){
        node_dict<A,B>* temp = head;
        while (temp!=NULL){
            if (typeid(temp->key) == typeid(string) && typeid(temp->value) == typeid(string))
                cout << "{\"" << temp->key << "\" : \"" << temp->value << "\"}"<< endl;
            //Quoting the value if its a string
            else if (typeid(temp->key) == typeid(string))
                cout << "{\"" << temp->key << "\" : " << temp->value << "}"<< endl;

            else if (typeid(temp->value) == typeid(string))
                cout << "{" << temp->key << " : \"" << temp->value << "\"}"<< endl;

            else
                cout << "{" << temp->key << " : " << temp->value << "}"<< endl;

            temp=temp->next;
        }
    }
    B getValue (A key){
        node_dict<A,B>* temp = head;
        while (temp!=NULL){
            if (temp->key == key){
                return temp->value;
                break;
            }
            temp=temp->next;
        }
        return 0;
    }
    A getKey (B value){
        node_dict<A,B>* temp = head;
        while (temp!=NULL){
            if (temp->value == value){
                return temp->key;
                break;
            }
            temp=temp->next;
        }
    }  
    bool isKey (A key){
        node_dict<A,B>* temp = head;
        while (temp!=NULL){
            if (temp->key == key){
                return true;
                break;
            }
            temp=temp->next;
        }
        return false;
    } 
    bool isValue (B value){
        node_dict<A,B>* temp = head;
        while (temp!=NULL){
            if (temp->value == value){
                return true;
                break;
            }
            temp=temp->next;
        }
        return false;
    } 
};

