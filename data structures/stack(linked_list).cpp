#include <iostream>
using namespace std;

typedef struct link
{
    int element;
    link* next;
}Link;


Link* create_link1 (int it, Link* nextval)
{
    Link* n = (Link*) malloc (sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

Link* create_link2 (Link* nextval)
{
    Link* n = (Link*) malloc (sizeof(Link));
    n->next = nextval;
    return  n;
}


typedef struct stack
{
    Link* top;
    int size;
}Stack;

Stack* create_stack()
    {
        Stack* s = (Stack*) malloc (sizeof(Stack));
        s->top = NULL;
        s->size = 0;
        return s;
    }

void push (Stack* s, int it)
{
    s->top = create_link1(it, s->top);
    s->size++;
}

int pop (Stack* s)
{
    if (s->top == NULL)
    {
        cout << "Error" << "\n";
    }
    int it = s->top->element;
    s->top = s->top->next;
    s->size--;
    return it;
}









int main()
{
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; i++)
    {
        string operacao;
        int num = 0;
        Stack* s;
        s = create_stack();
        while (operacao != "end")
        {
            cin >> operacao;
            if (operacao != "end")
            {
                cin >> num;
                if (operacao=="push")
                {
                    push(s,num);
                } else if (operacao=="pop")
                {
                    int contador = 0;
                    for (int i = 0; i<num; i++)
                    {
                        contador += pop(s);
                    }
                    cout << contador << "\n";
                }
            }
        };
    }
    return 0;
}