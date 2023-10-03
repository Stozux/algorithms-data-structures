#include <iostream>
using namespace std;

typedef struct link
{
    int element;
    link* next;
}Link;


Link* create_link1(int it, Link* nextval)
{
    Link* n = (Link*) malloc (sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

Link* create_link2(Link* nextval)
{
    Link* n = (Link*) malloc (sizeof(Link));
    n->next = nextval;
    return n;
}

typedef struct linkedlist
{
    Link* head;
    Link* tail;
    Link* cur;
    int cnt;
}List;

List *create_list()
{
    List* I = (List*) malloc (sizeof(List));
    I->cur = I->tail = I->head = create_link2(NULL);
    I->cnt = 0;
    return I;
}


void insert(List* I, int it)
{
    I->cur->next = create_link1(it, I->cur->next);
    if (I->tail == I->cur)
    {
        I->tail = I->cur->next;
    }
    I->cnt++;
}

void moveToStart(List* I)
{
    I->cur = I->head;
}

void moveToEnd(List* I)
{
    I->cur = I->head;
}

void prev(List* I)
{
    if (I->cur == I->head)
    {
        return;
    }
    Link* temp = (Link*) malloc (sizeof(Link));
    temp = I->head;
    while (temp->next != I->cur)
    {
        temp = temp->next;
    }
    I->cur = temp;
}

void next(List* I)
{
    if (I->cur != I->tail)
    {
        I->cur = I->cur->next;
    }
}

int remove (List* I)
{
    if (I->cur->next == NULL)
    {
        return NULL;
    }
    int it = I->cur->next->element;
    if (I->tail == I->cur->next)
    {
        I->tail = I->cur;
    }
    I->cur->next = I->cur->next->next;
    I->cnt--;
    return it;
}



int main()
{
    int casos;
    cin >> casos;
    for (int i = 0 ; i < casos; i++)
    {
        List* l;
        l = create_list();
        int op;
        cin >> op;
        for (int i = 0; i < op; i++)
        {
            string operacao;
            int num;
            cin >> operacao;
            if (operacao == "insert" || operacao == "count")
            {
            cin >> num;
            
                if (operacao == "insert")
                {
                    insert(l,num);
                }  else if (operacao == "count")
                {
                    int contador = 0;
                    Link* posicao = l->cur;
                    moveToStart(l);
                    while (l->cur->next != NULL)
                    {
                        if (l->cur->next->element == num)
                        {
                            contador += 1;
                        }
                        next(l);
                    }
                    l->cur = posicao;
                    cout << contador << "\n";
                } 
            } else
            {
                if (operacao == "remove")
                {
                    remove(l);
                }else if (operacao == "next")
                {
                    next(l);
                } else if(operacao == "prev")
                {
                    prev(l);
                }
            }
        }
    }    
}


