#include<iostream>
using namespace std;
struct node{
        int data;
        node *left;
        node *right;
        node(int val){
            data =val;
            left=nullptr;
            right=nullptr;
        }
};
