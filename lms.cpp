#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class Library
{
   public:
       char bknm[100],atnm[50],sc[20],sc1[50];
       int q,B,p;
       Library()
       {
           strcpy(bknm,"NO Book Name");
           strcpy(atnm,"No Author Name");
           strcpy(sc,"No Book ID");
           strcpy(sc1,"No Book ID");
           q=0;
           B=0;
           p=0;
       }
          void get();
          void student();
          void pass();
          void librarian();
          void getinput();
          void show(int);
          void bklist(int);
          void modify();
          void see(int);
          int Type(int);
          void issue();
          void check(char[],int,int);
};
void Library::getinput()
{
                    int i;
                    fflush(stdin);
                    cout<<"\n\t\tEnter the details :-\n";
                    cout<<"\n\t\tEnter name of the book : ";
                    cin.getline(bknm,100);
                    for(i=0;bknm[i]!='\0';i++)
                    {
                    if(bknm[i]>='a'&&bknm[i]<='z')
                       bknm[i]-=32;
                    }
                    cout<<"\n\t\tEnter name of the author : ";
                    cin.getline(atnm,50);
                    cout<<"\n\t\tEnter Book's ID : ";
                    cin.getline(sc,20);
                    cout<<"\n\t\tEnter Book's Price : ";
                    cin>>p;

}
void Library::show(int i)
{
    cout<<"\n\t\tBook Name : "<<bknm<<endl;
    cout<<"\n\t\tBook's Author Name : "<<atnm<<endl;
    cout<<"\n\t\tBook's ID : "<<sc<<endl;
    if(i==2)
    {
        cout<<"\n\t\tBook's Price : "<<p<<endl;
    }
}
  void Library::bklist(int i)
  {
                int b,r=0;
                system("cls");
                b=Type(i);
                system("cls");
                ifstream intf("Booksdata.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tFile Not Found.";
                else
                {
                    cout<<"\n\t    ------------ Book List ------------ \n\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(q==0 && i==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n\t\t---------- "<<r<<". ---------- \n";
                                show(i);
                            }
                    }
                    intf.read((char*)this,sizeof(*this));
                }
                }
                cout<<"\n\t\tPress any key to continue";
                getch();
                system("cls");
                if(i==1)
                    student();
                else
                    librarian();
    }
  void Library::modify()
  {
    char ch,st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n\t\t>>Please Choose one option :-\n";
    cout<<"\n\t\t1.Add New Book\n\n\t\t2.Delete A Book\n\n\t\t3.Go back\n";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    B=Type(2);
                    system("cls");
                    getinput();
                    ofstream outf("Booksdata.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\tBook added Successfully.\n";
    }
    else if(i==2)
    {
                    system("cls");
                    b=Type(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tFile Not Found\n";
                        cout<<"\n\t\tPress any key to continue";
                        getch();
                        intf1.close();
                        system("cls");
                        librarian();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tPlease Choose One Option for deletion:-\n";
                        cout<<"\n\t\t1.By Book Name\n\n\t\t2.By Book's ID\n";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tEnter Book Name : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&bknm[i]!='\0'&&st1[i]!='\0'&&(st1[i]==bknm[i]||st1[i]==bknm[i]+32);i++);
                                        if(bknm[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));

                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }

                    intf.close();
                    outf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tEnter Book's ID : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
                                        if(sc[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));
                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }
                    outf.close();
                    intf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                        }
                        else
                        {
                            cout<<"\n\t\tIncorrect Input:(\n";
                            cout<<"\n\t\tPress any key to continue";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tBook Not Found.\n";
                            cout<<"\n\t\tPress any key to continue";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tDeletion Successful.\n";

    }
    else if(i==3)
    {
    system("cls");
    librarian();
    }
    else
    {
    cout<<"\n\t\tWrong Input.\n";
    cout<<"\n\t\tPress any key to continue";
    getch();
    system("cls");
    modify();
    }
    cout<<"\n\t\tPress any key to continue";
    getch();
    system("cls");
    librarian();

  }
  int Library::Type(int x)
  {
      int i;
      cout<<"\n\t\t>>Please Choose one section :-\n";
      cout<<"\n\t\t1.B.Tech\n\n\t\t2.Fiction\n\n\t\t\t3.Go to menu\n";
      cout<<"\n\t\tEnter your choice : ";
      cin>>i;
      switch(i)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: system("cls");
                  if(x==1)
                  student();
                  else
                    librarian();
          default : cout<<"\n\t\tPlease enter correct option :(";
                    getch();
                    system("cls");
                    Type(x);
        }
  }
  void Library::see(int x)
  {
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b=Type(x);
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found.\n";
            cout<<"\n\t\t->Press any key to continue";
            getch();
            system("cls");
            if(x==1)
            student();
            else
            librarian();
        }

      system("cls");
      cout<<"\n\t\tPlease Choose one option :-\n";
      cout<<"\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID- ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tEnter Book's Name : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==B&&q!=0&&bknm[i]!='\0'&&ch[i]!='\0'&&(ch[i]==bknm[i]||ch[i]==bknm[i]+32);i++);
            if(bknm[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tBook Found :-\n";
                        show(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\n\t\tEnter Book's ID : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==B&&q!=0&&sc[i]!='\0'&&ch[i]!='\0'&&ch[i]==sc[i];i++);
              if(sc[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tBook Found :-\n";
                            show(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tPlease enter correct option :(";
             getch();
             system("cls");
             see(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tThis Book is not available :( \n";

    cout<<"\n\t\tPress any key to continue";
    getch();
    system("cls");
    if(x==1)
    student();
    else
    librarian();


  }
void Library::issue()
{
    char st[50],st1[20];
    int b,i,j,d,m,y,dd,mm,yy,cont=0;
    system("cls");
    cout<<"\n\t\t->Please Choose one option :-\n";
    cout<<"\n\t\t1.Issue Book\n\n\t\t2.View Issued Book\n\n\t\t3.Search student who issued books\n\n\t\t4.Return Book\n\n\t\t5.Go back to menu\n\n\t\tEnter Your Choice : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    system("cls");
    b=Type(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\t\tEnter Book Name : ";
    cin.getline(bknm,100);
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(sc,20);
    //strcpy(st,sc);
    check(sc,b,1);
    cout<<"\n\t\tEnter Student Name : ";
    cin.getline(atnm,100);
    cout<<"\n\t\tEnter Student's ID : ";
    cin.getline(sc1,20);
    cout<<"\n\t\tEnter date : ";
    cin>>q>>B>>p;
    ofstream outf("student.txt",ios::binary|ios::app);
    outf.write((char*)this,sizeof(*this));
    outf.close();
    cout<<"\n\n\t\tIssue Successfully.\n";
    }
    else if(i==2)
    {
    ifstream intf("student.txt",ios::binary);
    system("cls");
    cout<<"\n\t\t->The Details are :-\n";
    intf.read((char*)this,sizeof(*this));
    i=0;
    while(!intf.eof())
    {
    i++;
    cout<<"\n\t\---------- "<<i<<". ---------\n";
    cout<<"\n\t\tStudent Name : "<<atnm<<"\n\t\t"<<"Student's ID : "<<sc1<<"\n\t\t"<<"Book Name : "<<bknm<<"\n\t\t"<<"Book's ID : "<<sc<<"\n\t\t"<<"Date : "<<q<<"/"<<B<<"/"<<p<<"\n";
    intf.read((char*)this,sizeof(*this));
    }
    intf.close();
    }
    else if(i==3)
    {
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t->Please Enter Details :-\n";
        cout<<"\n\n\t\tEnter Student Name : ";
        cin.getline(st,50);
        cout<<"\n\n\t\tEnter Student's ID : ";
        cin.getline(st1,20);
        system("cls");
        ifstream intf("student.txt",ios::binary);
        intf.read((char*)this,sizeof(*this));
        cont=0;
        while(!intf.eof())
        {
              for(i=0;sc1[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc1[i];i++);
              if(sc1[i]=='\0'&&st1[i]=='\0')
              {
                  cont++;
                  if(cont==1)
                  {
                      cout<<"\n\t\t->The Details are :-\n";
                      cout<<"\n\t\tStudent Name : "<<atnm;
                      cout<<"\n\t\tStudent's ID : "<<sc1;
                  }
                  cout<<"\n\n\t\t******* "<<cont<<". Book details *******\n";
                  cout<<"\n\t\tBook Name : "<<bknm;
                  cout<<"\n\t\tBook's ID : "<<sc;
                  cout<<"\n\t\tDate : "<<q<<"/"<<B<<"/"<<p<<"\n";
              }
                      intf.read((char*)this,sizeof(*this));

        }
        intf.close();
        if(cont==0)
            cout<<"\n\t\tNo record found.";
    }

    else if(i==4)
    {
    system("cls");
    b=Type(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(st1,20);
    check(st1,b,2);
    cout<<"\n\n\t\tEnter Student's ID : ";
    cin.getline(st,20);
    cout<<"\n\t\tEnter Present date : ";
    cin>>d>>m>>y;
    ofstream outf("temp.txt",ios::app|ios::binary);
    ifstream intf("student.txt",ios::binary);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
            for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++);
            if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0)
                {
                    cont++;
                    intf.read((char*)this,sizeof(*this));
                    cout<<"\n\t\tReturned successfully.";
                }
            else
                {
                    outf.write((char*)this,sizeof(*this));
                    intf.read((char*)this,sizeof(*this));
                }
        }

    intf.close();
    outf.close();
    getch();
    remove("student.txt");
    rename("temp.txt","student.txt");
    }
    else if(i==5)
    {
    system("cls");
    librarian();
    }
    else
        cout<<"\n\t\tWrong Input.\n";

    cout<<"\n\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    librarian();
}
void Library::check(char st[],int b,int x)
{
    int i,cont=0;
    fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
    {
        for(i=0;b==B&&sc[i]!='\0'&&st[i]!='\0'&&st[i]==sc[i];i++);
        if(sc[i]=='\0'&&st[i]=='\0')
        {
            cont++;
            if(x==1)
            {
                q--;
            }
            else
            {
                q++;
            }
            intf.seekp(intf.tellp()-sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
        }
        intf.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
        cout<<"\n\t\tBook not found.\n";
        cout<<"\n\n\t\tPress any key to continue";
        getch();
        system("cls");
        issue();
    }
    intf.close();
}
void Library::get()
{
   int i;
        cout<<"\n\t----------- LIBRARY MANAGEMENT SYSTEM -----------\n"<<"\n";
        cout<<"\n\t\tChoose Any Option To login as \n";
        cout<<"\n\t\t1.Student\n\n\t\t2.Library Manager\n\n\t\t3.Exit\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            student();
        }
        else if(i==2)
            pass();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("CLS");
           get();
        }
}
void Library::student()
{
    int i;
        cout<<"\n\t------------ WELCOME STUDENT ------------\n";
        cout<<"\n\t\tPlease Choose One Option:\n";
        cout<<"\n\t\t1.Display Book List\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Exit\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            if(i==1)
                bklist(1);
            else if(i==2)
                see(1);
            else if(i==3)
            {
                system("cls");
                get();
            }
            else if(i==4)
                exit(0);
            else
            {
                cout<<"\n\t\tPlease enter correct option :(";
                getch();
                system("cls");
                student();
            }
}
void Library::pass()
{
    int i=0;
    char ch,st[21],ch1[21]={"geu"};
    cout<<"\n\t\tEnter Password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        librarian();
    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again\n";
        getch();
        system("cls");
        get();
    }
}
void Library::librarian()
{
    int i;
        cout<<"\n\t------------ WELCOME LIBRARY MANAGER ------------\n";
        cout<<"\n\t\tPlease Choose One Option:\n";
        cout<<"\n\t\t1.Display Book List\n\n\t\t2.Search for a Book\n\n\t\t3.Add/delete Book\n\n\t\t4.Issue Book\n\n\t\t5.Go to main menu\n\n\t\t6.Exit\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:bklist(2);
                     break;
            case 2:see(2);
                     break;
            case 3:modify();
                     break;
            case 4:issue();
                     break;
            case 5:system("cls");
                     get();
                     break;
            case 6:exit(0);
            default:cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            librarian();
        }
}
int main()
{
    Library obj;
    obj.get();
    getch();
    return 0;
}

