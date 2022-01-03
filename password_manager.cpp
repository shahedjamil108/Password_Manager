#include <bits/stdc++.h>
using namespace std;

void add_new_account()
{
  string account,pass;
  cout<<"Type your id:\n";
  cin>>account;
  cout<<"Type your password: \n";
  cin>>pass;
  string filename("password.txt");
  ofstream file_out;
  file_out.open(filename, ios_base::app);
  file_out <<account<<" "<<pass<<endl;
  cout<<"New id added successfully!\n\n\n";
  return;
}


void view()
{
 string id;
 cout<<"Enter your id: \n";
 cin>>id;
 ifstream read("password.txt");
 string one,account,pass;
 while(getline(read,one))
 {
  account.clear();
  pass.clear();
  bool got=false;
  for(int i=0;i<one.length();i++)
  {
   if(one[i]==' ')
   {
   got=true;
   continue;
   }
   if(got==true) pass+=one[i];
   else account+=one[i];
  }
  if(account==id)
  {
  cout<<"Your password is:\n"<<pass<<"\n\n\n\n";
  break;
  }
 }
 return;
}

void delete_account(const char *file_name, int n)
{
    ifstream is(file_name);
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        if (c == '\n')
        line_no++;
        if (line_no != n)
            ofs << c;
    }
    ofs.close();
    is.close();
    remove(file_name);
    rename("temp.txt", file_name);
}
void update()
{
 string id,pass;
 cout<<"Enter your id:\n";
 cin>>id;
 cout<<"Enter your new pass:\n";
 cin>>pass;
 ifstream read("password.txt");
 string one,account;
 int line=1;
 while(getline(read,one))
 {
  account.clear();
  for(int i=0;i<one.length();i++)
  {
   if(one[i]==' ')
   {
   break;
   }
   account+=one[i];
  }
  if(account==id)
  {
  delete_account("password.txt",line);
  string filename("password.txt");
  ofstream file_out;
  file_out.open(filename, ios_base::app);
  file_out <<account<<" "<<pass<<endl;
  cout<<"Your password is updated sucessfully!\n\n\n\n";
  return;
  }
  line++;
 }
}


int main()
{

     while(1){
     string mode;
     cout<<"Please select your mode.\n";
     cout<<"Type 'Add' to add a new account and password.\n";
     cout<<"Type 'View' to view an existing account and password.\n";
     cout<<"Type 'Update' to update an existing account and password.\n";
     cout<<"Type 'Quit' to quit.\n";
     cin>>mode;
     transform(mode.begin(), mode.end(), mode.begin(), ::tolower);
     if(mode=="add")
     {
      add_new_account();
     }
     else if(mode=="view")
     {
      view();
     }
     else if(mode=="update")
     {
      update();
     }
     else
     {
     break;
     }
     }
   return 0;
}
