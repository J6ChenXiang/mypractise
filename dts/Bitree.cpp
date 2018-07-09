#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct Bitree
{
    Bitree * lchild;
    Bitree * rchild;
    int val;
    Bitree(int tag) : val(tag),lchild(NULL),rchild(NULL)
    {

    }
} *pBitree,MyBitree;

MyBitree * initBTree(int elements[],int size)
{
    if(size < 1)
    {
        return NULL;
    }
    
    MyBitree **nodes = new MyBitree *[size];

    for(int i=0;i<size;i++)
    {
        if(elements[i] == 0)
        {
            nodes[i] = NULL;
        }
        else
        {
            nodes[i] = new MyBitree(elements[i]);
        }
    }
    queue<pBitree> nodequeue;
    nodequeue.push(nodes[0]);

    MyBitree *node;
    int index = 1;
    while(index < size)
    {
        node = nodequeue.front();
        nodequeue.pop();
        nodequeue.push(nodes[index++]);
        node->lchild = nodequeue.back();
        nodequeue.push(nodes[index++]);
        node->rchild = nodequeue.back();
    }

    return nodes[0];
}

void preOrder(MyBitree *root,vector<int> &result)
{
    if(root)
    {
        result.push_back(root->val);
        preOrder(root->lchild,result);
        preOrder(root->rchild,result);
    }
    else
    {
        return ;
    }
}

void traverse(vector<int> nums)
{
    vector<int> :: size_type size =  nums.size();
    for(size_t i = 0; i< size; i++)
    {
        cout << nums[i] << ' ';
    }

    cout << endl;
}

int main()
{
    int nums[] = {1,2,3,4,0,5,6,0,7};
    MyBitree * root = initBTree(nums,9);
    vector<int> preresult;
    preOrder(root,preresult);
    
    cout << "前序遍历的结果: " << endl;

    traverse(preresult);
    
    return 0;
}
