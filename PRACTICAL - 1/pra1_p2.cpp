#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main()
{
    unordered_map<int,int> lib;

    int no;

    cout<<"\n HOW MANY ENTER BOOK DATA :- ";
    cin>>no;

    for(int i =1 ; i<=no;i++)
    {
        int book_id;
        int recieve;

        cout<<"\n ENTER BOOK ID "<< i << ":- " ;
        cin>>book_id;
        
        cout<<"\n HOW MANY BOOK ARE BOUGHT "<< i << ":-" ;
        cin>>recieve;

    auto result = lib.insert({book_id, recieve});
    
    
    for (const auto &l : lib) {
        cout << "Book ID: " << l.first << " | Quantity: " << l.second << endl;
    }

}
 cout<<"\n ---BOOK BOUGHT MORE THEN ONE THIS BOOK ID NUMBER AND HOW MANY BOOK ARE BOUGHT ---"<<endl;
for(auto &x : lib)
{
    if(x.second >1)
    {
        cout<<"BOOK ID :- "<<x.first<<"||"<<"BOUGHT BOOK :-"<<x.second<<endl;
        cout<<"---------------------------------------";
        cout<<"\n restoke books list(ID) are(is) :- "<<x.first;
        
    }
   
}
}