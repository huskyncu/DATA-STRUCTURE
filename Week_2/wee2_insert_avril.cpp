#include <iostream>
#include <vector>
using namespace std;

class ScoreData
{
public:
    int id;
    int score;

    ScoreData(int id, int score): id(id), score(score) {}
};

int main()
{
    int amount, maxIndex = 0;
    vector<ScoreData> scoreArray;

    cin >> amount;
    for (int i = 0; i < amount; i++)
    {
        int id, score;
        cin >> id >> score;

        ScoreData s(id, score);
        scoreArray.push_back(s);
    }

    for (int i = 0; i < amount - 1; i++)
    {
        maxIndex = i;

        for (int j = i + 1; j < amount; j++)
        {
            if (scoreArray[j].score > scoreArray[maxIndex].score)
            {
                maxIndex = j;
            }
        }

        ScoreData s = scoreArray[maxIndex];

        scoreArray.erase(scoreArray.begin() + maxIndex);
        scoreArray.insert(scoreArray.begin() + i, s);
        for (int i = 0; i < amount; i++)
        {
            cout << scoreArray[i].id <<" ";
        }
        cout<<endl;
    }

    for (int i = 0; i < amount; i++)
    {
        cout << scoreArray[i].id << endl;
    }

    return 0;
}
