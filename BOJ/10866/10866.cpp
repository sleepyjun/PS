#include<cstdio>
#include<cstring>

class Deque
{
private:
    int Size;
    struct Deq
    {
        int data;
        Deq* prev;
        Deq* next;

        Deq()
        {prev = next = NULL;}

        Deq(int N) : data(N)
        {prev = next = NULL;}
    };
    Deq* fr;
    Deq* la;
public:
    Deque()
    {Size = 0; fr = la = NULL;}

    void push_front(int X)
    {
        Deq* new_node = new Deq(X);
        if(Size)
        {
            fr->prev = new_node;
            new_node->next = fr;
            fr = fr->prev;
        }
        else
        {
            fr = la = new_node;
            fr->next = la;
            la->prev = fr;
        }
        Size++;
    }
    void push_back(int X)
    {
        Deq* new_node = new Deq(X);
        if(Size)
        {
            la->next = new_node;
            new_node->prev = la;
            la = la->next;
        }
        else
        {
            fr = la = new_node;
            fr->next = la;
            la->prev = fr;
        }
        Size++;
    }
    void pop_front()
    {
        if(Size)
        {
            Deq* temp = fr;
            printf("%d\n",fr->data);
            fr = fr->next;
            delete temp;
            Size--;

            if(fr == NULL) la = NULL;
        }
        else
            printf("-1\n");

    }
    void pop_back()
    {
        if(Size)
        {
            Deq* temp = la;
            printf("%d\n",la->data);
            la = la->prev;
            delete temp;
            Size--;

            if(la == NULL) fr = NULL;
        }
        else
            printf("-1\n");
    }
    void size()
    {
        printf("%d\n",Size);
    }
    void empty()
    {
        if(Size)
            printf("0\n");
        else
            printf("1\n");
    }
    void front()
    {
        if(Size)
            printf("%d\n",fr->data);
        else
            printf("-1\n");
    }
    void back()
    {
        if(Size)
            printf("%d\n",la->data);
        else
            printf("-1\n");
    }
};
int main()
{
    Deque D;
    char str[11] = "\0";
    int N;
    int temp;
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
    {
        scanf("%s",str);
        if(!strcmp(str,"push_front"))
        {
            scanf("%d",&temp);
            D.push_front(temp);
        }
        else if(!strcmp(str,"push_back"))
        {
            scanf("%d",&temp);
            D.push_back(temp);
        }
        else if(!strcmp(str,"pop_front"))
            D.pop_front();
        else if(!strcmp(str,"pop_back"))
            D.pop_back();
        else if(!strcmp(str,"size"))
            D.size();
        else if(!strcmp(str,"empty"))
            D.empty();
        else if(!strcmp(str,"front"))
            D.front();
        else if(!strcmp(str,"back"))
            D.back();

    }
}
