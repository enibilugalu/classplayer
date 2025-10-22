#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
    string name;
    string nickname;
    string team;
    int age;
    int* scores;
    int matchesCount;

public:
    void setName(const string& n) { name = n; }
    void setNickname(const string& nick) { nickname = nick; }
    void setTeam(const string& t) { team = t; }
    void setAge(int a)
    {
        if (a > 0 && a < 120)
            age = a;
        else
            age = 0;
    }

    void setScores(int count)
    {
        matchesCount = count;
        scores = new int[matchesCount];
        for (int i = 0; i < matchesCount; i++)
        {
            cout << "Enter score for match " << i + 1 << ": ";
            cin >> scores[i];
        }
    }

    void printScores() const
    {
        cout << "Scores for " << matchesCount << " matches: ";
        for (int i = 0; i < matchesCount; ++i)
        {
            cout << scores[i] << " ";
        }
        cout << endl;
    }

    string getName() const { return name; }
    string getNickname() const { return nickname; }
    string getTeam() const { return team; }
    int getAge() const { return age; }

    void print() const
    {
        cout << "Name: " << name << endl;
        cout << "Nickname: " << nickname << endl;
        cout << "Team: " << team << endl;
        cout << "Age: " << age << endl;
        printScores();
    }

    Player(string n, string nick, string t, int a)
    {
        setName(n);
        setNickname(nick);
        setTeam(t);
        setAge(a);
        scores = nullptr;
        matchesCount = 0;
    }

    Player()
    {
        name = "empty";
        nickname = "empty";
        team = "none";
        age = 0;
        scores = nullptr;
        matchesCount = 0;
    }

    ~Player()
    {
        delete[] scores;
        cout << "object deleted" << endl;
    }
};

int main()
{
    Player player1("Petr", "Sniper", "Wolves", 14);
    Player player2("Alex", "Shadow", "Tigers", 15);
    Player player3("John", "Ghost", "Lions", 13);
    Player player4("Elena", "Flame", "Eagles", 16);

    int matches;
    cout << "\nEnter number of matches for player 1: ";
    cin >> matches;
    player1.setScores(matches);

    cout << "\nEnter number of matches for player 2: ";
    cin >> matches;
    player2.setScores(matches);

    cout << "\nEnter number of matches for player 3: ";
    cin >> matches;
    player3.setScores(matches);

    cout << "\nEnter number of matches for player 4: ";
    cin >> matches;
    player4.setScores(matches);

    string name, nickname, team;
    int age;

    cout << "\nEnter Player 5:\n";
    cout << "Name: ";
    cin >> name;
    cout << "Nickname: ";
    cin >> nickname;
    cout << "Team: ";
    cin >> team;
    cout << "Age: ";
    cin >> age;

    Player player5(name, nickname, team, age);
    cout << "Enter number of matches for player 5: ";
    cin >> matches;
    player5.setScores(matches);

    Player player6;
    cout << "Enter number of matches for player 6: ";
    cin >> matches;
    player6.setScores(matches);

    cout << "\nplayer 1:\n"; player1.print();
    cout << "\nplayer 2:\n"; player2.print();
    cout << "\nplayer 3:\n"; player3.print();
    cout << "\nplayer 4:\n"; player4.print();
    cout << "\nplayer 5:\n"; player5.print();
    cout << "\nplayer 6:\n"; player6.print();

    return 0;
}
