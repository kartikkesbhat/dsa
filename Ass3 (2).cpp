#include <iostream>
using namespace std;

struct node
{
    char title[20];
    int node_count;
    struct node *child[10];
} * base;

class book
{
public:
    book()
    {
        base = NULL;
    }

    void creat()
    {
        int chapter, section, subsection, i, j, k;
        base = new node();

        cout << "The name of book is => ";
        // cin >> base->title;
        cin.getline(base->title,20);

        cout << "Enter the number of chapter => ";
        cin >> chapter;
        base->node_count = chapter;

        for (i = 0; i < chapter; i++)
        {
            base->child[i] = new node;

            cout << "Enter the name of chapter " << i + 1 << " => ";
            cin >> base->child[i]->title;

            cout << "Enter the number of section => ";
            cin >> section;
            base->child[i]->node_count = section;

            for (j = 0; j < section; j++)
            {
                base->child[i]->child[j] = new node;

                cout << "Enter the name of section " << j + 1 << "=> ";
                cin >> base->child[i]->child[j]->title;

                cout << "Enter the number of sub-section => ";
                cin >> subsection;
                base->child[i]->child[j]->node_count = subsection;

                for (k = 0; k < subsection; k++)
                {
                    base->child[i]->child[j]->child[k] = new node;

                    cout << "Enter the name of sub-section " << k + 1 << "=> ";
                    cin >> base->child[i]->child[j]->child[k]->title;
                }
            }
        }
    }

    void print(node *r)
    {
        int i, j, k, chapter;
        if (r != NULL)
        {
            cout << "\nThe book name is " << r->title << endl;

            chapter = r->node_count;

            for (i = 0; i < chapter; i++)
            {
                cout << "\nChapter " << i + 1 << endl;
                cout << "  " << r->child[i]->title;
                cout << "\n\tSection";
                for (j = 0; j < r->child[i]->node_count; j++)
                {
                    cout << "\n\t  " << r->child[i]->child[j]->title;
                    cout << "\n\t\tsubsection";
                    for (k = 0; k < r->child[i]->child[j]->node_count; k++)
                    {
                        cout << "\n\t\t   " << r->child[i]->child[j]->child[k]->title;
                    }
                }
            };
        }
    }
};

int main()
{
    book obj;
    obj.creat();

    cout << "---------------------" << endl;
    obj.print(base);
}




void create(){
    base=new node();
    cout<<"enter the name of the book: "<<endl;
    cin>>base->title;

    cout<<"enter the no of chapters: "<<endl;
    cin>>chapter;

    for(i=0;i<chapter;i++){
        base->node_count=chapter;
        base->child[i]=new node();
        cout<<"enter the name of the chapters: "
        cin>>base->child[i]->title;

        cout<<"enter the no of sections: ";
        base->child[i]->child[j]=new node();
        base->child[i]->node_count=section;
        cin>>section;
        for(j=0;j<section;j++){
            cout<<"enter the name of section: "<<endl;
            cin>>base->child[i]->child[j]->title;

            cout<<"\t\t";

            cout<<"enter the no of subsections: ";
            base->child[i]->child[j]->node_count=subsection;
            cin>>subsection;
            cout<<"\t";
            cout<<'\t';

            for(k=0;k<subsection;k++){
                cout<<"enter the name of subsections: ";
                cin>>base->child[i]->child[j]->child[k]->title;

            }
        }
    }
}
void display(node *root){
    cout<<"enter the name of the book: "<<endl;
    cout>>r->title;"<<endl;
    cout<<endl;
    chapter=r->node_count;
    for(i=o;i<chapter;i++){
        cout<<"the name of your chapter is: ";
        cout<<r->child[i]->title;


        for(j=0;j<r->child[i]->node_count;i++){
            cout<<"the of the section is: ";
            cout<<r->child[i]->child[j]->title;

            for(k=0;k<r->child[i]->child[j]->node_count;i++){
                cout<<"the name of your subsections is: ";
                cout<<
            }
        }
    }
}
int main(){
    book obj;
    int opt;
    cout<<"enter yor option: ";
    cin>>opt;
    do{
    switch(opt){
        case 1:
        obj.create();
        break;


        case 2:
        obj.display(base)
        break;

        case 3:
        default
        }while(opt!=4)
    }
}