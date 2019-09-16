#include<iostream>
using namespace std;

class tree
{
private:
    char data;
    tree* left;
    tree* right;
public:
    static tree* Find;

    tree(char ch) : data(ch)
    {
        left = NULL;
        right = NULL;
    }

    void SetLeft(char ch)
    {
        if(ch != '.')
            this->left = new tree(ch);
    }
    void SetRight(char ch)
    {
        if(ch != '.')
            this->right = new tree(ch);
    }

    tree* GetLeft()
    {
        return this->left;
    }
    tree* GetRight()
    {
        return this->right;
    }
    tree* Get()
    {
        return Find;
    }

    void Search(char ch);
    void preorder();
    void inorder();
    void postorder();


};
tree* tree::Find;

void tree::Search(char ch)
{
    if(this->data == ch)
    {
        Find = this;
        return;
    }
    else
    {
        if(GetLeft() != NULL) GetLeft()->Search(ch);
        if(GetRight() != NULL) GetRight()->Search(ch);
    }
}
void tree::preorder()
{
    cout << this->data;
    if(GetLeft() != NULL) GetLeft()->preorder();
    if(GetRight() != NULL) GetRight()->preorder();
}
void tree::inorder()
{
    if(GetLeft() != NULL) GetLeft()->inorder();
    cout << this->data;
    if(GetRight() != NULL) GetRight()->inorder();
}
void tree::postorder()
{
    if(GetLeft() != NULL) GetLeft()->postorder();
    if(GetRight() != NULL) GetRight()->postorder();
    cout << this->data;
}

int main()
{
    int N;
    cin >> N;
    char root, left, right;
    cin >> root >> left >> right;

    tree T(root);
    T.SetLeft(left);
    T.SetRight(right);

    for(int i = 1; i < N; ++i)
    {
        cin >> root >> left >> right;

        T.Search(root);
        T.Get()->SetLeft(left);
        T.Get()->SetRight(right);
    }

    T.preorder();
    cout<<endl;
    T.inorder();
    cout<<endl;
    T.postorder();

    return 0;
}
