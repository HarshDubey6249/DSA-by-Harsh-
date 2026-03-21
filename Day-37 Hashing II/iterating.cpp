#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;

void printiterating( unordered_map<string, string> &tickets){

    unordered_set<string>to;

    for(pair<string, string>ticket: tickets){

       to.insert(ticket.second);
    }

    string start="";

     for(pair<string, string>ticket: tickets){

      if( to.find(ticket.first)==to.end()){

        start=ticket.first;
      }
    }
  cout << start;
    while (tickets.count(start))
    {
        cout<<" -> " <<tickets[start];
        start=tickets[start];
    }
    cout<<" -> destination";

}

int main()
{
    unordered_map<string, string> tickets;

    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";
printiterating(tickets);
    return 0;
}