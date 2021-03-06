
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

//Task 1
struct Team{
   string name;
   int points;
   int done_matches;
};

void inputArray(int n, Team iTeam[]);
int  ChoosingTeam(int n, Team iTeam[]);
void Store(int n, Team iArrayTeam[], int team_chosen, int point_earned);
void OutputGameTable(int n, Team iTeam[]);
void ResetGame(int n, Team iTeam[]);
bool compareTwoTeams(Team x, Team y);


int main()
{
    int n;
    cout<<"number of teams: ";
    cin>>n;
    cout<<endl;
    Team iArrayTeam[n];
    cout<<"inputs of teams"<<endl<<"==============="<<endl;
    inputArray(n,iArrayTeam);
    cout<<"initial ranking"<<endl<<"==============="<<endl;
    OutputGameTable(n,iArrayTeam);
    int choice;
    while(1)
         {
               cout<<"0 end"<<endl<<"1 add result of a match"<<endl<<"2 show ranking"<<endl<<"9 reset points"<<endl;
               cout<<"your choice: ";
               cin>>choice;
               switch (choice)
               {
                    case 0: exit(1);
                    case 1:
                          {
                            cout<<"please choose team 1?"<<endl;
                            int a=ChoosingTeam(n,iArrayTeam);
                            cout<<"please choose team 2?"<<endl;
                            int b=ChoosingTeam(n,iArrayTeam);
                            if (a==b){
                              cout<<"*** sorry teams need to be different ***"<<endl<<endl;
                            }
                            else{
                             //input score for two teams
                             int point1st, point2nd;
                             cout<<"input as [point of "<<iArrayTeam[a-1].name<<"] : [points of "<<iArrayTeam[b-1].name<<"] ? ";
                             char colon;
                             cin>>point1st>>colon>>point2nd;
                             //update new total points
                             Store(n,iArrayTeam,a-1, point1st);
                             Store(n,iArrayTeam,b-1, point2nd);
                             sort(iArrayTeam, iArrayTeam+n, compareTwoTeams);
                                }
                          }
                            break;
                    case 2:
                            cout<<endl<<"ranking"<<endl<<"======="<<endl;
                            cout<<setfill(' ')<<setw(7)<<endl;
                            OutputGameTable(n,iArrayTeam);
                            break;
                    case 9:
                            ResetGame(n,iArrayTeam);
                            break;
                    default: cout<<"invalid choice"<<endl;
               }
           }
    return 0;
}


/******************************* FUNCTIONS *********************************************************/
//Task 2:  Initialization Array
void inputArray(int n, Team iTeam[]){
    for (int i=0; i<n;i++){
                  cout<<"team "<<i+1<<": ";
                  cin>>iTeam[i].name;
                  iTeam[i].points=0;
                  iTeam[i].done_matches=0;
                         }
    cout<<endl;
    }


//Task 3: Output Game Table
void OutputGameTable(int n, Team iTeam[]){
    //print the ranking table
     cout<<setw(15)<<left<<"points";
     cout<<setw(15)<<left<<"done matches";
     cout<<setw(15)<<left<<"name"<<endl;
     for (int i=0; i<n; i++)
         {
        cout<<setw(15)<<left<< iTeam[i].points;
        cout<<setw(15)<<left<< iTeam[i].done_matches;
        cout<<setw(15)<<left<< iTeam[i].name<<endl;
         }
    cout<<endl;
}

//Task 4: Choosing a Team
int ChoosingTeam(int n, Team iTeam[]){
    int teamno;
    cout<<"teams"<<endl<<"===="<<endl;
    //print team table
     for (int i=0; i<n; i++)
         {
            cout<<setw(15)<<left<< i+1<<iTeam[i].name<<endl;
         }
    cout<<endl;
    //choosing a team from the table
    cout<<"choose team by number: ";
    cin>>teamno;
    return teamno;
}

//Task 5: Store Game and Points for a Team
void Store(int n, Team iArrayTeam[], int team_chosen, int point_earned){
       iArrayTeam[team_chosen].points+=point_earned;
       iArrayTeam[team_chosen].done_matches+=1;
}

//Task 6: Reset a Game Table
void ResetGame(int n, Team iTeam[]){
              for (int i=0;i<n;i++){
                    iTeam[i].done_matches=0;
                    iTeam[i].points=0;
              }
}

//Sorting table conditions
bool compareTwoTeams(Team x, Team y){
    if (x.points != y.points) return x.points>y.points;
    return x.done_matches<y.done_matches;
}
